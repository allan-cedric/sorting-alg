#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TAM 20
#define TESTES 1

/*
    Retorna o tempo de execução
    do programa em milisegundos
*/
double timestamp(void);

void imprime_vetor(int *v);
void gera_vetor(int *v);
void troca(int *v, int i, int j);
void bubblesort(int *v, int tam);
void selectionsort(int *v, int tam);
void insertionsort(int *v, int tam);
void mergesort(int *v, int ini, int fim);
void quicksort(int *v, int ini, int fim);

#endif