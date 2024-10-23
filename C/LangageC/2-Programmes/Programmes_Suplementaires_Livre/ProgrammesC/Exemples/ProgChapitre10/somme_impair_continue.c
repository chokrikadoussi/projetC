/* ----------------------- */
/* somme_impair_continue.c */
/* ----------------------- */
#include <stdio.h>

int main()
{
 int somme=0, i ;
 int impair     ;

 printf("Nombres impairs:");
 for (i=1; i<20; i++)
 {
   impair=i%2;

   if (! impair )
      continue ;
   printf("%3d",i);
   somme+=i;
 }
 printf("\nSomme = %d\n",somme);
}
