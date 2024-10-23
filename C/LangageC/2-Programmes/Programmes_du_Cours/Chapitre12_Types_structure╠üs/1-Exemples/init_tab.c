#include <stdio.h>
int main()
{
  int image[2][3]={
      0,0,0,
      1,1,1 };
      
  int i,j;
  
  for (i=0;i<2;i++)
  {
    printf("i=%d => ",i);
    for (j=0;j<3;j++)
      printf("%d",image[i][j]);
    printf("\n");
  }
}
