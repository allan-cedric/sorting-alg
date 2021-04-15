// === Header file: sorting.h ===

#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// === Estrutura de dados: Heap ===
typedef struct Heap
{
    int *arr;
    int heap_size, arr_size;
} Heap;

// === Retorna o tempo atual do programa em milissegundos ===
double timestamp(void);

// === Imprime um vetor no console ===
void print_array(int *arr, int size);

// === Gera um vetor aleatório, e retorna um ponteiro no mesmo ===
int *make_array(int size);

// === Atualiza um vetor com valores aleatórios ===
void update_array(int *arr, int size);

// === Troca dois elementos de um array ===
void swap_array(int *arr, int i, int j);

// === Algoritmo de ordenação: BubbleSort O(n^2) ===
void bubble_sort(int *arr, int size);

// === Algoritmo de ordenação: SelectionSort O(n^2) ===
void selection_sort(int *arr, int size);

// === Algoritmo de ordenação: InsertionSort O(n^2) ===
void insertion_sort(int *arr, int size);

// === Intercala as duas metades de um vetor  ===
void merge_array(int *arr, int begin, int mid, int end);

// === Algoritmo de ordenação: MergeSort O(n*log n) ===
void merge_sort(int *arr, int begin, int end);

// === Encontra a posição de um pivô no vetor ===
int pivot_index(int *arr, int begin, int end);

// === Algoritmo de ordenação: QuickSort O(n*log n) ===
void quick_sort(int *arr, int begin, int end);

// === Imprime uma Heap ===
void print_heap(Heap *H);

// === Gera uma Heap aleatória ===
void make_heap(Heap *H, int size);

// === Organiza uma Heap com o elemento pai sendo maior que os 2 filhos ===
void max_heapify(Heap *H, int i);

// === Constrói uma Heap de máximo com a função max_heapify() ===
void build_max_heap(Heap *H);

// === Algoritmo de ordenação: HeapSort O(n*log n) ===
void heap_sort(Heap *H);

#endif