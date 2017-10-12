#include "threads.h"
#include <stdlib.h>

struct semaphore {
	int val;
	Queue *q;
};

void InitSem(semaphore sem, int x) {
	val = x;
}
