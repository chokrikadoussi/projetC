#include <stdio.h>
#define MAX 200

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

float puissance(float x, int N)
{
 int i ;
 float resultat[MAX] ;

 resultat[0]=1 ;
 for (i=1 ;i<=N ;i++) 
   resultat[i]=x*resultat[i-1];
 return resultat[N] ;
}
