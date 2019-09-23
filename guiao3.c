#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


/*
//Exercício 1
int main(int argc, char const *argv[])
{
	printf("Executa o comando ls -l\n");
	execlp("ls","ls","-l",NULL);
	perror("Algo não correu bem...\n");
	exit(-1);
	return 0;
}
*/

/*
//Exercício 2
int main(int argc, char const *argv[])
{
	int x;
	x = fork();
	if(x==0){
		execlp("ls","ls","-l",NULL);
		perror("Algo correu mal...\n");
		_exit(-1);
	}
	else{
		wait(NULL);
		printf("Processo pai diz olá\n");
	}
	return 0;
}
*/

/*
//Exercício 3
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foram fornecidos comandos para imprimir\n");
		exit(-1);
	}
	else{
		for(int i=1; i<argc; i++){
			printf("Argumento nº %d %s\n", i, argv[i]);
		}
	}
	return 0;
}
*/

/*
// Exercício 4
int main(int argc, char const *argv[])
{
	execlp("/Users/pedrogoncalves/Documents/Universidade/3º Ano/2º Semestre/SO/Guião 3/ex3","ex3","p","w",NULL);
	return 0;
}
*/

/*
//Exercício 5
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foram fornecidos comandos para executar\n");
		exit(-1);
	}
	else{
		int i,x;
		for(i=1;i<argc;i++){
			//Copia o comando do argv para uma string e coloca um \0 no final
			char *filename;
			filename = (char *) malloc(sizeof(argv[i]) +1);
			strcpy(filename, argv[i]);
			strcat(filename,"\0");

			//Cria um processo e executa o comando nesse novo processo
			x=fork();
			if(x==0){
				execlp(filename,filename,NULL);
				perror("Algo correu mal...\n");
				_exit(-1);
			}
			else{
				wait(NULL);
			}

		}
	}
	return 0;
}
*/

//Exercício 6
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foram fornecidos comandos para executar\n");
		exit(-1);
	}
	else{
		char *filename;
		filename = (char *) malloc(sizeof(argv[1]) +1);
		strcpy(filename, argv[1]);
		strcat(filename,"\0");
		execvp(filename, *argv);
		perror("Algo correu mal...\n");
	}
	return 0;
}