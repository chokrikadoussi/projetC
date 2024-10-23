#include <stdio.h>

int main()
{
  char nom[20],saisie[20];
  char Npersonne[20],Ppersonne[20];
  
  FILE *sortie ;
  
  printf("Nom du fichier :");
  scanf("%s",nom);
  
  sortie=fopen(nom,"w");
  if (sortie == NULL)
  {
    printf("Pb acces fichier %s\n",nom);
  
  }
  else
  {
    printf("ouverture ok\n");
    printf("Entrez un nom    : ");
    scanf("%s",Npersonne);
    printf("          prenom : ");
    scanf("%s",Ppersonne);
    
    fprintf(sortie,"%s %s\n",Npersonne,Ppersonne);
    printf("%s %s sauvegarde dans le fichier %s\n",Npersonne,Ppersonne,nom);
  }
  
  
  fclose(sortie);

}
