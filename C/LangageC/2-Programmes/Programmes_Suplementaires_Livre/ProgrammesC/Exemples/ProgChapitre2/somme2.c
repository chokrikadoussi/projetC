/* --------- */
/* somme2.c   */
/* --------- */

#include <stdio.h>

int calcul (int i , int j) ;

int main()
{
 int a, b, somme ;

 printf("Entrez deux entiers : ");
 scanf("%d %d",&a,&b);

 somme = calcul(a,b) ;

 printf("La somme de %d et de %d est : %d\n",a,b,somme);
}

int calcul (int i , int j)
{
  int resultat ;

  resultat = i+j ;

  return resultat ;
  
}
