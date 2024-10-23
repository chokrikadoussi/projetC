#include <stdio.h>
#define MILIEU 41

void triangle(int PL, int *DL);

int main()
{
  int  NbTriangles, i, debut, fin ;


  printf("Entrez le nombres de triangles:");
  scanf("%d",&NbTriangles);
  
  for (i=0;i<NbTriangles;i++)
  {
        debut=i+1;
        fin=i+3  ;
        triangle(debut,&fin);
  }
        
  printf("debut=%d   fin=%d\n",debut,fin);
}

void triangle(int PremL,int *DernL)
{ 
  int nbespaces, nbetoiles ;
  int ligne                ;
 
  for (ligne=PremL ; ligne<*DernL+1 ; ligne++)
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
  *DernL=58;
  printf("DernL=%d\n",*DernL);
}
