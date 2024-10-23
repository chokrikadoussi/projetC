/* --------- */
/*   bool1.c  */
/* --------- */
#include <stdio.h>

int main()
{
  /* --- declarations --- */
  int a,b,c ;
  int b1    ;

  /* --- instructions --- */
  printf("Entrez 3 entiers (ex: 21 44 12) :");
  scanf("%d %d %d",&a,&b,&c);

  b1 = (a < b) && (a <c) ;
  
  if (b1 == 1)
  {
    printf("(%d < %d) && (%d < %d) : VRAI \n",a,b,a,c);
  }
  else
  {
    printf("(%d < %d) && (%d < %d) : FAUX \n",a,b,a,c);
  }



}
