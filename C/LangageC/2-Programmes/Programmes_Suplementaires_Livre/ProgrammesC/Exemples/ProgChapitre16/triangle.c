/* ---------- */
/* triangle.c */
/* ---------- */
#include <stdio.h>
#define MILIEU 41

main()
{
  int nbespaces, nbetoiles, N ;
  int ligne,j                 ;

  printf("Entrez le nombre de lignes:");
  scanf("%d",&N);
  /* --- trace du triangle --- */
  for (ligne=1 ; ligne<N+1 ; ligne++)
  {
    for (nbespaces=1 ; nbespaces < MILIEU-ligne+1 ; nbespaces++)
        printf(" ");
    for (nbetoiles=1 ; nbetoiles < (2*ligne) ; nbetoiles++)
        printf("*");
    printf("\n");
  }
/* --- fin du trace --- */
}

