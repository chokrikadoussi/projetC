/* -------- */
/* sapin2.c */
/* -------- */
#include <stdio.h>
#define MILIEU 41
/* declaration preliminaire */
int triangle (int PremL,int DernL) ;
/* ---- programme principal ---- */
main()
{
  int Nbtriangles , i ,debut, fin;

  printf("Entrez un nombre de triangles: ");
  scanf("%d",&Nbtriangles);
  for (i=0 ; i<Nbtriangles ; i++)
  {
      debut =i+1 ;
      fin   =i+3 ;
      triangle(debut,fin) ;
  }
}
/* ---- procedure triangle ---- */
 int triangle (int PremL,int DernL)
{
  int ligne, nbesp, nbet ;

  for (ligne=PremL ; ligne<DernL+1 ; ligne++)
  {
    for (nbesp=1 ; nbesp<(MILIEU-ligne+1) ; nbesp++)
         printf(" ") ;
    for (nbet=1 ; nbet < (2*ligne) ; nbet++)
         printf("*") ;
    printf("\n");
  }
}

