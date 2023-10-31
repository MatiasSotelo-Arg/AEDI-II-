/*En la recepción de un banco, la recepcionista entrega un ticket con el número de atención a cada persona.
El sistema almacena los siguientes datos de cada turno: 
número de turno, 
nombre del cliente 
y motivo (1.transacción 2. consulta). 
Además de las operaciones básicas para el manejo de la cola con punteros, se
solicita disponer de:
a) una función que devuelva la cantidad de personas que están esperando un turno para realizar una
“transacción”
b) una función que devuelva la cantidad de personas que están esperando un turno para realizar una
“consulta”
c) un listado que permita visualizar el orden, nombre y motivo de cada persona en la cola.
d) Implementar un menú principal que contenga todas las operaciones disponibles
*/

/* ESTRATEGIA
inicializarCola(); ok
colaVacia(); ok 
ingresarDatos(); ok
push(); ok
cantidadTransaccion() -> retorna el valor  ok
cantidadConsultas -> retorna el valor ok
visualizarLista -> nombre y motivo 
menuOpciones(); ok */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

//tipos de datos
typedef char tString[25];

typedef struct {
	int numero;
	tString nombreCliente;
	int motivo;
}tCliente;

typedef struct nodo {
	tCliente cliente;
	struct nodo * siguiente;
} tNodo;

typedef struct {
	tNodo * principio;
	tNodo * final;
}tCola;

//variables globales 
tCola cola;
tCliente vCliente;

int numeroTicket = -1;

//prototipo de funciones
void inicializarCola();
bool colaVacia( tCola );
void menuOpciones();
void ingresarDatos();
void push( tCliente );
int cantidadTransaccion( tCola );
int cantidadConsultas( tCola );
void visualizarLista( tCola );

//MAIN
int main() {
	inicializarCola();
	menuOpciones();
	return 0;
}

//implementacion 
void inicializarCola() {
	cola.principio = NULL;
	cola.final = NULL;
	printf("Cola inicializada...\n\n");
}

bool colaVacia(tCola pCola) {
	return (pCola.principio == NULL && pCola.final == NULL);
}

void menuOpciones() {
	int opciones = 0;
	
	printf("\n##### MENU #####\n");
	printf("0-Salir\n1-Entregar ticket\n2-Mostrar cant transacciones\n3-Mostrar cant consultas\n4-Mostrar cola\n");
	scanf("%d",&opciones);
	
	switch(opciones) {
		case 1:
			system("cls");
			printf("Ingrese nuevo cliente\n");
			ingresarDatos();
			push(vCliente);
			menuOpciones();
			break;
		case 2:
			if(!colaVacia(cola)) {
				printf("\nCantidad clientes por transacciones (%d)\n",cantidadTransaccion(cola));
			} else {
				printf("\nNo se ingreso ningun cliente para transacciones\n");
			}
			
			menuOpciones();
			break;
		case 3:
			if(!colaVacia(cola)) {
				printf("\nCantidad clientes por consultas (%d)\n",cantidadConsultas(cola));
			} else {
				printf("\nNo se ingreso ningun cliente para transacciones\n");
			}
			
			menuOpciones();
			break;
		case 4:
			visualizarLista(cola);
			menuOpciones();
			break;
		case 0:
			printf("Salir");
			break;
		default:
			system("cls");
			printf("\n-> La opcion %d no es valida!\n",opciones);
			menuOpciones();
			break;
	}
}

void ingresarDatos() {

	numeroTicket++;
	
	vCliente.numero = numeroTicket;
	
	tString nombreCliente; 
	
	printf("Nombre cliente: ");
	fflush(stdin);
	scanf("%s",&nombreCliente);
	strcpy(vCliente.nombreCliente, nombreCliente);
	
	printf("Motivo (1.transaccion 2. consulta): ");
	scanf("%d",&vCliente.motivo);
	
}

void push( tCliente pCliente ) {
	tNodo * nuevoNodo;
	
	nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
	
	nuevoNodo->cliente = pCliente;
	nuevoNodo->siguiente = NULL;
	
	if(colaVacia(cola)) {
		cola.principio = nuevoNodo;
		cola.final = nuevoNodo;
	} else {
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
	
	printf("\nNuevo cliente ingresado\nTicket nro: %d\nNombre: %s\nMotivo: %d\n",cola.final->cliente.numero,cola.final->cliente.nombreCliente, cola.final->cliente.motivo );
	
}

int cantidadTransaccion(tCola pCola) {
	int cantTransaccion = 0;
	
	if(!colaVacia(pCola)) {
		tNodo * aux = pCola.principio;
		
		while(aux != NULL) {
			
			if(aux->cliente.motivo == 1) {
				cantTransaccion++;
			}
			aux = aux->siguiente;
		}
	} 
	return cantTransaccion;
}

int cantidadConsultas(tCola pCola) {
	int cantConsultas = 0;
	
	if(!colaVacia(cola)) {
		tNodo * aux = pCola.principio;
		
		while(aux != NULL) {
			if(aux->cliente.motivo == 2) {
				cantConsultas++;
			}
			aux = aux->siguiente;
		}
	} 
	return cantConsultas;
}

void visualizarLista( tCola pCola ) {
	if(colaVacia(pCola)) {
		printf("\nNo hay elementos para visualizar!\n");
	} else {
		tNodo * aux = pCola.principio;
		printf("#### Elementos en la cola ####\n");
		while(aux != NULL){
			if(aux->cliente.motivo == 1) {
				printf("%d %s transaccion\n",aux->cliente.numero, aux->cliente.nombreCliente);
			} 
			if(aux->cliente.motivo == 2) {
				printf("%d %s consulta\n",aux->cliente.numero, aux->cliente.nombreCliente);
			}
			aux = aux->siguiente;
		}
	}
}
