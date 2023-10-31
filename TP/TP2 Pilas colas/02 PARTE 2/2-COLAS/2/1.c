/*
	En la recepción de un banco, la recepcionista entrega un 
	ticket con el número de atención a cada persona.
	
	El sistema almacena los siguientes datos de cada turno: 
	número de turno, 
	nombre del cliente y 
	motivo (1.transacción 2. consulta). 
	
	Además de las operaciones básicas para el manejo de la cola con punteros, se
	solicita disponer de:
	a) una función que devuelva la cantidad de personas que 
	están esperando un turno para realizar una “transacción”.
	b) una función que devuelva la cantidad de personas que están 
	esperando un turno para realizar una “consulta”.
	c) un listado que permita visualizar el orden, nombre y 
	motivo de cada persona en la cola.
	d) Implementar un menú principal que contenga 
	todas las operaciones disponibles
*/

/* Recepcion banco 

	inicializarCola();
	colaVacia();
	
	menu();
	
	ingresarDatos();
		nroTurno
		nombreCliente
		motivo
	push(); 
	pop();
	
	int cantPersonasTransaccion();
	int cantPersonasConsulta();
	
	visualizarLista()
		-> turno, nombre, motivo
				
*/
	
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//tipos de datos
typedef char tString[25];

typedef struct {
	int nroTurno;
	tString nombreCliente;
	int motivo;
} tCliente;

typedef struct nodo {
	tCliente cliente;
	struct nodo * siguiente;
}tNodo;

typedef struct {
	tNodo * primero;
	tNodo * ultimo;
}tCola;
 
//funciones globales
tCliente vCliente;
tCola cola;
int nroCliente = -1;

//prototipos de funciones
void inicializarCola();
bool colaVacia(tCola);
void menu(int);
tCliente ingresarDatos();
void push(tCliente);

int main() {
	inicializarCola();
	
	int opcionMenu = -1;

	do {
		printf("\n##MENU##\n");
		
		//opciones
		printf("1-Nuevo cliente\n0-Salir\n");
	
		scanf("%d",&opcionMenu);
		
		//invoco el menu
		menu(opcionMenu);
		
	} while( opcionMenu != 0 );
	
	printf("Salir");
	
	return 0;
}

//implementacion de funciones
void inicializarCola() {
	cola.primero = NULL;
	cola.ultimo = NULL;
	printf("Cola inicializada!\n");
}

bool colaVacia(tCola pCola) {
	return (pCola.primero == NULL && pCola.ultimo == NULL); 
}

void menu(int pOpcion) {
	
	switch(pOpcion) {
		case 1:
			ingresarDatos();
			break;
		case 2:
			printf("Entro opcion 1");
			break;
		case 0: 
			break;
			
		default: 
			printf("El valor no es correcto %d", pOpcion);
			break;
	}
	
}

tCliente ingresarDatos() {
	
	nroCliente++;
	
	printf("\n##Nuevo cliente##\n");
	printf("Nro cliente: %d",nroCliente);
	
	tString nombre, apellido, nombreCompleto; 
	
	printf("\nNombre: ");
	fflush(stdin);
	scanf("%s",nombre);
	
	printf("\nApellido: ");
	fflush(stdin);
	scanf("%s",apellido);	
	
	stcpy(vCliente.nombreCliente, nombre);
 	strcat(nombreCliente, " ");
    strcat(nombreCliente, apellido);
	
	vCliente.nombreCliente = nombreCompleto;
	
	printf("%s",vCliente.nombreCliente);
	

	return;
}



