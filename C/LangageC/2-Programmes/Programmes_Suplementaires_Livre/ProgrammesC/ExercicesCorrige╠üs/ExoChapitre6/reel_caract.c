/* ------------- */
/* reel_caract.c */
/* ------------- */
#include <stdio.h>
#include <math.h>

main()
{
 char c1,c2,c3,c4,c5 ;
 float pdeci, x ;
 int pent ;
 
 printf("Entrez nombre avec une virgule :");
 scanf("%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5);
 /* recuperation de la valeur avant la virgule */
 pent = ((c1-48)*10)+(c2-48);
 /* c3 n'est pas traite. C'est la virgule */
 /* recuperation de la valeur apres la virgule */
 pdeci = ((c4-48)/10.0)+((c5-48)/100.0);
 x=pent+pdeci; 
 printf("La racine de %f est: %f\n",x, sqrt(x));
}
