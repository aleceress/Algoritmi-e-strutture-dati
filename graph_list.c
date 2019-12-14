#include "graph.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct listnode {
    int v;
    struct listnode *next;
}; 

struct graph {
    int V; 
    int E; 
    struct listnode **A;
}; 

void dfs1(Graph g, int i, int *aux);
void dfs(Graph g); 

int main (void) {
Graph g = graph_read();
graph_print(g); 
dfs(g);
}

Graph graph_new(int n) {
  Graph g = malloc(sizeof(struct graph));
  g -> V = n; 
  g -> A = calloc(n,sizeof(struct listnode*)); 
  return g; 
}

void graph_edgeinsert(Graph g,int v,int w) {
    struct listnode *new = malloc(sizeof(struct listnode));
    new -> v = w; 
    new -> next = g -> A[v]; 
    g -> A[v] = new; 
}

void graph_destroy(Graph g) {
    free(g -> A); 
    free(g);
}

Graph graph_read(void) {
    int n, v= 0, w= 0; 
    char c; 
    Graph g; 
    printf("Inserire numero vertici: "); 
    scanf("%d",&n);  
    g = graph_new(n); 
    printf("Inserire archi (formato a -> b), -1 per terminare):\n"); 

    while (1) {
        scanf("%d", &v);
        if (v == -1)
            break; 

        while (!isalnum((c= getchar()))) {
            continue; 
        }
        w = c - '0';

        graph_edgeinsert(g,v,w); 
    } 
    return g; 
}

void graph_print(Graph g) {
    int i; 
    struct listnode *l; 
    for (i=0; i< g -> V; i++) {
        l = g -> A[i];
        while (l != NULL) {
        printf("%d -> %d\n", i , l -> v); 
        l = l-> next; 
        }
    }
}

void dfs1(Graph g, int i, int *aux) {
    struct listnode *t;
    aux[i] = 1;
    for(t = g->A[i]; t; t = t->next)
        if(!aux[t->v]) {
            printf("%d,",t->v);
            dfs1(g,t->v,aux);
        }
}

void dfs(Graph g) {
    int i, *aux = calloc(g->V,sizeof(int));
    if(!aux) { 
        fprintf(stderr,"Errore di Allocazione\n"); 
        exit(-4);
        }
    for(i = 0; i < g->V; i++)
        if(!aux[i]) {
            printf("\n%d,",i);
            dfs1(g,i,aux);
        }
    free(aux);
}
