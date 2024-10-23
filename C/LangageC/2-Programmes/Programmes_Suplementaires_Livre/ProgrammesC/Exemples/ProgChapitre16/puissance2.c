/* ----------- */
/* puisance2.c */
/* ----------- */
#include <stdio.h>
/* declaration preliminaire */
int puissance (float nombre,int e,float *resultat);
/* ---- programme principal ---- */
main()
{
  int N        ;
  float x, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&x, &N);
  puissance(x,N,&res)  ;
  printf("res=%10.2f\n",res);
}
/* ---- procedure  ---- */
int puissance (float nombre,int e,float *resultat)
{
  int i  ;

  *resultat = 1 ;

  for (i=0 ; i < e ; i++)
      *resultat = *resultat * nombre ;
}

