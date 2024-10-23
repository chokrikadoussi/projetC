/* --------- */
/*   bool2.c  */
/* --------- */
#include <stdio.h>

int main()
{
  /* --- declarations --- */
  int nb, filtre ,resultat  ;


  /* --- instructions --- */
  printf("Entrez le nombre a filtrer :");
  scanf("%d",&nb);
  
  /* filtre F en hexa = 15 en decimal = 1111 en binaire */
  filtre = 0xF ;

  resultat=nb & filtre ;
  
  printf("Le resultat : %d \n",resultat);




}
