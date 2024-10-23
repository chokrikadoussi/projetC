#include <stdio.h>
#define MILIEU 41
int main()
{
  int Nb, ligne, nbesp, nbet;
  printf("Entrez un nombre de lignes: ");
  scanf("%d",&Nb);
  for (ligne=1 ; ligne<Nb+1 ; ligne++)
  {
    for (nbesp=1 ; nbesp<(MILIEU-ligne+1) ; nbesp++)
         printf(" ") ;
    for (nbet=1 ; nbet < (2*ligne) ; nbet++)
         printf("*") ;
    printf("\n");
  }
}
