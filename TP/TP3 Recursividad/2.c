/* Escribir un programa que, a partir del ingreso de un número entero, 
y mediante la utilización de una función recursiva verEnBinario, 
permita visualizar el número binario equivalente por pantalla. */

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

