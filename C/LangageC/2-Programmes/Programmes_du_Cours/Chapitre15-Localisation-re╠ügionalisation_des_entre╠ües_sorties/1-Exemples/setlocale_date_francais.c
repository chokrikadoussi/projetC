#include <locale.h>
#include <stdio.h>
#include <time.h> /* pour time */

int main ()
{
   time_t heure_actuelle;
   struct tm *temps;
   char memoire_tampon[80];

   time( &heure_actuelle );
   temps = localtime( &heure_actuelle );

   printf("----------------------\n");
   printf("Locale is : %s\n", setlocale(LC_ALL,"C"));
   strftime(memoire_tampon,80,"%c", temps );
   printf("Date is: %s\n", memoire_tampon);

   printf("----------------------\n");
   printf("Langue : %s\n", setlocale(LC_ALL,"fr_FR.UTF-8"));
   strftime(memoire_tampon,80,"%c", temps );
   printf("La date est : %s\n", memoire_tampon);
   printf("----------------------\n");
}
