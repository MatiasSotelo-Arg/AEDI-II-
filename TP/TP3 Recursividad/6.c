/*
Escribir un programa que, a partir del ingreso de dos n�meros enteros positivos, 
calcule el producto de los mismos utilizando una funci�n recursiva. 

Tener presente que la definici�n recursiva de la multiplicaci�n de dos n�meros a y b,
se deriva de la definici�n de la multiplicaci�n como una suma abreviada y la
aplicaci�n de la propiedad asociativa de la suma.
*/

#include <stdio.h>

//prototipo 
int calcProducto(int, int);

int main() {
	
	int producto = 0;
	int multiplicando, multiplicador;
	
	multiplicando = 7;
	multiplicador = 10;
	
	producto = calcProducto(multiplicando,multiplicador);
	
	printf("Resultado: %d",producto);
	
	return 0;
}

int calcProducto(int pMultiplicando,int pMultiplicador) {
	
	int aux;
	
	if(pMultiplicador == 0 || pMultiplicador == 0) {
		printf("No se puede multiplicar por 0\n");
		return;
	} else {
	    aux = pMultiplicando + calcProducto(pMultiplicando, pMultiplicador-1);
	    printf("%d\n",aux);
	    return aux;
	}
}
