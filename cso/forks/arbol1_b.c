#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    int id_proc = fork(); // 1

    if(id_proc == 0) {
        id_proc = fork(); // 2
        if(id_proc == 0) {
            id_proc = fork(); // 4
            if(id_proc == 0) {
				id_proc = fork(); // 6
				if(id_proc == 0) exit(0); // salir 6
            }
            exit(0); // salir 4
        }
        exit(0); // salir 2
    }

    if(id_proc == 0) {
        id_proc = fork(); // 3
        if(id_proc == 0) {
            id_proc = fork(); // 5
            if(id_proc == 0) exit(0); // salir 5
        }
        exit(0); // salir 3
    }
    exit(0); // salir 1

    id_proc = fork(); // 1.1
    if(id_proc == 0) {
        id_proc = fork(); // 1.2
        if(id_proc == 0) {
            id_proc = fork(); // 1.3
            if(id_proc == 0) exit(0); //salir 1.3
        }
        exit(0); // salir 1.2
    }
    exit(0); // salir 1.1
}