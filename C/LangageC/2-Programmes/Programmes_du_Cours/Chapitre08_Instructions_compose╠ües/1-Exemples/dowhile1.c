#include <stdio.h>

int main()
{
  int i ,base=3;
  
  do
  {
    printf("Entrez un entier (0=FIN):");
    scanf("%d",&i);
    
    printf("%d x %d = %d\n",i,base,i*base);
  }
  while (i!=0);
}
