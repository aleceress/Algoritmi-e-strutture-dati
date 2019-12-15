#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "code.c"
#include "graph.h"

struct graph {
    int n,m; 
    int **A; 
}; 

void dfs1(Graph g, int i, int *aux);
void dfs(Graph g);
void bfs(Graph g);
void bfs1(Graph g, int i, int *aux); 

int main (void) {
    Graph g = graph_read(); 
    graph_print(g); 
    bfs(g); 
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

void dfs1(Graph g, int i, int *aux) {   
    int j;
    for (j=0;j< g->n; j++) {
        if (g->A[i][j] &&  (!aux[i])) {
            printf("%d ",i);
            aux[i] = 1;
            dfs1(g,j,aux); 
        } 
    }  
}

void dfs(Graph g) {
    int i,j; 
    int *aux = calloc(g->n, sizeof(int)); 
    for (i=0;i< g->n; i++) {
        for (j=0;j< g->n; j++) {
            if (g->A[i][j] && !aux[i]) {
                printf("%d ",i);
                aux[i] = 1; 
                dfs1(g,j,aux);
            }
        }
    }
    
}

void bfs1(Graph g, int i, int *aux) {
    int x, j;
    struct queue *q = createqueue();
    enqueue(q,i);
    aux[i] = 1; 
    while (!emptyq(q)) {
        x = dequeue(q);
        for (j=0;j< g->n; j++) {
            if(g->A[x][j] && !aux[j]) {
                printf("%d",j); 
                enqueue(q,j);
                aux[j] = 1;
            }
        }
    }
}

void bfs(Graph g) {
    int i, j;
    int *aux = calloc(g->n,sizeof(int));
    for (i=0;i< g->n; i++) {
        for (j=0;j< g->n;j++) {
            if (!aux[i] && g->A[i][j]) {
                printf("%d",i);
                bfs1(g,i,aux);     
            }        
        }
    }
}
