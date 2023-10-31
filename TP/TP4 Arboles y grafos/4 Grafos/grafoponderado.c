/*Escribe en lenguaje c, la declaración de un tipo de dato tGrafoPonderado para un grafo ponderado de
hasta 10 vértices, donde el peso corresponde a kg. Utilizar la implementación de grafos con arrays.
Además, escribir las funciones para:*/
#include <stdio.h>
#include <stdbool.h>
#define N 10

typedef int tVertice;

typedef float tPeso;

typedef struct{
	tVertice origen;
	tVertice destino;
	tPeso peso;
} tArco;

typedef bool vVertices[N];
typedef tPeso mArcos[N][N];

typedef struct{
	vVertices vertices;
	mArcos arcos;	
} tGrafoPonderado;
///prototipos

void inicializar(tGrafoPonderado*);
void insertarVertice(tGrafoPonderado*,tVertice);
void insertarArco(tGrafoPonderado*,tArco);
void verMatriz(tGrafoPonderado);
int maximoVertice(tGrafoPonderado);

int main()
{
	tGrafoPonderado grafo;
	inicializar(&grafo);
	insertarVertice(&grafo,2);
	insertarVertice(&grafo,3);
	insertarVertice(&grafo,4);
	
	tArco arco;
	arco.origen = 2;
	arco.destino = 3;
	arco.peso = 25.3;
	
	insertarArco(&grafo, arco);
	
	arco.origen = 4;
	arco.destino = 2;
	arco.peso = 17.2;
	
	insertarArco(&grafo, arco);
	
	verMatriz(grafo);
	
	return 0;
}


///implementaciones

void inicializar(tGrafoPonderado * pGrafo)
{
	int i,j;

	for(i=0; i<N; i++)
	{
		///limpiar vector de vertices
		//(*pGrafo).vertices[i] = 0;
		pGrafo->vertices[i] = 0;
	
		for(j=0; j<N; j++)
		{
			///limpiar matriz de pesos
			pGrafo->arcos[i][j] = 0; 
		}
	}
	
	
}


void insertarVertice(tGrafoPonderado * pGrafo, tVertice pVertice)
{
	if(pVertice < N)
	{
		pGrafo->vertices[pVertice] = 1;
	}
	else
	{
		printf("Se supero la capacidad del vector de vertices");
	}
	
}


void insertarArco(tGrafoPonderado * pGrafo, tArco pArco)
{
	
	int i,j;
	i = pArco.origen;
	j = pArco.destino;
	///verficar si el vertice existe
	if(pGrafo->vertices[i] == 1 && pGrafo->vertices[j] == 1)
	{
		pGrafo->arcos[i][j] = pArco.peso;
		pGrafo->arcos[j][i] = pArco.peso;
	}
	else
	{
		printf("Alguno de los vertices no existe");
	}
}

int maximoVertice(tGrafoPonderado pGrafo)
{
	int i,max = 0;
	for(i=0;i<N;i++)
	{
		if(pGrafo.vertices[i] == 1)
		{
			max = i;
		} 		
	}
	return max;
}

void verMatriz(tGrafoPonderado pGrafo)
{
	
	int max = maximoVertice(pGrafo);
	
	int i,j;
	for(i=1;i<=max;i++)
	{
		for(j=1;j<=max;j++)
		{		
			printf("%.2f ",pGrafo.arcos[i][j]);
		}
		printf("\n");
	}

}
