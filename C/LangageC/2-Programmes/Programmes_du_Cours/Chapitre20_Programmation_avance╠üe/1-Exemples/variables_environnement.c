/* ------------------------- */
/* variables_environnement.c */
/* ------------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* variable globale externe */
extern char **environ;

int main()
{
  int i=0 ;
  char c,saisie[100],ma_var[100];

  /* saisie du contenu de la variable */
  printf("Contenu de la variable:");
  while((c=getchar())!='\n')
    saisie[i++]=c;
  saisie[i]='\0';

  /* mise en forme de la chaine */
  /* MA_VARIABLE=texte_saisie   */
  strcpy(ma_var,"MA_VARIABLE=");
  strcat(ma_var,saisie);

  /* positionnement de la variable */
  putenv(ma_var);

  /* consultation de la variable */
  printf("MA_VARIABLE: %s\n",getenv("MA_VARIABLE"));

  /* affichage de toutes les variables */
  printf("--- liste des variables ---\n");
  i=0;
  while (environ[i]!=NULL)
     printf("%s\n",environ[i++]);
}

