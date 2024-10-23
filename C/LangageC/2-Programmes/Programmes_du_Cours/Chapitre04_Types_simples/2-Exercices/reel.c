/* -------------------- */
/* Programme reel.c  */
/* -------------------- */

#include <stdio.h>
#include <math.h>

int main()
{
 /* ******************** */
 /* *** declarations *** */
 /* ******************** */

  float  x,deci      ;
  int    ent ,arrondi  ;  
  	
 
 /* ******************** */
 /* *** instructions *** */ 
 /* ******************** */

 
 /* --- operateurs sur les reels --- */
    	 
 /* --- saisie --- */   
  printf("Entrez 1 reels (ex: 2.4) : "); 
  scanf("%f",&x);

 /* --- calcul --- */
  ent=x ;
  deci=x-ent;
  arrondi=floor(x+0.5);

 /* --- affichage --- */ 
  printf("%f  : partie entiere=%d  decimale=%f arrondi=%d\n",x,ent,deci,arrondi);
  
   	
}
