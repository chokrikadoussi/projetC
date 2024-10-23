/* ------------------- */
/* format_affichage.c  */
/* ------------------- */
#include <stdio.h>

int main()
{
  int i,j,k ;

  i = 10 ;
  j = 20 ;
  k = 30 ;
  /* format d'affichage correct */
  printf("%d %d %d\n",i,j,k);

  /* pas assez de codage dans le format */
  printf("%d %d\n",i,j,k);

  /* trop de codage dans le format */
  printf("%d %d %d %d\n",i,j,k);
}
