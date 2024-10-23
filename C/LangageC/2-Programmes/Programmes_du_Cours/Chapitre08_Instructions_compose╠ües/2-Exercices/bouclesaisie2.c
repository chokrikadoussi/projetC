#include <stdio.h>

int main()
{
  char caract ;
  
  printf("Entrez un texte : ");
    
  while ((caract=getchar()) != '\n')
  {
    printf("%c\n",caract);
  } 
}
