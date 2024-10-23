#include <stdio.h>

#define TAILLE_TAB 5

int main()
{
  int i, nbelements;
  float tab_notes[TAILLE_TAB], x ,resultat ;
  float *debtab ;
  
  /* --- memorisation de l'adresse de la premiere case ---*/
  
  debtab=tab_notes ;
  
  /* --- saisie des notes dans le tableau --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  
  x=1;
  i=0;
  while ( x >=0 )
  {
    scanf("%f",debtab);
    x=*debtab         ;
    debtab++          ;
    i++               ; 
  }
  nbelements=--i ;
   
  /* --- Traitement : calcul de la moyenne --- */
  /* --- lecture de chaque case du tableau --- */
  
  resultat=0        ;
  debtab=tab_notes ;
  
  for (i=0; i<nbelements;i++)
  {
    resultat=resultat+ *debtab;
    debtab++                ;
    printf("%f\n",*(debtab-1));
  } 
  resultat=(resultat/nbelements);
  
  printf("la moyenne est : %f\n",resultat);
}
