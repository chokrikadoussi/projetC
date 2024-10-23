/* ------------ */
/* taille_int.c */
/* ------------ */
#include <stdio.h>
#include <limits.h>

int main()
{
  printf("-----------------------------------\n");
  printf("Type            int : min=%12d max=%12d\n",INT_MIN,INT_MAX);
  printf("Type      short int : min=%12d max=%12d\n",SHRT_MIN,SHRT_MAX);
  printf("Type      long  int : min=%12d max=%12d\n",LONG_MIN,LONG_MAX);
  printf("-----------------------------------\n");
  printf("Type            unsigned int : min=%u max=%12u\n",0,UINT_MAX);
  printf("Type      unsigned short int : min=%u max=%12u\n",0,USHRT_MAX);
  printf("Type      unsigned long  int : min=%u max=%12u\n",0,ULONG_MAX);
  printf("-----------------------------------\n");

}

