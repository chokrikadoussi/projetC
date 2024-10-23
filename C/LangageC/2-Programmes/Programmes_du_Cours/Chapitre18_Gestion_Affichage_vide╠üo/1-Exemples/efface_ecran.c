/* -----------------------
GESTION VIDEO DU TEXTE
les codes des séquences d'échappement sont disponibles à:
http://ascii-table.com/ansi-escape-sequences.php
http://ascii-table.com/ansi-escape-sequences-vt-100.php
------------------------- */
#include <stdio.h>

int main()
{
  int type_effacement ;

  /* On pilote le terminal via son langage en SUITE D'ÉCHAPPEMENT */
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  printf("Entrez un entier pour indiquer le type d'effacement de l'écran.\n");
  printf("-0- Efface à partir du curseur vers le bas\n");
  printf("-1- Efface à partir du curseur vers le haut\n");
  printf("-2- Efface tout l'écran\n");
  printf("Choix : ");
  scanf("%d",&type_effacement);
  /* Effacement de l'écran */
  switch (type_effacement)
  {
    case 0 : printf("\033[1;1H"); /* déplacement ligne 1 colonne 1 */
             printf("\033[0J"); break ; // Efface vers le bas
    case 1 : printf("\033[1J"); break ; // Effacement vers le haut
    case 2 : printf("\033[2J"); break ; // effacement de tout
  }
  printf("Effacement effectué ! \n");
}

