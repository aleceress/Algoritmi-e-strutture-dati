#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct intervallo {
        int i; 
        int f;
        int v; 
}; 

void ordinaIntervalli(struct intervallo *intervalli, int n); 
void scambia(int *a, int *b); 
int *createP(struct intervallo *intervalli, int n);

int main (void) {
    int numero_intervalli;
    int i, f, v, j;

    scanf("%d",&numero_intervalli); 
    
    struct intervallo *intervalli = malloc(numero_intervalli*sizeof(struct intervallo)); 

    for (j = 0; j< numero_intervalli;j++) {
        printf("%d\n", j); 
        scanf("%d-%d %d", &i, &f, &v);
        intervalli[j].i = i;
        intervalli[j].f = f; 
        intervalli[j].v = v; 
    }

    ordinaIntervalli(intervalli,numero_intervalli); 
    int *p = createP(intervalli, numero_intervalli);

    for (i=0; i<numero_intervalli;i++) 
        printf("%d ",p[i]); 
}

int *createP(struct intervallo *intervalli, int n) {
    int i, j, max; 
    int *p = calloc(n,sizeof(int)); 

    for (j=1; j<n;j++) {
        max = 0; 
        for (i=0; i < j; i++) {
            if ((intervalli[j].f <= intervalli[i].i || intervalli[j].i >= intervalli[i].f) && intervalli[i].v > max) {
                max = intervalli[i].v; 
                printf("%d\n", max);
                p[j] = i;  
                printf("ciao\n"); 
            }
        }
    }
    return p;
}


void scambia(int *a, int *b) { 
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ordinaIntervalli(struct intervallo *intervalli, int n) {
    int i, j; 
    for(i = 0; i < n - 1; i++) 
      for (j = n - 1; j > i; j--)
                  if (intervalli[j].f < intervalli[j-1].f) {
                          scambia(&intervalli[j].f, &intervalli[j-1].f); 
                          scambia(&intervalli[j].i, &intervalli[j-1].i); 
                          scambia(&intervalli[j].v, &intervalli[j-1].v); 
                  }
} 
