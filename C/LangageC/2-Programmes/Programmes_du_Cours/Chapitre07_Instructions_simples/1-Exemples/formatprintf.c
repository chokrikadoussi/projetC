#include <stdio.h>
#include <string.h>

int main()
{
   short int si;
   unsigned short int usi;
   long int li;
   unsigned long int uli;
   long long int lli;
   unsigned long long int ulli;

   float x;
   double dx;
   long double ldx;

   char Nom[100];
   
   printf("--- Format des entiers ---\n");
   si=32767;
   printf("short int : %i\n",si);
   usi=(2*si)+1;
   printf("unsigned short int : %hu\n",usi);

   li=2147483647L;
   printf("long int : %ld\n",li);
   uli=(2*li)+1;
   printf("unsigned long int : %lu\n",uli);

   lli=9223372036854775807LL;
   printf("long long int : %lld\n",lli);
   //ulli=(lli*2)+1;
   ulli=18446744073709551615ULL;
   printf("unsigned long long int : %llu\n",ulli);


   printf("--- Format des réels ---\n");

   x=2.3e-4 ;
   printf("reel (format f)=%f\n",x) ;
   printf("reel (format e)=%e\n",x) ;
   printf("reel (format E)=%E\n",x) ;
   printf("reel (format g)=%e\n",x) ;
   printf("reel (format G)=%E\n",x) ;
   printf("reel (format a)=%a\n",x) ;
   printf("reel (format A)=%A\n",x) ;

   dx=2.3e-4 ;
   printf("double (format lf)=%lf\n",dx) ;
   printf("double (format le)=%le\n",dx) ;
   printf("double (format lE)=%lE\n",dx) ;
   printf("double (format lg)=%le\n",dx) ;
   printf("double (format lG)=%lE\n",dx) ;
   printf("double (format la)=%la\n",dx) ;
   printf("double (format lA)=%lA\n",dx) ;

   ldx=2.3e-4 ;
   printf("long double (format Lf)=%Lf\n",ldx) ;
   printf("long double  (format Le)=%Le\n",ldx) ;
   printf("long double  (format LE)=%LE\n",ldx) ;
   printf("long double  (format Lg)=%Le\n",ldx) ;
   printf("long double  (format LG)=%LE\n",ldx) ;
   printf("long double  (format La)=%La\n",ldx) ;
   printf("long double  (format LA)=%LA\n",ldx) ;

   printf("--- Lecture d'une chaine avec des espaces ---\n");
   printf("Entrez un nom : ");
   scanf("%[^\n]",Nom);
   printf("Nom = |%s|\n",Nom);
   


     
}
