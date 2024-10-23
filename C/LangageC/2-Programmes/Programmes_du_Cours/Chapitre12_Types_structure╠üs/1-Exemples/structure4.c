#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
 
 /* --- definition des types globaux --- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;
/* --- definition des variables globales --- */
int  nbeleves=0 ;
struct etudiant tab_eleves[MAX_ETUDIANTS];
 
/* --- definition preliminaire des procedures --- */
void saisie_eleves();
void affichage() ;
struct etudiant recherche_eleve(char nom_recherche[]);
 
int main()
{ 
  struct etudiant eleve ;
  char nom_eleve[TAILLE_NOM] ;
  int choix = -1 ;
  
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
  
       /* --- Appel procedure saisie --- */
       case 2 : printf("Entrez le nom de l'eleve :");
                scanf ("%s",nom_eleve);
                eleve=recherche_eleve(nom_eleve);
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
  
       /* --- Appel procedure d'affichage --- */
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
  struct etudiant studtmp ;
  int termine ;

  termine = 0 ;
   
  while (! termine)
  { 
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",studtmp.nom);
   
   termine=((strcmp(studtmp.nom,"fin"))==0) ;

   if (! termine)
   {   
     printf("Entrez un prenom:");
     scanf("%s",studtmp.prenom);
  
     printf("Entrez un age:");
     scanf("%d",&studtmp.age);
     
     tab_eleves[nbeleves]=studtmp ;
     nbeleves++ ;
   }   
  }
}

/*--- fonction de recherche d'un eleve --- */
struct etudiant recherche_eleve(char nom_recherche[])
{
  struct etudiant studtmp, eleve_retour={"NON_TROUVE","",0};
  int trouve, i ;

  trouve = 0 ;
  i = 0 ;
   
  while ((! trouve) && (i < nbeleves)  )
  { 
   studtmp=tab_eleves[i++] ;
   trouve=((strcmp(studtmp.nom,nom_recherche))==0) ;

   if (trouve)
   {   
     eleve_retour=studtmp ;
   }   
  }
  return eleve_retour ;
}

/*--- procedure d'affichage du tableau des eleves --- */
void affichage()
{
   int i ;
   
   printf("Verification saisie :\n");
  
   for (i=0 ; i < nbeleves ; i++)
   {
     printf("%s %s %d\n",tab_eleves[i].nom,tab_eleves[i].prenom,tab_eleves[i].age);
   } 
} 
