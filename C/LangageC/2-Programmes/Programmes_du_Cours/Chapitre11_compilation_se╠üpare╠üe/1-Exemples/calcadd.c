#include <stdio.h>

extern float resultat ;
extern char operation ;

void addition(float nombre,int e)
{
  int i        ;
  
  resultat = 0 ;
  
  for (i=0 ; i<e ; i++)
    resultat = resultat + nombre ;
}

