#include <stdio.h>
#include <stdbool.h>

#define N 10

//tipos de datos
typedef int tVertice;

typedef float tPeso;

typedef struct {
	tVertice origen;
	tVertice destino;
	tPeso peso;
}tArco;

typedef bool conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoPonderado;

//Prototipos de funciones
void inicializarGrafo(tGrafoPonderado *);
void agregarVertice(tGrafoPonderado *, tVertice);
void agregarArco(tGrafoPonderado *, tArco);
void eliminarVertice(tGrafoPonderado *, tVertice);
void eliminarArco(tGrafoPonderado *, tArco);
//
int maximoVertice(tGrafoPonderado);
void mostrarMatrizAdyacencia(tGrafoPonderado);
void mostrarMatrizPesos(tGrafoPonderado);
bool existeVertice(tGrafoPonderado, tVertice);

//variables globales
tGrafoPonderado grafo;

//Main 
int main() {
	tArco arco;
	
	inicializarGrafo(&grafo);
	agregarVertice(&grafo, 2);
	agregarVertice(&grafo, 3);
	
	arco.origen = 2;
	arco.destino = 3;
	arco.peso = 100.00;
	
	agregarArco(&grafo, arco);
	
	mostrarMatrizAdyacencia(grafo);

	mostrarMatrizPesos(grafo);
	return 0;
}

//declaracion de funciones
void inicializarGrafo(tGrafoPonderado * pGrafo) {
	int x, y; 
	
	for(x=0;x<=N;x++) {
		pGrafo->vertices[x] = 0;
		
		for(y=0;y<=N;y++) {
			pGrafo->arcos[x][y] = 0;
		}
	}
	printf("Grafo ponderado Inicializado!\n");
}

void agregarVertice(tGrafoPonderado * pGrafo, tVertice pVertice) {
	if(pVertice < N) {
		pGrafo->vertices[pVertice] = true;
		printf("Se agrego vertice %d\n",pVertice);
	} else {
		printf("Vertice invalido!\n");
	}
}

void agregarArco(tGrafoPonderado * pGrafo, tArco pArco) {
	if(pGrafo->vertices[pArco.origen] == true && pGrafo->vertices[pArco.destino] == true) {
	   	pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
	   	printf("Arco activado [%d, %d] peso: %.2f\n",pArco.origen, pArco.destino,pArco.peso);
	   } else {
	   	printf("Arco invalido!\n");
	   }
}

void eliminarVertice(tGrafoPonderado * pGrafo, tVertice pVertice) {
	bool existeVer = existeVertice(*pGrafo, pVertice);
	
	if(existeVer) {
		pGrafo->vertices[pVertice] = false;
		printf("Vertice: %d eliminado!\n",pVertice);
	} else {
		printf("No existe el vertice que se desea quitar!\n");	
	}
}

bool existeVertice(tGrafoPonderado pGrafo, tVertice pVertice) {
	return pGrafo.vertices[pVertice] == true;
}

void eliminarArco(tGrafoPonderado * pGrafo,tArco pArco) {
	if(pGrafo->arcos[pArco.origen][pArco.destino] != 0.0) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0.0;
		printf("Arco [%d, %d] eliminado!\n ", pArco.origen, pArco.destino);
	} else {
		printf("El arco que quiere eliminar no existe!\n");
	}
}

int maximoVertice(tGrafoPonderado pGrafo) {
	int x, max;
	max = 0;
	
	for(x=0;x<N;x++){
		if(pGrafo.vertices[x] == true) {
			max = x;
		}
	}
	
	return max;
}

void mostrarMatrizAdyacencia(tGrafoPonderado pGrafo) {
	int x, y, maxVertice;
	maxVertice = maximoVertice(grafo);
	
	bool existeArista = false;
	
	printf("Matriz de adyacencia\n");
	for(x=1;x<=maxVertice;x++) {
		for(y=1;y<=maxVertice;y++) {
			existeArista = (pGrafo.arcos[x][y] != 0.0
							&& existeVertice(grafo, x)
							&& existeVertice(grafo, y));
							
			if(existeArista == true) {
				printf(" 1");
			} else {
				printf(" 0");
			}
		}
		printf("\n");
	}
}

void mostrarMatrizPesos(tGrafoPonderado pGrafo) {
	int x, y, maxVertice;
	maxVertice = maximoVertice(grafo);
	
	bool existeArista = false;
	
	printf("Matriz de pesos\n");
	for(x=1;x<=maxVertice;x++) {
		for(y=1;y<=maxVertice;y++) {
			existeArista = (pGrafo.arcos[x][y] != 0.0
							&& existeVertice(grafo, x)
							&& existeVertice(grafo, y));
							
			if(existeArista == true) {
				printf(" %.f",pGrafo.arcos[x][y]);
			} else {
				printf("  0 ");
			}
		}
		printf("\n");
	}
}






