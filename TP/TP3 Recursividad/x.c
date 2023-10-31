#include <stdio.h>

//prototipo 
int contador(int *);

int main() {
	
	int i = 0;
		
	int resultado = 0;
	
	for(i; i<10; i++) {
		contador(&resultado);
		printf("%d\n",resultado);
	}
	
	return 0;
}

int contador( int * pIterar ) {
	return (*pIterar)++;
}
