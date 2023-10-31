/* 
Escribir un programa que permita ingresar un número entero positivo y luego, mediante una función
recursiva, muestre el número de forma invertida. Ej.: 123 - 321.
*/

#include <stdio.h>
 
//	int numero = 4565;
//	
//	printf("Nro original: %d\n",numero);
//	printf("Ult digito: %d\n", numero % 10);
//	printf("Nro sin ult digito: %d\n", numero / 10);

//prototipo 
void invertirNumero(int);
 
int main() {
	
	int numero = 4565;
	
	printf("Numero original: %d\n",numero);
	printf("Numero invertido: ");
	invertirNumero(numero);
	
	return 0;
}

void invertirNumero(int pNumero) {
	if(pNumero == 0) {
		return;
	} else {
		printf("%d", pNumero % 10);
		invertirNumero(pNumero / 10);
	}
}
