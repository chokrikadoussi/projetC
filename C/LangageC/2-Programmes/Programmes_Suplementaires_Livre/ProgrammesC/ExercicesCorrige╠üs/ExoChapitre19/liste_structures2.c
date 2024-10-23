/* ------------------ */
/* liste_structure2.c */
/* ------------------ */
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 30

/* --- sous-programmes --- */
void saisie()       ;
void affichage()    ;
struct etudiant *recherche(char nom_recherche[]);
void modification() ;

/* --- variables globales --- */
struct etudiant {
             struct etudiant *pred     ;
             char nom[TAILLE_NOM]      ;
             char prenom[TAILLE_PRENOM];
             int age                   ;
             struct etudiant *succ     ;
            } ;

struct etudiant *debut_liste,*fin_liste;
int nbeleves=0;

/* ===== PROGRAMME ===== */
main()
{
  char choix=' ', ch_saisie[20];

  debut_liste = NULL;
  fin_liste   = NULL;

  while (choix!='q')
  {
    printf("-1- Saisie d'une liste\n");
    printf("-2- Affichage\n");
    printf("-3- Modification d'un 