/* ----------- */
/* puissance.c */
/* ----------- */
#include <stdio.h>

int main()
{
 float x, resultat ;
 int compteur, m ;

 printf("Entrez le nombre et sa puissance :");
 scanf("%f %d",&x,&m);

 compteur=0;
 resultat=1;

 while (compteur<m)
 {
  compteur++ ;
  resultat=resultat*x ;
 }
 printf("%5.2f puissance %d =%10.3f\n",x,m,resultat);
}
