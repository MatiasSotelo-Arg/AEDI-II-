/* 1. El archivo Fix_you.txt contiene la letra de la canción de Coldplay del mismo nombre. 
Escribir un programa que lea este archivo y muestre la canción por pantalla */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prototipos de funciones 
void abrirArchivo();
void leerDatos();
void cerrarArchivo();

FILE * archivoTexto;

int main() {
	abrirArchivo();
	leerDatos();
	cerrarArchivo();
	return 0;
}
//prototipos de funciones
void abrirArchivo() {
	
	archivoTexto = fopen("Fix_you.txt","r");
	
	if(archivoTexto == NULL) {
		printf("Hubo un error!");
		cerrarArchivo();
	}
}

void cerrarArchivo() {
	printf("Se cerro el archivo!");
	fclose(archivoTexto);
}

void leerDatos() {
	
	
//	letra = getc(archivoTexto);
//	
//	while(!feof(archivoTexto)) {
//		
//		printf("%c",letra);
//		letra = getc(archivoTexto);
//	} 

	//do - while
//	do {
//		letra = getc(archivoTexto);
//		printf("%c",letra);
//	} while(!feof(archivoTexto));

	/* fgets: lee líneas completas de texto en lugar de caracteres individuales
			  lee caracteres del archivo o entrada estándar hasta que se 
			  encuentra con un salto de línea ('\n');

		sintaxtis: fgets(char *cadena, int longitud, FILE *archivo); 
			
		cadena: es un puntero a un arreglo de caracteres 
		(cadena) donde se almacenará la línea leída.
			
		longitud: es el número máximo de caracteres que se 
		pueden leer (típicamente el tamaño del arreglo).
			
	    archivo: es un puntero a un archivo desde el cual leer la línea. 
		(stdin) se leerá desde la entrada estándar.
	
	*/
	char linea[100];
	
	while(fgets(linea, sizeof(linea), archivoTexto) != NULL ) {
		printf("%s", linea);
	}
} 
