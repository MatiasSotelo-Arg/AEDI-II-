#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* **** lista de productos ****
	Estrategia
		inicializarLista
		ingresarDatosProductos
		agregarProductoLista
			listaVacia
				agregarPrimero
		mostrarLista
	*/

//tipos de datos
typedef char tString[25];

typedef struct {
	int codProducto;
	tString descripcion;
	float precioUnitario;
}tProducto;
	
typedef struct nodo {
	tProducto producto;
	struct nodo * siguiente;
}tListaProductos; 

//prototipos de funciones
void inicializarLista();
void ingresarDatosProductos();
bool listaVacia( tListaProductos *);

void agregarProductoLista( tProducto );
void agregarPrimero( tProducto );

void mostrarLista( tListaProductos *);



//variables
tProducto producto;
tListaProductos * lista;

//MAIN
int main() {
	
	inicializarLista();
	mostrarLista(lista);
	
	ingresarDatosProductos();
	agregarProductoLista(producto);
	
	mostrarLista(lista);
	return 0;
}

//implementacion de funciones
void inicializarLista() {
	lista = NULL;
	printf("Lista inicializada!\n");
}

void ingresarDatosProductos() {
	printf("\n***Ingresar nuevo producto***\n");
	printf("Codigo: ");
	scanf("%d",&producto.codProducto);
	
	printf("Descripcion: ");
	fflush(stdin);
	scanf("%s",&producto.descripcion);
	
	printf("Precio: $");
	scanf("%f",&producto.precioUnitario);
	
	printf("\nAgrego-> %d %s $%.2f\n",producto.codProducto, producto.descripcion, producto.precioUnitario);
}

bool listaVacia(tListaProductos * pLista) {
	return (pLista == NULL);
}


void agregarProductoLista(tProducto pProducto) {
	if(listaVacia(lista)) {
		agregarPrimero(pProducto);
	}
 }

void agregarPrimero(tProducto pProducto) {
	tListaProductos * nuevoNodo;
	
	nuevoNodo = (tListaProductos *) malloc(sizeof(tListaProductos));
	
	nuevoNodo->producto = pProducto;
	
	nuevoNodo->siguiente = NULL;
	
	lista = nuevoNodo;
	
	printf("\nSe ingreso el primer producto a la lista!\n");
}

void mostrarLista( tListaProductos * pLista) {
	tListaProductos * aux;
	aux = pLista;
	
	if(!listaVacia(aux)) {
		printf("\n***Elementos de la lista***\n");
		while(aux != NULL) {
			printf("%d %s %.2f \n", aux->producto.codProducto, aux->producto.descripcion, aux->producto.precioUnitario);
			aux = aux->siguiente;
		}
	} else {
		printf("\nNo hay elementos en la lista!\n");
	}
}



