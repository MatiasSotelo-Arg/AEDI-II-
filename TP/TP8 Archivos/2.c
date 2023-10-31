/* Escribir un programa que permita grabar un archivo de texto con datos de alumnos contenidos en una
línea de texto que se ingresa por teclado. Cada línea contiene los siguientes datos: DNI, nombre del
alumno y finaliza con un salto de línea. Ingresar alumnos hasta que el usuario indique que no desea
continuar ingresando datos. Informar al final la cantidad de registros grabados. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * archivoTexto;

typedef char tString[10];

//defino tipo de dato registro
typedef struct alumno {
	int dni;
	tString nombre;
}tAlumno;

int contador = 0;

//prototipo de funciones
void abrirArchivo();
void pedirDatos();
//void escribirDatosEnElArchivo(tAlumno);
void cerrarArchivo();


int main() {

	
	abrirArchivo();
	pedirDatos();
	
	printf("Cantidad de registros ingresados %d\n",contador);
	cerrarArchivo();
	
	return 0;
}

//implementacion de funciones
void abrirArchivo() {
	
	archivoTexto = fopen("datos_alumnos.txt", "a");
	
	if(archivoTexto != NULL) {
		printf("Archivo abierto!\n");
	} else {
		printf("Hubo un error!\n");
		exit(EXIT_FAILURE);
	}
	
}

void cerrarArchivo() {
	fclose(archivoTexto);
	printf("\nArchivo Cerrado!");
}

void pedirDatos() {
		
	tAlumno alumno;
	
	int opcion = 's';
	
	printf("\nIngresar un nuevo alumno\n");
	do {
		printf("\nIngrese DNI: ");
		scanf("%d",&alumno.dni);
		
		printf("Ingrese Nombre: ");
		fflush(stdin);
		gets(alumno.nombre);
		
//		escribirDatosEnElArchivo(alumno);
		
		fprintf(archivoTexto, "%d, %s \n",alumno.dni, alumno.nombre);
		
		contador++;
		
		printf("Ingresar otro? s-n: ");
		fflush(stdin);
		scanf("%c",&opcion);
	} while(opcion != 'n');
	

}

//void escribirDatosEnElArchivo(tAlumno pAlumno) {
//	
//}

