#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
#define ELEVE_NON_TROUVE -1
 
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
void ajout_eleves();
void affichage() ;
int  recherche_eleve(char nom_recherche[]);
void ouvrir_fichier() ;
void sauvegarder_fichier() ;
 
int main()
{ 
  struct etudiant eleve ;
  char nom_eleve[TAILLE_NOM] ;
  int  numero_case =-1;
  char choix = 'A' , chaine_choix[20];
  
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
                  numero_case=recherche_eleve(nom_eleve);
                  if (numero_case == ELEVE_NON_TROUVE)
                  {
                    printf("Aucun %s n'a ete trouve \n",nom_eleve);
                  }
                  else
                  {
                    eleve=tab_eleves[numero_case] ;
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
  struct etudiant studtmp ;
  int termine ;

  termine = 0 ;
   
  while ((! termine) && (nbeleves < MAX_ETUDIANTS) )
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
  if (! (nbeleves < MAX_ETUDIANTS) )
  {
      printf("Nb Maximum d'eleves = %d Atteint !\n",MAX_ETUDIANTS);
  }

  printf("Nombre d'eleves=%d\n",nbeleves);
}

/*--- fonction de recherche d'un eleve --- */
int recherche_eleve(char nom_recherche[])
{
  struct etudiant studtmp   ;
  int trouve, i , num_case_retour=ELEVE_NON_TROUVE;

  trouve = 0 ;
  i = 0 ;
   
  while ((! trouve) && (i < nbeleves)  )
  { 
   studtmp=tab_eleves[i++] ;
   trouve=((strcmp(studtmp.nom,nom_recherche))==0) ;

   if (trouve)
   {   
     num_case_retour=i-1 ;
   }   
  }
  return num_case_retour ;
}

/*--- procedure d'affichage du tableau des eleves --- */
void affichage()
{
   int i ;
   
   for (i=0 ; i < nbeleves ; i++)
   {
     printf("%s %s %d\n",tab_eleves[i].nom,tab_eleves[i].prenom,tab_eleves[i].age);
   }
   printf("Nombre d'eleves = %d\n",nbeleves); 
} 
/*--- fonction de chargement d'un fichier --- */
void ouvrir_fichier()
{
  char NomFichier[50]     ;
  FILE *entree            ;
  struct etudiant studtmp ;
  int nbeleves_a_lire,taille_structure_etudiant,nbeleves_lus;
  
   
  printf("Entrez le nom du fichier :");
  scanf("%s",NomFichier);
  
  entree=fopen(NomFichier,"rb");
 
  if (entree == NULL)
  {
    printf("Pb acces fichier %s\n",NomFichier);
  
  }
  else
  {
    while ( (! feof(entree)) && (nbeleves < MAX_ETUDIANTS) )
    {
    
      /* -- lecture du fichier binaire --- */
      nbeleves_a_lire=1 ;
      taille_structure_etudiant=sizeof(struct etudiant);
        
      nbeleves_lus=fread(&studtmp,taille_structure_etudiant,nbeleves_a_lire,entree);
       
      /* --- chargement du tableau --- */
      if (nbeleves_lus == 1)
      {
        tab_eleves[nbeleves++]=studtmp ;

      }        
    }
    printf("Nombre d'eleves lus = %d\n",nbeleves);
            
    if (! (nbeleves < MAX_ETUDIANTS) )
    {
      printf("Fichier trop gros, Nb Maximum d'eleves = %d \n",MAX_ETUDIANTS);
    }
  }
  
  fclose(entree);
}
/*--- fonction de sauvegade dans un fichier --- */
void sauvegarder_fichier()
{
  char NomFichier[50]     ;
  FILE *sortie            ;
  struct etudiant studtmp ;
  int taille_structure_etudiant,nbeleves_ecrits;
   
  printf("Entrez le nom du fichier :");
  scanf("%s",NomFichier);
  
  sortie=fopen(NomFichier,"wb");
 
  if (sortie == NULL)
  {
    printf("Pb acces fichier %s\n",NomFichier);
  
  }
  else
  {
  
    taille_structure_etudiant = sizeof(struct etudiant);
    
    nbeleves_ecrits=fwrite(tab_eleves,taille_structure_etudiant,nbeleves,sortie);
    
    printf("Nombre elves ecrits : %d \n",nbeleves_ecrits); 
  }
  
  fclose(sortie);
}
