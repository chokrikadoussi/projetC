#include <stdio.h>
#include <ctype.h>

int main()
{
  char caract ;
  
  caract = ' ' ;
  
  while (caract != 'Q')
  {
    printf("Entrez une Majuscule (Q pour FIN):");
    scanf("%c",&caract);
    fflush(stdin)     ;
    
    printf("Majuscule de %c : %c\n",caract,tolower(caract)); 
  } 
}
