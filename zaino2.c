#include <stdio.h>
#include <stdlib.h>

struct oggetto {
    int tipo; 
    int peso; 
    int valore; 
};

typedef struct oggetto *Oggetto; 

Oggetto new(int tipo, int peso, int valore);

int main (void) {
int i, j, k; 
int val, peso, maxpeso = 10; 
Oggetto *oggetti = calloc(5,sizeof(Oggetto));
oggetti[0] = new(1,3,3);
oggetti[1] = new(2,2,4);
oggetti[2] = new(3,5,4);
oggetti[3] = new(4,2,1);
oggetti[4] = new(5,6,7);

int **matrix = calloc(5,sizeof(int*));

for (i = 0; i<5; i++)
    matrix[i] = calloc(maxpeso,sizeof(int));

for (k=0; k<5; k++) {
    for (j=0; j<4; j++) {
        for (i=0; i<maxpeso;i++) {
            val = matrix[i][j] + oggetti[k]->valore;
            peso = i + oggetti[k]->peso; 
            if (peso <= i)
                matrix[i][j+1] = val; 
            if (peso<= maxpeso)
                matrix[peso-1][j+1] = val;
        }
    }
}

for (i=0; i<maxpeso; i++) {
    for (j=0; j<5; j++)
        printf("%d ",matrix[i][j]);
    printf("\n");
}

}

Oggetto new(int tipo, int peso, int valore) {
    Oggetto o = malloc(sizeof(struct oggetto));
    o->tipo = tipo; 
    o->peso = peso; 
    o->valore = valore; 
    return o;
}