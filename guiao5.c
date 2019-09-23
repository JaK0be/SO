#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*
//Exercíco 1
int main(int argc, char const *argv[])
{
	int fd[2],x;
	pipe(fd);//cria um pipe
	x = fork();
	char buffer[1024];
	if(x==0){//Processo filho 
		close(fd[1]);//fecha escrita do processo filho
		read(fd[0],buffer,1024);//Lê mensagens do pai
		close(fd[0]);
		printf("Mensagem recebida pelo processo filho: %s", buffer);
		_exit(x);
	}
	else{
		close(fd[0]);//fecha leitura do processo pai
		sleep(2);
		write(fd[1],"Mensagem teste enviada pelo processo pai",300);
		printf("Mensagem enviada\n");
		close(fd[1]);
	}
	return 0;
}
*/

/*
//Pelos vistos end of file é fechar ambos os canais de escrita, logo é igual ao 1, SO é retardado
//Exercíco 2
int main(int argc, char const *argv[])
{
	int fd[2],x;
	pipe(fd);
	x = fork();
	char buffer[1024];
	if(x==0){
		close(fd[1]);//fecha canal escrita do processo filho
		//while(read(fd[0],buffer,1) != -1);
		read(fd[0],buffer,1024);
		close(fd[0]);
		printf("Mensagem recebida pelo processo filho: %s", buffer);
		_exit(x);
	}
	else{
		close(fd[0]);//fecha canal leitura do processo pai
		write(fd[1],"Mensagem teste enviada pelo processo pai\n",300);
		printf("Mensagem enviada\n");
		close(fd[1]);
		printf("Filho deverá ter fechado\n");
	}
	return 0;
}
*/

/*
//Exercício 3
int main(int argc, char const *argv[])
{
	char buffer[1024];
	int fd[2],x;
	int f = open("teste.txt",O_CREAT|O_WRONLY|O_RDONLY|O_APPEND,0777);
	pipe(fd);
	x = fork();
	if(x==0){
		close(fd[1]);
		printf("Filho a receber dados\n");
		while(read(fd[0],buffer,1)){
			write(f,buffer,1);
		}
		printf("Dados recebidos\n");
		execlp("wc","wc","teste.txt",NULL);
		perror("Algo correu mal");
		exit(-1);
	}
	else{
		close(fd[0]);
		printf("Pai a enviar dados\n");
		while(read(0,buffer,1)){
			write(fd[1],buffer,1);
		}
		printf("Dados enviados\n");
		close(fd[1]);
		exit(0);
	}
	return 0;
}
*/

int main(int argc, char const *argv[])
{
	char buffer[1024];
	int fd[2],x;
	int f = open("teste.txt",O_CREAT|O_WRONLY|O_RDONLY|O_APPEND,0777);
	pipe(fd);
	x = fork();
	if(x==0){
		close(fd[1]);
		printf("Filho a receber dados\n");
		while(read(fd[0],buffer,1)){
			write(f,buffer,1);
		}
		printf("Dados recebidos\n");
		execlp("wc","wc","teste.txt",NULL);
		perror("Algo correu mal");
		exit(-1);
	}
	else{
		close(fd[0]);
		printf("Pai a enviar dados\n");
		while(read(0,buffer,1)){
			write(fd[1],buffer,1);
		}
		printf("Dados enviados\n");
		close(fd[1]);
		exit(0);
	}
	return 0;
}

//Exercício Extra
/*
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
			execlp("wc","wc","teste.txt",NULL);
			_exit(status);
		}
	}
	for(z=0;z<10;z++){
		wait(&status);
		//exit = WEXITSTATUS(status);
		//printf("PAI -- FILHO: %d - CÓDIGO SAÍDA: %d\n", exit,exit);
	}
}
*/
//OS EXERCÍCIOA QUE FALTAM SÃO BONS PARA PREPARAÇÃO PARA O TESTE
//LOGO SÓ OS FAÇO NESSA ALTURA