/* --------- */
/*   bool3.c  */
/* --------- */
#include <stdio.h>

int main()
{
  /* --- declarations --- */
  int a,b ;
  int b1  ;

  /* --- instructions --- */
  printf("Entrez 2 entiers (ex: 27553 255) :");
  scanf("%d %d",&a,&b);

  b1 = a & b ;
  
  printf("Le resultat de %d & %d est : %d \n",a,b,b1);




}
