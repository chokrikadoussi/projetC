/* ---------------------- */
/* structure_en_globale.c */
/* ---------------------- */
#include <stdio.h>
#include <string.h>

/* -- declaration des constantes -- */
#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
 
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;

/* -- variables globales -- */
int  nbeleves=0 ;
struct etudiant tab_eleves[MAX_ETUDIANTS];

/* -- procedures et fonctions -- */ 
void saisie_eleves();
void affichage() ;
struct etudiant recherche_eleve(char nom_recherche[]);

/* ----------------------------------- */
main()
{ 
  struct etudiant eleve ;
  char nom_eleve[TAILLE_NOM] ;
  int choix = -1 ;
 
  /* -- boucle d'affichage du menu -- */ 
  while (choix != 0 )
  {
     printf("\n");
     printf("  -1- Saisie d'une liste d'