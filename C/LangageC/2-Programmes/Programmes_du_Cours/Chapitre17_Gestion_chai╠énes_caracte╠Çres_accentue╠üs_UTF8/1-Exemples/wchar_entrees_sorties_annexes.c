#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */
#define TAILLE 100 

int main()
{
 wchar_t Initiale        ;
 wchar_t Nom[TAILLE] = {0}, Prenom[TAILLE] = {0}, *pNom, NomComplet[2*TAILLE] = {0}   ;
 wchar_t Affiche[TAILLE] = {0}   ;
 int resultat ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 wprintf(L"Entrez un nom avec des accents : ");
 pNom = fgetws(Nom, TAILLE, stdin); // On lit nom via fgetws, équivalent de la fonction fgets.
 // Attention Nom ou pNom contiennent également la fin de ligne !!! 
 wprintf(L"Nom   = |%ls|\n",Nom)   ;
 wprintf(L"pNom  = |%ls|\n",pNom)  ;

 resultat = fputws(Nom,stdout)   ;
 swprintf(Affiche,TAILLE,L"Le nom est : %ls et sa longueur est :%d",Nom,wcslen(Nom));                                 
 wprintf(L"|%ls|\n",Affiche);

 wcscpy(NomComplet, L"Léçi Frédéric")   ;
 wprintf(L"NomComplet=|%ls|\n",NomComplet);
 swscanf(NomComplet,L"%ls %ls",Nom,Prenom);                                 
 wprintf(L"|%ls|\n",Nom);
 wprintf(L"|%ls|\n",Prenom);
}


