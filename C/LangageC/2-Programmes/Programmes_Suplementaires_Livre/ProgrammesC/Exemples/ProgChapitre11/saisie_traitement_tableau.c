/* --------------------------- */
/* saisie_traitement_tableau.c */
/* --------------------------- */
#include <stdio.h>
#define TAILLE_TAB 30

main()
{ /* declarations */
  int i, nbelements;
  float tab_notes[TAILLE_TAB] ;
  float x ,somme, moyenne ;
  
  /* --- SAISIE des notes dans le tableau --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  x = 1;
  i = 0;
  while ( x >= 0 )
  {
    scanf("%f",&tab_notes[i]);
    x = tab_notes[i++]       ; 
  }
  /* on memorise le nombre d'elements lus */
  nbelements = --i ;

  /* --- TRAITEMENT : calcul de la moyenne --- */
  /* --- lecture de chaque case du tableau --- */
  /* --- de la case 0 a nbelements-1       --- */
  somme=0;
  printf("%d notes saisies :\n",nbelements);  
  for (i=0 ; i < nbelements ; i++)
  {
    /* somme des notes */
    somme = somme + tab_notes[i];
    printf("%6.2f",tab_notes[i]);
  } 
  printf("\n");  

  /* calcul de la moyenne */
  moyenne = somme / nbelements ;
  printf("la moyenne est : %5.2f\n",moyenne);
}
