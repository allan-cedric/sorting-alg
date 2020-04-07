#include "sorting.h"

int main()
{
    srand(time(NULL));
    int v[TAM];
    int i;
    double t_ini, t_fim, t_soma = 0;

    for (i = 0; i < TESTES; i++)
    {
        gera_vetor(v) ;
        imprime_vetor (v);
        t_ini = timestamp();
        bubblesort(v, TAM);
        /*selectionsort(v, TAM);
        insertionsort(v, TAM);*/
        t_fim = timestamp();
        imprime_vetor (v);
        t_soma += (t_fim - t_ini);
    }
    printf("Tempo(ms): %f\n", t_soma / TESTES);

    return 0;
}