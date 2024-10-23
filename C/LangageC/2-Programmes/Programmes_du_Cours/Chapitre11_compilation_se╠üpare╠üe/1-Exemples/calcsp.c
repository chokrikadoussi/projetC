#include <stdio.h>

float puissance(float nombre,int e)
{
  int i,restmp  ;
  
  restmp = 1   ;
  
  for (i=0 ; i<e ; i++)
    restmp = restmp * nombre ;
    
  return restmp;
}

float somme(float nombre,int e)
{
  int i ,restmp ;
  
  restmp = 0 ;
  
  for (i=0 ; i<e ; i++)
    restmp = restmp + nombre ;
    
  return restmp ;
}
