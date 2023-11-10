#include <stdio.h>
#include <stdlib.h>

typedef char tString[20];

typedef struct {	    
    short codUniverso; 
    tString nombrePersonaje;
    tString nombreTerrestre;
    char genero;
    char codRol;	
    short cantPeliculasAparicion; 
} tPersonaje;

int main() {
    FILE *csvFile = fopen("productos.csv", "r");
    FILE *datFile = fopen("productos.dat", "wb");

    if (csvFile == NULL || datFile == NULL) {
        printf("No se pudo abrir uno de los archivos.\n");
        return 1;
    }

    // Ignorar la primera línea del archivo CSV (encabezado)
    char buffer[1024];
    fgets(buffer, sizeof(buffer), csvFile);

    tPersonaje producto;

    while (fscanf(csvFile, "%hd,%19[^,],%19[^,],%c,%c,%hd\n", &producto.codUniverso, producto.nombrePersonaje, producto.nombreTerrestre, &producto.genero, &producto.codRol, &producto.cantPeliculasAparicion) == 6) {
        fwrite(&producto, sizeof(tPersonaje), 1, datFile);
    }

    fclose(csvFile);
    fclose(datFile);

    return 0;
}

