/* Metodo baraja */
#include <stdio.h>

int main() {
	
	#define N 10
	
	int vector[N] = {7, 2, 10, 3, 8, 1, 6, 5, 4, 9};	
	
	int i, j, aux = 0;
	
	for(i = 1;i<N;i++){
		
		aux = vector[i]; 
		j = i; 
				
				
		while(j>0 && aux < vector[j-1]) {
				  
			vector[j] = vector[j-1]; 
			
			j--; {0}
		}
			 
		vector[j] = aux; 
	}
	
	for(i=0; i<N; i++) {
		printf("%d ",vector[i]);
	}
	return 0;
}

