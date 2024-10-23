/* --------- */
/* typedef.c */
/* --------- */
#include <stdio.h>

main()
{
  typedef unsigned char BIT8 ;
  typedef unsigned short int BIT16 ;
  typedef unsigned int BIT32 ;

  BIT8 i;
  BIT16 j;
  BIT32 k;

  i=1;
  j=2;
  k=3;
  printf("i=%d j=%d k=%d\n",i,j,k);
}
