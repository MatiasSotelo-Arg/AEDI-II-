/* 
Construir un árbol binario de búsqueda, donde el contenido de cada nodo sea un entero positivo, y que 
permita las siguientes acciones: 
a) Insertar nodos en el árbol.
b) Saber si el árbol está vacío.
c) Buscar un elemento en el árbol. 
d) Eliminar un nodo del árbol.
*/

#include <stdio.h>
#include <stdbool.h>

/* Tipos de datos */
typedef struct {
	int numero;
}tDato;

typedef struct nodoArbol {
	tDato dato;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

/* Prototipos */
void crearArbol( tArbol ** );
bool arbolVacio( tArbol * );
void insertarElemento( tArbol ** , tDato);
int buscarElemento( tArbol * , int );
void eliminarNodo( tArbol ** , int );
	
/* Variables globales */
tArbol * arbol;


/* Main */
int main() {
	
	crearArbol(&arbol);
	
	printf("%s",arbolVacio(arbol) ? "El arbol esta vacio!\n" : "False\n");
	
	tDato vDato;
	
	vDato.numero = 55;
	insertarElemento(&arbol, vDato);
	
	vDato.numero = 55;
	insertarElemento(&arbol, vDato);
	
	vDato.numero = 40;
	insertarElemento(&arbol, vDato);
	
	int elemento = buscarElemento(arbol, 40);
	
	if(elemento != 0) {
		printf("\nElemento encontrado: %d\n",elemento);
	} else {
		printf("\nEl elemento %d no existe!\n",elemento);
	}
	
	return 0;
}

/* Implementacion de funciones */
void crearArbol( tArbol ** pArbol ) {
	*pArbol = NULL;
	printf("Arbol creado!\n");
}

bool arbolVacio( tArbol * pArbol ){
	return (pArbol == NULL);
}

void insertarElemento( tArbol ** pArbol, tDato pDato){
	
	if(arbolVacio(*pArbol)) {
		(*pArbol) = (tArbol *)malloc(sizeof(tArbol));	
		
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
				printf("\nElemento duplicado!\n");
			}
		} 
	}
}

int buscarElemento( tArbol * pArbol , int pElemento ){
	if(arbolVacio(pArbol)) {
		return 0;
	} else {
		if( pElemento > pArbol->dato.numero ) {
			buscarElemento(pArbol->hijoDerecho, pElemento);
		} else {
			if( pElemento < pArbol->dato.numero ) {
				buscarElemento(pArbol->hijoIzquierdo, pElemento);
			} else {
				return pArbol->dato.numero;
			}
		}
	}
}

void eliminarElemento( tArbol ** pArbol, int pCodigo) {
	tArbol * aux;
	
	if(arbolVacio(*pArbol)){
		printf("No existe el elemento que se desea eliminar!\n");
	} else {
		if(pCodigo < (*pArbol)->datos.codigo) {
			eliminarElemento(&((*pArbol)->hijoIzquierdo));
		} else {
			if( pCodigo > (*pArbol)->datos.codigo) {
				eliminarElemento(&((*pArbol)->hijoDerecho, pDato));
			} else {
				if((*pArbol)->hijoIzquierdo == NULL) {
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDerecho;
					free(aux);
				} else {
					if( (*pArbol)->hijoDerecho == NULL) {
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzquierdo;
						free(aux);
					}
				}
			}
		}
	}
}


