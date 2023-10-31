/* El departamento de alumnado necesita trabajar con los datos de los alumnos de la materia AEDII, para
ello implementa una lista simplemente enlazada, donde cada nodo guarda el número de libreta
universitaria y el nombre del alumno. Se pide crear las funciones necesarias para:
a) Generar la lista #OK.
b) Insertar el primer alumno (nodo) de la lista. #OK 
c) Insertar alumnos al principio de la lista. #OK
d) Eliminar el primer alumno de la lista. 
e) Insertar un alumno en una determinada posición dentro de la lista. #OK
f) Eliminar un alumno de una determinada posición de la lista.
g) Visualizar todos los datos de los alumnos que están en la lista. #OK
Además, crear una función que retorne la cantidad de alumnos que contiene la lista e implementar un
menú principal que contenga todos los ítems anteriormente solicitados */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//tipos de datos
typedef char tString[15];

typedef struct {
	int nroLibreta;
	tString nombreAlumno;
}tAlumno;

typedef struct nodo {
	tAlumno alumno;
	struct nodo * siguiente;
}tListaAlumnos;

//variables globales
tListaAlumnos * lista;
tAlumno vAlumno;

//prototipo de funciones
void menu();
void limpiarPantalla();
void inicializarLista();
bool listaVacia(tListaAlumnos *);
void ingresarDatosAlumno();
void agregarAdelante();
void agregarK(int, tAlumno);
void eliminarPrimero();
void eliminarK(int);
void mostrarListaAlumnos();
int cantidadAlumnos();


//MAIN
int main() {
	
	inicializarLista();
	menu();
	
	return 0;
}

//implementacion de funciones
void menu() {
	int opcion = 1;
	int cantNodos;
	int posicion;

	printf("\n#### MENU LISTA ALUMNO ####\n");
	
	printf("\n0-Salir\n1-Agregar adelante\n2-Agregar en determinada posicion\n3-Eliminar primero\n4-Eliminar en determinada posicion\n5-Mostrar lista\n6-Mostrar cantidad alumnos");
	
	while(opcion != 0) {
		
		printf("\n\nIngrese una opcion:");
		scanf("%d",&opcion);
		
		switch (opcion) {
			case 0:
				limpiarPantalla();
				printf("Salir!");
				break;
			case 1:		
				ingresarDatosAlumno();
				agregarAdelante();	
				printf("\nAlumno agregado -> %d %s",lista->alumno.nroLibreta, lista->alumno.nombreAlumno);
				break;
			case 2:
				ingresarDatosAlumno();
				printf("Que posicion ingresar?:");
				scanf("%d",&posicion);
				agregarK(posicion, vAlumno);
				printf("\nAlumno agregado -> %d %s",lista->alumno.nroLibreta, lista->alumno.nombreAlumno);
				break;
			case 3: 
				eliminarPrimero();
				break;
			case 4:
				mostrarListaAlumnos();
				printf("Que posicion eliminar?: ");
				scanf("%d",&posicion);
				
				eliminarK(posicion);
				break;
			case 5:
				mostrarListaAlumnos();
				break;
			case 6:
				cantNodos = cantidadAlumnos();
				
				if(cantNodos != 0 ) {
					printf("\nCantidad alumnos: %d",cantNodos);
				} else {
					printf("\nLa lista esta vacia!");
				}
				break;
			default:
				printf("\nOpcion %d no valida!",opcion);
				break;
		}
	}
	
}

void limpiarPantalla() {
	system("cls");
}

void inicializarLista() {
	lista = NULL;
	printf("Lista inicializada!\n");
}

bool listaVacia(tListaAlumnos * pLista) {
	return (pLista == NULL);
}

void ingresarDatosAlumno() {
	printf("\nIngrese alumno");
	
	printf("\nNumero libreta:");
	scanf("%d",&vAlumno.nroLibreta);
	
	printf("Nombre alumno:");
	scanf("%s",&vAlumno.nombreAlumno);
}

void agregarAdelante() {
	tListaAlumnos * nuevoNodo;
	
	nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));
	
	nuevoNodo->alumno = vAlumno;
	
	if(listaVacia(lista)) {
		nuevoNodo->siguiente = NULL;
	} else {
		nuevoNodo->siguiente = lista;
	}
	
	lista = nuevoNodo;
}

void agregarK(int pos, tAlumno pElemento) {
	int i;
	tListaAlumnos * aux, * nuevoNodo;
	
	aux = lista;
	
	for(i=1; i < pos - 1; i++) {
		aux = aux-> siguiente;
	}
	
	nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));
	
	nuevoNodo->alumno = pElemento;
	
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
}

int cantidadAlumnos() {
	tListaAlumnos * aux;
	int contador = 0;
	
	aux = lista;
	
	if(!listaVacia(lista)) {
		
		while(aux != NULL) {
			aux = aux->siguiente;
			contador++;
		}
	}
	return contador;
}

void mostrarListaAlumnos() {
	tListaAlumnos * aux;	
	aux = lista;
	int cont = 1;
	if(!listaVacia(lista)) {
		printf("\n#### ELEMENTO DE LA LISTA ####\n");
		while(aux!=NULL) {
			printf("%d- %d %s\n",cont,aux->alumno.nroLibreta, aux->alumno.nombreAlumno);
			cont++;
			aux = aux->siguiente;
		}
	} else {
		printf("\nNo hay elementos para visualizar!");
	}
}

void eliminarPrimero() {
	if(!listaVacia(lista)) {
		tListaAlumnos * nodoSuprimir = lista;
		
		lista = lista->siguiente;
		
		printf("\nPrimer elemento eliminado -> %d %s", nodoSuprimir->alumno.nroLibreta, nodoSuprimir->alumno.nombreAlumno);
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	} else {
		printf("\nNo hay elementos para eliminar!");
	}
	tListaAlumnos * aux;
}

void eliminarK(int pPos) {
	int i, cantNodos;
	tListaAlumnos * aux, * nodoSuprimir;
	
	cantNodos = cantidadAlumnos(lista);
	
	if(pPos <= cantNodos && pPos > 0) {
		if(pPos == 1) {
			eliminarPrimero();
		} else {
			aux = lista;
			
			for(i=1;i < pPos -1 ; i++) {
				aux = aux->siguiente;
			}
			
			nodoSuprimir = aux->siguiente;
			
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("\nSe elimino: %d %s", nodoSuprimir->alumno.nroLibreta, nodoSuprimir->alumno.nombreAlumno);
			
			free(nodoSuprimir);
			
			nodoSuprimir = NULL;
		}
	}
}
