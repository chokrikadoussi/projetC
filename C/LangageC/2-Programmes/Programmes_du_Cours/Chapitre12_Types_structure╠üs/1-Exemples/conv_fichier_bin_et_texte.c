#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50
#define TAILLE_NOM_FICHIER 40

/* --- déclaration préliminaires --- */
void conversion_texte_binaire() ;
void conversion_binaire_texte() ;

 
 /* --- definition des types globaux --- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;

/* --- definition des variables globales --- */
int  nbeleves=0 ;
struct etudiant tab_eleves[MAX_ETUDIANTS]; 

int main()
{
   int choix=1;
   
   while (choix != 0)
   {
      printf("\n");
      printf("  -1- Conversion Fichier   Texte   -> Binaire\n");
      printf("  -2- conversion Fichier   Binaire -> Texte\n")  ;
      printf("\n");
      printf("  -0- Quitter\n");
      
      printf("\n");
      printf("Choix :");
      scanf("%d",&choix);
      
      switch(choix)
      {
         case 1 : conversion_texte_binaire();
                  break ;
                  
         case 2 : conversion_binaire_texte();
                  break ;
         case 0 : printf("Au revoir\n");
                  break ;
         default : printf("Choix impossible !\n");
                   break ;
      }     
   }
}


/* --- conversion fichier texte en fichier binaire ---*/
void conversion_texte_binaire()
{
   FILE *entree, *sortie ;
   char NomFichierTexte[TAILLE_NOM_FICHIER] ,NomFichierBinaire[TAILLE_NOM_FICHIER];
   struct etudiant eleve ;
   int erreur, nbeleves_ecrits ,taille_structure_etudiant;
 
   printf("Nom du fichier texte a convertir :");
   scanf("%s",NomFichierTexte);
   
   strcpy(NomFichierBinaire,NomFichierTexte);
   strcat(NomFichierBinaire,".bin");
   
   nbeleves=0 ;
   
   printf("Generation du fichier : %s\n",NomFichierBinaire);
   
   entree=fopen(NomFichierTexte,"r");
   sortie=fopen(NomFichierBinaire,"wb");
   
   if ( (entree == NULL) || (sortie == NULL) )
   {
      printf("Pb acces fichier %s ou %s\n",NomFichierTexte,NomFichierBinaire);
   }
   else
   {
      while ( (! feof(entree)) )
      {
        erreur=fscanf(entree,"%s %s %d",eleve.nom,eleve.prenom,&eleve.age);
        if (erreur != EOF)
        {
          printf("   %s %s %d\n",eleve.nom,eleve.prenom,eleve.age);
          tab_eleves[nbeleves++] = eleve;
          
        }
      }
      printf("Lecture  %s : %d eleves\n",NomFichierTexte,nbeleves);
      
      taille_structure_etudiant = sizeof(struct etudiant);

      nbeleves_ecrits=fwrite(tab_eleves,taille_structure_etudiant,nbeleves,sortie);
      printf("Ecriture %s : %d eleves\n",NomFichierBinaire,nbeleves_ecrits); 
   }

   fclose(entree);
   fclose(sortie);
}

/* --- conversion fichier binaire en fichier texte ---*/
void conversion_binaire_texte()
{
   FILE *entree, *sortie ;
   char NomFichierTexte[TAILLE_NOM_FICHIER] ,NomFichierBinaire[TAILLE_NOM_FICHIER];
   struct etudiant eleve ;
   int i, erreur, nbeleves_lus, nbeleves_a_lire, taille_structure_etudiant;
 
   /* --- saisie du nom du fichier binaire a lire --- */
   printf("Nom du fichier binaire a convertir :");
   scanf("%s",NomFichierBinaire);
   
   strcpy(NomFichierTexte,NomFichierBinaire);
   strcat(NomFichierTexte,".txt");
   
   nbeleves=0 ;
   
   printf("Generation du fichier : %s\n",NomFichierTexte);
   
   /* -- ouverture des fichiers --- */
   entree=fopen(NomFichierBinaire,"rb");
   sortie=fopen(NomFichierTexte,"w");
   
   if ( (entree == NULL) || (sortie == NULL) )
   {
      printf("Pb acces fichier %s ou %s\n",NomFichierTexte,NomFichierBinaire);
   }
   else
   {
      while ( (! feof(entree)) )
      {
        /* -- lecture du fichier binaire --- */
        nbeleves_a_lire=1 ;
        taille_structure_etudiant=sizeof(struct etudiant);
        
        nbeleves_lus=fread(&eleve,taille_structure_etudiant,nbeleves_a_lire,entree);
       
        /* --- chargement du tableau --- */
        if (nbeleves_lus == 1)
        {
          printf("   %s %s %d\n",eleve.nom,eleve.prenom,eleve.age);
          tab_eleves[nbeleves++] = eleve;
        }        
      }
      printf("Lecture %s : %d eleves\n",NomFichierBinaire,nbeleves);
      
      /* --- boucle de sauvegarde dans un fichier texte --- */
      for (i=0 ; i<nbeleves ; i++)
      {
       eleve=tab_eleves[i] ;
       fprintf(sortie,"%s %s %d\n",eleve.nom,eleve.prenom,eleve.age);
      }
      printf("Ecriture %s : %d eleves\n",NomFichierTexte,i);
   }

   fclose(entree);
   fclose(sortie);
}

