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

/* --- definition preliminaire des procedures --- */
int saisie_eleve(struct etudiant *student);
void affichage(struct etudiant tabetud[]) ;
 
int main()
{
  int i ,finir_saisie ;
  struct etudiant   eleve ,tab_eleve[MAX_ETUDIANTS];

  /* --- boucle de saisie --- */
  i=0;
  finir_saisie=0;
  
  while (! finir_saisie)
  {
   finir_saisie   = saisie_eleve(&eleve);
   printf("echo nom |%s| \n",eleve.nom);
   tab_eleve[i++] = eleve ;
  }

  affichage(tab_eleve);
  
  
}
/*--- fonction de saisie d'un eleve --- */
int saisie_eleve(struct etudiant *student)
{
   struct etudiant studtmp ;
   int termine ;
   
   
   printf("Entrez un nom ( nom=fin   pour terminer):");
   scanf("%s",studtmp.nom);
   
   termine=((strcmp(studtmp.nom,"fin"))==0) ;

   if (! termine)
   {   
     printf("Entrez un prenom:");
     scanf("%s",studtmp.prenom);
  
     printf("Entrez un age:");
     scanf("%d",&studtmp.age);
     
     *student=studtmp ;
     nbeleves++ ;
   }   
   return termine ;
}
/*--- procedure d'affichage du tableau des eleves --- */
void affichage(struct etudiant tabetud[])
{
   int i ;
   
   printf("Verification saisie :");
  
   for (i=0 ; i < nbeleves ; i++)
   {
     printf("%s %s %d\n",tabetud[i].nom,tabetud[i].prenom,tabetud[i].age);
   }

 
} 
