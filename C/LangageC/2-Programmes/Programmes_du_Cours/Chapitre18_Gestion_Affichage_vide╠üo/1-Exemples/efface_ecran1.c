/* -----------------------
GESTION VIDEO DU TEXTE
les codes des séquences d'échappement sont disponibles à:
http://ascii-table.com/ansi-escape-sequences.php
------------------------- */
#include <stdio.h>
#include <string.h>

int main()
{
  int bidon ;
  char chaine_effacement_ecran[5]            ;

  /* On pilote le terminal via son langage en SUITE D'ÉCHAPPEMENT */
  /* la chaine contenant Esc[2J = effacement */
  strcpy(chaine_effacement_ecran,"\033[2J")  ; /* Esc[2J */

  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  printf("Entrez un entier quelconque avant effacement de l'écran : ");
  scanf("%d",&bidon);
  /* Effacement de l'écran */
  printf("%s",chaine_effacement_ecran);
  printf("Effacement effectué ! \n");
}
