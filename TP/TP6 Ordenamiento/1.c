/* TP ordenamiento: 

Escribir un programa que permita ingresar 10 valores reales por teclado. 
Luego escribir funciones que permitan:
a) Ordenar un vector de menor a mayor por el método directo de burbuja.
b) Ordenar un vector de menor a mayor por el método directo de selección.
c) Ordenar un vector de menor a mayor por el método directo de inserción
*/ 

#include <stdio.h>

//Var - tipos datos
#define MAX 10

typedef int tVectorInt;

//tVectorInt vector[MAX];
tVectorInt vector1[MAX] = {2,3,1,5,4,7,6,9,8,10};
tVectorInt vector2[MAX] = {2,3,1,5,4,7,6,9,8,10};
tVectorInt vector3[MAX] = {2,3,1,5,4,7,6,9,8,10};

//prototipos de funciones
void ingresarValores();
void mostrarVector(tVectorInt *);

void metodoBurbuja(tVectorInt *);
void metodoSeleccionDirecta(tVectorInt *);
void metodoInsercion(tVectorInt *);

int main() {
//	ingresarValores();

	printf("Metodo burbuja\n");
	metodoBurbuja(vector1);
	mostrarVector(vector1);
	
	printf("\n\nMetodo Seleccion\n");
  	metodoSeleccionDirecta(vector2); //Obtencion suseciva de menores
	mostrarVector(vector2);
	
	printf("\n\nMetodo Baraja \n");
  	metodoInsercion(vector3); //Inserción directa - se ordena ascendentemente
	mostrarVector(vector3);
	return 0;
}

//implementacion de funciones
void ingresarValores() {

	printf("Ingrese los valores: \n");

	int i = 0;
	for(i;i<MAX;i++) {
		printf("%d: ",i+1);
		scanf("%d",&vector1[i]);
	}
}

void mostrarVector(tVectorInt * pVector) {
	int i = 0;

	for(i;i<MAX;i++) {
		printf("%d ",pVector[i]);
	}
}

void metodoBurbuja(tVectorInt * pVector) {
	
	int i, j;
	int aux;
	
	for(i = 0;i<MAX-1;i++) {
		
		for(j = 0;j < (MAX - 1);j++){
			if(pVector[j] > pVector[j+1]) {
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
			}
		}
	}
}

void metodoSeleccionDirecta(tVectorInt * pVector) {
	int i, j;
	int posMenor, valMenor, aux;
	
	for(i=0;i<MAX-1;i++) {
		valMenor = pVector[i];
		posMenor = i;
		
		for(j = i+1; j < MAX - 1; j++) {
			if(pVector[j] < valMenor) {
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if(posMenor != i) {
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}
	}
}

void metodoInsercion(tVectorInt * pVector) {
	int i,j;
	int aux;
	
	for(i=1;i<MAX; i++) {
		aux = pVector[i];
		j = i - 1;
		while( (j >= 0) && (pVector[j] > aux) ) {
			pVector[j+1] = pVector[j];
			j = j - 1;
		}
		pVector[j+1] = aux;
	}
}

