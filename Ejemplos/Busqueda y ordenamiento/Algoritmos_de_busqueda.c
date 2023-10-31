#include <stdio.h>	
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5 

/* Declaración de tipos de datos personalizados */
typedef float tVectorFloat [MAX];

/* Declaración de prototipos */
void cargarVectorOrdenado( tVectorFloat );
void cargarVectorDesordenadoRandom( tVectorFloat );
void mostrarElementos( tVectorFloat );

bool busquedaSecuencial( tVectorFloat, float );
bool busquedaSecuencialOrdenada( tVectorFloat, float );
bool busquedaBinaria( tVectorFloat, float );

float mayorElemento( tVectorFloat );
float menorElemento( tVectorFloat );


/* Declaración de tipos de variables */
tVectorFloat v1, v2;

int main() {
	bool existeElem1, existeElem2, existeElem3;
	
	/*printf("------------------------------------------------------\n");
	printf(" *** BUSQUEDA SECUENCIAL *** \n");
	printf("------------------------------------------------------\n");
		
	cargarVectorDesordenadoRandom( v1 );
	mostrarElementos( v1 );
	
	
	existeElem1 = busquedaSecuencial( v1, 12.50);	
	printf("\nExiste el %.2f ? %s \n", 12.50, existeElem1 == true ? "si": "no" );
	
	existeElem1 = busquedaSecuencial( v1, 10.0);	
	printf("Existe el %.2f ? %s \n\n", 10.0, existeElem1 == true ? "si": "no" );*/


	/*printf("------------------------------------------------------\n");
	printf(" *** BUSQUEDA SECUENCIAL ORDENADA *** \n");
	printf("------------------------------------------------------\n");
	
	cargarVectorOrdenado( v2 );
	mostrarElementos( v2 );
	
	existeElem2 = busquedaSecuencialOrdenada( v2, 48.50);
	printf("\nExiste el %.2f ? %s \n", 48.50, existeElem2 == true ? "si": "no" );
	
	existeElem2 = busquedaSecuencialOrdenada( v2, 47.00);
	printf("Existe el %.2f ? %s \n\n", 47.00, existeElem2 == true ? "si": "no" );*/
	
	printf("------------------------------------------------------\n");
	printf(" *** BUSQUEDA BINARIA *** \n");
	printf("------------------------------------------------------\n");
	
	cargarVectorOrdenado( v2 );
	mostrarElementos( v2 );
	
	existeElem3 = busquedaBinaria( v2, 48.50);
	printf("\nExiste el %.2f ?  %s \n", 48.50, existeElem3 == true ? "si": "no" );
	
	existeElem3 = busquedaBinaria( v2, 47.00);
	printf("Existe el %.2f ?  %s \n\n", 47.00, existeElem3 == true ? "si": "no" );
	
	/*printf("------------------------------------------------------\n");
	printf(" *** MAYOR ELEMENTO *** \n");
	printf("------------------------------------------------------\n");
	
	mostrarElementos( v1 );		
	printf("\nMayor elemento: %.2f \n\n", mayorElemento( v1 ) );
	
	printf("------------------------------------------------------\n");
	printf(" *** MENOR ELEMENTO *** \n");
	printf("------------------------------------------------------\n");
	
	mostrarElementos( v1 );		
	printf("\nMenor elemento: %.2f \n\n", menorElemento( v1 ) );*/


	return 0;
}

void cargarVectorOrdenado( tVectorFloat pVector ) {
	pVector[0] = 25.5;
	pVector[1] = 40.25;
	pVector[2] = 45.0;
	pVector[3] = 48.50;
	pVector[4] = 50.75;
}

void cargarVectorDesordenadoRandom( tVectorFloat pVector ) {
	int i;
	int lim_inferior = 0;
	int lim_superior = 10;
	
	srand( time( NULL ) );
	
	for( i=0; i<MAX; i++) {
		pVector[i] = ( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1.25;
	}	
}

void mostrarElementos( tVectorFloat pVector ) {
	int i;
	printf("\nElementos: \n | ");
	for( i=0; i<MAX; i++) {
		printf("%.2f | ", pVector[i]);
	}
	printf("\n");
}

/* Devuelve true en el caso que el elemento existe y false en caso contrario */
bool busquedaSecuencial( tVectorFloat pVector, float pElem ) {
	int i = 0;
	bool existe = false;
	
	while( !(pVector[i] == pElem) && i != MAX ) {
		i++;
	}
	
	if( pVector[i] == pElem ){
		existe = true;
	}
	
	return existe;	
}

bool busquedaSecuencialOrdenada( tVectorFloat pVector, float pElem ) {
	int i = 0;
	bool existe = false;
	
	while( (pVector[i] < pElem) && i <= MAX ) {
		i++;
	}
	
	if( pVector[i] == pElem ){
		existe = true;
	}
	
	printf("Indice al finalizar el algoritmo: %d\n", i);
	
	return existe;
}

bool busquedaBinaria( tVectorFloat pVector, float pElem ) {
	int extInf = 0;
	int extSup = MAX;
	int posMedio = -1;
	bool encontrado = false;
	
	// while( (encontrado == false) && (extSup >= extInf)) {
	while( !encontrado && (extSup >= extInf)) {
		
		/* Determinar la posición central */
		posMedio = (extInf + extSup) / 2;
		
		/* Consultar si el elemento buscado es el que está en la posición central */
		if( pElem == pVector[posMedio] ) {
			encontrado = true;
		}else {
			/* Determinar de qué lado está el elemento */
			if( pElem > pVector[posMedio] ) {
				/* Actualizar el extremo inferior */
				extInf = posMedio + 1;
			}else {
				/* Actualizar el extremo superior */
				extSup = posMedio - 1;
			}						
		}		
	}
	
	printf("extInf algoritmo: %d\n", extInf);
	printf("extSup algoritmo: %d\n", extSup);
	
	return encontrado;
	
}

float mayorElemento( tVectorFloat pVector ) {
	int i;
	float mayor = pVector[0];
	
	for( i=0; i<MAX; i++) {
		if( pVector[i] > mayor ) {
			mayor = pVector[i];
		}
	}
	return mayor;
}

float menorElemento( tVectorFloat pVector ) {
	int i;
	float menor = pVector[0];
	
	for( i=0; i<MAX; i++) {
		if( pVector[i] < menor ) {
			menor = pVector[i];
		}
	}
	return menor;
}







