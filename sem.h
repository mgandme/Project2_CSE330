#include "threads.h"
#include <stdlib.h>

typedef struct semaphore {
	int val;
	Queue *q;
}semaphore;

void InitSem(semaphore sem, int x) {
	sem.val = x;
}

void P(semaphore sem) {
	if(sem.val > 0) {
		sem.val--;
	}
	else {
		P(sem);
	}
}

void V(semaphore sem) {
	sem.val++;
	if(sem.val <= 0) {
		TCB_t *temp;
		//call delete function from q.h
		temp = DelQueue(sem->q);
		//call addq from q.h to put deleted tcb into runq
		AddQueue(runQ, temp);
		//take pcb out of semaphore queue and puts it in the runQ
	}

}
