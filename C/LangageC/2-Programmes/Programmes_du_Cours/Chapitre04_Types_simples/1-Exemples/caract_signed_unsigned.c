#include <stdio.h>
#include <ctype.h>
int main()
{
/* ******************** */
 /* *** declarations *** */
 /* ******************** */
 char c1, c2 ;
 int code    ;

 /* ******************** */
 /* *** instructions *** */ 
 /* ******************** */

 printf("Entrez une MAJUSCULE : ");
 
 /* --- saisie --- */
 c1=getc(stdin);     /*ou   scanf("%c",&c1); */

 /* --- code ascii --- */
 code = c1    ;
 
 /* --- minuscule --- */
 c2 = tolower(c1) ;
 
 /* --- affichage --- */
 printf("le code ascii de %c  est %d la minuscule est ",c1,code)   ;
 putc(c2,stdout);
 putc('\n',stdout);
}


