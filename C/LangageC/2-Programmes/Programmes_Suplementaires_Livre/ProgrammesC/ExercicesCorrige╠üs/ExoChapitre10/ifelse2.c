/* --------- */
/* ifelse2.c */
/* --------- */
#include <stdio.h>
#include <ctype.h>

main()
{
 char lettre ;

 printf("Entrez une lettre :");
 scanf("%c",&lettre);

 if (isupper(lettre)) /* majuscule */
 {
   printf("C'est la majuscule N