/* -------------- */
/* declar_const.c */
/* -------------- */

#define PI 3.14159

int main()
{
  const int COEFF=4 ;

  float surface, rayon ;

  printf("Entrez un rayon d'une sphere :");
  scanf("%f",&rayon);

  surface = COEFF * PI * rayon * rayon ;

  printf("La surface est : %f\n",surface);

}

