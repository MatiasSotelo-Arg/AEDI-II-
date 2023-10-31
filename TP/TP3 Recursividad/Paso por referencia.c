

#include <stdio.h>

int contar( int * );

void otraFuncion();

int main() {
	
	int n = 0;
	
	int i;
	
	for(i = 0; i < 10; i++) {
		printf("%d\n",contar(&n));
	}
	
	otraFuncion();
	
	return 0;
}

void otraFuncion () {
	printf("\nOtro contador\n");
	
	int n2 = 0;
	
	int i;
	
	for(i = 0; i < 10; i++) {
		printf("%d\n",contar(&n2));
	}
	
}

int contar( int * pNumero ) {
	(*pNumero)++;
	return *pNumero;
}
