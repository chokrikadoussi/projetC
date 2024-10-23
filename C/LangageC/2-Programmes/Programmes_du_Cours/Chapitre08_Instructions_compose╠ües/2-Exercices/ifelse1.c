#include <stdio.h>

int main()
{
  float Nb , Deci    ;
  int   Pent,saisieOK  ;

  printf("Entrez un Nombre :");
  saisieOK=scanf("%f",&Nb);
  
  if (! saisieOK)
  {
    printf("erreur de saisie\n");
  }
  else
  {
    Pent=Nb     ;
    Deci=Nb-Pent;

    if (Pent == Nb)
    {
      printf("Nombre Entier %d\n",Pent);
    }
    else
    {
      printf("Nombre reel %8.2f\n",Nb);
      printf("Partie entiere : %d\n",Pent);
      printf("Partie decimale: %4.2f\n",Deci);
    }
  }

}
