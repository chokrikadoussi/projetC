#include <stdio.h>
float puissance(float val, int p);

int main()
{
	float resultat, x ;
	int N ;

	printf("Entrez une valeur : ");
	scanf("%f",&x);
	printf("Entrez la puissance : ");
	scanf("%d",&N);
	resultat = puissance(x,N);
}
float puissance(float val, int p)
{
  float res ;

  if (p == 0)
  	res = 1 ;
  else
  	res = puissance(val,p-1);

 return res ;
}