#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/* Tamanho dos vetores de teste */
#define TAM 20

/*Número de testes*/
#define TESTES 1

/* Estrutura de dados: Heap */
struct Heap
{
    int *h;
    int tam_heap;
    int tam_vet;
};
typedef struct Heap Heap;

/*
    Retorna o tempo de execução
    do programa em milisegundos
*/
double timestamp(void);

void imprime_vetor(int *v);
void gera_vetor(int *v);
void troca(int *v, int i, int j);

void bubble_sort(int *v, int tam);

void selection_sort(int *v, int tam);

void insertion_sort(int *v, int tam);

void intercala(int *v, int ini, int meio, int fim);
void merge_sort(int *v, int ini, int fim);

int particiona(int *v, int ini, int fim);
void quick_sort(int *v, int ini, int fim);

void cria_heap(Heap *H);
void max_heapify(Heap *H, int i);
void build_max_heap(Heap *H);
void heapsort(Heap *H);

#endif