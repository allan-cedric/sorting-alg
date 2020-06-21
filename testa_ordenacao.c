#include "sorting.h"

int main()
{
    srand(time(NULL));
    /*int v[TAM];*/ /* Usar p/ o Bubble/Insertion/Selection/Merge ou Quick */
    int i;
    double t_ini, t_fim, t_soma = 0;

    /* Quando desejar usar o Heapsort */
    Heap heap;
    criar_heap(&heap);

    for (i = 0; i < TESTES; i++)
    {
        /*gera_vetor(v);
        imprime_vetor(v);*/
        imprime_heap(&heap);
        t_ini = timestamp();
        /*bubble_sort(v, TAM);
        selection_sort(v, TAM);
        insertion_sort(v, TAM);
        merge_sort(v, 0, TAM - 1);
        quick_sort(v, 0, TAM - 1);*/
        heap_sort(&heap);
        t_fim = timestamp();
        /*imprime_vetor(v);*/
        imprime_heap(&heap);
        t_soma += (t_fim - t_ini);
    }
    printf("Tempo(ms): %f\n", (t_soma / TESTES));
    free(heap.h);

    return 0;
}
