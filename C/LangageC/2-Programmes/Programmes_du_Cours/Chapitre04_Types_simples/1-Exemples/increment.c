#include <stdio.h>

int main()
{
 int i,j,k;
 
 i=1 ;
 j=++i;
 printf("j=++i : j=%d  i=%d\n",j,i);
 k=j++;
 printf("k=j++ : k=%d  j=%d\n",k,j);

 k+=j; 		/* k=k+j */
 printf("k+=j  %d\n",k);
 
  k*=j;		/* k=k*j */
 printf("k*=j  %d\n",k);

}
