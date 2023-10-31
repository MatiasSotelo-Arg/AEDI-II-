#include <stdio.h>
#include <string.h>

typedef char tString[30];

int main() {
    tString palabra = "Aqui voy a buscar un texto";
    tString palabraBuscada = "texto";
    tString aux = "";
    int i, j;

    for (i = 0; i <= strlen(palabra) ; i++) {
        for (j = 0; j < strlen(palabraBuscada); j++) {
            if (palabra[i + j] != palabraBuscada[j]) {
                break;
            }
        }
        if (j == strlen(palabraBuscada)) {
            strncpy(aux, palabra + i, strlen(palabraBuscada));
            printf("Se encontro %s\n", aux);
        }
    }

    if (aux[0] == '\0') {
        printf("La palabra buscada no se encontró en la cadena.\n");
    }

    return 0;
}

