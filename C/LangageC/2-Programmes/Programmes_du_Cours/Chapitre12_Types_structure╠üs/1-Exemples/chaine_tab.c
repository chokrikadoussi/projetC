#include <stdio.h>
#include <string.h>

#define NB_PERSONNES 50
#define TAILLE_NOM 20

int main()
{
  int nbpersonnes=0, termine=0;
  char liste_personnes[NB_PERSONNES][TAILLE_NOM], nom[TAILLE_NOM];
  int i,j;
   
  while (! termine)
  { 
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",nom);
   
   termine=((strcmp(nom,"fin"))==0) ;

   if (! termine)
   {   
     strcpy(liste_personnes[nbpersonnes],nom) ;
     nbpersonnes++ ;
   }   
  }
  for (i=0 ; i< nbpersonnes ; i++)
  {
    printf("nom de la personne %d : %s\n",i,liste_personnes[i]);
  }



}
