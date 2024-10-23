#include <stdio.h>

void multiplication(float nombre, int e);
void addition(float nombre, int e)    ;

float resultat ;
char operation ;

int main()
{
  float x       ;
  int   n,choix ;

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
    case 1 : multiplication(x,n);
             operation='*' ;
             break ;
    case 2 : addition(x,n)    ;
             operation='+' ;
             break ;
  }
  printf("%4.2f%c%4.2f ... %d fois =%10.4f\n",x,operation,x,n,resultat); 
}
