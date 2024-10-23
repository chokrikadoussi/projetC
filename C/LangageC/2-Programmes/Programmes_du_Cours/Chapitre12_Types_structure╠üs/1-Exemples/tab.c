#include <stdio.h>

#define TAILLE_TAB 5

int main()
{
  int i, nbelements;
  float tab_notes[TAILLE_TAB], x ,resultat ;
  
  /* --- saisie des notes dans le tableau --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  
  x=1;
  i=0;
  while ( x >=0 )
  {
    scanf("%f",&tab_notes[i]);
    x=tab_notes[i++]        ; 
  }
  nbelements=--i ;
   
  /* --- Traitement : calcul de la moyenne --- */
  /* --- lecture de chaque case du tableau --- */
  resultat=0;
  
  for (i=0; i<nbelements;i++)
  {
    resultat=resultat+tab_notes[i];
    printf("%f\n",tab_notes[i]);
  } 
  resultat=(resultat/nbelements);
  
  printf("la moyenne est : %f\n",resultat);
}
