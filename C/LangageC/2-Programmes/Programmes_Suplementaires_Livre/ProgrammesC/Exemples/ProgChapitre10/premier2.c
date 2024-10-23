/* ---------- */
/* premier2.c */
/* ---------- */
#include <stdio.h>
#include <math.h>

int main()
{
  int nb, diviseur1, diviseur2,reste  ;
  int trouve,i ,racinecar,limite      ;
  int nb_iterations=1;

  printf("Entrez un Nombre :");
  scanf("%d",&nb);
 
  /* partie entiere de la racine carre+1 */
  limite=sqrt(nb)+1;
  trouve=0         ;
  
  if (nb != 2) /* 2 est premier */
  {
    /* on retire le cas des nombres pairs */
    reste=nb%2 ;
    if (reste == 0)
    {
       trouve=1       ;
       /* on memorise les diviseurs */
       diviseur1=2    ;
       diviseur2=nb/2 ;
    }
    else
    {
       /* teste tous les diviseurs impairs */
       i=3;
       while ( (! trouve) && (i<=limite) )
       {
         nb_iterations++;

         reste= nb%i ;
         if (reste == 0)
         {
            trouve=1       ;
            /* on memorise les diviseurs */
            diviseur1=i    ;
            diviseur2=nb/i ;
         }
         i+=2 ;
       }
    }
  }
  
  if (trouve)
  {
    printf("%d n'est pas premier !\n",nb);
    printf("il est divisible par %d et %d\n",diviseur1,diviseur2);
  }
  else
  {
    printf("%d est un nombre PREMIER !\n",nb);
  }     
  printf("R