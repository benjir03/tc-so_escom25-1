#include <stdio.h>

void guardar(int n) {
    int mitad = n/2;
    int tope = mitad/2;

    int up = 1;
    int dw = 1;
    int eUp = tope;
    int eDw = tope; 
    int eMid = 2 * tope;

    FILE *archivo = fopen("salida.txt","w");

    for(int i = 0 ; i < mitad ; i++) {
        if (i == tope){
            for(int x = 0 ; x < n ; x++) fprintf(archivo,"*");fprintf(archivo,"\n");
            eUp++;
            eMid++;
            up = up - 2;
        }else if (i < tope){
            for(int e = 0; e < eUp ; e++) fprintf(archivo,"-");
            for(int a = 0; a < up ; a++) fprintf(archivo,"*");
            for(int e2 = 0; e2 < eMid ; e2++) fprintf(archivo,"-");
            for(int a2= 0; a2 < dw ; a2++) fprintf(archivo,"*");
            for(int e2 = 0; e2 < eDw ; e2++) fprintf(archivo,"-");
            fprintf(archivo,"\n");
            eUp--;
            eMid--;
            up = up+2;
        }else if(i > tope){
            for(int e2 = 0; e2 < eDw ; e2++) fprintf(archivo,"-");
            for(int a2= 0; a2 < dw ; a2++) fprintf(archivo,"*");
            for(int e2 = 0; e2 < eMid ; e2++) fprintf(archivo,"-");
            for(int a = 0; a < up ; a++) fprintf(archivo,"*");
            for(int e = 0; e < eUp ; e++) fprintf(archivo,"-");
            fprintf(archivo,"\n");
            eUp++;
            eMid++;
            up = up-2;
        }
    }
    fclose(archivo);
    printf("¿El archivo se guardó correctamente.\n");
}

int main () {
    int n = 0;
    printf("Ingresa un número par entre 6 y 18 y que sea suna de dos impares:\n");
    scanf("%d",&n);

    if ( n < 6 || n > 18) printf("Número no válido.");
    else {
        int mitad = n/2;
        int tope = mitad/2;

        int up = 1;
        int dw = 1;
        int eUp = tope;
        int eDw = tope; 
        int eMid = 2 * tope;

        //printf("Mitad: %d\n",mitad);
        //printf("Tope: %d\n",tope);

        for(int i = 0 ; i < mitad ; i++) {
            if (i == tope){
                for(int x = 0 ; x < n ; x++) printf("*");printf("\n");
                eUp++;
                eMid++;
                up = up - 2;
            }else if (i < tope){
                for(int e = 0; e < eUp ; e++) printf("-");
                for(int a = 0; a < up ; a++) printf("*");
                for(int e2 = 0; e2 < eMid ; e2++) printf("-");
                for(int a2= 0; a2 < dw ; a2++) printf("*");
                for(int e2 = 0; e2 < eDw ; e2++) printf("-");
                printf("\n");
                eUp--;
                eMid--;
                up = up+2;
            }else if(i > tope){
                for(int e2 = 0; e2 < eDw ; e2++) printf("-");
                for(int a2= 0; a2 < dw ; a2++) printf("*");
                for(int e2 = 0; e2 < eMid ; e2++) printf("-");
                for(int a = 0; a < up ; a++) printf("*");
                for(int e = 0; e < eUp ; e++) printf("-");
                printf("\n");
                eUp++;
                eMid++;
                up = up-2;
            }
        }
    int r = 0;
    printf("¿Desea guardar el archivo?  1/0\n");
    scanf("%d",&r);
    if(r==1)guardar(n);
    }
    return 0;
}