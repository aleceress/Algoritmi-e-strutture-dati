#include <stdio.h>
#include <stdlib.h>

struct node {
    int val; 
    struct node *next;
};

typedef struct node *Node; 

Node new_node(int n);
void list_insert(Node *l, int n);
void list_print(Node head);
void list_recursiveprint(Node head);
Node reverse(Node l);

/*
int main (void) {
Node new = new_node(1);
Node newlist = list_insert(new,3);
list_print(newlist);
printf("\n");
list_recursiveprint(newlist);
printf("\n");
Node pd = list_insert(newlist,5);
list_print(pd);
printf("\n");
Node prev = reverse(pd);
list_print(prev);
}
*/

Node new_node(int n) {
    Node new = malloc(sizeof(struct node));
    new->next = NULL;
    new->val = n;
    return new; 
}

void list_insert(Node *l, int n) {
    Node head = new_node(n);
    (*l)-> next = *l; 
    *l = head; 
}

void list_print(Node head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

void list_recursiveprint(Node head) {
    if (head != NULL) {
        list_recursiveprint(head->next);
        printf("%d ",head->val);
    }
}

Node reverse(Node l) {
    Node prev = NULL;
    Node curr = l; 
    Node next = l->next;

    while (curr != NULL) {
        curr ->next = prev; 
        prev = curr; 
        curr = next; 
        if (next != NULL)
            next = next->next; 
    }

    return prev; 
}
