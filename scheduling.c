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
int *ComputeOpt(int *p, int n, struct intervallo *intervalli);
void FindSolution(int j, int *opt, int *p, struct intervallo *intervalli); 


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

    for (j = 0; j< numero_intervalli;j++) {
        printf("%d ",intervalli[j].v);
    }

    printf("\n"); 

    int *p = createP(intervalli, numero_intervalli);

    for (i=0; i<numero_intervalli;i++) 
        printf("%d ",p[i]); 

    int *opt = ComputeOpt(p,numero_intervalli, intervalli);

    printf("\n"); 

    for (i=0; i<numero_intervalli;i++) 
        printf("%d ",opt[i]);

    printf("\n"); 

    FindSolution(numero_intervalli - 1, opt, p, intervalli); 
}

void FindSolution(int j, int *opt, int *p, struct intervallo *intervalli) {
    if (j!=0) {
        if (opt[j] + intervalli[j].v >= opt[j-1]) {
            printf("%d-%d %d\n", intervalli[j].i, intervalli[j].f, intervalli[j].v); 
            FindSolution(p[j], opt, p, intervalli); 
        } else {
            FindSolution(j-1, opt, p, intervalli); 
        }  
    }
}

int *ComputeOpt(int *p, int n, struct intervallo *intervalli) {
    int *opt = calloc(n,sizeof(int)); 
    int i; 
    for(i=1; i<n;i++) {
        if (intervalli[i].v + opt[p[i]] > opt[i-1])
            opt[i] = intervalli[i].v + opt[p[i]]; 
            else
                opt[i] = opt[i-1];
    }
    return opt; 
}

int *createP(struct intervallo *intervalli, int n) {
    int i, j, max; 
    int *p = calloc(n,sizeof(int)); 

    for (j=1; j<n;j++) {
        max = 0; 
        for (i=0; i < j; i++) {
            if ((intervalli[j].f <= intervalli[i].i || intervalli[j].i >= intervalli[i].f) && intervalli[i].v > max) {
                max = intervalli[i].v; 
                p[j] = i;  
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
    int i, ti, tf, tv; 
    int scambiato; 
    do { 
        scambiato = 0;
        for (i=1; i< n; i++) {
            if (intervalli[i].v < intervalli[i-1].v) {
                printf("ciao\n"); 
                scambia(&intervalli[i].i, &intervalli[i-1].i); 
                scambia(&intervalli[i].f, &intervalli[i-1].f); 
                scambia(&intervalli[i].v, &intervalli[i-1].v); 
                scambiato = 1; 
            }
        }
    } while (scambiato); 
} 
