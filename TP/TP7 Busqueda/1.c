/* 1. Escribir un programa que permita determinar si un número 
entero ingresado por teclado, existe en un vector. 

Para ello será necesario, disponer de lo siguiente:
a) Una función que permita cargar elementos en un vector de números enteros.
b) Una función que permita visualizar los elementos almacenados en el vector.
c) Una función que devuelva verdadero en el caso que el elemento a buscar 
exista en el vector, y falso en caso contrario. */ 

#include <stdio.h>
#include <stdbool.h>

#define MAX 5
typedef int tVectorInt;

tVectorInt vector[MAX];

//prototipos de funciones
void cargarElementos(tVectorInt *);
void mostrarElementos(tVectorInt *); 
bool existeElemento(tVectorInt *, int);

int main() {
	cargarElementos(&vector);
	mostrarElementos(vector);
	
	int ele = 3;
	printf(existeElemento(vector,3) == true ? "\nExiste %d" : "\nNo existe %d", ele);
	return 0;
}

//implementacion
void cargarElementos(tVectorInt * pVector) {
	int i = 0;
	printf("Ingresar elementos al Vector\n");
	for(i;i<MAX;i++) {
		printf("Elemento: ");
		scanf("%d",&pVector[i]);
	}
}

void mostrarElementos(tVectorInt * pVector) {
	int i = 0;
	printf("\nMostrar Elementos del Vector\n");
	for(i;i<MAX;i++) {
		printf("%d ",pVector[i]);
	}
}

bool existeElemento(tVectorInt * pVector , int pElemento) {
	
	bool existe = false;
	int i = 0;
	
	while((i < MAX) && (pElemento > pVector[i])) {
		i++;
	}
	
	if(pElemento == pVector[i]) {
		existe = true;
	}
	return existe;
}

