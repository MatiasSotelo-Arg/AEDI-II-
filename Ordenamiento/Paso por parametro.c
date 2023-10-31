#include <stdio.h>

void cambiarValor(int *);
int main() {
	
	int valor = 1;
	
	int *direccion = &valor;
	
	printf("valor: %d",valor);
	printf("\ndireccion: %d",direccion);
	
	cambiarValor(&valor);

	
	printf("\nMain - valor: %d",valor);
	return 0;
}

void cambiarValor(int *pValor) {
	
	*pValor = 2;
	
}
