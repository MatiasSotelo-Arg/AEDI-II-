#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[20];
typedef struct {	     
	short codUniverso; 
	tString nombrePersonaje;
	tString nombreTerrestre;
	char genero;
	char codRol;	
	short cantPeliculasAparicion; 
}tr_personaje;	 

void verPersonajes();

FILE * vf_personajes;
tr_personaje vr_personaje;

int main(){
	verPersonajes();
	return 0;
}

void verPersonajes() {
	vf_personajes = fopen("Personajes.dat", "rb");
	fread(&vr_personaje, sizeof(tr_personaje), 1, vf_personajes);	
	printf("Universo\tNombre Personaje\tNombre Terrestre\tRol\t Peli \n"); 
	tString universo = "";
	while(!feof(vf_personajes)){	
		switch(vr_personaje.codUniverso){
			case 1: strcpy(universo, "DC");
					break;
			case 2: strcpy(universo, "Marvel");
					break;
		}
		
		printf("%s\t\t%s\t\t%s\t\t%c\t%d\n", universo, vr_personaje.nombrePersonaje, vr_personaje.nombreTerrestre, vr_personaje.codRol, vr_personaje.cantPeliculasAparicion );
		fread(&vr_personaje, sizeof(tr_personaje), 1, vf_personajes);		
	}
	
	fclose(vf_personajes);
}
