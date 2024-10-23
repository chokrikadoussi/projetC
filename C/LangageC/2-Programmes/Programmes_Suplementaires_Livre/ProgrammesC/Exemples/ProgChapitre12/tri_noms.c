/* ---------- */
/* tri_noms.c */
/* ---------- */
#include <stdio.h>
#include <string.h>

#define NB_PERSONNES 50
#define TAILLE_NOM 20

main()
{
  int nbpersonnes=0, termine=0;
  char liste_personnes[NB_PERSONNES][TAILLE_NOM] ;

  char nom[TAILLE_NOM], tempnom[TAILLE_NOM] ;
  int i,j,k;
  
  /* --- boucle de saisie des noms --- */
  while (! termine)
  { 
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",nom);
   
   termine=((strcmp(nom,"fin"))==0) ;
   if (! termine)
   { /* rangement dans te tableau */  
     strcpy(liste_personnes[nbpersonnes],nom) ;
     nbpersonnes++ ;
   }   
  }
  /* --- boucle de tri du tableau --- */
  for (i=0 ; i < nbpersonnes ; i++)
  {
     k=i ;
     /* boucle inverse, d'inversion des cases */
     /* tant que le nom dans la case k est    */
     /* "plus petit" que celui de la case k-1 */
     while ((k>0) && (strcmp(liste_personnes[k],liste_personnes[k-1])<0))
     {
        /* on inverse avec la fonctions strcmp */
        strcpy(tempnom,liste_personnes[k-1]) ;
        strcpy(liste_personnes[k-1],liste_personnes[k]);
        strcpy(liste_personnes[k],tempnom);
	k--;
     }
  }

  /* --- boucle d'affichage des noms --- */
  for (i=0 ; i< nbpersonnes ; i++)
  {
    printf("nom de la personne %d:%s\n",i,liste_personnes[i]);
  }
}

