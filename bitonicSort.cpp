/* Programma C++ sul Bitonic Sort*/
#include<bits/stdc++.h>
using namespace std;

/* Nota:8 */
void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

/* Nota 7 */
void confrontaEScambia(int array[], int i, int j, int dir){
	if (dir==(array[i]>array[j]))
    swap(array, i, j);
}

/* Nota: 6 */
void bitonicMerge(int array[], int pos, int focus, int dir){
   // Se ci fosse un solo elemento non avrebbe senso ordinarlo
	if (focus>1)
	{
    // Divisore per la sottosequenza
		int k = focus/2;

    //Dalla posizione iniziale fino alla fine della sotto sequenza
		for (int i=pos; i<pos+k; i++)
			confrontaEScambia(array, i, i+k, dir);

    //Ricorsione
		bitonicMerge(array, pos, k, dir);
		bitonicMerge(array, pos+k, k, dir);
	}
}

/* Nota: 5 */
void bitonicSort(int arrayDaOrdinare[],int sottoSequenza, int size, int direzione){
	if (size > 1)
	{
		int k = size/2;

    // per il sort crescente la direzione è 1
		bitonicSort(arrayDaOrdinare, sottoSequenza, k, 1);

		// per il sort decrescente la direzione è 0
		bitonicSort(arrayDaOrdinare, sottoSequenza+k, k, 0);

		// Unirà la sequenza in ordine crescente
    // bitonicMerge(array, pos, focus, dir)
		bitonicMerge(arrayDaOrdinare, sottoSequenza, size, direzione);
	}
}

/* Nota: 4*/
void sort(int arrayDaOrdinare[], int sizeArrayDaOrdinare, int direzione){
  //bitonicSort(array, sottoSequenza, size, direzione)
	bitonicSort(arrayDaOrdinare, 0, sizeArrayDaOrdinare, direzione);
}

// Main del programma
int main(){
  // Indicazioni Programma ---> Nota: 1
	// Sequenza Bitonica ---> Nota: 2
	int arrayDaOrdinare[]= {3, 7, 4, 8, 6, 2, 1, 5};
	int sizeArrayDaOrdinare = sizeof(arrayDaOrdinare)/sizeof(arrayDaOrdinare[0]);

	int direzione = 1; // Nota: 3
	sort(arrayDaOrdinare, sizeArrayDaOrdinare, direzione);
	cout << "Array ordinato: ";
	for (int i = 0; i < sizeArrayDaOrdinare; i++)
		cout << arrayDaOrdinare[i] << ' ';
	return 0;
}
