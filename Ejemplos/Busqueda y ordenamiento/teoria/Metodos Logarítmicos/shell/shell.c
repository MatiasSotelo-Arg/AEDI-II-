/* Metodo SHELL */ 

#include <stdio.h>

#define N 5

int v[N] = {15, 42, 33, 7, 10};

void mostrarVectorOrdenado();

int main() {
	
	int inter=(N/2), i = 0, j = 0, k = 0, aux = 0;
	
	while(inter > 0) {
	
		for(i=inter; i < N; i++){ 
			j = (i-inter);
		
		
			while(j>=0) {
		
				k=j+inter;
		
				if(v[j]<=v[k]) {
					j--;		
				} else {
					
					aux=v[j];
					v[j] = v[k];
					v[k] = aux;
					j=(j-inter);
					
				}
			}
		}
	
		inter = (inter/2);
	}
	
	mostrarVectorOrdenado();
	
	return 0;
}

void mostrarVectorOrdenado() {
	printf("\n\nVector ordenado ");
	int i;
	for(i=0;i<N;i++) {
		printf("%d ",v[i]);
	}
}

