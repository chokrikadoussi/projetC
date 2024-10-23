/* ---------------------- */
/* tableau_en_parametre.c */
/* ---------------------- */
#include <stdio.h>
#define TAILLE_TAB 30

/* declaration des sous-programmes */
void chargement (float tabsaisie[], int *nbel);
float calcul_moyenne (float tabtraitement[],int nbel);

/* === DEBUT PROGRAMME === */
main()
{ /* declarations */ 
  float tab_notes[TAILLE_TAB], moyenne ;
  int nbelements ;

  /* --- Appel chargement --- */
  chargement (tab_notes,&nbelements);
  
  /* --- Appel calcul_moyenne --- */
  moyenne = calcul_moyenne(tab_notes,nbelements);
  
  printf("la moyenne est : %5.2f\n",moyenne);
}
/* ====================================== */
void chargement (float tabsaisie[], int *nbel)
{  
  float x ;
  int i   ;
  /* --- saisie des notes dans le tableau tabsaisie --- */
  printf("Entrez une liste de notes (-1 pour fin):");
  
  x=1;
  i=0;
  while ( x >=0 )
  {
    scanf("%f", &tabsaisie[i]);
    x = tabsaisie[i++]        ; 
  }
  *nbel = --i ;
}
/* ====================================== */
float calcul_moyenne (float tabtraitement[],int nbel)
{  
  float somme, moyenne ;
  int i ;
  
  /* --- Traitement : calcul de la moyenne --- */
  somme=0;
  printf("%d notes saisies :\n",nbel);   
  for (i=0; i < nbel; i++)
  {
    somme = somme+tabtraitement[i];
    printf("%6.2f",tabtraitement[i]);
  } 
  printf("\n");
  moyenne=(somme/nbel);
  return moyenne ;
}

