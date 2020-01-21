#include <stdio.h>
#include <stdlib.h>

struct oggetto {
    int tipo; 
    int peso; 
    int valore; 
};

typedef struct oggetto *Oggetto; 

int main (void) {
    int i; 
    int val = 0, pesomax, peso = 0; 

    Oggetto o1 = malloc(sizeof(struct oggetto));
    Oggetto o2 = malloc(sizeof(struct oggetto));
    Oggetto o3 = malloc(sizeof(struct oggetto));


    o1->tipo = 1; 
    o1->peso = 5;
    o1->valore = 2;

    o2->tipo = 2;
    o2->peso = 3;
    o2->valore = 3;

    o3->tipo = 3;
    o3-> peso = 7;
    o3->valore = 8; 


    pesomax = 20; 

    int *valoremax = calloc(pesomax,sizeof(int));

    for (i=0; i < 4; i++) {
        val = valoremax[i] +  o1->valore;
        peso = i + o1 ->peso;
        if (valoremax[peso] <= val && peso <= pesomax)
            valoremax[peso] = val; 

        val = valoremax[i] +  o2->valore;
        peso = i + o2 ->peso;
        if (valoremax[peso] <= val && peso <= pesomax)
            valoremax[peso] = val; 

        val = valoremax[i] +  o3->valore;
        peso = i + o3 ->peso;
        if (valoremax[peso] <= val && peso <= pesomax)
            valoremax[peso] = val; 
    }

    for (i=0; i<20; i++)
        printf("%d ",valoremax[i]);
}


