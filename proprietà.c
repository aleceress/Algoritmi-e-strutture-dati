#include <stdio.h>
#include "graph.c"

Graph gen(float p, int n); 
int degree(Graph g,int v);
int dfspath(Graph g, int v, int w, int *camm);
int path(Graph g,int v, int w);

int main (void) {
    Graph g = gen(0.2,4);
    graph_print(g);
    //printf("%d\n",degree(g,3));
    printf("%d\n",path (g,1,3));
}

Graph gen(float p, int n) {
    int i, j;
    float prob; 
    Graph g; 
    g = graph_new(n);

    for (i =0; i<n;i++) {
        for (j=0;j<n;j++) {
            if (i == j)
                continue;
            prob = ((float) rand()) / (float) RAND_MAX;
            if (prob < p)
                graph_edgeinsert(g,i,j);
        }
    }
    return g; 
}

int degree(Graph g,int v) {
    int deg = 0,j;
    for (j=0;j< g-> n; j++) {
        if (g -> A[v][j] == 1)
        deg++;
    }
    return deg; 
}

int dfspath(Graph g, int v, int w, int *camm) {
    int j; 
    for (j=0;j< g-> n;  j++) {
        if (g-> A[v][j] && !camm[j]) {
            if (j== w) 
                return 1; 
        camm[j] = 1; 
        dfspath(g,j,w,camm); 
        }
    }
}

int path(Graph g,int v, int w) {
    int j; 
    int *camm = calloc(g->n, sizeof(int)); 
    camm[v] = 1; 
    for (j = 0; j< g -> n; j++) {
        if(g-> A[v][j] && !camm[j]) {
            if (j == w) {
                return 1;
            }
            camm[j] = 1; 
            return dfspath(g,j,w,camm); 
        }
    }
    return 0; 
}
