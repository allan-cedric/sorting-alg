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

void bubble_sort(int *v, int tam)
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

void selection_sort(int *v, int tam)
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
void intercala(int *v, int ini, int meio, int fim)
{
    int w[fim - ini + 1];
    int i = ini, j = meio + 1, k = 0;

    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }

    while (i <= meio)
        w[k++] = v[i++];
    while (j <= fim)
        w[k++] = v[j++];

    for (i = ini; i <= fim; i++)
        v[i] = w[i - ini];
}

void merge_sort(int *v, int ini, int fim)
{
    if (ini < fim)
    {
        int meio = ini + (fim - ini) / 2;
        merge_sort(v, ini, meio);
        merge_sort(v, meio + 1, fim);
        intercala(v, ini, meio, fim);
    }
}

int particiona(int *v, int ini, int fim)
{
    int pivo = v[ini];
    int i, j;
    for (i = fim, j = fim; j > ini; j--)
    {
        if (v[j] > pivo)
            troca(v, i--, j);
    }
    troca(v, i, ini);
    return i;
}

void quick_sort(int *v, int ini, int fim)
{
    if (ini < fim)
    {
        int i_pivo = particiona(v, ini, fim);
        quick_sort(v, ini, i_pivo - 1);
        quick_sort(v, i_pivo + 1, fim);
    }
}