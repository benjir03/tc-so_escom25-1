#include <stdio.h>

int numElem(int n) {
    if(n == 0)
        return 1;  // 2^0 es 1
    else
        return 2 * numElem(n - 1);
}

void genPalabra(int n, char *palabra, int pos, FILE *archivo) {
    if(pos == n) {
        palabra[n] = '\0';
        printf("%s",palabra);
        fprintf(archivo,"%s",palabra);
        return;
    }

    palabra[pos] = '0';
    genPalabra(n,palabra,pos + 1,archivo);
    printf(",");
    fprintf(archivo,",");
    palabra[pos] = '1';
    genPalabra(n,palabra,pos + 1,archivo);
}

void kleene(int n, int numElem, int contador, int U, int P, FILE *archivo) {
    char palabra[n+1];

    if(contador == 0) {
        if(U && !P) {
            printf("{λ}");
            fprintf(archivo,"{λ}");
        }
        else if (!U && !P) {
            printf("{λ,");
            fprintf(archivo,"{λ,");
        }
        else {
            printf("{");
            fprintf(archivo,"{");
        }
        kleene(n,numElem,contador+1,U,P,archivo);
    }
    else {
        if(contador <= n) {
            if(U) {
                printf("U{");
                fprintf(archivo,"U{");
            }
            genPalabra(contador,palabra,0,archivo);
            if(U && contador != n) {
                printf("}");
                fprintf(archivo,"}");
            }
            else if(U) {
                printf("}");
                fprintf(archivo,"}");
            }
            else if(!U && contador == n) {
                printf("}");
                fprintf(archivo,"}");
            }
            else  {
                printf(",");
                fprintf(archivo,",");
            }
            kleene(n,numElem,contador+1,U,P,archivo);
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);

    FILE *archivo = fopen("TC_P01-GRUPO-INTEGRANTES.txt","w");

    printf("∑^*=");
    fprintf(archivo,"∑^*=");
    kleene(n,0,0,1,0,archivo);

    printf("\n∑^*=");
    fprintf(archivo,"\n∑^*=");
    kleene(n,0,0,0,0,archivo);

    printf("\n∑^+=");
    fprintf(archivo,"\n∑^+=");
    kleene(n,0,0,0,1,archivo);
    
    fclose(archivo);
    
    return 0;
}