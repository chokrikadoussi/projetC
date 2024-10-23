/* ----------- */
/* puisance4.c */
/* ----------- */
#include <stdio.h>
float puissance (float x,int e) ;
/* ---- programme principal ---- */
main()
{
  int N        ;
  float nombre, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&nombre, &N)         ;
  printf("res=%10.2f\n", puissance(nombre,N))    ;
}
/* ---- fonction recursive  ---- */
float puissance (float x,int e) 
{
  float resultat ;

  if (e==1)
      resultat = x ;
  else
      resultat = puissance(x,e-1) * x ;
  return resultat ;
}

