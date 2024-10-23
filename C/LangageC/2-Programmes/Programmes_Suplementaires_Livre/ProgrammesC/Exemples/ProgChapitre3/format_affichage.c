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
  printf("Premier affichage: %d %d %d\n",i,j,k);

  /* pas assez de codages dans le format */
  printf("Deuxieme affichage: %d %d\n",i,j,k);

  /* trop de codages dans le format */
  printf("Troisieme affichage: %d %d %d %d\n",i,j,k);
}
