/* ------------- */
/* tab_eleves2.c */
/* ------------- */
#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50

/* === definition des synonymes === */
typedef char NOM_T[TAILLE_NOM];
typedef char PRENOM_T[TAILLE_NOM];
typedef int BOOLEEN;

/* declaration du type etudiant */
typedef struct {
                  NOM_T nom       ;
                  PRENOM_T prenom ;
                  int age         ;
               } ETUDIANT;

typedef ETUDIANT TAB_ETUDIANT[MAX_ETUDIANTS];

main()
{
  int i , nbeleves     ;
  BOOLEEN finir_saisie ;

  /* declaration du tableau des eleves */
  TAB_ETUDIANT tab_eleves;

  /* === DEBUT DU PROGRAMME === */
  i=0;
  finir_saisie=0;
  /* boucle de saisie */
  while (! finir_saisie)
  {
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",tab_eleves[i].nom);
   
   finir_saisie=((strcmp(tab_eleves[i].nom,"fin"))==0);

   /* si la saisie n'est pas finie */
   /* on demande le reste des informations */
   if (! finir_saisie)
   {   
     printf("Entrez un prenom:");
     scanf("%s",tab_eleves[i].prenom);
  
     printf("Entrez un age:");
     scanf("%d",&tab_eleves[i].age);
     i++ ;
   }  
  }
  /* on met a jour la variable de controle du tableau */ 
  nbeleves = i ;
  
 
  /* boucle de verification */
  printf("--Verification saisie--\n");
  
  for (i=0 ; i < nbeleves ; i++)
  {
     printf("eleve %2d : ",i);
     printf("%10s %10s ",tab_eleves[i].nom,tab_eleves[i].prenom);
     printf("%2d \n", tab_eleves[i].age );
  }
}

