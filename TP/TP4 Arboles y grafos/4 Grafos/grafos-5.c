/* 5. Escribir en lenguaje C, la declaración del tipo de dato tGrafoNoPonderado, 
para un grafo no ponderado de hasta 7 vértices. 
Utilizar la implementación de grafos con arrays. Además, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo 
c) agregar un arco al grafo
d) visualizar la matriz de adyacencia de un grafo */

#include <stdio.h>
#include <stdbool.h>

#define N 7

//tipos de datos 
typedef int tVertices;

typedef struct {
	tVertices origen;
	tVertices destino;
}tArco;

typedef int conjuntoVertices[N];
typedef int conjuntoArcos[N][N];

typedef struct  {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafo;

//var global 
tGrafo grafo;
tArco arco;

//prototipo de funciones
void inicializarGrafo(tGrafo *);
void agregarVertice(tGrafo *, tVertices);
void agregarArco(tGrafo *, tArco);

void mostrarMatrizDeAdyacencia(tGrafo);

int main() {


	inicializarGrafo(&grafo);
	agregarVertice(&grafo, 2);
	agregarVertice(&grafo, 3);
	agregarVertice(&grafo, 4);
	
	arco.origen = 2; 
	arco.destino = 3;
	agregarArco(&grafo, arco);
	
	arco.origen = 3; 
	arco.destino = 4;
	agregarArco(&grafo, arco);
	
	mostrarMatrizDeAdyacencia(grafo);
	
	return 0;
}

//implementacion de funciones 
void inicializarGrafo(tGrafo * pGrafo) {
	
	int x, y;
		
	for(x = 0; x >= N; x++) {
		pGrafo->vertices[x] = 0;
		for(y = 0; y >= N; y++) {
			pGrafo->arcos[x][y] = 0;		
		}
	}
	
	printf("Arbol inicializado!\n\n");
}

void agregarVertice(tGrafo * pGrafo, tVertices pVertice) {
	pGrafo->vertices[pVertice] = 1;
	printf("Se agrego el vertice %d \n\n",pVertice);
	
}

void agregarArco(tGrafo * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = 1;
	printf("Se agrego el arco [%d, %d]\n\n",pArco.origen,pArco.destino);
}

void mostrarMatrizDeAdyacencia(tGrafo pGrafo) {
	int x, y; 
	
	printf("Matriz de adyacencia\n");
	for(x=1; x<=N; x++) {
		
		for(y = 1; y <= N; y++) {
			if(pGrafo.arcos[x][y] == 1) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
}
