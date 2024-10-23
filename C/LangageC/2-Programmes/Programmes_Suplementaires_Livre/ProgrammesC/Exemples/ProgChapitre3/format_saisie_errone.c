/* ----------------------- */
/* format_saisie_erronne.c */
/* ----------------------- */
#include <stdio.h>

int main()
{
  int i,j,k ;

  /* format de saisie correct */
  printf("Entrez deux entiers : ");
  scanf("%d %d",&i,&j);

  /* format de saisie errone: absence du & */
  printf("Entrez un entier : ");
  scanf("%d",k);
}
