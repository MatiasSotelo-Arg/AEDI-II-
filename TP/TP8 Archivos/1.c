/* 1. El archivo Fix_you.txt contiene la letra de la canci�n de Coldplay del mismo nombre. 
Escribir un programa que lea este archivo y muestre la canci�n por pantalla */

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

	/* fgets: lee l�neas completas de texto en lugar de caracteres individuales
			  lee caracteres del archivo o entrada est�ndar hasta que se 
			  encuentra con un salto de l�nea ('\n');

		sintaxtis: fgets(char *cadena, int longitud, FILE *archivo); 
			
		cadena: es un puntero a un arreglo de caracteres 
		(cadena) donde se almacenar� la l�nea le�da.
			
		longitud: es el n�mero m�ximo de caracteres que se 
		pueden leer (t�picamente el tama�o del arreglo).
			
	    archivo: es un puntero a un archivo desde el cual leer la l�nea. 
		(stdin) se leer� desde la entrada est�ndar.
	
	*/
	char linea[100];
	
	while(fgets(linea, sizeof(linea), archivoTexto) != NULL ) {
		printf("%s", linea);
	}
} 
