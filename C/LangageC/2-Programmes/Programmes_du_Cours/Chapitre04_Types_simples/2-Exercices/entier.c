/* -------------------- */
/* Programme entier.c  */
/* -------------------- */

#include <stdio.h>

int main()
{

 /* ******************** */
 /* *** declarations *** */
 /* ******************** */
 int a , b ;
 int somme, soust, mult, quotient, reste ;

 /* ******************** */
 /* *** instructions *** */ 
 /* ******************** */

 printf("Entrez 2 entiers : ");
 
 /* --- saisie --- */
 scanf("%d %d",&a,&b);

 /* --- calcul --- */
 somme=a+b   ;
 soust=a-b   ;
 mult=a*b    ;
 quotient=a/b;
 reste=a%b   ;

 /* --- affichage --- */
 printf("%d + %d = %d\n",a,b,somme)   ;
 printf("%d - %d = %d\n",a,b,soust)   ;
 printf("%d * %d = %d\n",a,b,mult)    ;
 printf("%d / %d = %d\n",a,b,quotient);
 printf("%d %% %d = %d\n",a,b,reste)  ;

}

