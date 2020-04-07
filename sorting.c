#include "sorting.h"

double timestamp(void)
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return ((double)(tp.tv_sec * 1000.0 + tp.tv_usec / 1000.0));
}

void imprime_vetor(int *v)
{
    int i;
    printf("[");
    for (i = 0; i < TAM - 1; i++)
        printf("%i ", v[i]);
    printf("%i]\n", v[TAM - 1]);
}

void gera_vetor(int *v)
{
    int i;
    for (i = 0; i < TAM; i++)
        v[i] = (rand() % (TAM * 3));
}

void troca(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubblesort(int *v, int tam)
{
    if (!v)
        return;
    int i, j;
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
                troca(v, j, j + 1);
        }
    }
}

void selectionsort(int *v, int tam)
{
    if (!v)
        return;
    int i, j, min;
    for (i = 0, j = 0, min = 0; i < tam - 1; i++)
    {
        for (j = i + 1, min = i; j < tam; j++)
        {
            if (v[j] < v[min])
                min = j;
        }

        if (min != i)
            troca(v, i, min);
    }
}

void insertion_sort(int *v, int tam)
{
    if (!v)
        return;
    int i, j, chave;
    for (i = 1; i < tam; i++)
    {
        chave = v[i];
        for (j = i; (j > 0) && (chave < v[j - 1]); j--)
            v[j] = v[j - 1];
        if (j != i)
            v[j] = chave;
    }
}