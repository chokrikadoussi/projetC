#include <stdio.h>

float puissance(float nombre, int e);
float somme(float nombre, int e)    ;

int main()
{
  float x ,resultat  ;
  int   n,choix      ;
  char operation     ;

  printf("Entrez un nombre reel :");
  scanf("%f",&x);
  
  printf("Entrez le nombre d'iterations: ");
  scanf("%d",&n);
  
  printf("Entrez l'operation:\n");
  printf(" -1- Multiplication\n");
  printf(" -2- Addition\n");
  printf("Choix:");
  scanf("%d",&choix);
  
  switch(choix)
  {
    case 1 : resultat=puissance(x,n);
             operation='*' ;
             break ;
    case 2 : resultat=somme(x,n)    ;
             operation='+' ;
             break ;
  }
  printf("%4.2f%c%4.2f ... %d fois =%10.4f\n",x,operation,x,n,resultat); 
}
