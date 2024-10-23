#include <stdio.h>
int main()
{
  int lig, col        ;
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  /* Effacement de l'écran */
  printf("\033[2J");
  /* Déplacement en lig 1 col 1 */
  printf("\033[1;1H");
  /* Saisie de la lig et de la col de déplacement */
  printf("Entrez un numéro de ligne entre 1 et 50 : ");
  scanf("%d",&lig);
  printf("Entrez un numéro de colonne entre 1 et 50 : ");
  scanf("%d",&col);
  printf("\033[%d;%dH",lig,col);
  printf("Déplacement effectué à la ligne %d colonne %d !\n", lig, col);
}
