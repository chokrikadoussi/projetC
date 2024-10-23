/* ------------------- */
/* boucle_sans_break.c */
/* ------------------- */
#include <stdio.h>
#include <ctype.h>

int main()
{
 int i,j ;
 char car='o', bidon ;

 while (car != 'n')
 {
  printf("Entrez deux entiers :");
  scanf("%d %d",&i,&j);
  printf("La somme est :%d\n",i+j);
  bidon=getchar(); /* on vide le buffer */
  printf("Continuer (o/n) ?");
  car=getchar() ;
 }
}
