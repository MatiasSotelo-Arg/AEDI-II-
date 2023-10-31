/* Metodo marge sort:
	se utiliza para intercambiar elementos de dos 
	vectores ordenados y obtener otro vector ordenado 
*/ 

#include <stdio.h>

void merge(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 3, 5, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int result[size1 + size2];

    merge(arr1, size1, arr2, size2, result);

    printf("Arreglo combinado y ordenado: ");
    int i = 0;
    for (i; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

