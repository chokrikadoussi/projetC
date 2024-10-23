#include <stdio.h>
int main()
{
  int i,j,k,compteur;

  printf("Entrez 2 nombres: ");
  scanf("%d %d",&i,&j);

  compteur=0  ;
  k=-1;
  
  while (j!=0)
  {
    k=i%j;
    i=j  ;
    j=k  ;
    compteur++ ;
  }

  printf("Resultat:%d\n",i) ;
}
