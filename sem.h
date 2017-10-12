#include "threads.h"
#include <stdlib.h>

typedef struct semaphore {
	int val;
	Queue *q;
}semaphore;

void InitSem(semaphore sem, int x) {
	sem.val = x;
}

int P(semaphore sem) {
	sem.val--;
	if(sem.val > 0) {
		return -1;
	}
	return 1;

}
