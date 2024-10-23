#include <stdio.h>

float puissance(float nombre, int e);

int main()
{
  float res,x ;
  int   n     ;

  printf("Entrez un nombre reel :");
  scanf("%f",&x);
  
  printf("Entrez la puissance entiere: ");
  scanf("%d",&n);
  
  res=(puissance(x,n)/2);
  printf("Résultat du calcul : (%4.2f ** %2d)/2=%10.4f\n",x,n,res); 
}

float puissance(float nombre,int e)
{
  int i        ;
  float restmp ;
  
  restmp = 1   ;
  
  for (i=0 ; i<e ; i++)
    restmp = restmp * nombre ;
    
  return restmp ;
}
