#include <stdio.h>
#include <stdlib.h>

typedef char *apuntadorC; //define un tipo de dato que se llama apuntadorC de tipo char*
apuntadorC a1, a2; //declaro dos variables de tipo apuntadorC

int main() {
	// Memory Allocation -> retorna void 
a1 = malloc(sizeof(char)); //malloc solicita al sistema operativo que reserve un bloque de memoria
a2 = malloc(sizeof(char)); //sizeof devuelve el numero de la cantidad de bytes del dato 

*a1 = 'A';
*a2 = 'B';

//printf("%c \n", *a1);
//printf("%c \n", *a2);

printf("posicion de memoria del puntero a1 %d\n", &a1);
printf("valor de a1 (posicion de memoria donde apunta a1) %d \n", a1);
printf("valor de donde apunta a1 %c \n\n", *a1);

printf("valor de a1 %p \n", a2);
printf("valor de donde apunta a1 %c \n\n", *a2);

free(a1);
free(a2);

return 0;
}

/* Devuelve 
Linea 9 y 10, col 25
[Error] invalid conversion from 'void*' to 'apuntadorC {aka char*}' [-fpermissive]
*/
