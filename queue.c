#include <stdio.h>
#include <stdlib.h>
#include "reverse.c"

struct queue {
    Node inizio;
    Node fine; 
};

typedef struct queue *Queue; 

Queue queue_init() {
    Queue q = malloc(sizeof(struct queue));
    q ->inizio = NULL;
    q->fine = NULL; 
    return q; 
}

void enqueue(Queue q, int elemento) {
    Node new = new_node(elemento);

    Node curr;
    if (q->inizio == NULL) {
        q->inizio = new;
        q->fine = new; 
    } else {
        for (curr = q->inizio; curr->next; curr = curr->next);
        curr-> next = new; 
        q -> fine = new; 
    }
}

/*faccio ritornare un valore -1 in caso di errore: da questo momento in poi assumerò che alle città non possano essere associati dei
valori negativi */
int dequeue(Queue q) {
    int elemento; 
    if (q->inizio == NULL)
        return -1;
    
    elemento = q->inizio->val; 
    //Node curr = q->inizio; 
    q->inizio = q->inizio->next;
    //free(curr);

    if (q->inizio == NULL)
        q->fine = NULL; 

    return elemento; 
}

int isEmpty(Queue q) {
    return (q->inizio == NULL);
}

/*int main (void) {
    Queue q = queue_init();
    enqueue(q,2);
    printf("%d\n",q->inizio->val);
    enqueue(q,5);
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    enqueue(q,4);
    printf("%d\n",dequeue(q));
}
*/