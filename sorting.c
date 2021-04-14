#include "sorting.h"

double timestamp(void)
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return ((double)(tp.tv_sec * 1000.0 + tp.tv_usec / 1000.0));
}

void print_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
        printf("%i ", arr[i]);
    printf("%i]\n", arr[size - 1]);
}

void make_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (size * 3));
}

void swap_array(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int *arr, int size)
{
    if (!arr)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap_array(arr, j, j + 1);
        }
    }
}

void selection_sort(int *arr, int size)
{
    if (!arr)
        return;
    for (int i = 0, j = 0, min = 0; i < size - 1; i++)
    {
        for (j = i + 1, min = i; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
            swap_array(arr, i, min);
    }
}

void insertion_sort(int *arr, int size)
{
    if (!arr)
        return;
    for (int i = 1, j; i < size; i++)
    {
        int key = arr[i];
        for (j = i; (j > 0) && (key < arr[j - 1]); j--)
            arr[j] = arr[j - 1];
        if (j != i)
            arr[j] = key;
    }
}
void merge_array(int *arr, int begin, int mid, int end)
{
    int w[end - begin + 1];
    int i = begin, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            w[k++] = arr[i++];
        else
            w[k++] = arr[j++];
    }

    while (i <= mid)
        w[k++] = arr[i++];
    while (j <= end)
        w[k++] = arr[j++];

    for (i = begin; i <= end; i++)
        arr[i] = w[i - begin];
}

void merge_sort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = begin + (end - begin) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge_array(arr, begin, mid, end);
    }
}

int pivot(int *arr, int begin, int end)
{
    int pivot = arr[begin];
    int i, j;
    for (i = end, j = end; j > begin; j--)
    {
        if (arr[j] > pivot)
            swap_array(arr, i--, j);
    }
    swap_array(arr, i, begin);
    return i;
}

void quick_sort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        int pivot_index = pivot(arr, begin, end);
        quick_sort(arr, begin, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

void print_heap(Heap *H)
{
    printf("[");
    for (int i = 1; i <= H->arr_size - 1; i++)
        printf("%i ", H->arr[i]);
    printf("%i]\n", H->arr[H->arr_size]);
}

void make_heap(Heap *H, int size)
{
    H->arr_size = size;
    H->heap_size = size;
    H->arr = malloc(sizeof(int) * (H->arr_size + 1));
    for (int i = 1; i <= H->arr_size; i++)
        H->arr[i] = (rand() % (size * 3));
}

void max_heapify(Heap *H, int i)
{
    int left = 2 * i, right = 2 * i + 1, largest = i;

    if (left <= H->heap_size && H->arr[left] > H->arr[i])
        largest = left;

    if (right <= H->heap_size && H->arr[right] > H->arr[largest])
        largest = right;

    if (largest != i)
    {
        swap_array(H->arr, i, largest);
        max_heapify(H, largest);
    }
}

void build_max_heap(Heap *H)
{
    for (int i = H->heap_size / 2; i >= 1; i--)
        max_heapify(H, i);
}

void heap_sort(Heap *H)
{
    build_max_heap(H);
    while (H->heap_size >= 2)
    {
        swap_array(H->arr, H->heap_size--, 1);
        max_heapify(H, 1);
    }
}