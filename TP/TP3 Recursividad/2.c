/* Escribir un programa que, a partir del ingreso de un n�mero entero, 
y mediante la utilizaci�n de una funci�n recursiva verEnBinario, 
permita visualizar el n�mero binario equivalente por pantalla. */

#include <stdio.h>

int mostrarBinario(int);

int main() {
	
	mostrarBinario(28);
	
	return 0;
}

int mostrarBinario(int pNumero) {

	if(pNumero == 0) {
		return 0;
	} else {
		int resultado;
		resultado = pNumero % 2;
		printf("%d",resultado);
		mostrarBinario(pNumero / 2);
		printf("%d",resultado);
		
		return;
	}

}

