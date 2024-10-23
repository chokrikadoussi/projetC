/* -------------- */
/* saisie_eleve.c */
/* -------------- */
#include <stdio.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define NB_NOTES 3
main()
{
  float somme ;
  int i       ;
  /* --- type structure etudiant --- */
  struct etudiant {
                    char nom[TAILLE_NOM]       ;
                    char prenom[TAILLE_PRENOM] ;
                    float notes[NB_NOTES]      ;
                    float moyenne              ;
                  } ;
  /* --- variable eleve --- */ 
  struct etudiant eleve ;

  /* === DEBUT DU PROGRAMME === */
  printf("Entrez un nom (par ex :Dupont):");
  scanf("%s",eleve.nom);
  
  printf("Entrez un pr