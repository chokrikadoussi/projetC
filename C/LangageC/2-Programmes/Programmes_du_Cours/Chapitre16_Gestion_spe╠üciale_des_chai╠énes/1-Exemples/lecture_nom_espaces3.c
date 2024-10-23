/* ---------------------- */
/* lecture_nom_espace3.c   */
/* ---------------------- */
#include <stdio.h>

int main()
{
  char nom[100], prenom[200];
  
  printf("Nom    : ")    ;
  scanf("%[^\n]",nom)    ;
  while(getchar()!='\n') ; /* on vide le buffer */ 
  printf("Prénom : ")    ;
  scanf("%[^\n]",prenom) ;
     
  printf("Nom saisi    : |%s|\n",nom);
  printf("Prénom saisi : |%s|\n",prenom);
  
}
