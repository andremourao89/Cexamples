/*Este programa cria N threads que alteram o conteúdo
de uma variável global. Como não estão sendo utilizados
mecanismos de sincronização, o conteúdo da variável
se tornará inconsistente ao executar o programa.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define NUM_THREADS 5

int x = 0 ;
int lock = 0;
bool waiting[NUM_THREADS];


void *threadBody (void *id){
   long tid = (long) id ;
	long j;
	int i;
	bool key;
	//Atualiza a variável global
	for (i=0;i<10000;i++){
	waiting[tid] = true;
	key = true;
	while(waiting[tid] && key)
		key = __sync_lock_test_and_set(&lock, 1);
	waiting[tid] = false;
        x++ ;
	j = (i + 1) % NUM_THREADS; //Inicia a busca no próximo
	while ((j != tid) && !waiting[j]) //Enquanto não encontrar
 		j = (j + 1) % NUM_THREADS; //Passa para o próximo
	if (j == tid) //Se não há processos esperando
 		lock = false; //Libera o recurso
	else
 		waiting[j] = false; //Libera o processo “j” do “while” na linha 4.
    }
   pthread_exit (NULL) ;
}

int main (int argc, char *argv[])
{
   pthread_t thread [NUM_THREADS] ;
   long i, status ;
   
   for (i=0; i<NUM_THREADS; i++) {
      status = pthread_create (&thread[i], NULL, threadBody, (void *) i) ;
  }
	for (i=0; i<NUM_THREADS; i++){
		   status = pthread_join (thread[i], NULL) ;
	}
	printf ("\n\nValor final de x: %02d\n\n", x) ;	
   pthread_exit (NULL) ;
}
