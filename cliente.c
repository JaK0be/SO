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
//Cliente
int main(int argc, char const *argv[]){

	int escrita, n;
	char buffer[1024];
	escrita = open("server",O_WRONLY);
	printf("Cliente criado\n");
	while( (n = read(0,buffer,1024)) > 0 ) //Lê do stdin e escreve isso no pipe
		write(escrita,buffer,n);
	close(escrita);
	printf("Cliente criado\n");
	return 0;

}