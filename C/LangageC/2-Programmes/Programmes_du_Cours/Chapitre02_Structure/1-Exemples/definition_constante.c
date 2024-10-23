#include <stdio.h>
#define PI 3.1415926
int main()
{
	float rayon,diametre,circonf,surface;

	rayon=2;
	diametre=2*rayon;
	circonf = PI * diametre ;
	surface = rayon * rayon * PI ;
	
	printf("Rayon=%f\n",rayon);
	printf("diametre=%f\n",diametre);
	printf("circonf=%f\n",circonf);
	printf("surface=%f\n",surface);

}
