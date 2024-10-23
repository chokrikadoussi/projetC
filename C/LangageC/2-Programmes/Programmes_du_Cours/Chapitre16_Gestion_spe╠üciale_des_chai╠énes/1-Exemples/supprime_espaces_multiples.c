/* ----------------------------- */
/* supprime_espaces_multiples.c  */
/* ----------------------------- */

#include <string.h>
#include <stdio.h>
 
void supprime_espaces_multiples(char *ch) ;

int main()
{
    char chaine1[1000] = "   anaïs    léry,   frédérique     èphémâreùÙ";
    char *chaine2;
 
    printf("AVANT : |%s|\n", chaine1)   ;
    /* appel de la fonction */
    supprime_espaces_multiples(chaine1) ;
    printf("APRES : |%s|\n", chaine1)   ;

}

// ===========================================================
// --- fonction outil de suppression des espaces multiples ---
// ===========================================================

void supprime_espaces_multiples(char *ch)
{
      char chaine1[200] ;
      int i = 0, j = 0 , taille = 0, espace_rencontre=0 ;

      if (strcmp(ch,"") != 0) /* On teste si la chaine n'est pas vide */
      {
         taille = strlen(ch);
         
         for (i=0 ; i< taille ; i++)
         {
            if (ch[i]!= ' ')
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
         chaine1[j]='\0';
         strcpy(ch,chaine1);
      }
}

