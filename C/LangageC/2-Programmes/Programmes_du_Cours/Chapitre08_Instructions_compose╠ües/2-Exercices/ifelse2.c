#include <stdio.h>

int main()
{
  char Lettre ;
  int  Num    ;

  printf("Entrez une lettre :");
  scanf("%c",&Lettre);

  if ( (Lettre >= 'A') && (Lettre <= 'Z'))
  {
    Num=Lettre -'A' +1 ;
    printf("%c est la %deme MAJUSCULE\n",Lettre,Num);
  }
  else if ( (Lettre >= 'a') && (Lettre <= 'z'))
  {
    Num=Lettre -'a' +1 ;
    printf("%c est la %deme minuscule\n",Lettre,Num);
  }
  else
  {
    printf("%c   n'est pas une lettre de l'aphabet\n",Lettre);
  }

}
