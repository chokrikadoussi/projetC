#include <stdio.h>
int main()
{
   int i, base, res;

   printf("Entrez une base de calcul: ");
   scanf("%d",&base);

   for (i=-10 ; i<10 ; i++)
   {
     res = i * base ;
     printf("%4d x %4d =%4d\n",i,base,res);
   }
}

