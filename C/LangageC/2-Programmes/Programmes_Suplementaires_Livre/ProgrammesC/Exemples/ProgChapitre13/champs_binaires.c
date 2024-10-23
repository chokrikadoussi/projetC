/* ----------------- */
/* champs_binaires.c */
/* ----------------- */
#include <stdio.h>

main()
{
  int i;
  struct candidat
  {
     char nom[12] ;
    /* inscription 1 bit: 0 Nouveau, 1 Reinscription */
    unsigned int inscription:1 ;
    /* Num Cycle Universitaire 2 bits : 0,1,2,3 */
    unsigned int Cycle:2;
    /* Diplome Universitaire 4 bits : DEUG1=0,DEUG2=1,...*/
    unsigned int Diplome:4;
    /* Association Sportive 1 bit: 0 FAUX, 1 VRAI */
    unsigned int AssoSport:1 ;
  } ;
  struct candidat cand1 ;

  printf("Taille variable candidat %d\n",sizeof(struct candidat));

  printf("Entrez un nom : ");
  scanf("%s",cand1.nom);
  printf("Nouvelle inscription(0), R