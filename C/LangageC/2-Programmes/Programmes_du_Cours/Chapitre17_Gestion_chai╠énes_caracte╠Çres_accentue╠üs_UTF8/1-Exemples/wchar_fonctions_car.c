/* --------------------- */
/* wchar_fonctions_car.c */
/* -------------------- */
#include <stdio.h>
#include <wchar.h>  /* Pour le type wchar_t */
#include <locale.h> /* Pour setlocale UTF8 */

int main()
{
 wchar_t LettreW1, LettreW2, LettreW3 ;
 
 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Fixe la valeur a UTF-8 */
 
 wprintf(L"--- Conversion en majuscule ---\n");
 wprintf(L"Entrez une lettre accentuée minucule : ");
 wscanf(L"%lc",&LettreW1)            ;
 wprintf(L"Lettre saisie = %lc\n",LettreW1);
 if (iswlower(LettreW1))
 {
   LettreW2 = towupper(LettreW1);
   wprintf(L"Majuscule (towupper) = %lc\n",LettreW2);
 }
 else
   wprintf(L"Ce n'est pas une lettre minucule\n");

 while(getchar()!='\n'); /* On vide le buffer pour la saisie suivante */

 wprintf(L"--- Conversion en minuscule ---\n");
 wprintf(L"Entrez une lettre accentuée majuscule : ");
 wscanf(L"%lc",&LettreW1)            ;
 wprintf(L"Lettre saisie = %lc\n",LettreW1);
 if (iswupper(LettreW1))
 {
   LettreW2 = towlower(LettreW1);
   wprintf(L"Minuscule (towlower) = %lc\n",LettreW2);
 }
 else
 {
   wprintf(L"Ce n'est pas une lettre majuscule\n");
   /* On détermine la nature du caractère */
   if (iswalpha(LettreW1))
     wprintf(L"C'est une lettre aphabétique\n");
   if (iswalnum(LettreW1))
     wprintf(L"C'est une lettre aphanumérique\n");
   if (iswdigit(LettreW1))
     wprintf(L"C'est un chiffre\n");
   if (iswdigit(LettreW1))
     wprintf(L"C'est un chiffre héxadécimal\n");
   if (iswcntrl(LettreW1))
     wprintf(L"C'est caractère de contrôle\n");
   if (iswcntrl(LettreW1))
     wprintf(L"C'est caractère de contrôle\n");
   if (iswgraph(LettreW1))
     wprintf(L"C'est caractère imprimable\n");
   if (iswprint(LettreW1))
     wprintf(L"C'est caractère imprimable ou un espace\n");
   if (iswpunct(LettreW1))
     wprintf(L"C'est caractère imprimable sauf lettre, chiffre et espace\n");
   if (iswspace(LettreW1))
     wprintf(L"C'est caractère espace, tabulation ou de validation\n");
 }
}
