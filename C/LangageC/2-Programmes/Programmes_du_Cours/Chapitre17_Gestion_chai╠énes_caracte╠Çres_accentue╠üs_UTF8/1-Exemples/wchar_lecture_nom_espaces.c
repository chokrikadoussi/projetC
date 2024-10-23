/* ---------------------------- */
/* wchar_lecture_nom_espace.c   */
/* ---------------------------- */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>   /* Pour les fonctions de chaines wchar_t */
#include <wctype.h>  /* Pour les fonctions de caractères wchar_t */
#include <locale.h>  /* pour la fonction setlocale */


void lire_chaine_whar(wchar_t ch[]);


int main()
{
  wchar_t nom[100], prenom[200];
  
  setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur à UTF-8 */

  wprintf(L"Nom    : ")  ;
  lire_chaine_whar(nom)     ;
  wprintf(L"Prénom : ")  ;
  lire_chaine_whar(prenom)  ;
     
  wprintf(L"\n");
  wprintf(L"Nom saisi          : |%ls|\n",nom);
  wprintf(L"Prénom saisi       : |%ls|\n",prenom);
}

/* procédure outil de lecture d'une chaine avec des espaces */
void lire_chaine_whar(wchar_t ch[])
{
  int  i=0    ;
  wchar_t lettre ;

  while ((lettre = getwchar()) != L'\n')
  {
     ch[i++] = lettre; /* on range chaque caractère lu dans la chaine */
  }
  ch[i] = L'\0' ; /* on termine la chaine de caractère avec un caractère null */
}
