/* --------- */
/*   bool4.c  */
/* --------- */
#include <stdio.h>

int main()
{
  /* --- declarations --- */
  int a,b ;
  int b1  ;

  /* --- instructions --- */
  printf("Entrez 1 entier en decimal \n");
  printf("  puis 1 entier en octal (ex: 27553 377) :");
  scanf("%d %o",&a,&b);

  b1 = a & b ;
  
  printf("Le resultat de %d & %o est : %d \n",a,b,b1);




}
