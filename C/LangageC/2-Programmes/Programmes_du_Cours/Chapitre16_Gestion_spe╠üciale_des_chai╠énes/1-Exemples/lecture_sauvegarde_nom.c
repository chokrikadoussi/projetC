/* ------------------------- */
/* lecture_sauvegarde_nom.c  */
/* ------------------------- */
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void lire_chaine(char ch[])            ;
void trim(char *ch)                    ;
void conv_espace_en_souligne(char *ch) ;


int main()
{
  char nom[100], prenom[200];
  FILE *f1                  ;
  char NomFichier[200]      ;
  
  printf("Nom    : ")  ;
  lire_chaine(nom)     ;
  printf("Prénom : ")  ;
  lire_chaine(prenom)  ;
     
  printf("\n");
  printf("Nom saisi        : |%s|\n",nom);
  trim(nom);
  conv_espace_en_souligne(nom);
  printf("Nom sauvegardé   : |%s|\n",nom);
  
  printf("\n");
  printf("Prénom saisi     : |%s|\n",prenom);
  trim(prenom);
  conv_espace_en_souligne(prenom);
  printf("Prénom sauvegardé: |%s|\n",prenom);
  
  printf("Nom du fichier : ");
  scanf("%s", NomFichier);
  
  f1 = fopen(NomFichier,"w");
  fprintf(f1,"%s %s\n",nom,prenom);
  fclose(f1);
  
}

/* procédure outil de lecture d'une chaine avec des espaces */
void lire_chaine(char ch[])
{
  int  i=0    ;
  char lettre ;

  while ((lettre = getchar()) != '\n')
  {
     ch[i++] = lettre; /* on range chaque caractère lu dans la chaine */
  }
  ch[i] = '\0' ; /* on termine la chaine de caractère avec un caractère null */
}


/* procédure outil de retrait des espaces avan et après une chaine */
void trim(char *ch)
{
  char chaine1[200] ;
  int i = 0, j = 0 , k = 0 , taille = 0 ;

  if (strcmp(ch,"") != 0) /* On regarde si la chaine n'est pas vide */
  {
    /* --- suppression des espaces en début de chaine --- */
    while (isspace(ch[i++])); /* on passe les espaces en début de chaine */
    taille = strlen(ch);
    for (j=i-1 ; j<taille ; j++) chaine1[k++] = ch[j]; /* recopie des caractères APRES les espaces */
    chaine1[k++] = '\0' ; /* on finalise la chaine */
    strcpy(ch,chaine1)  ; /* on recopie la chaine traitée dans ch */
    /* --- suppression des espaces en fin de chaine --- */
    i = strlen(ch);
    while (isspace(ch[--i])); /* on passe les espaces */
    ch[++i] = '\0' ; /* on finalise la chaine */
  }
}


/* procédure outil de retrait des espaces avan et après une chaine */
void conv_espace_en_souligne(char *ch)
{
  int i=0, taille ;
  if (strcmp(ch,"") != 0) /* On regarde si la chaine n'est pas vide */
  {
    taille = strlen(ch);
    for (i = 0 ; i<taille ; i++)
    {
      if (ch[i] == ' ') ch[i] = '_';
    }
  }
}


