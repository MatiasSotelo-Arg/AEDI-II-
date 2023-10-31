#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define TAB4 "\t\t\t\t"

/* Declaración de tipos de datos personalizados */
typedef char tString [20];

typedef struct {
	short codigoUniverso;
	tString nombre;
	tString nombreTerrestre;
	char codigoGenero;
	char codigoRol;
	short cantidadPeliculas;		
}tRegistroPersonaje;

/* Declaración de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unPersonaje();
void finCorte();

/* Declaración de variables */
tRegistroPersonaje regPersonaje;
FILE * archPersonajes;
short codCampoControl;
int totalHeroes, totalVillanos;
int cantHeroeUniverso, cantVillanoUniverso, cantPeliculasUniverso;

/* Bloque principal */
int main() {
	inicializacion();
	procesoCorte();
	finalizacion();
	return 0;
}

/* Implementación de funciones */
void inicializacion() {
	/*
		1. Apertura del archivo en modo lectura
		2. Leer el primer registro
		3. Guarda el campo de control
		
		Opcionales:
			- Inicialización de contadores y acumuladores generales o totales
			- Imprimir los títulos
	*/

	

}

void procesoCorte() {
	/* Recorrer todo el archivo */
	while(!feof(archPersonajes)) {
		
		principioCorte();
		
		while(!feof(archPersonajes) && regPersonaje.codigoUniverso == codCampoControl ) {
			/* 	1. Procesar cada grupo
				2. Leer otro registro */
			unPersonaje();
			fread(&regPersonaje, sizeof(tRegistroPersonaje), 1, archPersonajes);
		}
		
		finCorte();
		
	}
	
}

void principioCorte() {
	/* Antes del iniciar el nuevo grupo
		Opcionales: 
			1.  Inicialización de contadores y acumuladores parciales
	 */
	
	 
}

void unPersonaje() {
	/* Por cada grupo:
		1. Actualizar contadores y acumuladores parciales
		2. Mostrar la línea de detalle en el caso que corresponda
		3. Buscar mayor/menor valor del grupo en el caso que corresponda
	 */
	 
	
	 
}

void finCorte() {
	/* 	Cambia de grupo, entonces antes de procesar el siguiente grupo
		se debería mostrar los datos parciales del grupo anterior, para esto:
		1- Mostrar los valores parciales
		2- Calcular porcentajes y promedio parciales en el caso que corresponda
		3- Actualizar contadores/acumuladores generales
		4- Buscar mayor/menor valor de todos (generales) en el caso que corresponda
		5- Volver a guardar el campo de control
	*/

}

void finalizacion() {
	/* 	1. Mostrar los valores generales 
		2. Calcular porcentajes y promedio generales en el caso que corresponda 
		3. Cerrar archivo */
	
}

