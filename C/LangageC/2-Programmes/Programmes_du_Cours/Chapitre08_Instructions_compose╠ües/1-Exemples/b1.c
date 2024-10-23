#include <stdio.h>

int main()
{
  int nb,base=3;

  do
  {
    printf("Entrez un nb :");
    scanf("%d",&nb);
    
    printf("%d x %d = %d\n",nb,base,nb*base);
  }
  while (nb != 0);


}
