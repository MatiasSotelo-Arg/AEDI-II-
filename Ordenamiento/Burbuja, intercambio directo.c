/* Algoritmos de ordenamiento directos:
	Burbuja: Itera cada elemento de vector
	y lo compara con el siguiente 
	si el anterior < siguiente -> hace el cambio 
	
	Burbuja	
	5	4	9	7
	4	5	9	7
	4	5	9	7
	4	5	7	9
	4	5	7	9 
		 
*/

#include <stdio.h>

#define N 10

typedef int tVectorInt;

tVectorInt vector[N] = {5, 2, 8, 1, 10, 3, 7, 9, 6, 4};

//prototipos de funciones
void mostrarVector(tVectorInt *);
void metodoBurbuja(tVectorInt *);

int main() {
	printf("Vector desordenado: \n");
	mostrarVector(vector);
	
	
	printf("\n\nVector ordenado Burbuja: \n");
	metodoBurbuja(vector);
	mostrarVector(vector);
	
	return 0;
}

//implementacion de funciones
void mostrarVector(tVectorInt * pVector) {
	int i = 0; 
	
	for(i;i<N;i++) {
		printf("%d ",pVector[i]);
	}
	
}

void metodoBurbuja(tVectorInt * pVector) {
	int i, j, aux;
	
	for(i = 0;i<N - 1;i++) {
		for(j = 0;j < N - 1; j++) {
			if(pVector[j] > pVector[j+1]) {
//		index	0	1	2	3
//				5	4	9	7
				aux = pVector[j];
//				aux = 5;
				pVector[j] = pVector[j+1];
//		index	0	1	2	3
//				4	4	9	7
				pVector[j+1] = aux;
//		index	0	1	2	3
//				4	5	9	7
			}
		}
	}
}
