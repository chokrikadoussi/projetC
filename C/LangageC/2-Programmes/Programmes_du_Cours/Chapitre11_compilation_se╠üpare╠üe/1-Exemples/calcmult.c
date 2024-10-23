#include <stdio.h>

extern float resultat ;
extern char operation ;

void multiplication(float nombre,int e)
{
  int i        ;
  
  resultat = 1   ;
  
  for (i=0 ; i<e ; i++)
    resultat = resultat * nombre ;
}

