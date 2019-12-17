#include <stdio.h>
#include "graph.c"

Graph gen(float p, int n); 
int degree(Graph g,int v);
int dfspath(Graph g, int v, int w, int *camm);
int path(Graph g,int v, int w);
void cccdfs(Graph g, int i, int *cc, int id); 
int ccc(Graph G);

int main (void) {
    Graph g = graph_new(5);
    graph_edgeinsert(g,0,1);
    graph_edgeinsert(g,1,3);
    graph_edgeinsert(g,3,0);
    graph_edgeinsert(g,2,4);

    graph_print(g);
    //printf("%d\n",degree(g,3));
    printf("%d\n", ccc(g));
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

void cccdfs(Graph g, int i, int *cc, int id) {   
    int j;
    cc[i] = id;
    for (j=0;j< g->n; j++) {
        if (g->A[i][j] &&  (cc[j] == -1)) {
            cc[j] = id; 
            cccdfs(g,j,cc,id); 
        } 
    }  
}

int ccc(Graph g) {
    int i,j, id = 0; 
    int max; 
    int *cc = malloc(g -> n*sizeof(int));   
    for (int i = 0; i< g -> n; i++) 
        cc[i] = -1; 

    for (i=0;i< g->n; i++) {
        for (j=0;j< g->n; j++) {
            if (g->A[i][j] && cc[i] == -1) {
                cccdfs(g,j,cc,id++);
            }
        }
    }

    max = cc[0];
    for (i=1; i< g-> n; i++) {
        if (cc[i] > max)
            max = cc[i];
    }

    return max+1; 
} 

void ccdfs(Graph g, int i, int *cc, int id) {   
    int j;
    cc[i] = 1; 
    for (j=0;j< g->n; j++) {
        if (g->A[i][j] &&  (!cc[j])) {
            cc[j] = 1;
            ccdfs(g,j,cc,id); 
        } 
    }  
}

void cc(Graph g,int v) {
    int i,j; 
    int *cc = calloc(g -> n,sizeof(int));   

    for (j=0;j< g->n; j++) {
        if (g->A[v][j]) {
            ccdfs(g,j,cc,id++);
        }
    }

    for (i = 0; i< g-> n; i++) {
        if (g ->A[i]) 
            printf("%d",i);
    }
} 
