#include <stdio.h>
int main()
{
/* ******************** */
 /* *** declarations *** */
 /* ******************** */
 char c1, c2       ;
 int code1, code2  ;

 /* ******************** */
 /* *** instructions *** */ 
 /* ******************** */

 printf("Entrez un code ASCII : ");
 scanf("%d",&code1);
 c1 = code1 ;
 printf("Le caractère est : %c\n",c1);

 printf("Entrez un caractère :");
 scanf("%c",&c2);
 code2 = c2 ;
 printf("Le code ASCII est : %d\n",code2);
}


