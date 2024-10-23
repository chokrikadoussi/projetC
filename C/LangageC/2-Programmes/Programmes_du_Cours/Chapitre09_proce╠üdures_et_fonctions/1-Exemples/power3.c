#include <stdio.h>
void puissance (float nombre,int e,float *resultat);
int main()
{
  int N        ;
  float x, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&x, &N);
  puissance(x,N,&res)  ;
  res = res/2 ;
  printf("res=%10.2f\n",res);
}

void puissance (float nombre,int e,float *resultat)
{
  int i  ;

  *resultat = 1 ;

  for (i=0 ; i < e ; i++)
      *resultat = *resultat * nombre ;
}

