#include <stdio.h>

int main()
{
  int ascii ;
  char c ;
  
  for (ascii=0;ascii<256;ascii++)
  {
    c=ascii;
    printf("ascii=%d  caractere=|%c|\n",ascii,c);
   }
}
