/* -------------- */
/* conv_euros.c   */
/* -------------- */

#include <stdio.h>
#include <math.h>

int main()
{
   float  Euros ;
   double Francs ;

   /* saisie des euros */
   printf("Entrez la valeur en Euros (ex 12.5) :");
   scanf("%f",&Euros);

   /* conversion en francs avec la fonction floor() */
   Francs = (floor((Euros * 6.55957)*100))/100 ;

   printf("Valeur en Francs : %f\n",Francs);

}
