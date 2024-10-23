/* ---------- */
/* premier1.c */
/* ---------- */
#include <stdio.h>
#include <math.h>

int main()
{
  int nb, diviseur1, diviseur2,reste  ;
  int trouve,i ,racinecar,limite      ;
  int nb_iterations=1, choix;

  printf("Entrez un Nombre :");
  scanf("%d",&nb);
  printf("Limite de la recherche ?\n");
  printf("-1- jusqu'au nombre\n");
  printf("-2- jusqu'