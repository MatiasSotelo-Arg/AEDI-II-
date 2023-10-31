/* Crear un tipo de dato tListaProductos para un nodo que permita 
almacenar los siguientes datos de unproducto: 
codProducto, descripción, precio unitario. 

Luego, declarar un puntero a una variable de ese tipo, y crear el 
primer nodo de la lista a partir del ingreso de datos por teclado. 

Por último, mostrar los datos
del primer nodo almacenado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* TIPOS DE DATOS */
typedef char tString [25];

typedef struct {
	int codProducto;
	tString descripcion;
	float precioUnitario;
}tDato;

typedef struct nodo {
	tDato dato;
	struct nodo * siguiente;
}tLista;

/* VARIABLES GLOBALES */
tDato datos;
tLista * lista;

/* PROTOTIPOS DE FUNCIONES */ 
void inicializarLista(tLista *);
bool listaVacia(tLista *);
void ingresarDatos();
void agregarDatosNodo(tDato);
void mostrarDatos(tLista *);

int main() {
	
	inicializarLista(lista);
	printf("Esta la lista vacia? %s", listaVacia(lista) ? "Si\n" : "No\n");
	mostrarDatos(lista);
	ingresarDatos();
	agregarDatosNodo(datos);
	mostrarDatos(lista);
	return 0;
}
/* IMPLEMENTACION */ 
void inicializarLista(tLista * pLista) {
	pLista = NULL;
	printf("Lista inicializada!\n\n");
}

bool listaVacia(tLista * pLista) {
	return pLista == NULL;
}

void ingresarDatos() {
	
	printf("\n####Ingresar nuevo producto####");
	printf("\nCod. producto: ");
	scanf("%d",&datos.codProducto);
	
	printf("Descripcion: ");
	fflush(stdin);
	scanf("%s",&datos.descripcion);
	
	printf("Precio unitario: ");
	scanf("%f",&datos.precioUnitario);
}

void agregarDatosNodo(tDato pDato) {
	
	tLista * nuevoNodo;
	
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	
	if(listaVacia(lista)) {
		//inserta el primer elemento
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = NULL;
	}
		
	lista = nuevoNodo;
	
	printf("\nSe agrego %d %s %.2f\n",lista->dato.codProducto, lista->dato.descripcion, lista->dato.precioUnitario);
}

void mostrarDatos(tLista * pLista) {
	tLista * aux = pLista;
	
	if(!listaVacia(pLista)) {
		printf("\n###Elementos de la lista###");
		while(aux != NULL) {
			printf("\n%d %s %.0f",pLista->dato.codProducto, pLista->dato.descripcion, pLista->dato.precioUnitario);
			aux = aux->siguiente;
		}
	} else {
		printf("\nNo hay elementos en la lista!\n");
	}
}


