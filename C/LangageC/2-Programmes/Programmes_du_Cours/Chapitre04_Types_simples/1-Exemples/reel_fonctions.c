#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main()
{
 /* declarations */
  float x,y,res,t,u,deci ;
  int ent ,i;  
  double resultat ;  	
 
 /* --- debut du programme --- */
 
 /* ecriture des constantes entieres */    	
  t=2.14;
  printf("t=%f\n",t);
  t=2.3e-2;
  printf("t=%f\n",t);
  t=2.3e-2f;
  printf("t=%f\n",t);
   t=2.3e-2F;
  printf("t=%f\n",t);
    	 
 /* operateurs sur les reels */   	 
   
  printf("Entrez 2 reels (ex: 2.4  3.5) :"); 
  scanf("%f %f",&x,&y);
  res=x+y;
  
  printf("la somme est : %f\n",res);
  ent=x ;
  deci=x-ent;
  
  printf("%f  : ent=%d  deci=%f\n",x,ent,deci);
  
  resultat=ceil(x);
  printf("ceil(%f)=%f\n",x,resultat);
  
  resultat=floor(x);
  printf("floor(%f)=%f\n",x,resultat);
  
  resultat=fabs(x);
  printf("fabs(%f)=%f\n",x,resultat);
  
  i=floor(x+0.5);
  printf("arrondi(%f)=%d\n",x,i);
  
  resultat=atof("123.56");
  printf("atof de 123.56 = %f\n",resultat);	
}
