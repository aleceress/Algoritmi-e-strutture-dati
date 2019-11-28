#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct occorrenza {
    char word[10];
    int n; 
};

#define Item struct occorrenza

struct bist_node {
    Item o; 
    struct bist_node *l;
    struct bist_node *r;
};

typedef struct bist_node *Bist_node;

int bist_searchparent (Bist_node r, char *k, Bist_node *parent , Bist_node p);
Bist_node bist_new(Item k); 
void bist_insert( Bist_node r, Item item);
void bist_orderprint(Bist_node p); 
void print_key(Bist_node p); 
void bist_invertedorderprint(Bist_node p);

int main (void) {
char s[] = "il cane il pesce il topo STOP"; 
int i; 
for (i=0; i< strlen(s); i++) {
    if (
}

}

Bist_node bist_new(Item k) {
    Bist_node new = malloc(sizeof(struct bist_node)); 
    new -> o = k; 
    new -> l = NULL; 
    new -> r = NULL; 
    return new; 
}

int bist_searchparent (Bist_node r, char *k, Bist_node *parent , Bist_node p) {
    int res;
    *parent = NULL;
    p = r;

    if(!r)
        return -1;  

    while(p && (res = strcmp(k, (p->o).word)!= 0)) {
        *parent = p;
        p = res < 0 ? p -> l : p -> r;
    }

    if (p == NULL)
        return -1;

    return 0; 
}


int bist_insert( Bist_node r, Item item) { 
    Bist_node parent = malloc(sizeof(struct bist_node)), q = r, new = bist_new(item);
    char *k = item.word;
    int res; 
    /* se l’albero e’ vuoto:*/
    if ( q == NULL ) {
        r = new;
        return 1; 
    } 
  
/* se la chiave c’e’ gia’ , non inserisco niente: */
    if (bist_searchparent (r, k, &parent,q ) == 0 ) {
        printf( "%s c’e’ gia’ \n",k);
        return 0; 
    }

/*altrimenti inserisco il nuovo nodo come figlio di parent:*/
    if ((res = strcmp(k, parent->o.word)) < 0) 
        parent -> l = new;
        else
            parent -> r = new;
    return 1; 
}

void bist_orderprint(Bist_node p) {
    if (p!= NULL) {
        bist_orderprint(p-> l); 
        print_key(p); 
        bist_orderprint(p->r); 
    }
}

void bist_invertedorderprint(Bist_node p) {
    if (p!= NULL) {
        bist_orderprint(p->r); 
        print_key(p); 
        bist_orderprint(p-> l); 
    }
}
    

void print_key(Bist_node p) {
    printf("%s\n", p->o.word); 
}