#include <stdio.h>

int main()
{
  int nb, diviseur1, diviseur2,reste  ;
  int trouve,i ,racinecar,limite      ;

  printf("Entrez un Nombre :");
  scanf("%d",&nb);
  
  trouve=0         ;
  limite = nb-1    ;

  reste= nb%2 ;
  if ((reste == 0) && (nb != 2))
  {
         trouve=1       ;
         diviseur1=i    ;
         diviseur2=nb/i ;
  }
  else
  {
    for (i=3; i<=limite ; i+=2)
    {
      reste= nb%i ;
      if (reste == 0)
      {
         trouve=1       ;
         diviseur1=i    ;
         diviseur2=nb/i ;
      }
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
