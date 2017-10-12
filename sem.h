#include "threads.h"
#include <stdlib.h>

struct semaphore {
	int val;
	Queue *q;
};
