#include <stdlib.h>
#include <stdio.h>

int main()
{
 /* declarations */    	
  int a , b , somme;
  int i ;
  div_t resultat ;
  int reste,quotient ;
 
 /* --- debut du programme --- */
 
 /* ecriture des constantes entieres */    	
  i=31;
  printf("i=%d\n",i);
  i=037;
  printf("i=%d\n",i);
  i=0x1f;
  printf("i=%d\n",i);
  i=0X1F;
  printf("i=%d\n",i);
    	 
 /* operateurs sur les entiers */   	 
  printf("Entrez 2 entiers : ");
    	 
  scanf("%d %d",&a,&b);
  somme=a+b;
   	
  printf("%d + %d = %d\n",a,b,somme);
    	
  somme%=b;
  printf("somme+=i : %d\n",somme);
  
  /* conversion vers des entiers */  	
    	
  i=atoi("1234");  	
  printf("chaine 1234 en entier = %d\n",i);
   
   resultat=div(a,b);
   quotient=resultat.quot;
   reste=resultat.rem;
   
   printf("%d div %d : reste %d   quotient %d\n",a,b,reste,quotient); 	
}
