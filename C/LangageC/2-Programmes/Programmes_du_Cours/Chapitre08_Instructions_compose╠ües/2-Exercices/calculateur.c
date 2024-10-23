#include <stdio.h>

int main()
{
  char caract,signe    ;
  int chiffre,nb,somme ;
  
  printf("Entrez une expression arithmetique : ");

  nb=0      ;
  chiffre=0 ;
  somme=0   ;
  signe='+' ;
      
  while ((caract=getchar()) != '\n')
  {
    switch(caract)
    {
      case '+':case '-' :
            if (signe == '+')
               somme = somme+nb ;
            else
               somme = somme-nb ;
            nb=0           ;
            signe = caract ;
            break;
            
      case '0':case '1':case '2':case '3':case '4':
      case '5':case '6':case '7':case '8':case '9':
            chiffre = caract-48;
            nb      = (nb*10)+chiffre;
            break;
    }
  }
 if (signe == '+')
     somme = somme+nb ;
 else
     somme = somme-nb ;
  
  printf("Resultat = %d \n",somme); 
}
