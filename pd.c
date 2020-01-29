#include <stdio.h>
#include <stdlib.h>
#include "reverse.c"

struct graph {
    Node *A; 
    int n,m; 
};

typedef struct graph *Graph; 

Graph graph_init(int n);
void graph_insert(Graph g, int v, int w);

int main (void) {
    int a, b, n, m, i; 
    int v,w; 
    Graph g;

    printf("Inserire numero nodi: \n");
    scanf("%d",&n);
    g = graph_init(n);

    printf("Inserire numero archi: \n");
    scanf("%d",&m);
    g->m = m;

    scanf("%d->%d",&v,&w);
    graph_insert(g,v,w);
    printf("%d\n",g->A[0]->val);
}

/*
Il grafo è implementato attraverso una lista di adiacenza. Ogni città corrisponde a un intero, un arco tra due interi corrisponde a un collegamento
attraverso una qualunque linea tra due città. Il grafo andrebbe colorato e quindi etichettato per specificare che si tratta di diverse 
tipologie di archi, ma qui per ragioni di semplicità di implementazione (e per il fatto che a livello di percorso più breve non serve
indicare per quale linea passo) ho scelto di rappresentare gli archi come uno uguale all'altro.
*/
Graph graph_init(int n) {
    Graph g = malloc(sizeof(struct graph));
    g -> A = calloc(n,sizeof(Node));
    g->n = n; 
    g -> m = 0; 
    return g; 
}

void graph_insert(Graph g, int v, int w) {
    list_insert(&(g->A[v]), w);
}

//void bfs()
