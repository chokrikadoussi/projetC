#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 wchar_t Nom[50] = {0}, Prenom[50] = {0}   ;
 FILE* fichier = NULL;
 char NomFichier[100] ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 // Saisie du Nom
 wprintf(L"Entrez un nom avec des accents : ");
 wscanf(L"%ls",Nom)              ;
 wprintf(L"Nom   = %ls\n",Nom)   ;
 // Saisie du Prénom
 wprintf(L"Entrez un prénom avec des accents : ");
 wscanf(L"%ls",Prenom)              ;
 wprintf(L"Prénom   = %ls\n",Prenom)   ;
 // Saisie du nom du fichier
 wprintf(L"Nom du fichier à écrire : ")  ;
 wscanf(L"%s",NomFichier)       ;
 // Sauvegarde
 wprintf(L"Sauvegarde dans le fichier : %s\n",NomFichier);
 fichier = fopen(NomFichier, "w"); // On ouvre le fichier en mode écriture.
 fwprintf(fichier,L"%ls %ls\n",Nom,Prenom); // Ecriture du Nom et du Prénom
 fclose(fichier); // On ferme le fichier.
}


