#include <stdio.h>
#define TAILLE_TAB 5

void chargement ();
float calcul_moyenne ();

float tab_notes[TAILLE_TAB];
int nbelements ;

int main()
{

  float  moyenne ;
  
  /* --- Appel chargement --- */
  chargement();
  
  /* --- Appel calcul_moyenne --- */
  moyenne=calcul_moyenne();
  
  printf("la moyenne est : %f\n",moyenne);
}
   
  
/* --- procedure chargement --- */
void chargement ()
{  
  float x ;
  int i   ;
  /* --- saisie des notes dans le tableau tab_notes --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  
  x=1;
  i=0;
  while ( x >=0 )
  {
    scanf("%f",&tab_notes[i]);
    x=tab_notes[i++]        ; 
  }
  nbelements=--i ;
 
}
 
 float calcul_moyenne ()
{  
  float resultat ;
  int i          ;
  
  /* --- Traitement : calcul de la moyenne --- */
  /* --- lecture de chaque case du tableau tab_notes --- */
  resultat=0;
  
  for (i=0; i<nbelements;i++)
  {
    resultat=resultat+tab_notes[i];
    printf("%f\n",tab_notes[i]);
  } 
  resultat=(resultat/nbelements);
  
  return resultat ;
}
