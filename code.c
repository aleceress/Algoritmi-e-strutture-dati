#include <stdlib.h>
#include <stdio.h>

struct queue {
    int *q; 
    int testaCoda;
    int fineCoda;     
}; 

struct queue *createqueue() {
    struct queue *coda = malloc(sizeof(struct queue));
    coda -> q = malloc(30*sizeof(int));
    coda -> testaCoda = 0;
    coda -> fineCoda = 0;
    return coda; 
}

void enqueue(struct queue *coda, int i) {
    coda -> q[coda ->fineCoda] = i; 
    coda -> fineCoda++;
}

int dequeue(struct queue *coda) {
    int elm = coda -> q[coda -> testaCoda]; 
    coda -> testaCoda++; 
    return elm; 
}

void destroyqueue(struct queue *coda) {
    free(coda -> q);
    coda -> testaCoda = 0; 
    coda -> fineCoda = 0; 
}

int emptyq(struct queue *coda) {
    return (coda ->testaCoda == coda ->fineCoda);
}
