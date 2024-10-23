#include <stdio.h>
#define MILIEU 41

void triangle(int NbL);

int main()
{
  int  NbTriangles, i ;


  printf("Entrez le nombres de triangles:");
  scanf("%d",&NbTriangles);
  
  for (i=0;i<NbTriangles;i++)
        triangle(i+3);
}

void triangle(int NbLignes)
{ 
  int nbespaces, nbetoiles ;
  int ligne                ;
 
  for (ligne=1 ; ligne<NbLignes+1 ; ligne++)
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
