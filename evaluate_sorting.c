// === Programa que calcula o tempo médio em segundos dos algoritmos de ordenação ===
#include "sorting.h"

#define MAX_ELEMENTS ((int)1e6)
#define MAX_TESTS ((int)1e2)

void bubble_sort_evaluate(int num_tests, int size);
void selection_sort_evaluate(int num_tests, int size);
void insertion_sort_evaluate(int num_tests, int size);

void merge_sort_evaluate(int num_tests, int size);
void quick_sort_evaluate(int num_tests, int size);
void heap_sort_evaluate(int num_tests, int size);

int main()
{
    srand(time(NULL));

    printf("num_elements,bubble_sort,selection_sort,insertion_sort");
    printf("merge_sort,quick_sort,heap_sort\n");
    for(int size = 10; size <= MAX_ELEMENTS; size *= 2)
    {
        printf("%i,",size);

        bubble_sort_evaluate(MAX_TESTS, size);
        printf(",");

        selection_sort_evaluate(MAX_TESTS, size);
        printf(",");

        insertion_sort_evaluate(MAX_TESTS, size);
        printf(",");

        merge_sort_evaluate(MAX_TESTS, size);
        printf(",");

        quick_sort_evaluate(MAX_TESTS, size);
        printf(",");

        heap_sort_evaluate(MAX_TESTS, size);
        printf("\n");
    }

    return 0;
}

void bubble_sort_evaluate(int num_tests, int size)
{
    int arr[size];

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_array(arr, size);
        // print_array(arr, size);

        t_begin = timestamp();
        bubble_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}

void selection_sort_evaluate(int num_tests, int size)
{
    int arr[size];

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_array(arr, size);
        // print_array(arr, size);

        t_begin = timestamp();
        selection_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}

void insertion_sort_evaluate(int num_tests, int size)
{
    int arr[size];

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_array(arr, size);
        // print_array(arr, size);

        t_begin = timestamp();
        insertion_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}

void merge_sort_evaluate(int num_tests, int size)
{
    int arr[size];

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_array(arr, size);
        // print_array(arr, size);

        t_begin = timestamp();
        merge_sort(arr, 0, size - 1);
        t_end = timestamp();

        // print_array(arr, size);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}

void quick_sort_evaluate(int num_tests, int size)
{
    int arr[size];

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_array(arr, size);
        // print_array(arr, size);

        t_begin = timestamp();
        quick_sort(arr, 0, size - 1);
        t_end = timestamp();

        // print_array(arr, size);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}

void heap_sort_evaluate(int num_tests, int size)
{
    Heap hp;

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        make_heap(&hp, size);
        // print_heap(&hp);

        t_begin = timestamp();
        heap_sort(&hp);
        t_end = timestamp();

        // print_heap(&hp);

        t_sum += ((t_end - t_begin) / 1000.0);
    }
    printf("%f", (t_sum / num_tests));
}
