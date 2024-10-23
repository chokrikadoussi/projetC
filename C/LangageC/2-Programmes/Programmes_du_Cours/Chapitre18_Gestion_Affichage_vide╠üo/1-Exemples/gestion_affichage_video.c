#include <stdio.h>
int main()
{
  int nombre ;
  /* on pilote le terminal via son langage en SUITE D'ÉCHAPPEMENT */
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  /* Effacement de l'écran */
  printf("\033[2J");
  /* Déplacement curseur ligne 1 colonne 1 */
  printf("\033[1;1H");
  /* Début attributs multiples  de texte */
  /* Esc[30;43;1;5m = couleur de texte en noir (30) sur fond cyan (46) en gras (1)  et clignotant (5) */
  printf("\033[30;46;1;5m");
  printf("Entrez un entier quelconque : ");
  /* Fin des attributs de texte */
  printf("\033[0m");
  /* Début texte en Vert et Inverse vidéo */
  printf("\033[32;1m");
  /* Saisie du nombre */
  scanf("%d",&nombre);
  /* Fin des attributs de texte */
  printf("\033[0m");
  /* Début attributs Esc[31m = texte en rouge */
  printf("\033[31m");
  printf("Changement d'attributs effectué ! \n");
  /* Fin des attributs de texte */
  printf("\033[m");
}
