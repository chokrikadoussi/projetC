#include <stdio.h>
#include <string.h>
int main()
{
  int valeur                  ;
  char deplacement_haut[20]   ;
  char deplacement_bas[20]    ;
  char deplacement_droite[20] ;
  char deplacement_gauche[20] ;

  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  /* Déplacement vers le bas */
  printf("Entrez un nombre de lignes de déplacement vers le bas : ");
  scanf("%d",&valeur);
  sprintf(deplacement_bas,"\033[%dB",valeur)  ;
  /* Déplacement à droite */
  printf("Entrez un nombre de colonnes de déplacement à droite : ");
  scanf("%d",&valeur);
  sprintf(deplacement_droite,"\033[%dC",valeur);
  /* Déplacement vers le haut */
  printf("Entrez un nombre de lignes de déplacement vers le haut : ");
  scanf("%d",&valeur);
  sprintf(deplacement_haut,"\033[%dA",valeur)  ;
  /* Déplacement à gauche */
  printf("Entrez un nombre de colonnes de déplacement à gauche : ");
  scanf("%d",&valeur);
  sprintf(deplacement_gauche,"\033[%dD",valeur);
  /* affichage des déplacements */
  printf("%sBas",deplacement_bas)      ;
  printf("%sDroite",deplacement_bas)   ;
  printf("%sHaut",deplacement_haut)    ;
  printf("%sGauche",deplacement_gauche);
  printf("\n");
}
