#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "serveur_scolarite.h"


#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50

int main()
{
  int i , nbeleves ,finir_saisie ;
  struct etudiant {
                    char nom[TAILLE_NOM]       ;
                    char prenom[TAILLE_PRENOM] ;
                    int age                    ;
                  } ;
  
  struct etudiant   eleve ;
/*  struct etudiant   tab_eleve[MAX_ETUDIANTS]; */


  struct etudiant  *tab_eleve;

/* ------------------------------------ */
/* Declaration de "tableaux dynamiques" */
/* ------------------------------------ */
  ligne *user;
  Un_dossier_groupe *Tab_numero_dossier;
  uidstruct *Tab_uid; 

/* ------------------------------------ */
/* Declaration de "tableaux statisques" */
/* ------------------------------------ */
/* ligne user[NB_ELET_PASSWD];
   Un_dossier_groupe Tab_numero_dossier[NB_ELET_PASSWD];
   uidstruct Tab_uid[NB_ELET_PASSWD];  */



  tab_eleve=(struct etudiant *) malloc(sizeof(struct etudiant)*MAX_ETUDIANTS);



/* ------------------------------------ */
/* Allocation de "tableaux dynamiques" */
/* ------------------------------------ */
  user=(ligne *) malloc(sizeof(ligne)*NB_ELET_PASSWD);
  Tab_numero_dossier=(Un_dossier_groupe *) malloc(sizeof(Un_dossier_groupe)*NB_ELET_PASSWD);
  Tab_uid=(uidstruct *) malloc(sizeof(uidstruct)*NB_ELET_PASSWD); 


printf("Verification : NB_ELET_PASSWD = %d\n\n",NB_ELET_PASSWD);


  i=0;
  finir_saisie=0;
  
  while (! finir_saisie)
  {
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",tab_eleve[i].nom);
   
   finir_saisie=((strcmp(tab_eleve[i].nom,"fin"))==0) ;

   if (! finir_saisie)
   {   
     printf("Entrez un prenom:");
     scanf("%s",tab_eleve[i].prenom);
  
     printf("Entrez un age:");
     scanf("%d",&tab_eleve[i].age);
     i++ ;
   }  
  }
  
  nbeleves = i ;
  
  
  printf("Verification saisie :\n");
  
  for (i=0 ; i < nbeleves ; i++)
  {
     printf("%s %s %d\n",tab_eleve[i].nom,tab_eleve[i].prenom,tab_eleve[i].age);
  }
}
