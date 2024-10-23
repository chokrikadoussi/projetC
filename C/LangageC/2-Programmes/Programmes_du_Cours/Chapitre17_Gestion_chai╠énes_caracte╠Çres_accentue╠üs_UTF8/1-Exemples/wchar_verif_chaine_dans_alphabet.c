/* ----------------------------------- */
/* wchar_verif_chaine_dans_alphabet_wchar.c  */
/* ----------------------------------- */
#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

int verif_chaine_dans_alphabet_wchar(wchar_t ch[], wchar_t alphabet[]);
void affiche_caracteres_absents_alphabet_wchar(wchar_t ch[], wchar_t alphabet[]);

int main()
{
  wchar_t alpabet[]=L"éàçï ;" ;
  int nbcarAlphabet          ;
  wchar_t saisie[100]        ;
  int i,taille, ChaineDansAlphabet ;
 
   /* fixe la valeur a UTF-8 pour les caractères accentués */
  setlocale (LC_ALL, "fr_FR.UTF-8") ; 
 
  nbcarAlphabet=wcslen(alpabet);
  
  wprintf(L"Entrez une chaine de caractères avec des accents : ");
  wscanf(L"%l[^\n]",saisie); /* Lit tous les caractères sauf la fin de ligne (LF) */

  wprintf(L"Vérification que la chaîne |%ls| ne contient \n",saisie);
  wprintf(L"que des caractères parmi : |%ls|\n",alpabet);
  
  ChaineDansAlphabet=verif_chaine_dans_alphabet_wchar(saisie, alpabet);
  if (ChaineDansAlphabet)
     wprintf(L"Tous les caractères de la chaîne accentuée sont dans l'alphabet\n");
  else
  {
     wprintf(L"Certains caractères de la chaîne sont absent de l'alphabet\n");
     affiche_caracteres_absents_alphabet_wchar(saisie, alpabet);
  }
}

// ================================================================
// --- fonction de vérification que les caractères d'une chaîne ---
// --- sont dans un alphabet ---
// ================================================================
int verif_chaine_dans_alphabet_wchar(wchar_t ch[], wchar_t alphabet[])
{
  int verificationOK = 1, trouve = 0       ;
  wchar_t lettre, calphabet                   ;
  int taillech, taillealpha, i = 0, j = 0  ;

  taillech    = wcslen(ch)         ;
  taillealpha = wcslen(alphabet)   ;

  i=0;
  while ((i < taillech) && (verificationOK))
  {
    lettre = ch[i] ;
    trouve = 0     ;
    j = 0          ;
    while ((j < taillealpha) && (!trouve))
    {
      calphabet = alphabet[j];
      if (calphabet == lettre) trouve=1;
      j++;
    }
    /* Quand on sort de la boucle précédente si trouve est FAUX  */
    /* alors lettre n'a pas été trouvé dans alphabet */
    if (!trouve) verificationOK = 0;
    i++;
  }
  return verificationOK ;
}
// ==================================================================
// --- fonction d'affichage des caractères absents de l'alphabet ---
// ==================================================================
void affiche_caracteres_absents_alphabet_wchar(wchar_t ch[], wchar_t alphabet[])
{
  int trouve = 0       ;
  wchar_t lettre, calphabet                   ;
  int taillech, taillealpha, i = 0, j = 0  ;

  taillech    = wcslen(ch)         ;
  taillealpha = wcslen(alphabet)   ;

  i=0;
  while (i < taillech)
  {
    lettre = ch[i] ;
    trouve = 0     ;
    j = 0          ;
    while ((j < taillealpha) && (!trouve))
    {
      calphabet = alphabet[j];
      if (calphabet == lettre) trouve=1;
      j++;
    }
    /* Quand on sort de la boucle précédente si trouve est FAUX  */
    /* alors lettre n'a pas été trouvé dans alphabet */
    if (!trouve)
      wprintf(L"-> le caractère %lc absent de l'aphabet\n",lettre);
    i++;
  }
}