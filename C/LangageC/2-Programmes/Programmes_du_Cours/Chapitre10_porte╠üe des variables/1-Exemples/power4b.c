#include <stdio.h>
float puissance (float nombre,int e);
int main()
{
  int N        ;
  float x, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&x, &N);
  res = (3*puissance(x,N))/2 ;
  printf("res=%10.2f\n",res);
}

float puissance (float nombre,int e)
{
  int i  ;
  float restmp ;

  restmp = 1 ;

  res = 1 ;

  for (i=0 ; i < e ; i++)
      restmp = restmp * nombre ;
  return restmp ;
}
