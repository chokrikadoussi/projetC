/* ------------------ */
/* liste_structures.c */
/* ------------------ */
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 30

main()
{
  /* --- Type etudiant --- */
  struct etudiant {
             struct etudiant *pred     ;
             char nom[TAILLE_NOM]      ;
             char prenom[TAILLE_PRENOM];
             int age                   ;
             struct etudiant *succ     ;
            } ;

  /* --- Variables --- */
  struct etudiant *debut_liste,*fin_liste;
  struct etudiant *nouv_eleve,*eleve_actuel;
  int termine = 0 , nbeleves=0;

  /* ===== PROGRAMME ===== */
  debut_liste = NULL;
  fin_liste   = NULL;
  
  /* --- boucle de saisie --- */
  while (! termine)
  { 
   nouv_eleve = malloc(sizeof(struct etudiant));
   
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",nouv_eleve->nom);
   
   termine=((strcmp(nouv_eleve->nom,"fin"))==0) ;

   if (! termine) /* saisie du reste */
   {   
     printf("Entrez un prenom:")   ;
     scanf("%s",nouv_eleve->prenom);
  
     printf("Entrez un age:")      ;
     scanf("%d",&(nouv_eleve->age));
     
    nouv_eleve->pred=NULL ;
    nouv_eleve->succ=NULL ;
     
    if (debut_liste == NULL)
    { /* Liste vide. C'est le seul element */
      debut_liste = nouv_eleve ;
      fin_liste   = nouv_eleve ;
    }
    else
    { /* ajout en fin de liste */
      fin_liste->succ  = nouv_eleve ;
      nouv_eleve->pred = fin_liste  ;
      fin_liste        = nouv_eleve ;
    }
    /* on compte de nombre d'eleves */
    nbeleves++ ;
   }   
  }
  /* --- boucle d'affichage --- */
  printf("--- %d 