/* ---------------------- */
/* lecture_nom_espace.c   */
/* ---------------------- */
#include <stdio.h>

void lire_chaine(char ch[]);

int main()
{
  char nom[100], prenom[200];
  
  printf("Nom    : ")  ;
  lire_chaine(nom)  ;
  printf("Prénom : ")  ;
  lire_chaine(prenom)  ;
     
  printf("Nom saisi    : |%s|\n",nom);
  printf("Prénom saisi : |%s|\n",prenom);
  
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