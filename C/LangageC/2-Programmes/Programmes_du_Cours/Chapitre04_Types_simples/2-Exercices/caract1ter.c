#include <stdio.h>
int main()
{
/* ******************** */
 /* *** declarations *** */
 /* ******************** */
 char c   ;
 int code ;

 /* ******************** */
 /* *** instructions *** */ 
 /* ******************** */

 printf("Entrez un code ASCII : ");
 scanf("%d",&code);
 printf("Le caractère est : %c\n",code);

 /* lecture du caractère LF qui traine dans le buffer */
 while(getchar() !='\n');

 printf("Entrez un caractère :");
 scanf("%c",&c);
 printf("Le code ASCII est : %d\n",c);
}
