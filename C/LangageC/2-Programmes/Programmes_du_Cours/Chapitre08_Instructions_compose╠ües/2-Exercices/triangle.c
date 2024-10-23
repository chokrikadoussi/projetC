#include <stdio.h>
#define MILIEU 41

int main()
{
  int nbespaces, nbetoiles, N ;
  int ligne,j                 ;

  printf("Entrez le nombres de lignes:");
  scanf("%d",&N);
  
  for (ligne=1 ; ligne<N+1 ; ligne++)
  {
    /* --- dessine MILIEU-ligne espaces --- */
    for (nbespaces=1 ; nbespaces < MILIEU-ligne+1 ; nbespaces++)
        printf(" ");
    /* --- dessine  (2*ligne)-1  etoiles --- */
    for (nbetoiles=1 ; nbetoiles < (2*ligne) ; nbetoiles++)
        printf("*");
    /* --- saut de lignes --- */
    printf("\n");
  }
}
