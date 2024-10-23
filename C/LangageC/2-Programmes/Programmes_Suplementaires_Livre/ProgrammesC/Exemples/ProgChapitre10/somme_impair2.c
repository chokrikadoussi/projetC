/* --------------- */
/* somme_impair2.c */
/* --------------- */
#include <stdio.h>

int main()
{
 int somme=0, i ;

 printf("Nombres impairs:");
 for (i=1; i<20; i+=2)
 {
   printf("%3d",i);
   somme+=i;
 }
 printf("\nSomme = %d\n",somme);
}
