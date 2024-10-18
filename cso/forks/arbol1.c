#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int id_proc;
	for(int i = 0; i < 4; i++) {
		if(i%2 == 0) {
			id_proc = fork(); //  crear 1
			for(int i=0; i < 3; i++) {
				id_proc = fork();
				if(id_proc == 0);
				else break;
			}
			for(int i=0; i < 3; i++) {
				if(id_proc == 0) exit(0);
			}

			for(int i=0; i < 2; i++) {
				id_proc = fork();
				if(id_proc == 0);
				else break;
			}
			for(int i=0; i < 2; i++) {
				if(id_proc == 0) exit(0);
			}
		}
		else // 3 en columna
		{
			for(int i=0; i < 3; i++) {
				id_proc = fork();
				if(id_proc == 0);
				else break; // crear 3 y 5
			}
			for(int i=0; i < 3; i++) {
				if(id_proc == 0) exit(0); // sale de 3 y 5
			}
		}
	}
}