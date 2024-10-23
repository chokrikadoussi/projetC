#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() 
{
  setlocale(LC_ALL,"fr_FR.UTF-8") ;
  int retour_fwide                ;

  /* un premier printf oriente la sortie en mode octets */
  printf("printf => orientation en mode octet \n");
  
  if ( (retour_fwide = fwide(stdout, 0)) == 0) /* 0 interroge sur le mode actuel */
  {    
    /* on tente de positionner le mode caractères étendus (wide) */
    if ((retour_fwide = fwide(stdout, 1)) <= 0) /* une valeur positive modifie le mode au wide character mode */
    {
      printf("printf : impossible de positionner le mode caractères étendus (retour_fwide) = %d\n",retour_fwide);
    }
    else
    {
      wprintf(L"wprintf : le mode caractères étendus a été positionné (retour_fwide) = %d\n",retour_fwide);
    }
  } /* le mode est déjà positionné */
  else if ((retour_fwide = fwide(stdout, 0)) <= 0) /* valeur négative = orientation octet */
  {
      printf("printf : flux écran déjà orienté octet (retour_fwide) = %d\n",retour_fwide);
  }
  else
  {
      wprintf(L"wprintf : flux écran déjà orienté caractères étendus (retour_fwide) = %d\n",retour_fwide);
  }  
}
