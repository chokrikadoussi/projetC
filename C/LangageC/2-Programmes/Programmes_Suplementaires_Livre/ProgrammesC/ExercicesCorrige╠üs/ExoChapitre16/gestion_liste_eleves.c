/* ---------------------- */
/* gestion_liste_eleves.c */
/* ---------------------- */
#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
#define ELEVE_NON_TROUVE -1
/* --- Type etudiant --- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;
/* --- variables globales --- */
int  nbeleves=0 ;
struct etudiant tab_eleves[MAX_ETUDIANTS];
/* --- sous-programmes --- */ 
void ajout_eleves();
void affichage() ;
int  recherche_eleve(char nom_recherche[]);
void ouvrir_fichier() ;
void sauvegarder_fichier() ;
/* -------------------------- */ 
main()
{ 
  struct etudiant eleve ;
  char nom_eleve[TAILLE_NOM] ;
  int choix = -1 , numero_case =-1;
  
  while (choix != 0 )
  {
     printf("\n");
     printf("  -1- Ouvrir un fichier          \n");
     printf("  -2- Sauvegarder un fichier     \n");
     printf("  -3- Ajout d'une liste d'