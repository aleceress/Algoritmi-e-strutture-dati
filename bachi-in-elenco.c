#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef char *String;

typedef struct {
  int size;
  int count;
  String *content;
} *Elenco;


int main( void ) {
  Elenco b; //non va dichiarato puntatore a NULL se successivamente viene allocato con una malloc
  int i = 0;

  b = malloc(sizeof(Elenco));
  b -> size = 4;
  b -> count = 0;
  b -> content = calloc(b->size, sizeof(String));

  while(1) {
    char *name = calloc(N+1,sizeof(char)); 
    /*alloco la stringa come puntatore a carattere in modo da poterla allocare dinamicamente
    a ogni iterazione e assegnarla come nuova stringa all'array b ->content[i].
    Nella scrittura di prima, tutti i puntatori dell'array venivano fatti puntare alla medesima stringa,dunque una
    volta che queste veniva modificata veniva modificato il contenuto di tutti gli elementi dell'array.
    */
    scanf("%s", name);
    printf("%s\n",name);
    if (strcmp(name, "FINE") == 0)
        break; //il ciclo va terminato non appena viene letta la parola fine, altrimenti viene salvata nell'array come le altre

    b -> count++; // il count va incrementato ogni volta che si inserisce una nuova parola
    if ( b -> count == b -> size) {
      b -> size *= 2;
      b-> content = realloc (b-> content, b ->size*sizeof(String)); //se è b ->size ad essere incrementata, b ->size deve essere utilizzata nella realloc
    }

    b -> content[i] = name; 
    printf("%s\n",b->content[i]);
    i++;
  }

  for (int k = 0; k < b -> size; k++)
      printf( "%s\n", b -> content[k] );

  return 0;
}
