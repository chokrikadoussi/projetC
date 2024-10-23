#include <stdio.h>

int main()
{

  int entier , *p_entier ;
  
  p_entier = &entier ;
  
  *p_entier = 28 ;
  
  printf("la donnee pointee par p_entier est : %d\n",*p_entier);
  printf("la variable entier est : %d\n",entier);


}
