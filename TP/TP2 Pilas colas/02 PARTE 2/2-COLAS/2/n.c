#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Tipos de datos
typedef char tString[25];

typedef struct {
    int nroTurno;
    tString nombreCliente;
    int motivo; // 1 para transacción, 2 para consulta
} tCliente;

typedef struct Nodo {
    tCliente cliente;
    struct Nodo* siguiente;
} tNodo;

typedef struct {
    tNodo* primero;
    tNodo* ultimo;
} tCola;

// Funciones globales
tCola cola;
int nroCliente = 0; // Inicializamos el número de cliente en 0

// Prototipos de funciones
void inicializarCola();
bool colaVacia(tCola);
void menu();
tCliente ingresarDatos();
void push(tCliente);
void pop();
int cantPersonasTransaccion();
int cantPersonasConsulta();
void visualizarLista();

int main() {
    inicializarCola();

    int opcionMenu = -1;

    do {
        printf("\n## MENU ##\n");

        // Opciones
        printf("1 - Nuevo cliente\n");
        printf("2 - Cantidad de personas en transacción\n");
        printf("3 - Cantidad de personas en consulta\n");
        printf("4 - Visualizar lista\n");
        printf("0 - Salir\n");

        scanf("%d", &opcionMenu);

        switch (opcionMenu) {
            case 1:
                ingresarDatos();
                break;
            case 2:
                printf("Cantidad de personas en transacción: %d\n", cantPersonasTransaccion());
                break;
            case 3:
                printf("Cantidad de personas en consulta: %d\n", cantPersonasConsulta());
                break;
            case 4:
                visualizarLista();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida: %d\n", opcionMenu);
                break;
        }

    } while (opcionMenu != 0);

    return 0;
}

// Implementación de funciones
void inicializarCola() {
    cola.primero = NULL;
    cola.ultimo = NULL;
    printf("Cola inicializada!\n");
}

bool colaVacia(tCola pCola) {
    return (pCola.primero == NULL && pCola.ultimo == NULL);
}

void push(tCliente cliente) {
    tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    nuevoNodo->cliente = cliente;
    nuevoNodo->siguiente = NULL;

    if (colaVacia(cola)) {
        cola.primero = nuevoNodo;
        cola.ultimo = nuevoNodo;
    } else {
        cola.ultimo->siguiente = nuevoNodo;
        cola.ultimo = nuevoNodo;
    }
}

void pop() {
    if (!colaVacia(cola)) {
        tNodo* nodoAEliminar = cola.primero;
        cola.primero = cola.primero->siguiente;
        free(nodoAEliminar);
    }
}

tCliente ingresarDatos() {
    tCliente nuevoCliente;
    nroCliente++;

    printf("\n## Nuevo cliente ##\n");
    printf("Nro cliente: %d\n", nroCliente);

    printf("Nombre: ");
    scanf("%s", nuevoCliente.nombreCliente);

    printf("Motivo (1 para transacción, 2 para consulta): ");
    scanf("%d", &nuevoCliente.motivo);

    nuevoCliente.nroTurno = nroCliente;

    push(nuevoCliente);

    return nuevoCliente;
}

int cantPersonasTransaccion() {
    tNodo* actual = cola.primero;
    int contador = 0;

    while (actual != NULL) {
        if (actual->cliente.motivo == 1) {
            contador++;
        }
        actual = actual->siguiente;
    }

    return contador;
}

int cantPersonasConsulta() {
    tNodo* actual = cola.primero;
    int contador = 0;

    while (actual != NULL) {
        if (actual->cliente.motivo == 2) {
            contador++;
        }
        actual = actual->siguiente;
    }

    return contador;
}

void visualizarLista() {
    tNodo* actual = cola.primero;

    printf("\n## Lista de clientes en espera ##\n");

    while (actual != NULL) {
        printf("Turno: %d | Nombre: %s | Motivo: %s\n", actual->cliente.nroTurno, actual->cliente.nombreCliente, (actual->cliente.motivo == 1) ? "Transacción" : "Consulta");
        actual = actual->siguiente;
    }
}

