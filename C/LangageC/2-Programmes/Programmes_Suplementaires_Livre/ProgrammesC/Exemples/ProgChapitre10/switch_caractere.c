/* ------------------ */
/* switch_caractere.c */
/* ------------------ */
#include <stdio.h>

int main()
{
 char saisie ;

 printf("Voulez vous continuer:");
 saisie=getchar();

 switch (saisie)
 {
    case 'o' :
    case 'O' :
    case 'y' :
    case 'Y' : printf("Traitement en cours ...\n");
	       break ;
    case 'n' :
    case 'N' : printf("Retour au menu ...\n");
	       break ;
    default : printf("r