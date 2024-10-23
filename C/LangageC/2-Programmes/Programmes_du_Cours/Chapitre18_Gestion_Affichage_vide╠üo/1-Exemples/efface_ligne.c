#include <stdio.h>
int main()
{
  int type_effacement ;

  /* On pilote le terminal via son langage en SUITE D'ÉCHAPPEMENT */
  /* -----------------------------
  Début de l'utilisation
  ------------------------------- */
  printf("Entrez un entier pour indiquer le type d'effacement de la ligne.\n");
  printf("-0- Efface à partir du curseur vers la droite\n");
  printf("-1- Efface à partir du curseur vers la gauche\n");
  printf("-2- Efface toute la ligne\n");
  printf("Choix : ");
  scanf("%d",&type_effacement);
  printf("\033[1;10H"); /* déplacement ligne 1 colonne 10 */
  /* Effacement de l'écran */
  switch (type_effacement)
  {
    case 0 : printf("\033[0K"); break ; // Efface vers la droite
    case 1 : printf("\033[1K"); break ; // Effacement vers la gauche
    case 2 : printf("\033[2K"); break ; // effacement de toute la ligne
  }
  printf("\nEffacement effectué ! \n");
}

