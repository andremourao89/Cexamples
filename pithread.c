#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#define SIZE 100
const size_t numprocs = 4;
int *vet, maiores[4];
void* func(void * id){
	long ID=(long)id;
	pid_t tid;
	tid = syscall(SYS_gettid);
	printf("Thread: %ld(%d) - Process ID: %5d Pai:%5d\n",ID,tid,getpid(),getppid());
	unsigned int i;
	maiores[ID] = 0;
	for (i = ID + 1; i <= SIZE/(numprocs - ID); i += numprocs) {
		vet[i] = rand()%100;
		if(vet[i] > maiores[ID]){
			maiores[ID] = vet[i];
		}
	}
	pthread_exit(NULL);
}

int main(){
	int maior;
	pid_t tid;
	tid = syscall(SYS_gettid);
	printf("Thread: (%d) - Process ID: %5d Pai:%5d\n",tid,getpid(),getppid());

	//Idenficador de cada thread
	pthread_t handles[numprocs];
	/*Carrega os atributos padrões para criação
	 das threads. Dentre os atributos, estão:
	prioridade no escalonamento e tamanho da pilha.*/
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	//Cria as threads usando os atributos carregados.
	long i;
	vet = (int *) malloc(SIZE * sizeof(int));
	for (i = 0; i < numprocs; i++){
		pthread_create(&handles[i], &attr, func, (void*)i);
	}
	// Espera todas as threads terminarem.
	for (i = 0; i != numprocs; ++i)
		pthread_join(handles[i], NULL); //NULL -> parâmetro de retorno
	/* Soma o resultado de cada thread.
	Observe que cada thread escreve em uma posição
	do vetor de resultados (o que evita inconsistência).*/
	printf("Vetor:\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ",vet[i]);
	printf("\nMaiores:\n");
	for (i = 0; i < numprocs; ++i)
		printf("%d ",maiores[i]);

	maior = maiores[0];
	for (i = 0; i < numprocs; i++){
		if(maior < maiores[i]){
			maior = maiores[i];
		}
	}
	printf("\n Maior %d\n", maior);
	return 0;
}
