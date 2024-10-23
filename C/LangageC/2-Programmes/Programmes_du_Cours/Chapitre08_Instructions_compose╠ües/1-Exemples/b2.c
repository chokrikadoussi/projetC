#include <stdio.h>

int main()
{
  int i,j,k;
  
  printf("Entrez 2 nombres:");
  scanf("%d %d",&i,&j);
  
  do
  {
    k=i%j;
    i=j;
    j=k;
  }
  while (j!=0);

  printf("le PGCD est:%d\n",i);


}
