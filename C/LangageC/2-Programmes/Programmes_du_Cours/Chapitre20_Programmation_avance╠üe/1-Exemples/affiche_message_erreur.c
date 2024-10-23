/* ------------------------ */
/* affiche_message_erreur.c */
/* ------------------------ */
#include <stdio.h>
#include <string.h>

int main()
{
 int saisie=1 ;

 while (saisie)
 {
   printf("Entrez un code d'erreur:");
   scanf("%d",&saisie);
   fprintf(stderr,"Erreur : %d\n",saisie); 
   fprintf(stderr,"Message: %s\n",strerror(saisie)); 
 }
}

