/* Seleccion Directa (obtencion sucesiva de menores):
	busca sucesivamente el elemento menor y lo cambia 
*/ 

#include <stdio.h>

#define N 10

typedef int tVectorInt;

tVectorInt vector[N] = {5, 2, 8, 1, 10, 3, 7, 9, 6, 4};

//prototipo de funciones
void mostrarVector(tVectorInt *);
void metodoSeleccionDirecta(tVectorInt *);

int main() {
	printf("Vector desordenado: \n");
	mostrarVector(vector);
	
	metodoSeleccionDirecta(vector);
	printf("\nVector ordenado: \n");
	mostrarVector(vector);
	return 0;
}

//implementacion de funciones
void mostrarVector(tVectorInt *pVector) {
	int i = 0; 
	
	for(i;i<N;i++) {
		printf("%d ",pVector[i]);
	}
	
}

void metodoSeleccionDirecta(tVectorInt *pVector) {
	
	int i,j;
	int valMenor, posMenor, aux;
	
	for(i = 0; i < N - 1; i++) {
		valMenor = pVector[i];
		posMenor = i;
		for(j = i + 1; j < N ; j++) {
			if(pVector[j] < valMenor) {
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if(posMenor != i) {
			aux = pVector[i];
			pVector[i] = valMenor;
			pVector[posMenor] = aux;
		}
	}
}
