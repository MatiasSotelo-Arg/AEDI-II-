/* Metodo Baraja: 


 */ 
#include <stdio.h>

#define N 10

typedef int tVectorInt;

tVectorInt vector[N] = {5, 2, 8, 1, 10, 3, 7, 9, 6, 4};

//prototipos de funciones
void mostrarVector(tVectorInt *);
void metodoBaraja(tVectorInt *);

//prototipo de funciones

int main() {
	printf("Vector desordenado: \n");
	mostrarVector(vector);
	
	metodoBaraja(vector);
	return 0;
}

// implementacion de funciones 
void mostrarVector(tVectorInt * pVector) {
	int i = 0; 
	
	for(i;i<N;i++) {
		printf("%d ",pVector[i]);
	}
	
}

void metodoBaraja(tVectorInt * pVector) {
	int i, j; //i for, j while
	int aux;  // intercambiar
	
	for(i=1; i < N; i++) {
		aux = pVector[i];
		j = i - 1;
		// se deben cumplir ambas condiciones
		while((j>=0) && (pVector[j] > aux)) {
			pVector[j+1] = pVector[j];
			j = j - 1; //pq cuando llega a 0 para el bucle
		}
		//una vez fuera del bucle asigna el valor al siguiente 
		pVector[j+1] = aux;
	}
	
}
