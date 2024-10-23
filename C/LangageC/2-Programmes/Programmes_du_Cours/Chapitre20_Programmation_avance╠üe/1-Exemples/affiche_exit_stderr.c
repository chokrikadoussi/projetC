/* --------------------- */
/* affiche_exit_stderr.c */
/* --------------------- */
#include <stdio.h>
#include <stdlib.h>

int main()
{
 int saisie ;

 printf("Entrez un nombre entier:");
 scanf("%d",&saisie);
 if (saisie)
    fprintf(stderr,"Erreur du programme: %d\n",saisie); 
 printf("Fin du programme\n");
 exit(saisie);
}

