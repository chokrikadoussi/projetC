#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>
#include <locale.h> /* pour setlocale UTF8 */
#define TAILLE 100
 
int main(void)
{
   FILE    *fichier;
   wchar_t chaineW[TAILLE] = L"Une chaîne de caractères par Léry.";
   int     i     ;
   wint_t retour ;

   setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */
 
   // --- fputwc ---
   if (NULL == (fichier = fopen("fputwc.txt", "w"))) 
   {
      wprintf(L"Impossible d'ouvrir : \"fputwc.txt\".\n");
   }
   else
   {
     for (i = 0; chaineW[i] != L'\0'; i++)
     {
        errno = 0;
        retour = fputwc(chaineW[i], fichier);
        if (retour == WEOF)
        {
         printf("Erreur d'écriture via fputwc() du caractère étendu chaineW[%d] = |%lc|\n", i, chaineW[i]);
         if (EILSEQ == errno)
            wprintf(L"Un caractère étendu invalide a été rencontré.\n");
        }
     }
     fclose(fichier);
   }
   // --- fputws ---
   if (NULL == (fichier = fopen("fputws.txt", "w"))) 
   {
      wprintf(L"Impossible d'ouvrir : \"fputws.txt\".\n");
   }
   else
   {
     errno = 0;
     retour = fputws(chaineW, fichier);
     if (retour == EOF)
     {
        printf("Erreur d'écriture via fputws() du texte étendu chaineW = |%ls|\n", chaineW);
        if (EILSEQ == errno)
          wprintf(L"Un caractère étendu invalide a été rencontré.\n");
     }
     fclose(fichier);
   }
}