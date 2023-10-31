/* METODO ORDENACION - QUICKSORT */
#include <stdio.h>
#include <stdlib.h>

void intercambio(int *, int *);
void quickSort(int *, int *);
void mostrarVector();


#define N 10
int vector[N] = {5, 8, 2, 12, 9, 4, 17, 6, 1, 3};

int main() {

	//mostramos vector original
	printf("Vector original: ");
	mostrarVector();
	
	//ordenamos el arreglo con quicksort
	quickSort(&vector[0],&vector[N-1]);
	
	//mostramos vector original
	printf("\nVector ordenado: ");
	mostrarVector();
	
	return 0;
}

// Intercambio
void intercambio(int * a,int * b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

// QuickSort
void quickSort(int * pIzq , int * pDer) {
	// Caso base: el subarray tiene 0 o 1 elementos, no se necesita ordenar
	if (pDer <= pIzq) {
        return; 
    }

    int pivote = *pIzq;
    int *ult = pDer;
    int *pri = pIzq;

    while (pIzq < pDer) {
        while (*pIzq <= pivote && pIzq < ult) {
            pIzq++;
        }
        while (*pDer > pivote) {
            pDer--;
        }
        if (pIzq < pDer) {
            intercambio(pIzq, pDer);
        }
    }
    intercambio(pri, pDer);

	// Llamada recursiva para el subarray izquierdo
    quickSort(pri, pDer - 1);  
    // Llamada recursiva para el subarray derecho
    quickSort(pDer + 1, ult);  
}

void mostrarVector() {
	int i = 0;
	
	for(i;i<N;i++){
		printf("%d ",vector[i]);
	}
}

