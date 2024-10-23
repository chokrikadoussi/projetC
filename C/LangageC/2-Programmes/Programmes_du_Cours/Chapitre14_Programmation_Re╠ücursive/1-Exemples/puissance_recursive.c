#include <stdio.h>

float puissance(float x, int N) ;

int main()
{
 float nb, res ;
 int   m       ;

 printf("Entrez le nombre et sa puissance: ") ;
 scanf("%f %d",&nb,&m) ;
 /* -- Appel de la fonction récursive -- */
 res=puissance(nb,m);
 printf("%5.2f puissance %d =%10.4f\n",nb,m,res) ;
}

/* fonction puissance */
float puissance(float x, int N)
{
 float resultat;

 if (N == 0) resultat=1;
 else        resultat=x*puissance(x,N-1);
 return resultat ;
}
