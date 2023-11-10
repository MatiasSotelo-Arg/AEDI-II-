#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TITULO1 "\n*** INFORME DE PERSONAJES ***\n"

typedef char tString[20];

typedef struct {	    
    short codUniverso; 
	tString nombrePersonaje;
	tString nombreTerrestre;
	char genero;
	char codRol;	
	short cantPeliculasAparicion; 
}tPersonaje;

//variables
FILE * personajes;
tPersonaje personaje, personajeAnterior;

int totalHeroes, totalVillanos, subTotalHeroes, subTotalVillanos;

//prototipos de funciones
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unUniverso();
void finCorte();

int main() {
	inicializacion();
	procesoCorte();
	finalizacion();
	return 0;
}

void inicializacion() {
	
	//manejo archivo
	personajes = fopen("personajes.dat", "rb");
	
	if(personajes != NULL) {
		printf("Archivo abierto!");
		fread(&personaje, sizeof(tPersonaje), 1, personajes);		
	} else {
		printf("No se encuentra el archivo!\n");
		printf("archivo cerrado!");
		exit(EXIT_FAILURE);
	}
	
	//valor variables
	personajeAnterior = personaje;
	
	totalHeroes = 0;
	totalVillanos = 0;
	
	printf("%s", TITULO1);
	
	printf("-------------------------------------------\n");
	printf("| Universo | Nombre del Personaje   | Rol |\n");
    printf("-------------------------------------------\n");

    
}

void procesoCorte() {
	
	while(!feof(personajes)) {
		
		principioCorte();
		
		while(!feof(personajes) && personaje.codUniverso == personajeAnterior.codUniverso) {
			unUniverso();
			fread(&personaje, sizeof(tPersonaje), 1, personajes);
		}
		
		finCorte();
	}
}

void principioCorte() {
	subTotalHeroes = 0;
	subTotalVillanos = 0;
}

void unUniverso() {
	printf("| %-8s | %-22s | %-4c|\n", 
		personaje.codUniverso == 1 ? "DC" : "MARVEL", 
		personaje.nombrePersonaje,
		personaje.codRol);

			
	if(personaje.codRol == 'H') {
		subTotalHeroes++;
	}else {
		subTotalVillanos++;
	}	
}

void finCorte() {
	printf("---------------------------------------------\n");
	printf("%s | Villanos: %d\tHeroes: %d\n", personajeAnterior.codUniverso == 1 ? "DC" : "MARVEL", subTotalVillanos, subTotalHeroes);
	printf("---------------------------------------------\n");
	
	totalHeroes += subTotalHeroes;
	totalVillanos += subTotalVillanos;
	
	personajeAnterior = personaje;
}

void finalizacion() {
	printf("Villanos: %d\tHeroes: %d\n", totalVillanos, totalHeroes);
	printf("---------------------------------------------\n");

	fclose(personajes);
	printf("archivo cerrado!");
}



