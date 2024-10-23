/* ---------- */
/* statique.c */
/* ---------- */
#include <stdio.h>

int traitement() ; 

int main()
{
  int i ;
  
  for (i=0 ; i<3 ; i++)
    traitement();
}

int traitement()
{
  /* la varaible k conserve sa valeur */
  /* a chaque appel successif         */

  static int k=0;
  int j=0       ;

  printf("j=%d k=%d\n",++j,++k);

}
