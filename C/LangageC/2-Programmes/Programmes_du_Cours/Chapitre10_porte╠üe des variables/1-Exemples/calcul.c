#include <stdio.h>

void puissance(float nombre, int e);
void somme(float nombre, int e)    ;

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
    case 1 : puissance(x,n);
             operation='*' ;
             break ;
    case 2 : somme(x,n)    ;
             operation='+' ;
             break ;
  }
  printf("%4.2f%c%4.2f ... %d fois =%10.4f\n",x,operation,x,n,resultat); 
}

void puissance(float nombre,int e)
{
  int i        ;
  
  resultat = 1   ;
  
  for (i=0 ; i<e ; i++)
    resultat = resultat * nombre ;
}

void somme(float nombre,int e)
{
  int i        ;
  
  resultat = 0 ;
  
  for (i=0 ; i<e ; i++)
    resultat = resultat + nombre ;
}
