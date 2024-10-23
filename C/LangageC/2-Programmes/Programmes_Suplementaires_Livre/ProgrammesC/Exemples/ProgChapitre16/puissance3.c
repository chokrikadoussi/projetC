/* ----------- */
/* puisance3.c */
/* ----------- */
#include <stdio.h>
/* declaration preliminaire */
float puissance (float nombre,int e) ;
/* ---- programme principal ---- */
main()
{
  int N        ;
  float x, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&x, &N)      ;
  res = (2*puissance(x,N))/3 ;
  printf("res=%10.2f\n",res)       ;
}
/* ---- fonction  ---- */
float puissance (float nombre,int e) 
{
  int i  ;
  float resultat ;

  resultat = 1 ;
  for (i=0 ; i < e ; i++)
      resultat = resultat * nombre ;
  return resultat ;
}

