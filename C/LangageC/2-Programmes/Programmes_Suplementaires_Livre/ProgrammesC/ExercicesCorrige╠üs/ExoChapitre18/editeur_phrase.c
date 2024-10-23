/* ---------------- */
/* editeur_phrase.c */
/* ---------------- */
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_PHRASE 80
main()
{
 char *phrase, lettre, action ;
 char *i, saisie[10]         ;
 int taille=0, numero        ;

 /* allocation dynamique */
 phrase=malloc(TAILLE_PHRASE);
 /* ---- saisie ---- */
 printf("Entrez une phrase :");
 i=phrase;
 while ((*i=getchar())!='\n')
 {
   i++ ;
   taille++ ;
 }
 /* ajout du delimiteur de fin de phrase */
 *(phrase+taille)='\0';

 /* ---- traitement ---- */
 action=' ';

 while (action != 'q')
 {
  printf("Action (d=destruction, i=insertion, q=quitter):");
  scanf("%s",saisie);
  action=*saisie;

  switch(action)
  {
    case 'd': printf("Num