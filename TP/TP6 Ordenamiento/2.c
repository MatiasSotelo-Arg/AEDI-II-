/* 
Desarrollar un programa que permita generar un arreglo de 15.000 números enteros aleatorios. 
Luego: 

a) Escribir una función para mostrar los elementos del array.

b) Escribir una función que reciba el array como parámetro y que permita ordenar 
los elementos de menor a mayor por el método directo de burbuja.

c) Escribir una función que reciba el array como parámetro y que permita ordenar 
los elementos de menor a mayor por el método directo de selección.

d) Escribir una función que reciba el array como parámetro y que permita ordenar
los elementos de menor a mayor por el método directo de inserción.

e) Calcular el tiempo de ejecución de cada método, y mostrar por pantalla la duración en cada caso.
*/

/* 
	clock_t inicio, fin;
	double tiempo; 
	
	inicio = clock();
	fin = clock();
	
	tiempo = ((double)(fin-inicio)) / CLOCKS_PER_SEC;
	
	printf("%f",tiempo); */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//variables
#define N 15000
typedef int tVectorInt;

tVectorInt vectorOriginal[N];
tVectorInt vector1[N];
tVectorInt vector2[N];
tVectorInt vector3[N];

time_t t;


//prototipos de funciones
void generarElementosVector(tVectorInt *);
void mostrarElementosVector(tVectorInt *);
void metodoBurbuja(tVectorInt *);
void metodoSeleccionDirecta(tVectorInt *);

int main() {
	
	clock_t inicio, fin;
	double tiempo;
	
	generarElementosVector(vectorOriginal);
	
	//METODO BURBUJA
	//copiamos el vector original
	memcpy(vector1, vectorOriginal, sizeof(vectorOriginal));
	
	inicio = clock();
	metodoBurbuja(vector1);
	fin = clock();
	
	printf("Tiempo: %f", tiempo = ((double)(fin-inicio)) / CLOCKS_PER_SEC);
	
	//METODO SELECCION DIRECTA  
	memcpy(vector2, vectorOriginal, sizeof(vectorOriginal));
	
	inicio = clock();
	metodoSeleccionDirecta(vector2);
	fin = clock();

	printf("Tiempo: %f", tiempo = ((double)(fin-inicio)) / CLOCKS_PER_SEC);
	
	return 0;
}

void generarElementosVector(tVectorInt * pVector) {
	
	srand(time(NULL));
	
	int i; 
	
	for(i = 0; i < N ; i++) {
		pVector[i] = rand() % N+1;
		
	}
	
}

void mostrarElementosVector(tVectorInt * pVector) {
	int i = 0;
	for(i;i<N;i++) {
		printf("%d: %d\n",i+1,pVector[i]);
	}
//	printf("%d - %d\n%d - %d", vectorOriginal[0] , vectorOriginal[N-1], vector1[0] , vector1[N-1]);
}

void metodoBurbuja(tVectorInt * pVector) {
	int i, j, aux;
	
	int comparaciones = 0;
	int cambios = 0;

	for(i = 0;i<N - 1;i++) {
		for(j = 0;j<N - 1;j++) {
			comparaciones++;
			if(pVector[j] > pVector[j+1]) {
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
				cambios++;
			}
		}
	}	
	printf("Comparaciones burbuja: %d\n",comparaciones);
	printf("Cambios burbuja: %d\n",cambios);
}

void metodoSeleccionDirecta(tVectorInt * pVector) {
	int i, j;
	int posMenor, valMenor, aux;
	
	int comparaciones = 0;
	int cambios = 0;
	
	for(i = 0; i < N - 1; i++) {
		valMenor = pVector[i];
		posMenor = i;
		for(j = i+1; j < N - 1 ; j++) {
			comparaciones++;
			if(pVector[j] < valMenor) {
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		comparaciones++;
		if(posMenor != i) {
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux; 
			cambios++;
		}
	}
	
	printf("\n\n");
	printf("Comparaciones Seleccion: %d\n",comparaciones);
	printf("Cambios Seleccion: %d\n",cambios);
}
