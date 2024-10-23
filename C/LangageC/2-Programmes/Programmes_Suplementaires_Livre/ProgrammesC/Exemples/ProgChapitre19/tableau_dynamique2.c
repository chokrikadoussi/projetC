/* -------------------- */
/* tableau_dynamique2.c */
/* -------------------- */
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 10
#define TAILLE_PRENOM 10
#define TAILLE_ADDR 30
#define MAX_NOTES 200

main()
{ 
  struct etudiant {
              char nom[TAILLE_NOM]       ;
              char prenom[TAILLE_PRENOM] ;
              char adresse[TAILLE_ADDR]  ;
              float notes[MAX_NOTES]  ;
              } ;
  int  i,nbeleves=0, retour1,retour2,retour3 ;
  int  taille_etudiant,nouvelle_taille ;
  /* declaration d'un pointeur de structure */
  struct etudiant *tab_eleves=NULL;
  struct etudiant eleve;
  char nomfichier[50];
  FILE *fichier;

  printf("Nom du fichier 