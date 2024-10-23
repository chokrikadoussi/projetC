/* -------------- */
/* bouclesaisie.c */
/* ----------- -- */
#include <stdio.h>
#include <ctype.h>

main()
{
 /* declaration et initialisation a l'espace */
 char c1=' ', bidon ;

 while (c1 != 'Q')
 {
   printf("Entrez une lettre Majuscule (Q=FIN) :");
   c1=getchar() ;
   /* on lit le caractere fin de ligne */
   bidon=getchar() ;

   printf("La minuscule est : %c\n",tolower(c1));
 }
}
