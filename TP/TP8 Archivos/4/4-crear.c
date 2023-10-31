/* Dado un archivo de texto clientes.txt que contiene, en cada línea, los 
siguientes datos de clientes de un banco: 

número de cuenta
nombre del cliente

realizar un programa que lea este archivo y copie el 
contenido en un nuevo archivo de texto clientes_backup.txt. 

Visualizar al final la cantidad de registros copiados. */

#include <stdio.h>
#include <stdlib.h>

typedef char tString[10];

typedef struct cliente {
	int nroCuenta;
	tString nombre;
} tRegistroCliente ;

tRegistroCliente cliente;

FILE * archivoClientes;

//prototipo de funciones
void crearArchivo();
void procesarDatos();
void ingresarDatos();
void escribirRegistro(); 
void cerrarArchivo();

int main() {
	crearArchivo();
	procesarDatos();
	cerrarArchivo();
	return 0;
}

//implementacion de funciones
void crearArchivo() {
	archivoClientes = fopen("clientes.txt", "w");
	
	if(archivoClientes != NULL) {
		printf("Archivo Creado\n");
	} else {
		printf("Hubo un error\n");
		exit(EXIT_FAILURE);
	}
}

void ingresarDatos() {
	printf("\nNro cuenta: ");
	scanf("%d",&cliente.nroCuenta);
	
	printf("Nombre cliente: ");
	fflush(stdin);
	scanf("%s",&cliente.nombre);
}

void escribirRegistro() {
	fprintf(archivoClientes,"%d %s \n",cliente.nroCuenta, cliente.nombre);
}

void procesarDatos() {
	 
	char caracter = 's';
	
	printf("\nIngrese los datos del cliente\n");
	do {
		ingresarDatos();
		escribirRegistro(); 
		
		
		fflush(stdin);
		printf("\nIngresar otro cliente? s - n:");
		scanf("%c",&caracter);
	} while(caracter == 's');
	
}

void cerrarArchivo() {
	fclose(archivoClientes);
	printf("\nArchivo cerrado");
}


 


