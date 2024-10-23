#include <stdio.h>

int main()
{
 const float PI = 3.1415926 ;
 float rayon, diametre, circonf,surface ;
 
 rayon = 2;
 
 diametre = 2*rayon ;
 circonf = PI * diametre ;
 surface = rayon * rayon * PI ;
 
 printf("%f %f \n",circonf,surface);
}
