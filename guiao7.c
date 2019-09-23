#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /*O_RDONLY, O_WRONLY, O_CREAT, O_* */ /*Dá permissão ao user*//*|S_IRGRP|S_IROTH);*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
typedef void (*sighandler_t) (int);

int tempo = 0;
int click = 0;

void tempoPassado(){
	tempo++;
	alarm(1);
}

void imprimetempo(){
	click++;
	printf("\nPassaram %d segundos desde o ínicio do programa\n", tempo);
}

void sair(){
	printf("\nO programa correu durante %d segundos, e foram carregadas %d vezes em Crtl-C\n", tempo, click);
	exit(0);
}

//Exercíco 1
int main(int argc, char const *argv[])
{
	signal(SIGALRM,tempoPassado);
	signal(SIGQUIT,sair);
	signal(SIGINT,imprimetempo);
	alarm(1);
	while(1){
		pause();//suspende um processo enquanto fica à espera de sinais
		//Pode tecnicamente causar deadlocks
	}	
	return 0;
}