#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

struct graph {
    Node *A; 
    int n,m; 
};

typedef struct graph *Graph; 

Graph graph_init(int n);
void graph_insert(Graph g, int v, int w);
void print_graph(Graph g);
int bfs(Graph g, int v, int w);
int dfs(Graph g, int v);

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

    for (i=0; i<m; i++) {
        scanf("%d->%d",&v,&w);
        graph_insert(g,v,w);
    }

    print_graph(g);
    printf("%d\n",bfs(g,2,4));

    printf("\n");
    printf("%d\n",dfs(g,1));
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

//Il grafo che voglio rappresentare è non orientato, dunque se inserisco un nodo va inserito anche il simmetrico
void graph_insert(Graph g, int v, int w) {
    list_insert(&(g->A[v]), w);
    list_insert(&(g->A[w]), v);
}

void print_graph(Graph g) {
    int i; 
    Node curr;

    for (i=0; i< g->n; i++) {
        printf("%d: ",i);
        for (curr = g->A[i]; curr; curr = curr -> next)
            printf("%d ", curr->val);
        printf("\n");
    }
}

/*funzione che, attraverso una visita in ampiezza, ritorna la lunghezza del percorso più breve da un vertice A al vertice B 
e stampa i vertici da attraversare per ottenere questo percorso.
*/
int bfs(Graph g, int v, int w) {
    int x; 
    int *aux = calloc(g->n,sizeof(int));
    int *profondita = calloc(g->n,sizeof(int));
    int *path = calloc(g->n,sizeof(int));
    int p = w; 
    Node curr; 

    Queue q = queue_init();
    enqueue(q,v);
    while (!isEmpty(q)) {
        x = dequeue(q);
        aux[x] = 1;
        printf("%d ",x);
        if (x == w)
            break; 
        for (curr=g->A[x]; curr; curr = curr->next) {
            if (!aux[curr->val]) {
                enqueue(q,curr->val);
                profondita[curr->val] = profondita[x]++; //la profondità nel momento in cui arrivo a un nodo sarà quella del nodo da cui sono arrivato precedentemente +1
                path[curr->val] = x; 
            }
        }
    }
    printf("\n");

    //mi salvo il "nodo da cui sono arrivato" in un array a parte e poi lo ripercorro a ritroso
    while (path[p] != 0) {
        printf("%d ",path[p]);
        p = path[p];
    }
    
    printf("\n");

    return profondita[w];
}

/*funzione che, attraverso una visita in profondità, ritorna la lunghezza del percorso più breve per tornare dal vertice A a 
se stesso (se esiste), altrimenti ritorna -1. Stampa i vertici da attraversare per ottenere questo percorso, ovvero la sua componente
fortemente connessa.
*/

void dfs1(Graph g, int v, int *aux, int *ccc) {
    Node curr; 
    aux[v] = 1; 
    for (curr = g->A[v];curr;curr = curr->next) {
        if (!aux[curr->val]) {
            printf("%d\n",curr->val);
            (*ccc)++;
            dfs1(g,curr->val,aux,ccc);
        }
    }
}

int dfs(Graph g, int v) {
    int ccc = 1; 
    int *aux = calloc(g->n, sizeof(int));
    printf("%d\n",v);
    dfs1(g,v,aux,&ccc);
    if (ccc != 0)
        return ccc;
        else 
            return -1;
}