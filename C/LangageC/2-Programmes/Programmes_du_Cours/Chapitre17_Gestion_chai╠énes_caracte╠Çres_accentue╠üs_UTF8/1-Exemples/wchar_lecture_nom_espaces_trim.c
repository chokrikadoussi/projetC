/* --------------------------------- */
/* wchar_lecture_nom_espace_trim.c   */
/* --------------------------------- */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>   /* Pour les fonctions de chaines wchar_t */
#include <wctype.h>  /* Pour les fonctions de caractères wchar_t */
#include <locale.h>  /* pour la fonction setlocale */


void lire_chaine_whar(wchar_t ch[]);
void trim_wchar(wchar_t *ch)        ;


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
  trim_wchar(nom);
  wprintf(L"Nom après trim_wchar()   : |%ls|\n",nom);
  
  wprintf(L"\n");
  wprintf(L"Prénom saisi       : |%ls|\n",prenom);
  trim_wchar(prenom);
  wprintf(L"Nom après trim_wchar()   : |%ls|\n",prenom);
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


/* procédure outil de retrait des espaces avant et après une chaine */
void trim_wchar(wchar_t *ch)
{
      wchar_t chaine1[200] ;
      int i = 0, j = 0 , k = 0 , taille = 0 ;

      if (wcscmp(ch,L"") != 0) /* On regarde si la chaine n'est pas vide */
      {
         /* --- suppression des espaces en début de chaine --- */
         while (iswspace(ch[i++])); /* on passe les espaces en début de chaine */
         taille = wcslen(ch);
         for (j=i-1 ; j<taille ; j++) chaine1[k++] = ch[j]; /* recopie des caractères APRES les espaces */
         chaine1[k++] = L'\0' ; /* on finalise la chaine */
         wcscpy(ch,chaine1)  ; /* on recopie la chaine traitée dans ch */
         /* --- suppression des espaces en fin de chaine --- */
         i = wcslen(ch);
         while (iswspace(ch[--i])); /* on passe les espaces */
         ch[++i] = L'\0' ; /* on finalise la chaine */
      }
}

