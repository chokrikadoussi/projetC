#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
 
 /* --- definition des types globaux --- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                  struct etudiant *predecesseur ;
                  struct etudiant *successeur   ;
                } ;
/* --- definition des variables globales --- */
int  nbeleves=0 ;
struct etudiant *debut_liste, *fin_liste,*eleve_actuel;
 
/* --- definition preliminaire des procedures --- */
struct etudiant *talloc();
void saisie_eleves();
void affichage() ;
struct etudiant *recherche_eleve(char nom_recherche[]);
 
int main()
{ 
  struct etudiant eleve , *peleve ;
  char nom_eleve[TAILLE_NOM] ;
  int choix = -1 ;
  
  
  debut_liste  = NULL ;
  fin_liste    = NULL ;
  eleve_actuel = NULL ;
  
  
  
  
  while (choix != 0 )
  {
     printf("\n");
     printf("  -1- Saisie d'une liste d'eleves \n");
     printf("  -2- Recherche d'un eleve \n");
     printf("  -3- Affichage de la liste\n");
     printf("  -0- FIN\n");
     printf("\n");
     printf("Choix:");
     scanf("%d",&choix);
     
     switch (choix)
     {
       /* --- Appel procedure saisie --- */
       case 1 : saisie_eleves();
                break ;
  
       /* --- Appel procedure recherche --- */
       case 2 : printf("Entrez le nom de l'eleve :");
                scanf ("%s",nom_eleve);
                peleve=recherche_eleve(nom_eleve);
                eleve = *peleve ;
                if (strcmp(eleve.nom,"NON_TROUVE")==0)
                {
                  printf("Aucun %s n'a ete trouve \n",nom_eleve);
                }
                else
                {
                  printf("Nom    : %s\n",eleve.nom);
                  printf("Prenom : %s\n",eleve.prenom);
                  printf("Age    : %d\n",eleve.age);
                }
                break ;
  
       case 3 : affichage();
                break ;               
       case 0 : printf("Au revoir \n");
                break ;
       default: printf("Erreur de saisie\n");
                break;                   
     }
  }
}

/*--- fonction de saisie d'un eleve --- */
void saisie_eleves()
{
  struct etudiant *studtmp, *prec, *succ;
  int termine ;

  termine = 0 ;
   
  while (! termine)
  {
   studtmp=talloc();
   
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",(*studtmp).nom);
   
   termine=((strcmp((*studtmp).nom,"fin"))==0) ;

   if (! termine)
   {   
     printf("Entrez un prenom:");
     scanf("%s",(*studtmp).prenom);
  
     printf("Entrez un age:");
     scanf("%d",&((*studtmp).age));
     
     (*studtmp).predecesseur=NULL ;
     (*studtmp).successeur=NULL;
     
     if (debut_liste == NULL)
     {
       debut_liste=studtmp ;
       fin_liste=studtmp ;
     }
     else
     {
        (*fin_liste).successeur=studtmp   ;
        (*studtmp).predecesseur=fin_liste ;
        fin_liste=studtmp               ;
        eleve_actuel=studtmp            ;
     }
     
     nbeleves++ ;
   }   
  }
}

/*--- fonction de recherche d'un eleve --- */
struct etudiant *recherche_eleve(char nom_recherche[])
{
  struct etudiant studtmp, *p_eleve_retour ;
  int trouve ;

  trouve = 0 ;
  
  p_eleve_retour=talloc();
  strcpy((*p_eleve_retour).nom,"NON_TROUVE");
  
   
  eleve_actuel=debut_liste ; 
   
  while ((! trouve) && (eleve_actuel != NULL)  )
  { 
   studtmp = (*eleve_actuel) ;
   eleve_actuel=(*eleve_actuel).successeur ; 
     
   trouve=((strcmp(studtmp.nom,nom_recherche))==0) ;

   if (trouve)
   {   
     *p_eleve_retour=studtmp ;
   }   
  }

  return p_eleve_retour ;
  
}

/*--- procedure d'affichage du tableau des eleves --- */
void affichage()
{
   int i ;
   
   printf("Verification saisie :\n");

   eleve_actuel=debut_liste ;
  
   while (eleve_actuel != NULL )
   {
     printf("%s %s %d\n",(*eleve_actuel).nom,(*eleve_actuel).prenom,(*eleve_actuel).age);
     eleve_actuel=(*eleve_actuel).successeur ;
   } 
   

}
/* --- allocation m