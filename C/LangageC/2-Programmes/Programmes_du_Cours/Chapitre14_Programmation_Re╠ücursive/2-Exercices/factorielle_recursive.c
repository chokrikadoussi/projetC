#include <stdio.h>

int factorielle(int nb);

int main()
{
 int compteur, N, resultat ;
 
 printf("Entrez un nombre : ") ;
 scanf("%d",&N) ;
 /* -- Appel de la fonction récursive -- */
 resultat=factorielle(N);
 printf("%d! = %d\n",N,resultat) ;
}
/* ----------------------- */
int factorielle(int nb)
{
 int res;

 if (nb<0) res=0;
 else if ((nb == 1) || (nb == 0)) res=1;
 else res=nb*factorielle(nb-1);
 return res ;
}
