#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
#define ELEVE_NON_TROUVE "NON_TROUVE"
 
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
struct etudiant *debut_liste, *fin_liste ;
 
/* --- definition preliminaire des procedures --- */
struct etudiant *talloc();
void ajout_eleves();
void affichage() ;
struct etudiant *recherche_eleve(char nom_recherche[]);
void ouvrir_fichier() ;
void sauvegarder_fichier() ;
 
int main()
{ 
  struct etudiant eleve , *peleve ;
  char nom_eleve[TAILLE_NOM] ;
  char choix = 'A' , chaine_choix[20];
  
  debut_liste  = NULL ;
  fin_liste    = NULL ;

  while ( choix != 'q' )
  {
     printf("\n");
     printf("  -1- Ouvrir un fichier \n");
     printf("  -2- Sauvegarder un fichier \n");
     printf("  -3- Ajout d'une liste d'eleves \n");
     printf("  -4- Recherche d'un eleve \n");
     printf("  -5- Affichage de la liste\n");
     printf("\n");
     printf("  -q- quitter\n");
     printf("\n");
     printf("Choix:");
     scanf("%s",chaine_choix);
     choix=chaine_choix[0];
     
     switch (choix)
     {
       /* --- Appel procedure chargement du fichier --- */
       case '1' : ouvrir_fichier();
                  break ;
       /* --- Appel procedure sauvegarde du tableau --- */
       case '2' : sauvegarder_fichier();
                  break ;
  
       case '3' : ajout_eleves();
                  break ;
  
       /* --- Appel procedure saisie --- */
       case '4' : printf("Entrez le nom de l'eleve :");
                  scanf ("%s",nom_eleve);
                  peleve=recherche_eleve(nom_eleve);
                  eleve = *peleve ;
                  if (strcmp(eleve.nom,ELEVE_NON_TROUVE)==0)
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
       case '5' : affichage();
                  break ;
                
       case 'q' : printf("Au revoir \n");
                  break ;
       default: printf("Erreur de saisie\n");
                break;                   
     }
  }
}

/*--- fonction de saisie d'un eleve --- */
void ajout_eleves()
{
  struct etudiant *studtmp, *prec, *succ;
  int termine ;

  termine = 0 ;

  while ((! termine) && (nbeleves < MAX_ETUDIANTS) )
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
     }
     nbeleves++ ;
   }   
  }
  if (! (nbeleves < MAX_ETUDIANTS) )
  {
      printf("Nb Maximum d'eleves = %d Atteint !\n",MAX_ETUDIANTS);
  }
  printf("Nombre d'eleves=%d\n",nbeleves);
}

/*--- fonction de recherche d'un eleve --- */
struct etudiant *recherche_eleve(char nom_recherche[])
{
  struct etudiant studtmp, *p_eleve_retour ,*eleve_actuel;
  int trouve ;

  trouve = 0 ;
  
  p_eleve_retour=talloc();
  strcpy((*p_eleve_retour).nom,ELEVE_NON_TROUVE);
  
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
   struct etudiant *eleve_actuel ;
   int i ;
   
   printf("Verification saisie :\n");

   eleve_actuel=debut_liste ;
  
   while (eleve_actuel != NULL )
   {
     printf("%s %s %d\n",(*eleve_actuel).nom,(*eleve_actuel).prenom,(*eleve_actuel).age);
     eleve_actuel=(*eleve_actuel).successeur ;
   } 
}

/*--- fonction de chargement d'un fichier --- */
void ouvrir_fichier()
{
  char NomFichier[50]     ;
  FILE *entree            ;
  int erreur              ;
  struct etudiant *studtmp, *prec, *succ;
   
  printf("Entrez le nom du fichier :");
  scanf("%s",NomFichier);
  
  entree=fopen(NomFichier,"r");
 
  if (entree == NULL)
  {
    printf("Pb acces fichier %s\n",NomFichier);
  }
  else
  {
    while ( (! feof(entree)) && (nbeleves < MAX_ETUDIANTS) )
    {
      studtmp=talloc();

      erreur=fscanf(entree,"%s %s %d",(*studtmp).nom,(*studtmp).prenom,&((*studtmp).age));
      if (erreur != EOF)
      {
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
        }
      
        nbeleves++ ;
      }
    }
    if (! (nbeleves < MAX_ETUDIANTS) )
    {
      printf("Fichier trop gros, Nb Maximum d'eleves = %d \n",MAX_ETUDIANTS);
    }
    printf("Nombre total d'eleves : %d\n",nbeleves);
  }
  fclose(entree);
}

/*--- fonction de chargement d'un fichier --- */
void sauvegarder_fichier()
{
  char NomFichier[50]     ;
  FILE *sortie            ;
  struct etudiant *eleve_actuel ;
  int i                   ;

  printf("Entrez le nom du fichier :");
  scanf("%s",NomFichier);
  
  sortie=fopen(NomFichier,"w");
  if (sortie == NULL)
  {
    printf("Pb acces fichier %s\n",NomFichier);
  }
  else
  {
    eleve_actuel=debut_liste ;
  
    while (eleve_actuel != NULL )
    {
      fprintf(sortie,"%s %s %d\n",(*eleve_actuel).nom,(*eleve_actuel).prenom,(*eleve_actuel).age);
      eleve_actuel=(*eleve_actuel).successeur ;
    } 
  }   
  printf("Nombre d'eleves ecrits: %d\n",nbeleves);
    
  fclose(sortie);
}

/*--- fonction d'alocation d'un élève --- */
struct etudiant *talloc()
{
  return (struct etudiant *) malloc(sizeof(struct etudiant));
}
