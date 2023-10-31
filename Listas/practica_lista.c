/* LISTA DE COMPRA
definir tipos de datos
	-> elemento
	-> lista
	
inicializarLista
agregarArticulo
	-> agregarPrimerElemento
	-> agregarUltimo
mostrarLista
eliminarUltimoElemento 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//tipos de datos propios
typedef char tString[15];

typedef struct {
	tString titulo;
}tArticulo;

typedef struct nodo {
	tArticulo articulo;
	struct nodo * siguiente;
} tLista;

//variables
tLista * lista;

//prototipos
void inicializar_lista();
bool lista_vacia( tLista * );
void agregar_articulo( tArticulo );
void agregar_primer_art();
void agregar_art_adelante();
void visualizar_articulos( tLista *);
void eliminar_primer_articulo();
void eliminar_ult_articulo( tLista *);
int cantidad_nodos( tLista * );


// main
int main () {
	tArticulo articulo;
	inicializar_lista();
	printf("La lista esta vacia? %s\n", lista_vacia(lista) ? "Si" : "No");
	
	//	agregar primer articulo
	strcpy(articulo.titulo, "fideos");
	agregar_articulo( articulo );
	
	//	agregar ult ele
	strcpy(articulo.titulo, "coca");
	agregar_articulo( articulo );
	
	//	agregar ult ele
	strcpy(articulo.titulo, "papas");
	agregar_articulo( articulo );
	
	//	agregar ult ele
	strcpy(articulo.titulo, "tacos");
	agregar_articulo( articulo );
	
	visualizar_articulos(lista);
	
	eliminar_primer_articulo();
	
	visualizar_articulos(lista);
	
	eliminar_ult_articulo(lista);
	
	visualizar_articulos(lista);
	
	return 0;
}

//implementacion
void inicializar_lista() {
	lista = NULL;
	printf("Lista inicializada!\n");
}

bool lista_vacia( tLista * pLista ) {
	return (pLista == NULL);
}

void agregar_articulo( tArticulo pArticulo ) {
	if(lista_vacia(lista)) {
		agregar_primer_art(pArticulo);
	} else {
		agregar_art_adelante(pArticulo);
	}
}

void agregar_primer_art( tArticulo pArticulo) {
	//	creo el nodo 
	tLista * nuevoNodo;
	
	//	bloque memoria
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	
	nuevoNodo->articulo = pArticulo;
	
	nuevoNodo->siguiente = NULL;
	
	lista = nuevoNodo;
	
	printf("Se agrego el primer rticulo %s\n", pArticulo.titulo);

}

void agregar_art_adelante( tArticulo pArticulo ) {
	//	creo el nodo 
	tLista * nuevoNodo;
	
	//	bloque memoria
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	
	nuevoNodo->articulo = pArticulo;
	
	nuevoNodo->siguiente = lista;
	
	lista = nuevoNodo;
	
	printf("Se agrego %s\n", pArticulo.titulo);
}

void visualizar_articulos( tLista * pLista ) {
	tLista * aux;
	aux = pLista;
	
	if(!lista_vacia(aux)) {
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("Articulo: %s\n", aux->articulo.titulo);
			aux = aux->siguiente;
		}
	} else {
		printf("No hay elementos para visualizar!\n");
	}	
	
	printf("\nCantidad nodos: %d\n", cantidad_nodos(lista));
}

void eliminar_primer_articulo( tLista * pLista ) {
	if(!lista_vacia(lista)) {
		tLista * nodoSuprimir = lista;
		
		lista = lista->siguiente;
		
		printf("\nSe elimino el primer elemento: %s\n", nodoSuprimir->articulo.titulo);
		
		free(nodoSuprimir);
		
		nodoSuprimir = NULL;
	} else {
		printf("No hay elementos para quitar!\n");
	}
}

int cantidad_nodos( tLista * pLista ) {
	tLista * aux;
	int contador = 0;
	aux = pLista;
	
	if( !lista_vacia(aux) ) {
		while(aux != NULL) {
			contador++;
			aux = aux->siguiente;
		}
	}
	return contador;
}

void eliminar_ult_articulo( tLista * pLista) {
	if(!lista_vacia(pLista)) {
		tLista * nodoActual = pLista;
		tLista * nodoAnterior = NULL;
		
		while(nodoActual->siguiente != NULL) {
			nodoAnterior = nodoActual;
			nodoActual = nodoActual->siguiente;
		}
		
		nodoAnterior->siguiente = NULL;
		
		printf("\nSe elimino el ultimo elemento: %s\n", nodoActual->articulo.titulo);
		
		free(nodoActual);
		nodoActual = NULL;
	} else {
		printf("\nLa lista esta vacia!\n");
	}
	
}

