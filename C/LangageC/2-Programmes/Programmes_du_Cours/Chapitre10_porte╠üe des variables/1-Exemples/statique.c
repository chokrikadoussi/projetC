#include <stdio.h>

void traitement() ; 

int main()
{
  int i ;
  
  for (i=0 ; i<3 ; i++)
    traitement();
}

void traitement()
{
  static int k=0;
  int j=0       ;

  printf("j=%d k=%d\n",++j,++k);

}
