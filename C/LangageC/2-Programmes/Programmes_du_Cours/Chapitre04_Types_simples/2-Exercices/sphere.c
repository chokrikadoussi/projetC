/* -------------------- */
/* Programme sphere.c  */
/* -------------------- */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535

/* --- debut du programme --- */
int main()
{
 /* --- declarations --- */
  float  rayon,surface,volume  ;  	
	 
 /* --- instructions --- */   
  printf("Entrez le rayon : ") ; 
  scanf("%f",&rayon)           ;

  surface = 4*PI*rayon*rayon   ;
  volume=(rayon*surface)/3     ;
   
  printf("surface=%f  volume=%f\n",surface,volume);
  
}
