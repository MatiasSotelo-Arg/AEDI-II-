///* Escribir un programa que permita mostrar por pantalla una 
//cuenta regresiva, a partir de un valor ingresado por teclado. 
//Programar una función recursiva que, al llegar la cuenta a cero, 
//informe que el tiempo se ha agotado. */
//
#include <stdio.h>;
#include <windows.h>

void cuentaRegresiva( int );

int main() {
	
	cuentaRegresiva(10);
	
	return 0;
}

void cuentaRegresiva( int pInicial ) {
	
	if(pInicial == 0){
		printf("el tiempo se ha agotado\n");
		return;
	} else {
		printf("%d\n",pInicial);
		cuentaRegresiva( pInicial - 1 );
	}
		
}


