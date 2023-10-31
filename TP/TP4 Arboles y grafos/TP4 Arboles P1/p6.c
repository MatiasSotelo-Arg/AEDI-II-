/* 
Escribir un programa que permita crear un árbol binario de búsqueda, 
el contenido de los nodos debe ser de tipo real. 

Incluir los procedimientos para insertar, devolver el número de nodos y recorrer el árbol.

a) El procedimiento Insertar debe emitir una leyenda 'Es un hijo izquierdo' o 'Es un hijo derecho', según 
corresponda.

b) Escribir la función que devuelva el número de nodos del árbol binario.

c) El procedimiento Recorrer debe mostrar el contenido del nodo, siguiendo algún recorrido en 
profundidad.
*/

#include <stdio.h>
#include <stdbool.h>

/* tipos de datos */
typedef struct {
	float numero;
}tDato;

typedef struct nodoArbol {
	tDato dato;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

/* prototipos */
void crearArbol( tArbol ** );
bool arbolVacio( tArbol * );
void insertarElemento( tArbol **, tDato );
//	Imprimir izq o der
int cantidadDeNodos(tArbol *);
void recorrerInOrden(tArbol *);

/* var globales */
tDato vDato;
tArbol * arbol;

/* Main */
int main () {
	
	crearArbol(&arbol);
	printf("%s",arbolVacio(arbol) ? "arbol vacio" : "false");
	
	printf("\nCantidad de nodos: %d",cantidadDeNodos(arbol));
	
	vDato.numero = 50;
	insertarElemento(&arbol, vDato);
	
	vDato.numero = 55;
	insertarElemento(&arbol, vDato);
	
	vDato.numero = 45;
	insertarElemento(&arbol, vDato);
	
	vDato.numero = 44;
	insertarElemento(&arbol, vDato);
	
	printf("\nCantidad de nodos: %d\n",cantidadDeNodos(arbol));
	
	recorrerInOrden(arbol);
	
	return 0;
}

/* Implementacion */
void crearArbol(tArbol ** pArbol) {
	(*pArbol) = NULL;
	printf("Arbol creado!\n");
}

bool arbolVacio(tArbol * pArbol) {
	return pArbol == NULL;
}

void insertarElemento(tArbol **pArbol, tDato pDato) {
    if (arbolVacio(*pArbol)) {
        /* Inserta raiz */
        (*pArbol) = (tArbol *)malloc(sizeof(tArbol));

        (*pArbol)->dato = pDato;
        (*pArbol)->hijoIzquierdo = NULL;
        (*pArbol)->hijoDerecho = NULL;

    } else {

        if (pDato.numero > (*pArbol)->dato.numero) {
            if ((*pArbol)->hijoDerecho == NULL) {
                printf("\n%.2f Es un hijo derecho",pDato.numero);
            }
            insertarElemento(&(*pArbol)->hijoDerecho, pDato);

        } else {
            if (pDato.numero < (*pArbol)->dato.numero) {
                if ((*pArbol)->hijoIzquierdo == NULL) {
                    printf("\n%.2f Es un hijo izquierdos",pDato.numero);
                }
                insertarElemento(&(*pArbol)->hijoIzquierdo, pDato);
                
            } else {
                printf("\nElemento duplicado!");
            }
        }
    }
}

int cantidadDeNodos (tArbol * pArbol) {
	if(arbolVacio(pArbol)) {
		return 0;
	} else {
		return 1 + cantidadDeNodos(pArbol->hijoIzquierdo) + cantidadDeNodos(pArbol->hijoDerecho);
	}
}

void recorrerInOrden(tArbol * pArbol) {
	if(!arbolVacio(pArbol)) {
		recorrerInOrden(pArbol->hijoIzquierdo);
		printf("%.2f ", pArbol->dato.numero);
		recorrerInOrden(pArbol->hijoDerecho);
	}
}



