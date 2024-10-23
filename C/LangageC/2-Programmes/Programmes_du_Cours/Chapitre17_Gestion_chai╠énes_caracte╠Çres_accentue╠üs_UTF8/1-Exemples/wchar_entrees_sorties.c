#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 wchar_t Initiale        ;
 wchar_t Nom[50] = {0}   ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 wprintf(L"--- Saisie et affichage ---\n");
 wprintf(L"Entrez une lettre accentuée : ");
 wscanf(L"%lc",&Initiale)            ;
 wprintf(L"Initiale = %lc\n",Initiale)  ;
 
 wprintf(L"Entrez un nom avec des accents : ");
 wscanf(L"%ls",Nom)              ;
 wprintf(L"Nom   = %ls\n",Nom)   ;
}


