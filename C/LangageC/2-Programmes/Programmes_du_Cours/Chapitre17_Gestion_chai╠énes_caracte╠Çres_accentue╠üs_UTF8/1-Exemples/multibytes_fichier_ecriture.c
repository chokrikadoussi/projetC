#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 char Nom[50] = {0}, Prenom[50] = {0}   ;
 FILE* fichier = NULL;
 char NomFichier[100] ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 // Saisie du Nom
 printf("Entrez un nom avec des accents : ");
 scanf("%s",Nom)              ;
 printf("Nom   = %s\n",Nom)   ;
 // Saisie du Prénom
 printf("Entrez un prénom avec des accents : ");
 scanf("%s",Prenom)              ;
 printf("Prénom   = %s\n",Prenom)   ;
 // Saisie du nom du fichier
 printf("Nom du fichier à écrire : ")  ;
 scanf("%s",NomFichier)       ;
 // Sauvegarde
 printf("Sauvegarde dans le fichier : %s\n",NomFichier);
 fichier = fopen(NomFichier, "w"); // On ouvre le fichier en mode écriture.
 fprintf(fichier,"%s %s\n",Nom,Prenom); // Ecriture du Nom et du Prénom
 fclose(fichier); // On ferme le fichier.
}


