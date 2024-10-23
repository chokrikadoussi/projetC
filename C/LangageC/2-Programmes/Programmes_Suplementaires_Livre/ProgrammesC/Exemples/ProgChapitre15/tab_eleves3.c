/* ------------- */
/* tab_eleves3.c */
/* ------------- */
#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50

main()
{
  char nomfichier[20];
  FILE *fichier      ;
  int i , nbeleves ,finir_saisie ;
  /* declaration du type etudiant */
  struct etudiant {
                    char nom[TAILLE_NOM]       ;
                    char prenom[TAILLE_PRENOM] ;
                    int age                    ;
                  } ;
  
  /* declaration du tableau des eleves */
  struct etudiant tab_eleves[MAX_ETUDIANTS];

  /* === DEBUT DU PROGRAMME === */
  i=0;
  finir_saisie=0;
  /* --- boucle de saisie --- */
  while (! finir_saisie)
  {
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",tab_eleves[i].nom);
   
   finir_saisie=((strcmp(tab_eleves[i].nom,"fin"))==0);

   /* si la saisie n'est pas finie */
   /* on demande le reste des informations */
   if (! finir_saisie)
   {   
     printf("Entrez un pr