typedef struct graph *Graph;

/*crea un grafo con n nodi*/
Graph graph_new(int n); 

/*inserisce l’arco (v,w) nel grafo g*/
void graph_edgeinsert(Graph g,int v,int w);

/*distrugge il grafo g*/
void graph_destroy(Graph g); 

/*legge da standard input un grafo nel formato a -> b dove (a,b) appartiene all'insieme degli archi
del grafo*/
Graph graph_read(void);

/*stampa su standard output un grafo (specificare il formato!!)*/
void graph_print(Graph g);