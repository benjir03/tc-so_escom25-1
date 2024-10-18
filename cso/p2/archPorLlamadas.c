#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

#define MAX 100

int main() {

    char ruta[MAX];
    char *contenidos[5] = {"hola","soy","un","archivo","vacío"};

    int createDir = mkdir("/Users/benjir/Documents/pgrmsC/cso/p2/archivos",0755);

    for(int i = 0; i < 5; i++) {
        sprintf(ruta,"/Users/benjir/Documents/pgrmsC/cso/p2/archivos/arch%d",i);
        strcat(ruta,".txt");
        printf("%s\n",ruta);
        printf("%s\n",contenidos[i]);
        int createFile = open(ruta,O_CREAT | O_WRONLY,0755);
        char *texto = contenidos[i];
        ssize_t nEscritos = write(createFile,texto,strlen(texto));
        close(createFile);
    }
    return 0;
}