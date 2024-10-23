#include <stdio.h>
#include "sequences_echap.h"
int main()
{
  int nombre ;
  /* on pilote le terminal via son langage en SUITE D'ÉCHAPPEMENT */
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  /* Effacement de l'écran */
  printf(EFFACE_ECRAN(2));
  /* Déplacement curseur ligne 1 colonne 1 */
  printf(DEPLAC_CURSEUR_POS(1,1));
  /* Début attributs multiples  de texte */
  printf(TEXTE_NOIR);
  printf(FOND_CYAN);
  printf(TEXTE_ATTR(1));
  printf(TEXTE_ATTR(5));
  printf("Entrez un entier quelconque : ");
  /* Fin des attributs de texte */
  printf(EFFACE_ATTR);
  /* Début texte en Vert */
  printf(TEXTE_VERT);
  printf(TEXTE_ATTR(1));
  /* Saisie du nombre */
  scanf("%d",&nombre);
  /* Fin des attributs de texte */
  printf(EFFACE_ATTR);
  /* Début attributs Esc[31m = texte en rouge */
  printf(TEXTE_ROUGE);
  printf("Changement d'attributs effectué ! \n");
  /* Fin des attributs de texte */
  printf(EFFACE_ATTR);
}
