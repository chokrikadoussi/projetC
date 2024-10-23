/* ------------------------ */
/* structure_en_parametre.c */
/* ------------------------ */
#include <stdio.h>
#include <string.h>

/* -- declaration des constantes -- */
#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50

/* -- declarations de la structure -- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;

/* -- procedures et fonctions -- */
int saisie_eleve(struct etudiant *student, int *nbel);
int affichage(struct etudiant tabetud[],int nbel);
 
/* --------------------------------- */
main()
{
  int i ,finir_saisie, nbeleves=0 ;
  struct etudiant   eleve ,tab_eleve[MAX_ETUDIANTS];

  i=0;
  /* -- boucle de saisie -- */
  finir_saisie=0;
  while (! finir_saisie)
  {
   /* -- appel de la fonction saisie_eleve -- */
   finir_saisie = saisie_eleve(&eleve,&nbeleves)   ;
   /* -- rangement dans le tableau -- */
   if (! finir_saisie)
       tab_eleve[i++] = eleve ;
  }
  /* -- appel de la procedure affichage -- */
  affichage(tab_eleve,nbeleves);
}
/* --------------------------------- */
int saisie_eleve(struct etudiant *student, int *nbel)
{  /* -- declaration des variables locales -- */
   struct etudiant studtmp ;
   int termine ;
   
   printf("Entrez un nom (\"fin\" pour terminer):");
   scanf("%s",studtmp.nom);
   
   /* -- saisie d'un eleve -- */
   termine=(!(strcmp(studtmp.nom,"fin"))) ;
   if (! termine)
   {   
     printf("Entrez un pr