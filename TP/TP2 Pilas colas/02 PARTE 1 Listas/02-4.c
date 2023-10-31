#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/*
	inicializarLista
	listaVacia
	ingresarDatos
	calcularImc		   
					   *********************
					   *   M	 *    F	   *
		-> peso bajo   *   20    *  < 19   *
		-> peso normal * 20 - 25 * 19 - 25 *
 		-> sobrepeso   *  >25    *   >24   *
                       ********************* 		
	agregarAdelante
		-> si la lista esta vacia
		-> si la lista ya tiene un elemento
	calcularTotalEncuestados
	calcularPromedio
		-> si peso bajo y menores de 15
	listadoPersonasSobrepeso
		-> mostrar los datos de personas con sobrepeso
	calcular IMC kg/m2
*/

//tipos de datos
typedef char tString[10];

typedef struct {
	char codSexo;
	int codRangoEdad;
	float peso;
	float altura;
	tString imc;
} tEncuestado;

typedef struct nodo {
	tEncuestado encuestados;
	struct nodo * siguiente;
} tListaEncuestados;


//variables globales
tListaEncuestados * listaEncuestados;
tEncuestado vEncuestado;

//prototipo de funciones
void inicializarLista();
bool listaVacia(tListaEncuestados *);
void ingresarDatos(); 
float calcularImc(float, float);
void ingresarDatoImc(char,float);
void agregarAdelante();
int calcularTotalEncuestados(); 
float calcularPromedio();
void listadoPersonasSobrepeso();

//MAIN
int main() {
	inicializarLista();
	ingresarDatos();
	printf("\nTotal encuestados: %d\n",calcularTotalEncuestados());
	printf("\nPromedio de pesos de personas con peso bajo y menores de 15 es: %.2f\n",calcularPromedio());
	listadoPersonasSobrepeso();
	return 0;
}

//implementacion de funciones
void inicializarLista() {
	listaEncuestados = NULL;
	printf("Lista inicializada!\n");
}

bool listaVacia(tListaEncuestados * pLista) {
	return(pLista == NULL);
}

void ingresarDatos() {
	int cantidad, dato;
	float imc;
	char respuesta;
//	printf("Cantidad encuestas a ingresar: ");
//	scanf("%d",&cantidad);

	printf("\nDatos encuestados\n");

	do {
		do {
			printf("Sexo - F. Femenino, M. Masculino:");
			fflush(stdin);
			scanf(" %c",&vEncuestado.codSexo);
		} while ((vEncuestado.codSexo != 'F') && (vEncuestado.codSexo != 'M'));
		
		printf("Rango de edad \n1. Menor de 15 anios \n2. Entre 15 y 30 anios \n3. Mas de 30 anios\n-> ");
		scanf("%d",&vEncuestado.codRangoEdad);

		printf("Peso: ");
		scanf("%f",&vEncuestado.peso);

		printf("Altura: ");
		scanf("%f",&vEncuestado.altura);
		
		imc = calcularImc(vEncuestado.peso, vEncuestado.altura);
		
		ingresarDatoImc(vEncuestado.codSexo, imc);
		
		printf("\n->Clasificacion: %s",vEncuestado.imc);
		printf("\n->IMC: %f",imc);
		
		agregarAdelante(); 
		
		
		printf("\n\nIngresar otro encuestado? 'S' SI - 'N' NO: ");
		fflush(stdin);
		scanf("%c",&respuesta);
		
	} while(respuesta != 'N');
}

float calcularImc(float pPeso, float pAltura) {

	return (pPeso / (pAltura * pAltura));

}

void ingresarDatoImc(char pSexo, float pImc) {
	
	if(pSexo == 'F') {
		if(pImc < 20) {
			strcpy(vEncuestado.imc,"Peso bajo");
		} else if(pImc >= 20 && pImc <= 25) {
			strcpy(vEncuestado.imc,"Peso normal");
		} else if(pImc > 25) {
			strcpy(vEncuestado.imc,"Sobrepeso");
		}
	}
	
	if(pSexo == 'M') {
		if(pImc < 19) {
			strcpy(vEncuestado.imc,"Peso bajo");
		} else if(pImc >= 19 && pImc <= 24) {
			strcpy(vEncuestado.imc,"Peso normal");
		} else if(pImc > 24) {
			strcpy(vEncuestado.imc,"Sobrepeso");
		}
	}
	 
}

void agregarAdelante() {
	tListaEncuestados * nuevoNodo;
	
	nuevoNodo = (tListaEncuestados *) malloc(sizeof(tListaEncuestados));
	
	nuevoNodo->encuestados = vEncuestado;
	
	if(listaVacia(listaEncuestados)) {
		nuevoNodo->siguiente = NULL;
	} else {
		nuevoNodo->siguiente = listaEncuestados;
	}
	
	listaEncuestados = nuevoNodo;
}

int calcularTotalEncuestados() {
	tListaEncuestados * aux = listaEncuestados;
	int contador = 0;
	
	if(!listaVacia(aux)) {
		while(aux != NULL) {
			aux = aux->siguiente;
			contador++;
		}
	}
	
	return contador;
}

float calcularPromedio() {
	float acumuladorPesos = 0;
	int contadorMenores = 0;
	float promedio = 0;
	
	tListaEncuestados * aux = listaEncuestados;
	
	if(!listaVacia(aux)) {
		while(aux != NULL) {
			
			if((strcmp(aux->encuestados.imc,"Peso bajo") == 0) && (aux->encuestados.codRangoEdad == 1) ) {
				acumuladorPesos = acumuladorPesos + aux->encuestados.peso;
				
				contadorMenores++;
			}
			aux = aux->siguiente;
		}
	}
	
	return (promedio = (acumuladorPesos / contadorMenores));
	
}

void listadoPersonasSobrepeso() {
	
	tListaEncuestados * aux = listaEncuestados;
	
	if(!listaVacia(aux) ){
		printf("\n#### Lista de encuestados con sobrepeso ####\n");
		while(aux != NULL) {
			if(strcmp(aux->encuestados.imc, "Sobrepeso") == 0) {
				printf("Sexo: %c\nRango edad: %d\nPeso: %.2f\nAltura: %.2f\nClasificacion: %s\n\n",aux->encuestados.codSexo, aux->encuestados.codRangoEdad,aux->encuestados.peso,aux->encuestados.altura,aux->encuestados.imc);
			}
			aux = aux->siguiente;
		}
	}
}

