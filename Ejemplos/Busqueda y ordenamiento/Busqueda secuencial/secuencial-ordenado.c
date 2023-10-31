/*	Busqueda secuencial:
	Si el vector esta ordenado se puede 
	optimizar la busqueda.
	Evaluando la salida del bucle si el 
	elemento buscado es mayor o igual 
	al elemento actual en el vector
	significa que no existe.	
*/ 

#include <stdio.h>

#define MAX 10

typedef int tVectorInt;
tVectorInt vector[MAX] = {1,2,3,4,5,6,7,8,9,10};

int busquedaSecuencialOrdenado(tVectorInt[], int);

int main() {
	
	int elementoBuscar, existe; 

	elementoBuscar = 5;
	existe = busquedaSecuencialOrdenado(vector,elementoBuscar);
	
	printf("%s", existe != -1 ? "Elemento encontrado" : "No se encontro el elemento");
	return 0;
}

int busquedaSecuencialOrdenado(tVectorInt pVector[], int pElemento) {
	int resultado = -1;
	int i = 0;
	
	while( pVector[i] < pElemento && pVector[i] <= MAX ) {
		i++;
	}
	
	if(pVector[i] == pElemento) {
		resultado = 1;
	}
	return resultado;
}
