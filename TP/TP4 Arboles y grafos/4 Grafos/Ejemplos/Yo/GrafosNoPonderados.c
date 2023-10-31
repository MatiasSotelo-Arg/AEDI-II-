#include <stdio.h>
#include <stdbool.h>
#define N 10

//tipos de datos 
typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
}tArco;

typedef bool conjuntoVertices[N];
typedef bool conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoNoPonderado;

//var globales
tGrafoNoPonderado grafo;

//prototipos de funciones 
void inicializarGrafo(tGrafoNoPonderado *);
void agregarVertice(tGrafoNoPonderado *, tVertice);
void agregarArco(tGrafoNoPonderado *, tArco);
void borrarVertice(tGrafoNoPonderado *,tVertice);
void borrarArco(tGrafoNoPonderado *, tArco);

int maximoVertice(tGrafoNoPonderado);
void mostrarMatrizDeAdyacencia(tGrafoNoPonderado);
bool existeVertice(tGrafoNoPonderado, tVertice);

int main() {
	tArco arco;
	
	inicializarGrafo(&grafo);
	
	agregarVertice(&grafo, 2);
	agregarVertice(&grafo, 3);
	agregarVertice(&grafo, 4);
	
	arco.origen = 3;
	arco.destino = 2;
	agregarArco( &grafo, arco);
	
	arco.origen = 2;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	mostrarMatrizDeAdyacencia(grafo);
	
	borrarVertice( &grafo, 2 );
	
	mostrarMatrizDeAdyacencia(grafo);
	
	borrarArco( &grafo, arco );
	
	mostrarMatrizDeAdyacencia(grafo);
	return 0;
}

//implementacion de funciones 
void inicializarGrafo(tGrafoNoPonderado * pGrafo) {
	int x, y;
	
	for(x = 0 ; x<=N ; x++) {
		pGrafo->vertices[x] = 0;
		for(y = 0 ; y<=N ; y++) {
			pGrafo->arcos[x][y] = 0;
		}
	} 
}

void agregarVertice(tGrafoNoPonderado * pGrafo, tVertice pVertice) {
	pGrafo->vertices[pVertice] = 1;
	printf("Se agrego el vertice %d\n",pVertice);
}

void agregarArco(tGrafoNoPonderado * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = 1;
	printf("Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino);
}

void borrarVertice(tGrafoNoPonderado * pGrafo, tVertice pVertice) {
	pGrafo->vertices[pVertice] = 0;
	printf("Se borro el vertices: %d\n", pVertice);
}

void borrarArco(tGrafoNoPonderado * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = 0;
	printf("Se desactivo el arco [%d, %d]\n",pArco.origen, pArco.destino);
}

int maximoVertice(tGrafoNoPonderado pGrafo) {
	int x, max;
	max = 0;
	
	for(x = 0; x < N; x++) { 
		if(pGrafo.vertices[x] == 1) {
			max = x;
		}
	}
	return max;
}

void mostrarMatrizDeAdyacencia(tGrafoNoPonderado pGrafo) {
	int x, y, maxVertice;
	bool existeArista = false;
	
	maxVertice = maximoVertice(pGrafo);
	
	printf( "\n MATRIZ DE ADYACENCIA \n" );
	
	//imprimir eje y
	printf(" ");
	for(y = 1; y <= maxVertice; y++) {
		printf(" %d",y);
		
	}
	printf("\n");
	
	for( x = 1; x <= maxVertice; x++) {
		//imprimir eje y
		printf("%d",x);

		for(y = 1; y <= maxVertice; y++) {
			existeArista = ( pGrafo.arcos[x][y] == 1 ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );
			if(existeArista) {
				printf(" 1");
			} else {
				printf(" 0");
			}
		}
		printf("\n");
	}
}

bool existeVertice( tGrafoNoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}





