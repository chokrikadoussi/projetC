#include <stdio.h>
#include <string.h>

#include "sequences_echap.h"

int main()
{
  int lig, col        ;
  char deplacement_curseur_lig_col[20] ;
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  /* On sauvegarde la position du curseur */
  printf("Position sauvegardée -->");
//  printf("\033%d", 7);    // Sauvegarde la position du curseur : Esc7
  printf(SAUVE_POS);    // Sauvegarde la position du curseur : Esc7
  printf("\nEntrez un numéro de line entre 1 et 50 : ");
  scanf("%d",&lig);
  printf("Entrez un numéro de colonne entre 1 et 50 : ");
  scanf("%d",&col);
  /* On effectue le déplacement du curseur */
  sprintf(deplacement_curseur_lig_col,"\033[%d;%dH",lig,col)  ;
  printf("%s",deplacement_curseur_lig_col);
  printf("Déplacement effectué à la ligne %d colonne %d !\n", lig, col);
  /* On restaure la position du curseur */
  //printf("\033%d", 8);    // Restaure la position sauvegardée  : Esc8
  printf(RESTAURE_POS);    // Restaure la position sauvegardée  : Esc8
  printf("Position restaurée !\n");
}
