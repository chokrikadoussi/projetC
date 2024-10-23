#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 char Nom[50] = {0}, Prenom[50] = {0}   ;
 FILE* fichier = NULL;
 char NomFichier[100] ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 // Saisie du nom du fichier
 printf("Nom du fichier à lire : ")  ;
 scanf("%s",NomFichier)       ;
 // Lecture
 fichier = fopen(NomFichier, "r"); // On ouvre le fichier en mode lecture.
 fscanf(fichier,"%s %s\n",Nom,Prenom); // Lecture du Nom et du Prénom
 fclose(fichier); // On ferme le fichier.
 // affichage à l'écran du Nom et du Prénom
 printf("Nom = %s - Prénom = %s\n",Nom,Prenom)   ;
}


