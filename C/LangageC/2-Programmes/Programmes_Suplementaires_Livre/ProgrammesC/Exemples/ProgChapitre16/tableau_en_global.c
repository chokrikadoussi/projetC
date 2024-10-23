/* ------------------- */
/* tableau_en_global.c */
/* ------------------- */
#include <stdio.h>
#define TAILLE_TAB 30

/*--  declaration des sous-programmes -- */ 
void chargement ()     ;
float calcul_moyenne ();

/* -- variable globale -- */ 
float tab_notes[TAILLE_TAB];
int nbelements             ;

/* === DEBUT PROGRAMME === */ 
main()
{ /* -- declarations -- */
  float  moyenne ;
  
  /* --- Appel chargement --- */
  chargement();
  
  /* --- Appel calcul_moyenne --- */
  moyenne = calcul_moyenne();
  
  printf("la moyenne est : %6.2f\n",moyenne);
}
 /* ====================================== */ 
 void chargement ()
 {  
  float x ;
  int i   ;

  printf("Entrez une liste de notes (-1 pour fin):");
  x = 1;
  i = 0;
  while ( x >= 0 )
  {
    scanf("%f", &tab_notes[i]);
    x = tab_notes[i++]        ; 
  }
  nbelements = --i ;
 }
 /* ====================================== */  
 float calcul_moyenne ()
 {  
  float somme, moyenne  ;
  int i          ;
  
  somme=0;
  for (i=0; i < nbelements ; i++)
  {
    somme = somme + tab_notes[i];
  } 
  moyenne = somme/nbelements;
  return moyenne ;
 }
 /* ====================================== */ 
