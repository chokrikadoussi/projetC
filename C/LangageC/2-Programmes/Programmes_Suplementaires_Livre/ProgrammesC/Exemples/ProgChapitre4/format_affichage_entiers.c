/* -------------------------- */
/* format_affichage_entiers.c */
/* -------------------------- */
#include <stdio.h>

int main()
{
  int k ;

  printf("Entrez un nombre entier :") ;
  scanf("%d",&k); 

  /* Affiche au differents formats entiers  */
  printf("Affichage de l'entier %d \n",k);
  printf("Au Format  %%d  :  %d\n",k);
  printf("Au Format  %%i  :  %i\n",k);
  printf("Au Format  %%o  :  %o\n",k);
  printf("Au Format  %%x  :  %x\n",k);
  printf("Au Format  %%X  :  %X\n",k);
  printf("Au Format  %%u  :  %u\n",k);

  k = -k ;
  /* Affiche au formats sign