#include <stdio.h>
int main()
{
  int i,j,k,compteur;

  printf("Entrez 2 nombres: ");
  scanf("%d %d",&i,&j);

  compteur=0  ;
  do
  {
    k=i%j;
    i=j  ;
    j=k  ;
    compteur++ ;
  }
  while (j!=0) ;

  printf("Resultat:%d\n",i) ;
}
