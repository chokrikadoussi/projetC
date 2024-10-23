/* -------------------- */
/* Programme caract.c  */
/* -------------------- */
#include <stdio.h>

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
 c1=getchar();     /*ou   scanf("%c",&c1); */

 /* --- code ascii --- */
 code = c1    ;
 
 /* --- minuscule --- */
 c2 = c1 - 'A' + 'a' ;
 
 /* --- affichage --- */
 printf("le code ascii de %c  est %d, la minuscule est %c\n",c1,code,c2)   ;
}

