/* La registración a un evento de informática se realiza a través de la inscripción online mediante un
formulario web. 
Para ello se registran los datos de los inscriptos en una pila con los siguientes datos: 
DNI,
Nombre y Apellido, 
e-mail, 
Código de Categoría (01-Estudiantes 02-Profesionales 03-Público en general)
Monto Abonado. 
El valor de la inscripción es de $200 para los estudiantes y $350 para profesionales y el
público en general, valor que se abona al momento de la inscripción (tener en cuenta esto al momento de
apilar inscriptos). 
Realizar las funciones necesarias para obtener:
a) la cantidad de Profesionales que se inscribieron al evento, y el porcentaje que representan sobre
el total de inscriptos
b) el monto recaudado de inscriptos de la categoría Estudiantes
c) el total recaudado en concepto de inscripciones
Tener en cuenta que se deben realizar las operaciones básicas necesarias para la manipulación de la pila con
punteros.
*/ 

/*
#### inscripcion evento ####
pilaVacia();
inicializarPila();
ingresarDatos();
push();
calcularMontoAbonar( 1 );
calcPorcentajeProfesionales();
	-> el total de profesionales y el porcentaje sobre el total 
calcMontoInscriptosEstudiantes(); 
calcTotalRecaudado(); 
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//tipos datos
typedef char tString[30];

typedef struct {
	int dni;
	tString nombreApellido;
	tString mail;
	int codCategoria;
	float montoAbonado;
}tInscripto;

typedef struct nodo {
	tInscripto inscripto;
	struct nodo * siguiente;
} tPila;

//variables globales
tPila * pila; 
tInscripto vInscripto;

//prototipo
void inicializarPila(); 
bool pilaVacia( tPila * );
void push( tInscripto );
float calcularMontoAbonar ( int );
float calcTotalRecaudado();
float calcMontoInscriptosEstudiantes();
void calcPorcentajeProfesionales();

int main() {
	
	inicializarPila();
	
	//Caso 1
	vInscripto.dni = 1;
	strcpy(vInscripto.nombreApellido, "Matias");
	strcpy(vInscripto.mail, "matysotelo07gmail.com");
	vInscripto.codCategoria = 1;
	vInscripto.montoAbonado = calcularMontoAbonar(vInscripto.codCategoria);
	
	printf("%d %s %s %.2f\n", vInscripto.dni, vInscripto.nombreApellido, vInscripto.mail, vInscripto.montoAbonado);
	
	push( vInscripto );
	
	//Caso 2
	vInscripto.dni = 2;
	strcpy(vInscripto.nombreApellido, "Inscripto 2");
	strcpy(vInscripto.mail, "inscripto2@gmail.com");
	vInscripto.codCategoria = 2;
	vInscripto.montoAbonado = calcularMontoAbonar(vInscripto.codCategoria);
	
	printf("%d %s %s %.2f\n", vInscripto.dni, vInscripto.nombreApellido, vInscripto.mail, vInscripto.montoAbonado);
	
	push( vInscripto );
	
	//Caso 3
	vInscripto.dni = 1;
	strcpy(vInscripto.nombreApellido, "Matias");
	strcpy(vInscripto.mail, "matysotelo07gmail.com");
	vInscripto.codCategoria = 2;
	vInscripto.montoAbonado = calcularMontoAbonar(vInscripto.codCategoria);
	
	printf("%d %s %s %.2f\n", vInscripto.dni, vInscripto.nombreApellido, vInscripto.mail, vInscripto.montoAbonado);
	
	push( vInscripto );
	
	//Caso 4
	vInscripto.dni = 1;
	strcpy(vInscripto.nombreApellido, "Matias");
	strcpy(vInscripto.mail, "matysotelo07gmail.com");
	vInscripto.codCategoria = 1;
	vInscripto.montoAbonado = calcularMontoAbonar(vInscripto.codCategoria);
	
	printf("%d %s %s %.2f\n", vInscripto.dni, vInscripto.nombreApellido, vInscripto.mail, vInscripto.montoAbonado);
	
	push( vInscripto );
	
	//Total recaudado
	printf("\nTotal recaudado: $%.2f",calcTotalRecaudado());
	
	//Total recaudado Estudiantes 
	printf("\nTotal recaudado de estudiantes: $%.2f",calcMontoInscriptosEstudiantes());
	
	calcPorcentajeProfesionales();
	
	return 0;
}

//implementacion
void inicializarPila() {
	pila = NULL;
}

bool pilaVacia( tPila * pPila ) {
	return (pPila == NULL);
}

void push( tInscripto pRegistro ) {
	tPila * nuevoNodo;
	
	nuevoNodo = (tPila *) malloc(sizeof(tPila));
	
	nuevoNodo->inscripto = pRegistro;
	
	if(pilaVacia(pila)) {
		nuevoNodo->siguiente = NULL;
	} else {
		nuevoNodo->siguiente = pila;
	}
	
	pila = nuevoNodo;
}

float calcularMontoAbonar( int pCategoria) {
	if(pCategoria == 1) {
		return 200;
	} else {
		return 350;
	}
}

float calcTotalRecaudado() {
	
	float total = 0;
	tPila * aux;
	
	aux = pila;
	
	while( aux != NULL ) {
		total += aux->inscripto.montoAbonado;
		aux = aux->siguiente;	
	}

	return total;
}

float calcMontoInscriptosEstudiantes() {
	float total = 0;
	tPila * aux;
	
	aux = pila;
	
	while( aux != NULL ) {
		if(aux->inscripto.codCategoria == 1) {
			total += aux->inscripto.montoAbonado;	
		}
		aux = aux->siguiente;
	}

	return total;
}

void calcPorcentajeProfesionales() {
	
	int inscriptos = 0;
	int profesional = 0;
	float porcentaje = 0;
	
	tPila * aux;
	aux = pila;
	
	while( aux != NULL ) {

		if(aux->inscripto.codCategoria == 2) {
			profesional++;
		}
		inscriptos++;
		aux = aux->siguiente;
	}
	
	porcentaje = (((float) profesional / (float) inscriptos) * 100);

	printf("\n\nTotal inscriptos %d\nTotal profesionales %d\nPorcentaje profesionales %.0f%%",inscriptos, profesional, porcentaje);
}





