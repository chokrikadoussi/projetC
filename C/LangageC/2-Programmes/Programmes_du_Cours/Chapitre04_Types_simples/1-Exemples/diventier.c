#include <stdio.h>

int main()
{
  int a,b,c,d ;
  
  float x,y,z ;
  
  a=9;
  b=4;
  
  c=a/b;
  d=a%b;

  printf("%d / %d = %d \n",a,b,c);
  printf("reste de %d par %d = %d \n",a,b,d);
   
  z=a/b;
  printf("%d / %d = %f \n",a,b,z);

  x=9;
  y=4;
  z=x/y;
  printf("%f / %f = %f \n",x,y,z);

}
