/* -------------- */
/* affiche_exit.c */
/* -------------- */
#include <stdio.h>
#include <stdlib.h>

void fin_programme() ;

int main()
{
 int saisie ;

 atexit(fin_programme);

 printf("Entrez un nombre entier:");
 scanf("%d",&saisie);
 
 exit(saisie);
}
void fin_programme()
{
 printf("Programme termin?\n");
}

