/* Dado un archivo de texto clientes.txt que contiene, en cada línea, los siguientes datos 
de clientes de un banco: 

número de cuenta, nombre del cliente; 

realizar un programa que lea este archivo y copie el contenido en un nuevo archivo de texto 
clientes_backup.txt. 

Visualizar al final la cantidad de registros copiados. */ 

#include <stdio.h>
#include <stdlib.h>
 
FILE *archivoOriginal, *archivoRespaldo; 

typedef char tString[10];

//prototipo de funciones
void abrirArchivo(FILE **, tString,char);
void procesarDatos();
void cerrarArchivo(FILE *, tString);

int contadorRegistros = 0;

int main() {
	abrirArchivo(&archivoOriginal,"clientes.txt",'r');
	abrirArchivo(&archivoRespaldo,"clientes_backup.txt", 'w');
	

	
	procesarDatos(); 
	printf("\nSe han copiado %d registros al archivo clientes_backup.txt\n", contadorRegistros);
	
	cerrarArchivo(archivoOriginal, "clientes.txt");
	cerrarArchivo(archivoRespaldo, "clientes_backup.txt");
	return 0;
}


//implementacion de funciones
void abrirArchivo(FILE ** pArchivo,tString pNombreArchivo , char pModoLectura) {
	 
	 *pArchivo = fopen(pNombreArchivo, &pModoLectura);
	 
	 if(pArchivo == NULL) {
	 	printf("Hubo en error en %s\n",pNombreArchivo);
	 	exit(EXIT_FAILURE);
	 } else {
	 	printf("Archivo %s abierto\n",pNombreArchivo);
	 }
	 
}

void procesarDatos() {
	tString registroAux;

	while(fgets(registroAux, sizeof(registroAux), archivoOriginal) != NULL) {
		fprintf(archivoRespaldo, "%s", registroAux);
		contadorRegistros++;
	}
	
}

void cerrarArchivo(FILE *pArchivo, tString pNombreArchivo) {
	fclose(pArchivo);
	printf("\nArchivo %s cerrado",pNombreArchivo);
}
