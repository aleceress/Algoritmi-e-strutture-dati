#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

struct graph {
    int n,m; 
    int **A; 
}; 

int main (void) {
    Graph g = graph_read(); 
    graph_print(g);  
}

Graph graph_new(int n) {
    Graph g = malloc(sizeof(struct graph)); 
    g -> A = calloc(n,sizeof(int*)); 
    int i; 
    for (i=0; i<n;i++)
        g -> A[i] = calloc(n,sizeof(int)); 
    g -> n = n; 
    return g; 
}

void graph_destroy(Graph g) {
    free(g -> A); 
    free(g); 
}

void graph_edgeinsert(Graph g, int v,int w) {
    g -> A[v][w] = 1;
    g -> A[w][v]= 1; 
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
    int i, j; 
    for (i= 0; i< (g ->n); i++) {
        for (j=0; j< (g-> n); j++) {
            if ((g->A[i][j]) == 1) 
                printf("%d -> %d\n",i,j);
        }
    }
}

