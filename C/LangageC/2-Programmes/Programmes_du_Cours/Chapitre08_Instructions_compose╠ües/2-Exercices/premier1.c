#include <stdio.h>

int main()
{
  int nb, diviseur1, diviseur2,reste  ;
  int trouve,i ,racinecar,limite      ;

  printf("Entrez un Nombre :");
  scanf("%d",&nb);
  
  trouve=0         ;
  limite = nb-1    ;
  
  for (i=2; i<=limite ;i++)
  {
      reste= nb%i ;
      if (reste == 0)
      {
         trouve=1       ;
         diviseur1=i    ;
         diviseur2=nb/i ;
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
