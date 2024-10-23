/* --------------- */
/* appel_systeme.c */
/* --------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 char commande[30],nomfichier[20],liste[20];
 int code_retour;

 /* vérification de la disponibilité d'un shell */
 code_retour=system(NULL);
 if (code_retour)
 {
   /* Commande UNIX pour lister les fichiers */
   printf("Liste des fichiers (*.txt):");
   scanf("%s",liste);
   strcpy(commande,"ls ");
   strcat(commande,liste);
   
   printf("--- Liste des fichiers %s ---\n",liste);
   code_retour=system(commande);
  
   if (!code_retour)
   {
    /* Saisie du nom du fichier a afficher */
    printf("Fichier à afficher:");
    scanf("%s",nomfichier);
   
    /* Mise en forme de la commande d'affichage */
    strcpy(commande,"cat ");
    strcat(commande,nomfichier);
    printf("--- %s ---\n",commande);
    system(commande);
   }
 }
}

