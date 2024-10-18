#include <stdio.h>
//#include <string.h>

#define MAX 50

void imprimir(char *cadena, int tamanoCadena, int contador) {
    if(contador == tamanoCadena);
    else {
        printf("%c",*cadena);
        imprimir(cadena+1,tamanoCadena, contador+1);
    }
}

int tamanoCadena(char *cadena, int tamano) {
    if(*cadena == '\0') return tamano;
    else return tamanoCadena(cadena+1,tamano+1);
}

void imprimirSubCadena(char *cadena, int subCaden, int contador) {
    if(contador == subCaden);
    else {
        imprimir(cadena,contador+1,0);
        printf("\n");
        imprimirSubCadena(cadena,subCaden,contador+1);
    }
}

void subcadenas(char *cadena, int repeticiones, int contador) {
    if(contador == repeticiones);
    else {
        imprimirSubCadena(cadena,repeticiones,0);
        subcadenas(cadena+1,repeticiones-1,0);
    }
}

void prefijos(char *cadena, int tamanoPrefijo, int contador) {
    if(contador == tamanoPrefijo);
    else {
        imprimir(cadena,tamanoPrefijo-contador,0);
        printf("\n");
        prefijos(cadena,tamanoPrefijo,contador+1);
    }
}

void sufijos(char *cadena, int tamSuf, int iteraciones) {
    if(tamSuf == iteraciones);
    else {
        imprimir(cadena,tamSuf+1,0);
        printf("\n");
        sufijos(cadena-1,tamSuf+1,iteraciones);
    }
}

int main() {

    char cadena[MAX];
    int tam = 0;

    scanf("%s",cadena);
    tam = tamanoCadena(cadena,0);

    //imprimir(cadena+tam-1,1,0);
    printf("Subcadenas de '%s':\n",cadena);
    subcadenas(cadena,tam,0);
    printf("\n");
    printf("Prefijos de '%s':\n",cadena);
    prefijos(cadena,tam,0);
    printf("\n");
    printf("Sufijos de '%s':\n",cadena);
    sufijos(cadena+tam-1,0,tam);
    printf("\n");

    return 0;
}