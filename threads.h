#include "q.h"
#define STACK_SIZE 8192
Queue *runQ;

void start_thread(void (*function)(void)) {
	//allocate a stack of size 8192 (malloc)
        void *stack = malloc(STACK_SIZE);
	//allocate a tcb (malloc)
	TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t));
	//call init_TCB w/ appropriate args
	init_TCB(tcb, (void*)function, stack, STACK_SIZE);
	//call addQ to add this TCB into the runQ which is a global head pointer
	AddQueue(runQ, tcb);
}

void run() {
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &runQ->head->context);
}

void yield() {
	TCB_t *prevThread, *nextThread;
	prevThread = runQ->head;
	RotateQ(runQ);
	nextThread = runQ->head;
	swapcontext(&prevThread->context, &nextThread->context);
}
