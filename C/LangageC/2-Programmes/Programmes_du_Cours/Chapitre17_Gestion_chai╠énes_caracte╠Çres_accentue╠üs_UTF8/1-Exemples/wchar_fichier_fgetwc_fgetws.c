#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>
#include <locale.h> /* pour setlocale UTF8 */
#define TAILLE 100
 
int main(void)
{
   FILE    *fichier                 ;
   wchar_t chaineW[TAILLE], LettreW ;
   int     i                        ;
   wint_t retour                    ;
   wchar_t * retourW                ;

   setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */
 
   // --------------
   // --- fgetwc ---
   // --------------
   if (NULL == (fichier = fopen("fputwc.txt", "r"))) 
   {
      wprintf(L"Impossible d'ouvrir : \"fputwc.txt\".\n");
   }
   else
   {
     errno = 0;                                                 
     while (WEOF != (LettreW = fgetwc(fichier)))
     {                    
       wprintf(L"fgetwc : LettreW = |%lc|\n", LettreW);
     } 
     /* 
     if (LettreW == WEOF)
     {                                                                              
        printf("Erreur de lecture via fgetwc() du caractère étendu\n");
        if (EILSEQ == errno)
        {                                     
          wprintf(L"Un caractère étendu invalide a été rencontré.\n");
        }
     }
     */
     fclose(fichier);
   }
   // --------------
   // --- fgetws ---
   // --------------
   if (NULL == (fichier = fopen("fputws.txt", "r"))) 
   {
      wprintf(L"Impossible d'ouvrir : \"fputws.txt\".\n");
   }
   else
   {
     errno = 0;
     retourW = fgetws(chaineW, TAILLE, fichier);
     if (retourW == NULL)
     {
        printf("Erreur de lecture via fgetws() du texte étendu chaineW = |%ls|\n", chaineW);
        if (EILSEQ == errno)
          wprintf(L"Un caractère étendu invalide a été rencontré.\n");
     }
     else
     {
       wprintf(L"fgetws : chaineW = |%ls|\n", chaineW);     
     }
     fclose(fichier);
   }
}