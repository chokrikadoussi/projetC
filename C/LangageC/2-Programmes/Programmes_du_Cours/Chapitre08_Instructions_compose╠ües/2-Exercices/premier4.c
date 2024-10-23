#include <stdio.h>
#include <math.h>

int main()
{
  int nb, diviseur1, diviseur2,reste  ;
  int trouve,i ,racinecar,limite      ;

  printf("Entrez un Nombre :");
  scanf("%d",&nb);
  
  trouve=0         ;
  limite=sqrt(nb)+1;

  reste= nb%2 ;
  if ((reste == 0) && (nb != 2))
  {
         trouve=1       ;
         diviseur1=i    ;
         diviseur2=nb/i ;
  }
  else
  {
    i=3;

    while ((i<=limite) && (! trouve))
    {
      reste= nb%i ;
      if (reste == 0)
      {
         trouve=1       ;
         diviseur1=i    ;
         diviseur2=nb/i ;
      }
      i+=2;
    }
  }

  
  if (trouve)
  {
    printf("%d n'est pas premier !\n",nb);
    printf("il est divisible par %d et %d\n",diviseur1,diviseur2);
  }
  else
  {
    printf("%d est un nombre PREMIER !\n",nb);
  }     

}
