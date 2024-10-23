#include <stdio.h>

int main()
{
  int i,j,res;
  
  for (i=1 ; i<13; i++)
  {
    printf("---Table de %d ---\n",i);
    for (j=1 ; j<11 ; j++)
    {
      res=i*j;
      printf("%4d",res);
    }
    printf("\n");
  }
}
