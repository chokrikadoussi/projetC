/* ---------- */
/* puisance.c */
/* ---------- */
#include <stdio.h>
/* declaration preliminaire */
int puissance (float nombre,int e) ;
/* ---- programme principal ---- */
main()
{
  int N        ;
  float x, res ;

  printf("Entrez un nombre et sa puissance: ");
  scanf("%f %d",&x, &N);
  puissance(x,N)  ;
  printf("MAIN: x=%10.2f\n",x);
}
/* ---- procedure  ---- */
int puissance (float nombre,int e)
{
  int i  ;
  float resultat ;

  resultat = 1 ;
  for (i=0 ; i < e ; i++)
      resultat = resultat * nombre ;
  printf("--------------\n");
  printf("resultat=%10.2f\n",resultat);
  /* modification d'un parametre */
  nombre=resultat ;
  printf("PUISSANCE: nombre=%10.2f\n",nombre);
  printf("--------------\n");
}

