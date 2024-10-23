/* --------------------------- */
/* lecture_nom_dans_fichier.c  */
/* --------------------------- */
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void conv_souligne_en_espace(char *ch) ;


int main()
{
  char nom[100], prenom[200];
  FILE *f1                  ;
  char NomFichier[200]      ;


  printf("Nom du fichier : ");
  scanf("%s", NomFichier);
  
  f1 = fopen(NomFichier,"r");
  fscanf(f1,"%s %s\n",nom,prenom);
  fclose(f1);
  
  conv_souligne_en_espace(nom);
  printf("Nom     : |%s|\n",nom);
  conv_souligne_en_espace(prenom);
  printf("Prénom  : |%s|\n",prenom);
  
}

/* procédure outil de retrait des espaces avan et après une chaine */
void conv_souligne_en_espace(char *ch)
{
  int i=0, taille ;
  if (strcmp(ch,"") != 0) /* On regarde si la chaine n'est pas vide */
  {
    taille = strlen(ch);
    for (i = 0 ; i<taille ; i++)
    {
      if (ch[i] == '_') ch[i] = ' ';
    }
  }
}


