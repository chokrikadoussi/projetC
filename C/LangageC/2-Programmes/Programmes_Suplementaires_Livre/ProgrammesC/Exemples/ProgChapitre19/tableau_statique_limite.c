/* ------------------------- */
/* tableau_statique_limite.c */
/* ------------------------- */
#include <stdio.h>

#define TAILLE_NOM 10
#define TAILLE_PRENOM 10
#define TAILLE_ADDR 30
#define MAX_NOTES 200
#define MAX_ETUDIANTS 10000

main()
{ 
  struct etudiant {
              char nom[TAILLE_NOM]       ;
              char prenom[TAILLE_PRENOM] ;
              char adresse[TAILLE_ADDR]  ;
              float notes[MAX_NOTES]  ;
              } ;
  int  i,nbeleves=0, retour1,retour2,retour3 ;
  /* allocation statique du tableau */
  struct etudiant eleve, tab_eleves[MAX_ETUDIANTS];
  char nomfichier[50];
  FILE *fichier;

  printf("Nom du fichier 