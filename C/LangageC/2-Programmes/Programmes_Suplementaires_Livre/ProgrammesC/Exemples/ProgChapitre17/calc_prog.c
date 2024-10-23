/* ----------- */
/* calc_prog.c */
/* ----------- */
#include <stdio.h>
#include "declarations.h"

void multiplication (float nombre1 , float nombre2);
void addition (float nombre1 , float nombre2);
/* variable globale */
float resultat ;

main()
{
  float N1 , N2     ;
  char operation,saisie[10]    ;

  printf("Entrez deux reel: ");
  scanf("%f %f",&N1,&N2);
  printf("Op