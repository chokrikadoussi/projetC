/* ------------------- */
/* inversion_chaine2.c */
/* ------------------- */
#include <stdio.h>
#include <stdlib.h>

main()
{
 char *chaine, lettre ;
 char *i,*j ;
 int taille=0 ;

 /* allocation dynamique */
 chaine=malloc(30);
 /* saisie */
 printf("Entrez une cha