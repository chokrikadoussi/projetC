/* ----------------------- */
/* moyenne_via_pointeurs.c */
/* ----------------------- */
#include <stdio.h>

main()
{
  float TabNotes[3], *preel, somme=0;
  int i ;

  /* affectation de l'adresse de la case 0 */
  preel=TabNotes;

  /* boucle de saisie */
  printf("Entrez 3 notes : ");
  for (i=0;i<3;i++)
  {
    /* rangement dans la case pointee */
    scanf("%f",preel);
    /* calcul de la somme */
    somme += *preel ;
    /* passage a la case suivante */
    preel++;
  }
  /* calcul de la moyenne */
  printf("Moyenne:%6.2f\n",somme/3);
}

