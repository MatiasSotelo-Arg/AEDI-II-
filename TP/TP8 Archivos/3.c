/* 3. Escribir un programa que lea el archivo de texto generado en el ejercicio anterior y 
visualice por pantalla cada registro del archivo. */ 

#include <stdio.h>
#include <stdlib.h>

FILE * archivoAlumnos;

//prototipo de funciones
void abrirArchivo();
void leerArchivo();
void cerrarArchivo();

int main() {
	abrirArchivo();
	leerArchivo();
	cerrarArchivo();
	return 0;
}

//implementacion de funciones
void abrirArchivo() {
	archivoAlumnos = fopen("datos_alumnos.txt","r");
	
	if(archivoAlumnos != NULL) {
		printf("Archivo abierto!\n");
	} else {
		printf("Hubo un error!\n");
		exit(EXIT_FAILURE);
	}
}

void leerArchivo() {
	char caracter; 
	int contador;
	
	printf("\n###Archivo Alumnos###\n");
	do {
		caracter = getc(archivoAlumnos);
		printf("%c",caracter);
		if(caracter == '\n') {
			contador++;
		}  
	} while(!feof(archivoAlumnos));
	
	printf("\nRegistros Leidos: %d\n",contador);
}

void cerrarArchivo() {
	fclose(archivoAlumnos);
	printf("\nArchivo cerrado!\n");
}

