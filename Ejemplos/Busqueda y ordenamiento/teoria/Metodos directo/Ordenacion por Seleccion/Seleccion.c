/* ORDENACION POR SELECCION */
#include <stdio.h>

int main () {
	int i, j, pos, aux = 0;
	#define N 10
	int v[N] = {7, 2, 10, 3, 8, 1, 6, 5, 4, 9};
	
	//ORDENAR
	for(i = 0;i<N-1;i++) {
		pos = i;

		for(j = (i+1) ; j<N ;j++) {
			if(v[pos] > v[j]) {
				pos = j;
			}
			

		}
		if(pos!=i) {
				aux = v[i];
				v[i] = v[pos];
				v[pos] = aux;
		}
	}
	
	//MOSTRAR LISTA ORDENADA
	printf("LISTA ORDENADA\n");
	for(i=0;i<N;i++) {
		printf("%d ",v[i]);
	}	
	return 0;
}
