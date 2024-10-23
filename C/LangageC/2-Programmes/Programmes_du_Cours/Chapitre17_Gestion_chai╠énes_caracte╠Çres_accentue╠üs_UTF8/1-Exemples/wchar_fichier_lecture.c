#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 wchar_t Nom[50] = {0}, Prenom[50] = {0}   ;
 FILE* fichier = NULL;
 char NomFichier[100] ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 // Saisie du nom du fichier
 wprintf(L"Nom du fichier à lire : ")  ;
 wscanf(L"%s",NomFichier)       ;
 // Lecture
 fichier = fopen(NomFichier, "r"); // On ouvre le fichier en mode lecture.
 fwscanf(fichier,L"%ls %ls\n",Nom,Prenom); // Lecture du Nom et du Prénom
 fclose(fichier); // On ferme le fichier.
 // affichage à l'écran du Nom et du Prénom
 wprintf(L"Nom = %ls - Prénom = %ls\n",Nom,Prenom)   ;
}


