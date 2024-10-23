/* ----------------------- */
/* pointeur_de_pointeurs.c */
/* ----------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LONG_MAX 20

main()
{
  int nbpersonnes=0, termine=0, Inversion;
  int totalpersonnes ;
  /* declaration du pointeur de pointeurs */
  char **liste_personnes ;
  char *pttmp ;

  char nom[LONG_MAX] ;
  int i,j,k;
 
  /* --- saisie du nombre de personnes a gerer --- */
   printf("Nombre de personnes a saisir:");
   scanf("%d",&totalpersonnes);

  /* --- allocation de la colone de pointeurs ---*/
  liste_personnes=malloc(totalpersonnes*sizeof(char *));

  /* --- boucle de saisie des noms --- */
  while (! termine)
  { 
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",nom);
   
   termine=((strcmp(nom,"fin"))==0) ;
   if (! termine)
   { 
     /* allocation de la chaine */
     *(liste_personnes+nbpersonnes)=malloc(strlen(nom)+1);
     /* rangement dans te tableau */  
     strcpy(*(liste_personnes+nbpersonnes),nom) ;
     nbpersonnes++ ;
   }   
  }
  /* --- boucle de tri du tableau --- */
  for (i=0 ; i < nbpersonnes ; i++)
  {
     k=i ;
     Inversion=1;
     /* boucle inverse, d'inversion des pointeurs */
     /* tant que le nom dans la case k est        */
     /* "plus petit" que celui de la case k-1     */
     while (Inversion && (k>0))
     {
       Inversion=(strcmp(*(liste_personnes+k),*(liste_personnes+k-1))<0);
       if (Inversion)
       {
         /* on inverse les pointeurs */
         pttmp = *(liste_personnes+k-1) ;
         *(liste_personnes+k-1) = *(liste_personnes+k);
         *(liste_personnes+k) = pttmp;
         k--;
       }
     }
  }
  /* --- boucle d'affichage des noms --- */
  for (i=0 ; i< nbpersonnes ; i++)
  {
    printf("nom de la personne %d:%s\n",i,*(liste_personnes+i));
  }
}

