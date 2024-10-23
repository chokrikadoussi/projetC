/* ----------------- */
/* moyenne_mention.c */
/* ----------------- */
#include <stdio.h>

main()
{
 float n1,n2,n3,c1,c2,c3, moyenne ;
 int moyenne_entiere ;

 printf("Entrez 3 notes :");
 scanf("%f %f %f",&n1,&n2,&n3);
 printf("Entrez 3 coefficients :");
 scanf("%f %f %f",&c1,&c2,&c3);

 /* calcul de la moyenne */
 moyenne=((n1*c1)+(n2*c2)+(n3*c3))/(c1+c2+c3);
 printf("Votre moyenne est : %5.2f\n",moyenne);

 /* calcul de la note entiere proche a 0.5 pres */
 /* de la mention superieure                    */
 moyenne_entiere = moyenne+0.5 ;
 if (moyenne_entiere > moyenne)
    printf("moyenne arrondi a : %d\n",moyenne_entiere);

 switch(moyenne_entiere)
 {
   case 10:
   case 11: printf("Mention Passable\n");
	    break;
   case 12:
   case 13: printf("Mention Assez Bien\n");
	    break;
   case 14:
   case 15: printf("Mention Bien\n");
	    break;
   case 16:
   case 17:
   case 18:
   case 19:
   case 20: printf("Mention Tr