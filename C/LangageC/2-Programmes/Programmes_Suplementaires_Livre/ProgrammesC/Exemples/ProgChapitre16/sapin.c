/* ------- */
/* sapin.c */
/* ------- */
#include <stdio.h>
#define MILIEU 41
/* -------PROGRAMME PRINCIPAL--------- */
main()
{
  int Nbtriangles , i ;

  printf("Entrez un nombre de triangles: ");
  scanf("%d",&Nbtriangles);
  for (i=0 ; i<Nbtriangles ; i++)
      triangle(i+3) ;
}
/* ------------TRIANGLE--------------- */
int triangle (int NbLignes)
{
  int ligne, nbesp, nbet ;

  for (ligne=1 ; ligne<NbLignes+1 ; ligne++)
  {
    for (nbesp=1 ; nbesp<(MILIEU-ligne+1) ; nbesp++)
         printf(" ") ;
    for (nbet=1 ; nbet < (2*ligne) ; nbet++)
         printf("*") ;
    printf("\n");
  }
}
/* ------------------------------------ */

