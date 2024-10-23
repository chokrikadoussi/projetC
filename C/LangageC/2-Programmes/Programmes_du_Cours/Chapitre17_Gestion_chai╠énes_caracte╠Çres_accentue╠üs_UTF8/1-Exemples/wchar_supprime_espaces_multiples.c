/* ----------------------------------- */
/* wchar_supprime_espaces_multiples.c  */
/* ----------------------------------- */
#include <string.h>
#include <stdio.h>
#include <wchar.h>   /* Pour les fonctions de chaines wchar_t */
#include <locale.h>  /* pour la fonction setlocale */

void supprime_espaces_multiples_wchar(wchar_t *ch) ;

int main()
{
    wchar_t chaine1[1000] = L"   anaïs    léry,   frédérique     èphémâreùÙ";
    wchar_t *chaine2;

    setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur à UTF-8 */
 
    wprintf(L"AVANT : |%ls|\n", chaine1)   ;
    /* appel de la fonction */
    supprime_espaces_multiples_wchar(chaine1) ;
    wprintf(L"APRES : |%ls|\n", chaine1)   ;
}
// ===========================================================
// --- fonction outil de suppression des espaces multiples ---
// ===========================================================
void supprime_espaces_multiples_wchar(wchar_t *ch)
{
      wchar_t chaine1[200] ;
      int i = 0, j = 0 , taille = 0, espace_rencontre=0 ;

      if (wcscmp(ch,L"") != 0) /* On teste si la chaine n'est pas vide */
      {
         taille = wcslen(ch);
         for (i=0 ; i< taille ; i++)
         {
            if (ch[i]!= L' ')
            {
                chaine1[j++]=ch[i];
                espace_rencontre=0;
            }
            else
            {
              if (!espace_rencontre)
              {
                 chaine1[j++]=ch[i] ;
                 espace_rencontre=1;
              }
            }
         }
         chaine1[j]=L'\0';
         wcscpy(ch,chaine1);
      }
}

