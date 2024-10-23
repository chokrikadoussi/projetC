/* ----------------------- */
/* pointeur_sur_fonction.c */
/* ----------------------- */
#include <stdio.h>

float multiplication (float nombre1 , float nombre2);
float addition (float nombre1 , float nombre2);

main()
{
  float N1, N2, resultat    ;
  char oper,saisie[10] ;
  /* declaration du pointeur de fonction */
  float (*point_fonct)(float nb1, float nb2);

  printf("Entrez deux r