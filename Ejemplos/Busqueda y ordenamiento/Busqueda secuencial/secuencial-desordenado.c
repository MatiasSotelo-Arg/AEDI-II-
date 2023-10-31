/* Busqueda secuencial:
	para elementos desordenados
*/ 

#include <stdio.h>

#define MAX 10

typedef int tVectorInt;

tVectorInt vector[MAX] = {2, 9, 5, 1, 7, 8, 4, 10, 3, 6};

int busquedaSecuencial(tVectorInt[], int);

int main() {
	int eleBuscado = 11;
	int elemento = busquedaSecuencial(vector,eleBuscado);
	
	printf((elemento != -1) ? "elemento %d encontrado\nen la posicion: %d" : "no se encontro el elemento %d",eleBuscado,elemento );
}

int busquedaSecuencial(tVectorInt pVector[], int pElemento) {
	int posicion = -1;
	int i = 0;
	
	while( (pVector[i] != pElemento) && ( i != MAX )) {
		i = i + 1;
	}
	
	if( pVector[i] == pElemento ) {
		posicion = i;
	}
	
	return posicion;
}
