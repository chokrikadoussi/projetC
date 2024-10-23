#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 wchar_t Initiale   = L'é'       ;
 wchar_t texte1[50] = L"Anaïs" ;
 wchar_t texte2[50] = {L'A', L'n', L'a', L'ï', L's', L'\0'} ;
 wchar_t Nom[50] = {0}           ;

 /* positionnement de la table de codage */
 //setlocale (LC_ALL, "") ; /* valeur selon environnement */
 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur a UTF-8 */

 wprintf(L"--- Valeurs initialisées ---\n");
 wprintf(L"Initiale = %lc\n",Initiale) ;
 wprintf(L"texte1   = %ls\n",texte1)   ;
 wprintf(L"texte2   = %ls\n",texte2)   ;
}


