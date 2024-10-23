/* -------- */
/* sphere.c */
/* -------- */
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

main()
{
 float Rayon, Surface, Volume ;

 printf("Entrez un Rayon:");
 scanf("%f",&Rayon);

 /* calcul de la Surface */
 Surface = 4*PI*pow(Rayon,2);

 /* calcul du Volume */
 Volume = (Rayon*Surface)/3 ;

 printf("Surface de la sph