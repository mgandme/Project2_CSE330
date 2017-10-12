#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

typedef struct q_element {
	int val;
	struct q_element *next;
	struct q_element *prev;
}q_element;

typedef struct Queue {
	TCB_t *head;
	TCB_t *list;
}Queue;

void InitQueue(Queue *q) {
	q->head = NULL;
	q->list = NULL;
}

TCB_t* NewItem() {
	TCB_t *q = (TCB_t*) malloc (sizeof(TCB_t));
	q->next = q;
	q->prev = q;
	return q;
}

void AddQueue(Queue *q, TCB_t *item) {
	if(q->head == NULL) {
		q->list = item;
		q->head = q->list;
		item->next = item;
		item->prev = item;
	}

	else {
		TCB_t *temp = q->head->prev;
		item->next = q->head;
		item->prev = q->head;
                temp->next = item;
                q->head->prev = item;
	}
}

TCB_t* DelQueue(Queue* q) {
	TCB_t *item = NULL;
	if(q->head == NULL) {
		return NULL;
	}
        else {
                item = q->head;
                TCB_t *temp1 = q->head->prev;
                TCB_t *temp2 = q->head->next;
                if(q->head == q->head->next) {
                        q->head = NULL;
                }
                else {
                        temp1->next = temp2;
                        temp2->prev = temp1;
                        q->head = temp2;
                }

        }
        return item;
}

void RotateQ(Queue *q) {
	q->head = q->head->next;
}
