/* 
Escribir un programa que permita construir un árbol binario de búsqueda correspondiente a una lista de 
números enteros. 

Se debe considerar el nodo raíz del árbol, el primer elemento que se inserta en la lista. 

Los siguientes nodos serán descendientes derechos si son mayores, y descendientes izquierdos si son 
menores (tener en cuenta el orden de la lista dada). 

Además, programar funciones para el recorrido en 
pre-orden, 
in-orden y 
post-orden. 

Testear el programa, insertando los siguientes valores: 4 19 -7 49 100 0 22 12
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//tipos de datos
typedef struct {
	int numero;
}tDato;

typedef struct nodoArbol {
	tDato dato;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

/* Declaración de prototipos */
void crearArbolVacio( tArbol ** );
bool arbolVacio( tArbol * );
void insertarElemento( tArbol **, tDato );
void recorrerPreorden( tArbol * );
void recorrerPostorden( tArbol * );
void recorrerInorder( tArbol * );

/* Variables globales */
tArbol * arbol;
tDato dato;

/* Main */
int main() {
	crearArbolVacio(&arbol);
	
	dato.numero = 4;
	insertarElemento(&arbol,dato);
	
	dato.numero = 19;
	insertarElemento(&arbol,dato);
	
	dato.numero = -7;
	insertarElemento(&arbol,dato);
	
	dato.numero = 49;
	insertarElemento(&arbol,dato);
	
	dato.numero = 100;
	insertarElemento(&arbol,dato);
	
	dato.numero = 0;
	insertarElemento(&arbol,dato);
	
	dato.numero = 22;
	insertarElemento(&arbol,dato);
		
	dato.numero = 12;
	insertarElemento(&arbol,dato);
	
	recorrerPreorden(arbol);
	printf("\n");
	recorrerInorden(arbol);
	printf("\n");
	recorrerPostorden(arbol);
}

/* Implementacion de funciones */
void crearArbolVacio( tArbol ** pArbol) {
	*pArbol = NULL;
	printf("Arbol creado!\n");
}

bool arbolVacio( tArbol * pArbol ) {
	return pArbol == NULL;
}

void insertarElemento( tArbol ** pArbol, tDato pDato ) {
	if(arbolVacio(*pArbol)) {
		(*pArbol) = (tArbol *) malloc(sizeof(tArbol)); 
		
		(*pArbol)->dato = pDato;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
	} else {
		if(pDato.numero > (*pArbol)->dato.numero) {
			insertarElemento(&(*pArbol)->hijoDerecho, pDato);
		} else {
			if(pDato.numero < (*pArbol)->dato.numero) {
				insertarElemento(&(*pArbol)->hijoIzquierdo, pDato);
			} else {
				/* si el valor ya existe */
				printf("Elemento duplicado!\n");
			}
		}
	}
}

void recorrerPreorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) {
		printf("%d ", pArbol->dato.numero);
		recorrerPreorden(pArbol->hijoIzquierdo);
		recorrerPreorden(pArbol->hijoDerecho);
	}
}

void recorrerPostorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) {
		recorrerPostorden(pArbol->hijoIzquierdo);
		recorrerPostorden(pArbol->hijoDerecho);
		printf("%d ",pArbol->dato.numero);
	}
}

void recorrerInorden( tArbol * pArbol ) {
	if(!(arbolVacio(pArbol))) {
		recorrerInorden(pArbol->hijoIzquierdo);
		printf("%d ",pArbol->dato.numero);
		recorrerInorden(pArbol->hijoDerecho);
	}
}





