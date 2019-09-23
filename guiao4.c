#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


//NADA DESTE FICHEIRO FOI TESTADO, O GCC ESTAVA BUGADO
int main(int argc, char const *argv[])
{
	int n = open("/etc/passwd", O_CREAT|O_RDWR, 00777);
	int nn = open("saida.txt", O_CREAT|O_RDWR, 00777);
	int nnn = open("erros.txt", O_CREAT|O_RDWR, 00777);
	dup2(0,n);
	dup2(1,nn);
	dup2(2,nnn);
	//Exercício 2
	int x = fork();
	char buffer[100];
	if(x==0){
		write(1,"kachow\n",10);
		_exit(0);
	}
	else{
		wait(NULL);
		read(0,buffer,10);
	}
	return 0;
}

/*
//Exercício 3
int main(int argc, char const *argv[])
{
	int n = open("/etc/passwd", O_CREAT|O_RDWR, 00777);
	int nn = open("saida.txt", O_CREAT|O_RDWR, 00777);
	int nnn = open("erros.txt", O_CREAT|O_RDWR, 00777);
	dup2(0,n);
	dup2(1,nn);
	dup2(2,nnn);
	//Exercício 2
	int x = fork();
	char buffer[100];
	if(x==0){
		execlp("wc","wc",NULL);
		perror("Algo correu mal...\n");
		_exit(-1);
	}
	else{
		wait(NULL);
	}
	return 0;
}
*/

/*
//Não está concluído - corrigir parte do execvp(Deve ser a partir do argv + 3)
//Exercício 4
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foram fornecidos comandos para executar\n");
		exit(-1);
	}
	else{
		printf("Só está feita versão que faz redirecionamento\n");
		int entrada, saida;
		entrada = atoi(argv[1]);
		saida = atoi(argv[2]);
		dup2(0,entrada);
		dup2(1,saida);
		char *filename;
		filename = (char *) malloc(sizeof(argv[3]) +1);
		strcpy(filename, argv[1]);
		strcat(filename,"\0");
		execvp(filename, *argv);
		perror("Algo correu mal...\n");
	}
	return 0;
}
*/