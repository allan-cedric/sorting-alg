# Comparação de custos dos principais algoritmos de ordenação

## Algoritmos:

### Classe O(n^2)

*	`Bubble Sort`
	
*	`Selection Sort`
	
*	`Insertion Sort`
	
### Classe O(n*log(n))
	
*	`Merge Sort`
	
*	`Quick Sort`
	
*	`Heap Sort`

### Arquivos

*	`sorting.h` \ `sorting.c`: Biblioteca onde estão implementados os algoritmos de ordenação.

*	`evaluate_sorting.c`: Programa principal para computar o custo de cada algoritmo. É realizado uma bateria de testes com vetores de diversos tamanhos, além disso o programa salva cada custo de cada algoritmo em um arquivo `.csv`.

*	`plot.py`: Script que realiza o plot dos gŕaficos de comparação entre os algoritmos de ordenação. Ele utiliza o arquivo `.csv` gerado pelo programa: `evaluate_sorting.c`.
