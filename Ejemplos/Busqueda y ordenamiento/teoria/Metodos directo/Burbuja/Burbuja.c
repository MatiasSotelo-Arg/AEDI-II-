/* BURBUJA */
#include <stdio.h>

int main() {
		
	// VARIABLES
	#define N 10 
	int i,j,comp, aux = 0;
	int vector[N] = {10,4,1,3,6,7,9,2,5,8};

	int iteraciones = 0;
	
	//ORDENAR
	for(i = 1;i<N;i++) {
		
		for(j = 0;j<N-1;j++) {
			
			if(vector[j] >= vector[j+1]) {
			aux = vector[j];
			printf("aux: %d\n",aux);
			
			vector[j] = vector[j+1];
			printf("vector[j]: %d\n",vector[j]);
			
			vector[j+1] = aux;
			printf("vector[j+1]: %d\n",vector[j+1]);
			printf("\n");
			
			comp++;
			
			}
			iteraciones++;
		}
	}
	
	
	//MOSTRAR VECTOR ORDENADO
	printf("Vector ordenado:\n");
	for(i =0;i<N;i++) {
		printf("%d ",vector[i]);
	}
	printf("\nCantidad comparaciones: %d",comp);
	 printf("\nTotal de iteraciones del bucle interior: %d\n", iteraciones);
	
	return 0;
	
}
