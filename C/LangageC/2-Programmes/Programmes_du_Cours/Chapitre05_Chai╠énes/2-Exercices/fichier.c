#include <stdio.h>

int main()
{
  char NomFichier[20]     ;
  char Nom[20],Prenom[20] ;
  int Age                 ;
  
  FILE *sortie            ;
  
  /* --- Saisie du nom du fichier --- */
  printf("NomFichier du fichier :");
  scanf("%s",NomFichier);
  
  /* --- ouverture du fichier en Ecrasement --- */
  sortie=fopen(NomFichier,"w");
  if (sortie == NULL)
  {
    printf("Pb acces fichier %s\n",NomFichier);
  
  }
  else
  {
    /* --- Saisie des informations au clavier --- */
    printf("Entrez un Nom    : ");
    scanf("%s",Nom)              ;
    printf("          Prenom : ");
    scanf("%s",Prenom)           ;
    printf("          Age    : ");
    scanf("%d",&Age)             ;
   
    /* --- Enregistrement des informations dans le fichier --- */
    fprintf(sortie,"%s %s %d\n",Nom,Prenom,Age);
    
    /* --- Echo a l'ecran du travail effectue --- */
    printf("%s Enregistre dans %s !\n",Nom,NomFichier); 

    fclose(sortie);
  }
}
