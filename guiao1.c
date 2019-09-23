#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N = 1024;

/*
//Exercício 1
//Criar um ficheiro de 10 mb cujo nome é passado como argumento
int main(int argc, char const *argv[])
{
	if(argc < 2){
		perror("Não foi fornecido um nome para o ficheiro\n");
		exit(-1);
		return -1;
	}
	else{
		int tamanho = 10000000;
		int n = open(argv[1], O_CREAT|O_RDWR, 00777);
		char *buffer;
		buffer = (char *) malloc((sizeof (char)) * tamanho);
		for(int i = 0;i<tamanho;i++){
			buffer[i]='k';
		}
		write(n,buffer,tamanho);
		close(n);
		free(buffer);
	}
	return 0;
}
*/

/*
//Exercício 2
//MyCat
int main(int argc, char const *argv[])
{
	char buffer[1024];
	while(read(0,buffer,1)){
		write(1,buffer,1);
	}
	return 0;
}
*/

/*
//Exercício 3
//MyCat que lê do terminal o valor de caracteres a ler, N
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foi fornecido um N\n");
		exit(-1);
		return -1;
	}
	else{
		int N = atoi(argv[1]);
		printf("O N é : %d\n", N);
		char *buffer;
		buffer = (char*) malloc((sizeof (char)) *N);
		while(read(0,buffer,N)){
			write(1,buffer,N);
			buffer=(char *) malloc((sizeof (char))*256);//para limpar o buffer, para este não encher
		}
		free(buffer);
	}
	return 0;
}
*/

/*
Exercício 4, o tmp/lixo fode-me os tempos, não sei porquê
Se imprimir no ecrã os tempos melhoram, it makes no sense

JaKobe-Toaster:Aula 1  pedrogoncalves$ time ./aula1 1 < 10mb.dat > \tmp\lixo  USANDO TMP

real	0m57.242s
user	0m10.749s
sys	0m45.533s

JaKobe-Toaster:Aula 1  pedrogoncalves$ time ./aula1 1024 < 10mb.dat > \tmp\lixo USANDO TMP

real	0m0.094s
user	0m0.015s
sys	0m0.075s

Imprimindo 1
real	0m32.137s
user	0m10.768s
sys	0m20.730s

Imprimindo 1024
real	0m0.273s
user	0m0.016s
sys	0m0.078s


Resposta -- A diferença observada suponho que seja por cagar mais caracteres de uma só vez, logo necessita de executar a função read e write menos vezes

*/

/*
//Exercíco 5
ssize_t readln(int fd , void* buff , size_t n){
	int i;
	for(i = 0; (read(fd,(char*)buff + i,1)>0) && (i<n) && (*((char *)buff +i)) != '\n'; i++);
	return i;
}

int readln(int fildes, char *buf, int size){
	int x = 0, i = 1;
	char c = 0;

	while (i && x < size && c!='\n'){
		i = read(fildes, &c, 1);
		if (i){
			buf[x] = c;
			x++;
		}
		if( c=='\0') break;
	}
	buf[x-1]='\0';
	return x;
}
*/

/*
//Exercício 6
//É possível fazer só com um buffer, utilizando o printf para imprimir o número da linha, mas não fica com a arquitetura pretendida, pois o printf só imprime depois dos writes por alguma razão
int	main(int argc, char const *argv[])
{
	int i=0,f,tamanho, n=1;
	char *buffer;
	char *final;
	buffer = (char *) malloc((sizeof (char))*1024);
	final = (char *) malloc((sizeof (char))*1024);
	if(argc > 1){
		f = open (argv[1],O_CREAT|O_RDWR, 00777);
	}
	else {f=0;}
	while((i=readln(f,buffer,1024))>0)
	{
		sprintf(final,"%d   ",n++);//Escreve em final a linha
		for(tamanho=0;buffer[tamanho];tamanho++);//número de caracteres de cada linha lida
		write(1,final,tamanho);
		//n++;//número da linha
		//printf("%d   ", n);
		write(1,buffer,i);
		write(1,"\n",1);
	}
	if(argc > 1){
		close(f);
	}
	free(buffer);
	free(final);
	return 0;
}
*/

/*
//Exercíco 8
//mycat
int main(int argc, char const *argv[])
{
	if(argc<2){
		perror("Não foram fornecidos nomes de ficheiros\n");
		exit(-1);
	}
	else{
		char *buffer;
		int i;
		buffer = (char *) malloc((sizeof (char))*1024);  
		for(i=1;i<argc;i++){
			int n = open(argv[i], O_CREAT|O_RDWR, 00777);
			read(n,buffer,1024);
			write(1,buffer,1024);
			write(1,"\n",3);
			close(n);
		}
		exit(0);
	}
	return 0;
}
*/

/*
//Exercício 9
//myhead
int main(int argc, char const *argv[])
{
	if(argc<3){
		perror("Não foram fornecidos nomes de ficheiros\n");
		exit(-1);
		return -1;
	}else{
		int z;
		int x = -atoi(argv[1]);
		printf("Número de linhas %d\n", x);
		char *buffer;
		char ci[30];
		char cf[4];		
		int i;
		for(i=2;i<argc;i++){
			
			strcpy(ci,"==>");
			strcpy(cf,"<==");
			int n = open(argv[i], O_CREAT|O_RDWR, 00777);
			strcat(ci,argv[i]);
			strcat(ci,cf);
			write(1,ci,30);			
			write(1,"\n",3);
			for(z=0;z<x;z++)
			{
				//assim tenho o buffer sempre limpo
				buffer = (char *) malloc((sizeof (char))*1024);
				readln(n,buffer,1024);
				write(1,buffer,1024);
			}
			//read(n,buffer,1024);
			//write(1,"\n",3);
			close(n);
		}
		exit(0);
	}
	return 0;
}
*/

/*
//Exercício 12
//mycmp
//Não está completa
int main(int argc, char const *argv[])
{
	if(argc<3){
		perror("Não foram fornecidos nomes de ficheiros\n");
		exit(-1);
		return -1;
	}else{
		if(strcmp(argv[1],argv[2])==0){
			printf("É o mesmo ficheiro, logo \n");
			return 0;
		}
	}
	return 0;
}
*/