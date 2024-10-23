#include <stdio.h>

int main()
{
  float res,x       ;
  int   n,compteur  ;

  printf("Entrez un nombre reel :");
  scanf("%f",&x);
  
  printf("Entrez la puissance entiere:");
  scanf("%d",&n);
  
  res = 1    ;
  compteur=0 ;
  
  do
  {
    res = res*x ;
    compteur++  ;
  }
  while (n != compteur);

  printf("%+5.2f ** %d = %+5.2f\n",x,n,res);


}
