#include <stdio.h>

int u(int nb) ;
int v(int nb) ;

int main()
{ int  N, res1, res2;
  printf("Entrez un nombre entier : ") ;
  scanf("%d",&N) ;
  /* -- Appel des fonctions récursives -- */
  res1=u(N) ;
  res2=v(N) ;
  printf("u(%d)=%d    ",N,res1) ;
  printf("v(%d)=%d    ",N,res2) ;
  printf("Vérification : v(%d)-u(%d)=%d\n",N,N,res2-res1) ;
}

int u(int nb)
{ if (nb==0) return 1 ;
  else       return ((3*u(nb-1))+(2*v(nb-1))) ;
}

int v(int nb)
{ if (nb==0) return 2 ;
  else       return ((2*u(nb-1))+(3*v(nb-1))) ;
}
