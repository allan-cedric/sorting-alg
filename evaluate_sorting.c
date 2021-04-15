// === Programa que calcula o tempo médio em milissegundos dos principais algoritmos de ordenação ===
#include "sorting.h"

#define MAX_ELEMENTS ((int)2e5)
#define MAX_TESTS ((int)5)

void bubble_sort_evaluate(int num_tests, int size);
void selection_sort_evaluate(int num_tests, int size);
void insertion_sort_evaluate(int num_tests, int size);

void merge_sort_evaluate(int num_tests, int size);
void quick_sort_evaluate(int num_tests, int size);
void heap_sort_evaluate(int num_tests, int size);

FILE *arq_csv;

int main()
{
    srand(time(NULL));

    arq_csv = fopen("./data_evaluate_sorting.csv", "w");
    if (!arq_csv)
    {
        fprintf(stderr, "Error opening data file\n");
        exit(1);
    }

    fprintf(arq_csv, "num_elements,bubble_sort,selection_sort,insertion_sort,");
    fprintf(arq_csv, "merge_sort,quick_sort,heap_sort\n");
    for (int size = 10; size <= MAX_ELEMENTS; size *= 2)
    {
        fprintf(arq_csv, "%i,", size);

        bubble_sort_evaluate(MAX_TESTS, size);
        fputc(',', arq_csv);

        selection_sort_evaluate(MAX_TESTS, size);
        fputc(',', arq_csv);

        insertion_sort_evaluate(MAX_TESTS, size);
        fputc(',', arq_csv);

        merge_sort_evaluate(MAX_TESTS, size);
        fputc(',', arq_csv);

        quick_sort_evaluate(MAX_TESTS, size);
        fputc(',', arq_csv);

        heap_sort_evaluate(MAX_TESTS, size);
        fputc('\n', arq_csv);
    }
    fclose(arq_csv);

    return 0;
}

void bubble_sort_evaluate(int num_tests, int size)
{
    int *arr = make_array(size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_array(arr, size);

        t_begin = timestamp();
        bubble_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);
        t_sum += (t_end - t_begin);

        update_array(arr, size);
    }
    free(arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}

void selection_sort_evaluate(int num_tests, int size)
{
    int *arr = make_array(size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_array(arr, size);

        t_begin = timestamp();
        selection_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);
        t_sum += (t_end - t_begin);

        update_array(arr, size);
    }
    free(arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}

void insertion_sort_evaluate(int num_tests, int size)
{
    int *arr = make_array(size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_array(arr, size);

        t_begin = timestamp();
        insertion_sort(arr, size);
        t_end = timestamp();

        // print_array(arr, size);
        t_sum += (t_end - t_begin);

        update_array(arr, size);
    }
    free(arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}

void merge_sort_evaluate(int num_tests, int size)
{
    int *arr = make_array(size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_array(arr, size);

        t_begin = timestamp();
        merge_sort(arr, 0, size - 1);
        t_end = timestamp();

        // print_array(arr, size);
        t_sum += (t_end - t_begin);

        update_array(arr, size);
    }
    free(arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}

void quick_sort_evaluate(int num_tests, int size)
{
    int *arr = make_array(size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_array(arr, size);

        t_begin = timestamp();
        quick_sort(arr, 0, size - 1);
        t_end = timestamp();

        // print_array(arr, size);
        t_sum += (t_end - t_begin);

        update_array(arr, size);
    }
    free(arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}

void heap_sort_evaluate(int num_tests, int size)
{
    Heap hp;
    make_heap(&hp, size);

    double t_begin, t_end, t_sum = 0.0;
    for (int i = 0; i < num_tests; i++)
    {
        // print_heap(&hp);

        t_begin = timestamp();
        heap_sort(&hp);
        t_end = timestamp();

        // print_heap(&hp);
        t_sum += (t_end - t_begin);

        hp.arr_size = size;
        hp.heap_size = size;
        update_array(hp.arr, hp.arr_size);
    }
    free(hp.arr);
    fprintf(arq_csv, "%.2f", (t_sum / num_tests));
}
