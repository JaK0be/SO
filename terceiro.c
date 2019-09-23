#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//Exercício 1
int main(int argc, char const *argv[]){

	int pipeR, n;
	char buffer[1024];
	pipeR = open("pipe",O_RDONLY);
	printf("Canal de leitura aberto\n");
	while( (n = read(pipeR,buffer,1024)) > 0 ) //Lê do pipe e escreve no stdout
		write(1,buffer,n);

	close(pipeR);
	printf("Canal de leitura fechado\n");
	return 0;

}