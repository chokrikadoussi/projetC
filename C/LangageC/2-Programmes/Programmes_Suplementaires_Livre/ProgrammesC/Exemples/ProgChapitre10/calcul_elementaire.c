/* -------------------- */
/* calcul_elementaire.c */
/* -------------------- */
#include <stdio.h>
int main()
{
  int i,j,k,cpt;

  printf("Entrez 2 nombres: ");
  scanf("%d %d",&i,&j);

  cpt=0  ;
  while (j!=0) ;
  {
    k=i%j;
    i=j  ;
    j=k  ;
    cpt++ ;
  }
  printf("Resultat:%d\n",i) ;
}

