#include <stdio.h>
#define TAILLE_TAB 5

void chargement (float tabsaisie[]);
float calcul_moyenne (float tabtraitement[]);

int nbelements ;

int main()
{

  float tab_notes[TAILLE_TAB], moyenne ;
  
  /* --- Appel chargement --- */
  chargement (tab_notes);
  
  /* --- Appel calcul_moyenne --- */
  moyenne=calcul_moyenne(tab_notes);
  
  printf("la moyenne est : %f\n",moyenne);
}
   
  
/* --- procedure chargement --- */
void chargement (float tabsaisie[])
{  
  float x ;
  int i   ;
  /* --- saisie des notes dans le tableau tabsaisie --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  
  x=1;
  i=0;
  while ( x >=0 )
  {
    scanf("%f",&tabsaisie[i]);
    x=tabsaisie[i++]        ; 
  }
  nbelements=--i ;
 
}
 
 float calcul_moyenne (float tabtraitement[])
{  
  float resultat ;
  int i          ;
  
  /* --- Traitement : calcul de la moyenne --- */
  /* --- lecture de chaque case du tableau tabtraitement --- */
  resultat=0;
  
  for (i=0; i<nbelements;i++)
  {
    resultat=resultat+tabtraitement[i];
    printf("%f\n",tabtraitement[i]);
  } 
  resultat=(resultat/nbelements);
  
  return resultat ;
}
