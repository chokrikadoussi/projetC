/* --------- */
/* ifelse1.c */
/* --------- */
#include <stdio.h>

main()
{
 float nb, pdeci ;
 int pent , saisieOK ;

 printf("Entrez un nombre :");
 saisieOK = scanf("%f",&nb);
 if (saisieOK)
 {
   /* calcul partie entiere et decimale */
   pent=nb;
   pdeci=nb-pent;
  
   if (pent == nb)
   {
     printf("Le nombre %d est un entier\n",pent);
   }
   else
   {
     printf("Le nombre %f est un r