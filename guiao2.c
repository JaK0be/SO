#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

/*
//Exercício 1
int main(int argc, char const *argv[])
{
	int i = getpid();
	int p = getppid();
	printf("O meu identificador de processo é: %d\n", i);
	printf("O identificador de processo do meu pai é: %d\n", p);
	return 0;
}
*/

/*
//Exercício 2
int main(int argc, char const *argv[])
{
	int i, p, x, status;
	x=fork();
	if(x==0){//Processo filho||fork retorna o pid do filho, guradandi neste caso esse valor no x filho 
		i = getpid();
		p = getppid();
		printf("FILHO -- ID: %d - ID PAI: %d\n", i,p);
		_exit(status);
	}
	else{//Processo pai
		wait(&status);
		i=getpid();
		p=getppid();
		printf("PAI -- ID: %d - ID PAI: %d - ID FILHO - %d\n", i,p,x);
	}
	return 0;
}
*/

/*
//Exercício 3
int main(int argc, char const *argv[])
{
	int z,i,p,x,status,exit;
	for(z=0;z<10;z++){
		x=fork();
		if(x==0){
			i = getpid();
			p = getppid();
			printf("FILHO -- ID: %d - ID PAI: %d\n", i,p);
			status = z;
			_exit(status);
		}
		else{
			wait(&status);
			exit = WEXITSTATUS(status);
			printf("Filho nº: %d || Código de saída %d\n", z ,exit);
		}
	}
	return 0;
}
*/

/*
//Exercício 4
int main(int argc, char const *argv[])
{
	int z,i,p,x,status,exit;
	for(z=0;z<10;z++){
		x=fork();
		if(x==0){
			i = getpid();
			p = getppid();
			printf("FILHO -- ID: %d - ID PAI: %d\n", i,p);
			status = z;
			_exit(status);
		}
	}
	for(z=0;z<10;z++){
		wait(&status);
		exit = WEXITSTATUS(status);
		printf("PAI -- FILHO: %d - CÓDIGO SAÍDA: %d\n", exit,exit);
	}
}
*/

/*
//Não percebo bem como isto funciona, mas funciona. Não fecho os filhos tho, e acho que é por isso que funciona
//Exercício 5
int main(int argc, char const *argv[])
{
	int x, ppid, pid, i,status;
	for(i=0;i<10;i++){
		x = fork();
		if(x>0){
			wait(&status);
			status = i;
			_exit(status);
		}
		printf("ID: %d -- PAI: %d\n",getpid(),getppid());
	}	
	return 0;
}
*/

/*
//Exercício 6
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foi fornecido um número a procurar.");
		exit(-1);
	}
	else{
		int i, j,contadorF=0, numero, x, status;
		int contador=0;
		int LINHAS=4;
		int COLUNAS=25;
		int a[LINHAS][COLUNAS];
		//----
		numero = atoi(argv[1]);
		printf("O número a procurar é: %d\n", numero);
		//----
		printf("A inicializar matriz...\n");
		for(i=0;i<LINHAS;i++){//Cria a matriz random
			printf("\n");
			for(j=0;j<COLUNAS;j++){
				a[i][j]=rand() % (numero + 1);
				printf("%d\t", a[i][j]);
			}
		}
		printf("\n\nMatriz inicializada.\n");
		//----
		for(i=0;i<LINHAS;i++){
			x = fork();
			if(x==0){
				for(j=0;j<COLUNAS;j++){
					if(a[i][j]==numero)contador++;
				}
				status = contador;
				_exit(status); //Fazemos exit com este número para depois conseguirmos somar os contadores de todos os forks
			}
			else{
				wait(&status);
				contadorF+=WEXITSTATUS(status);
			}
		}
		//----
		printf("%d Aparece %d vezes na matriz criada\n", numero, contadorF);
	}
	return 0;
}
*/