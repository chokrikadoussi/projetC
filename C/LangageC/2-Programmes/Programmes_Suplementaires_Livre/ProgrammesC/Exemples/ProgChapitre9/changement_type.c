/* ----------------- */
/* changement_type.c */
/* ----------------- */
#include <stdio.h>
int main()
{
 int i,j ;
 float x ;
 i=4;
 j=3;
 x=i/j;
 printf("sans changement de type : %d/%d = %f\n",i,j,x);
 x=((float)i)/j;
 printf("avec changement de type : %d/%d = %f\n",i,j,x);
}
