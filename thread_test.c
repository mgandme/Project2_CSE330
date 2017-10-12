//@Ryan Patterson

#include "threads.h"
#include <stdlib.h>
#include <unistd.h>
int globalVar = 0;
void funct1();
void funct2();
void funct3();
void funct4();
void funct5();

int main() {
	runQ = (Queue*) malloc(sizeof(Queue));
	start_thread(funct1);
	start_thread(funct2);
	start_thread(funct3);
	start_thread(funct4);
	start_thread(funct5);


run();
	return 0;
}

void funct1() {
	int i = 0;
	int j = 0;
	while(i == 0) {
		j++;
		yield();
		printf("%d\n", j);
		sleep(1);
	}

}

void funct2() {
	int i = 0;
	int j = 0;
	for(i = 0; i >= 0; i++ ) {
		j--;
		yield();
		printf("%d\n", j);
		sleep(1);
	}

}

void funct3() {
	int i, key, j, k;
	int n = 10;
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	for (i = 1; i < n; i++) {
        	key = arr[i];
        	j = i-1;

       		/* Move elements of arr[0..i-1], that are
          	greater than key, to one position ahead
          	of their current position */
        	while (j >= 0 && arr[j] > key) {
           		arr[j+1] = arr[j];
           		j = j-1;
       		}
		arr[j+1] = key;
		printf("Insertion sort array: ");
		for(k = 0; k < n; k++) {
			printf("%d ", arr[k]);
		}
		if(i == n - 1) {
			for(i = 0; i < n; i++) {
				arr[i] = n - i;
			}
			i = 1;

		}
		printf("\n");
		yield();
		sleep(1);
   	}
}

void funct4() {
	int i = 0;
	while(i == 0) {
		globalVar = globalVar * globalVar;
		printf("Global var ^ 2: %d\n", globalVar);
		yield();
		sleep(1);
	}
}

void funct5() {
	int j = 0;
	while(j < 1) {
		globalVar = globalVar + 1;
		printf("Global var + 1: %d\n", globalVar);
		yield();
		sleep(1);
	}
}
