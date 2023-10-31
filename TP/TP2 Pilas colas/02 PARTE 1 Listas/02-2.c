/*Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una
lista enlazada:*/
//a) Generar o inicializar la lista.
//b) Función para determinar si una lista está vacía.
//c) Insertar el primer producto (nodo) de la lista.
//d) Insertar un producto al principio de la lista.
//e) Eliminar el primer producto de la lista.
//f) Insertar un producto en una determinada posición dentro de la lista.
//g) Eliminar un producto de una determinada posición de la lista.

//h) Visualizar todos los datos de los productos que están en la lista.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* **** lista de productos ****
	Estrategia
		1)
		inicializarLista
		ingresarDatosProductos
		agregarProductoLista
			listaVacia
				agregarPrimero
		mostrarLista
		2)
		eliminarAdelante
		insertarK
		eliminarK
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

void eliminarAdelante();

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
	eliminarAdelante();
	
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

void eliminarAdelante() {
	if(!listaVacia(lista)) {
		tListaProductos * nodoEliminar;
		nodoEliminar = lista;
		
		lista = nodoEliminar->siguiente;

		printf("\nElimino -> %d %s $%.2f\n",producto.codProducto, producto.descripcion, producto.precioUnitario);
		
		free(nodoEliminar);
		nodoEliminar = NULL;
		
		
	} else {
		printf("No hay elementos en la lista!");
	}
}

