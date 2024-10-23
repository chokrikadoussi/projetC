#include <stdio.h>

#define DEBUG 0

#define PI 3.14
#define MESSAGE "BONJOUR"
#define max(a,b) ((a) > (b) ? (a) : (b))

int main()
{
 int i,j,k ;
  
 printf("Message : %s\n",MESSAGE);
 
 i=1;
 j=10;
 k=max(i,j);
 
 printf("PI=%f   max=%d\n",PI,k);

 #if DEBUG
 printf("DEBUG =1\n");
 #endif
}
