/*Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una 
lista enlazada:
a) Generar o inicializar la lista.
b) Función para determinar si una lista está vacía.
c) Insertar el primer producto (nodo) de la lista.
d) Insertar un producto al principio de la lista.
e) Eliminar el primer producto de la lista.
f) Insertar un producto en una determinada posición dentro de la lista.
g) Eliminar un producto de una determinada posición de la lista.
h) Visualizar todos los datos de los productos que están en la lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* TIPOS DE DATOS */ 
typedef char tString[25];

typedef struct {
	int codProducto;
	tString descripcion;
	float precioUnitario;
}tProducto;

typedef struct nodo {
	tProducto producto;
	struct nodo * siguiente;
}tListaProducto;

/* VARIBLES GLOBALES */ 
tProducto vProducto;
tListaProducto * listaProductos;

/* PROTOTIPOS DE FUNCIONES*/
void inicializarLista(tListaProducto **);
bool listaVacia(tListaProducto *);
int cantNodos(tListaProducto *);
tProducto ingresarDatos();
void agregarDatoLista(tProducto, tListaProducto *);
void eliminarPrimero(tListaProducto *);
void insertarK(tProducto, tListaProducto *);
void eliminarK(tListaProducto *);
void visualizarLista(tListaProducto *);

/* MAIN */ 
int main() {
	inicializarLista(&listaProductos);
	printf("Cantidad nodos: %d\n",cantNodos(listaProductos));
	
	
	return 0;
}

/* IMPLEMENTACION DE FUNCIONES */ 
void inicializarLista(tListaProducto ** pLista) {
	*pLista = NULL;
	printf("Lista inicializada!\n");

}

bool listaVacia(tListaProducto * pLista) {
	return (pLista == NULL);
}

int cantNodos(tListaProducto * pLista) {
	int contador = 0;
	tListaProducto * aux = pLista;
	
	if(!listaVacia(pLista)) {
		while(aux != NULL) {
			contador++;
			aux = aux->siguiente;
		} 
		return contador;
	} else {
		return contador;
	}
}

tProducto ingresarDatos() {
	printf("Ingresar datos productos!\n");
	
	printf("Cod. producto: ");
	scanf("%d",&vProducto.codProducto);
	
	printf("Descripcion: ");
	fflush(stdin);
	scanf("%s",&vProducto.descripcion);
	
	printf("Precio unitario: ");
	scanf("%f",&vProducto.precioUnitario);
	
	return vProducto;
}
 
