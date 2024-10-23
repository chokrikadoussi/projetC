#include <stdio.h>

#define PI 3.14159

int main()
{
 float rayon, diametre, circonf,surface ;
 
 rayon = 2;
 
 diametre = 2*rayon ;
 circonf = PI * diametre ;
 surface = rayon * rayon * PI ;
 
 printf("%f %f \n",circonf,surface);

}
