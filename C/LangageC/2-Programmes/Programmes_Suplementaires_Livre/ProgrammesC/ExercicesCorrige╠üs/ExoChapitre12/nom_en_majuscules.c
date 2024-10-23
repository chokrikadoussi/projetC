/* ------------------- */
/* nom_en_majuscules.c */
/* ------------------- */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

main()
{
  char nom[20] ;
  int i ;

  printf("Entrez un nom en minuscules:");
  scanf("%s",nom);

  for (i=0;i<strlen(nom);i++)
      nom[i]=toupper(nom[i]);

  printf("nom en majuscules:%s\n",nom);
}
