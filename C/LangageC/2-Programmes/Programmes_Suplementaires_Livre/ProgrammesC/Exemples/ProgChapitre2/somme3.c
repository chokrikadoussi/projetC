/* ---------- */
/* somme3.c   */
/* ---------- */

#include <stdio.h>

int calcul();

int a, b ;

int main()
{
 int somme ;

 printf("Entrez deux entiers : ");
 scanf("%d %d",&a,&b);

 somme = calcul() ;

 printf("La somme de %d et de %d est : %d\n",a,b,somme);
}

int calcul()
{
  int resultat ;

  resultat = a+b ;

  return resultat ;
  
}
