#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//TIPOS DE DATOS
typedef char tString[10];

typedef struct {
	tString nombre;
	float precio;
}tElemento;

typedef struct nodo {
	tElemento elemento;
	struct nodo * siguiente;
}tLista;

//VAR GLOBALES
tLista * lista;
tElemento elemento;

//PROTOTIPOS DE FUNCIONES
int opcion_menu();
void mostrar_menu(int);
void inicializar_lista();
bool lista_vacia(tLista *); 
void agregar_elemento(tElemento);
void ingresar_datos_elemento();
void agregar_primer_ele();
void agregar_adelante();
void visualizar_lista(tLista *);
void eliminar_ultimo_ele(tLista *);
int cantidad_nodos(tLista *);

//MAIN
int main () {
	
	inicializar_lista();
	
	int aux;
	aux = opcion_menu();
	
	mostrar_menu(aux);
	
	return 0;
}

//implementacion 
int opcion_menu() {
	int opcion;
	printf("\n#####Menu#####\n");
	printf("Ingrese una opcion\n1-Ver lista\n2-Agregar elemento\n3-Eliminar elemento\n0-Salir\n");
	scanf("%d",&opcion);
	return opcion;
}

void mostrar_menu(int auxiliar) {
	switch(auxiliar) {
		case 1:
			if(!lista_vacia(lista)) {
				printf("TE MUESTRO LA LISTA");
			} else {
				printf("La lista no posee elementos!");
			}
			break;
			
		case 2:
			system("cls");
			printf("Agregar un elemento a la lista\n");
			ingresar_datos_elemento();
			agregar_elemento(elemento);
			break;

		case 3:
			printf("Hola 3");
			break;
			
			
		case 0: 
			break;
			
		default:
			system("cls");
			printf("Opcion (%d) no es valida, vuelva a intentar!", auxiliar);
			opcion_menu();
			break;
	}
}

void inicializar_lista() {
	lista = NULL;
	printf("Se inicializo la lista!\n");
}

bool lista_vacia( tLista * pLista) {
	return (pLista == NULL);
}

void ingresar_datos_elemento() {
	tString aux_titulo;
	printf("Titulo: ");
	fflush(stdin);
	scanf("%s",&aux_titulo);
	strcpy(elemento.nombre, aux_titulo);
	
	printf("Ingrese precio: ");
	scanf("%f",&elemento.precio);
	
	printf("se agrego %s\n", elemento.nombre);
	printf("se agrego $%.2f", elemento.precio);
	
}

void agregar_elemento(tElemento pElemento) {

//	if(!lista_vacia(lista)) {
//		agregar_primer_ele(pElemento) {
//			
//		}
//	} else {
//		agregar_adelante(pElemento) {
//			
//		}
//	}
}





