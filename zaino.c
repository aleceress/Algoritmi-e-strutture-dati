#include <stdio.h>
#include <stdlib.h>

struct oggetto {
    int tipo; 
    int peso; 
    int valore; 
};

typedef struct oggetto *Oggetto; 

Oggetto new(int tipo, int peso, int valore);
void opt(int **matrix, int i, int j, int n, Oggetto *oggetti);

int main (void) {
int i, j, k, newval; 
int val, peso, maxpeso = 10, n = 5; 
Oggetto *oggetti = calloc(n+1,sizeof(Oggetto));
oggetti[1] = new(1,3,3);
oggetti[2] = new(2,2,4);
oggetti[3] = new(3,5,4);
oggetti[4] = new(4,2,1);
oggetti[5] = new(5,6,7);

int **matrix = calloc(maxpeso+1,sizeof(int*));

for (i = 0; i<= maxpeso; i++)
    matrix[i] = calloc(n+1,sizeof(int));


for (i=0; i<=maxpeso; i++) {
    for (j=0; j<=n; j++)
        printf("%d ",matrix[i][j]);
    printf("\n");
}

printf("\n");

for (j=1; j<=n; j++) {
    for (i=1; i<=maxpeso; i++)
        if (oggetti[j]->peso > i)
            matrix[i][j] = matrix[i][j-1];
            else {
                newval = matrix[i-oggetti[j]->peso][j-1] + oggetti[j]->valore;
                if (newval > matrix[i][j-1])
                    matrix[i][j] = newval;
                    else
                        matrix[i][j] = matrix[i][j-1];       
            }
}

printf("\n");

for (i=0; i<=maxpeso; i++) {
    for (j=0; j<=n; j++)
        printf("%d ",matrix[i][j]);
    printf("\n");
}
printf("\n");

opt(matrix,maxpeso,n,n,oggetti);

printf("\n");

for (i=0; i<=maxpeso; i++) {
    free(matrix[i]);
}

free(matrix);

for (i=0; i<=n;i++) {
    free(oggetti[i]);
}

free(oggetti);

}

Oggetto new(int tipo, int peso, int valore) {
    Oggetto o = malloc(sizeof(struct oggetto));
    o->tipo = tipo; 
    o->peso = peso; 
    o->valore = valore; 
    return o;
}

void opt(int **matrix, int i, int j, int n, Oggetto *oggetti) {
    if (i > 0 && j > 0) {
        if (matrix[i][j] == matrix[i][j-1]) {
            opt(matrix, i, j-1,n,oggetti);
            } else {
                printf("%d ",j);
                opt(matrix, i-oggetti[j]->peso,n,n,oggetti);
            }
    }
}