#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//Exercício 2
//Servidor
int main(int argc, char const *argv[]){

	int leitura, n;
	char buffer[1024];
	int log = open("log.txt", O_CREAT|O_RDWR, 00777);
	leitura = open("server",O_RDONLY);
	printf("Servidor iniciado\n");
	while( (n = read(leitura,buffer,1024)) > 0 ) //Lê do pipe e escreve no log
		write(log,buffer,n);

	close(leitura);
	printf("Servidor fechado\n");
	return 0;

}