#include <stdio.h>
#include <string.h>

int main()
{
  int nb, base ,nb_initial              ;
  int reste,quotient,diviseur           ;
  char affichage[20],digit[2],tempo[20] ;
  
  printf("Nombre a convertir:");
  scanf("%d",&nb)              ;
  nb_initial = nb ;
  
  printf("Base de conversion:");
  scanf("%d",&base)            ;

  diviseur=base     ;
  digit[1]='\0'     ;
  affichage[0]='\0' ;
  
  do
  {
    quotient = nb / diviseur ;
    reste    = nb % diviseur ;
    
    /* --- Mise en forme du resultat --- */
    if ((reste >= 0) && (reste <= 9))
        digit[0] = reste+48   ;
    else
        digit[0] = reste+55   ;
    strcpy(tempo,digit)     ;
    strcat(tempo,affichage) ;
    strcpy(affichage,tempo) ; 
          
    /* --- Evolution prochaine iteration --- */    
    nb       = quotient      ;
  }
  while (quotient != 0) ;

  printf("%d en base %d = %s\n",nb_initial,base,affichage);

}
