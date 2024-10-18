#include <stdio.h>
#include <string.h>

#define MAX 50

void subCadenas (char cadena[], int tam) {
    printf("Subcadenas de '%s':\n",cadena);
    for(int k = 0; k < tam; k++) {
        printf("\n");
        for(int i = k; i < tam; i++) {
            for(int j = k; j <= i; j++) {
                printf("%c",cadena[j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void prefijos(char cadena[], int tam) {
    printf("Prefijos de '%s':\n",cadena);
    
    for(int i = tam; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            printf("%c",cadena[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sufijos(char cadena[], int tam) {
    printf("Sufijos de '%s':\n",cadena);

    for(int i = tam; i > 0; i--) {
        for(int j = i-1; j < tam; j++) {
            printf("%c",cadena[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    char cadena[MAX];
    int tam = 0;

    scanf("%s",cadena);
    tam = strlen(cadena);

    printf("\nTamaño de la cadena: %d\n",tam); //tamaño

    subCadenas(cadena,tam);
    prefijos(cadena,tam);
    sufijos(cadena,tam);
    return 0;
}