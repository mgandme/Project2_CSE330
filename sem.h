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
		yield();//? maybe. . .
		//blocks the process in the queue associated with sem
	}
}

void V(semaphore sem) {
	sem.val++;
	if(sem.val <= 0) {
		//take pcb out of semaphore queue and puts it in the runQ
	}

}
