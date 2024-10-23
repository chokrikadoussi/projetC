#include <stdio.h>
#define MARGE 0.3

int main()
{
  int NoteMention                 ;
  float n1,n2,n3,c1,c2,c3,Moyenne ;


  printf("Entrez 3 notes        :");
  scanf("%f %f %f",&n1,&n2,&n3);

  printf("Entrez 3 coefficients :");
  scanf("%f %f %f",&c1,&c2,&c3);
  
  Moyenne=( (n1*c1)+(n2*c2)+(n3*c3) )/(c1+c2+c3) ;
  printf("Votre moyenne est : %+6.2f\n",Moyenne);
  
  NoteMention=(Moyenne+MARGE);
  
  switch (NoteMention)
  {
    case 0:case 1:case 2:case 3:case 4:
    case 5:case 6:case 7:case 8:case 9:
             printf("recale\n");
             break;
    case 10:case 11 :
             printf("Mention PASSABLE\n");
             break ;
    case 12:case 13 :
             printf("Mention ASSEZ BIEN\n");
             break ;
    case 14:case 15:
             printf("Mention BIEN\n");
             break ;
    case 16:case 17:case 18:case 19:case 20:
             printf("Mention TRES BIEN\n");
             break ;
    default: printf("Notes ou Coefficients ERRONNES\n");
             break;
  }
}
