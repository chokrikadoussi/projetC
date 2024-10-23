#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

  tab_eleve=(struct etudiant *) malloc(sizeof(struct etudiant)*MAX_ETUDIANTS);



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
