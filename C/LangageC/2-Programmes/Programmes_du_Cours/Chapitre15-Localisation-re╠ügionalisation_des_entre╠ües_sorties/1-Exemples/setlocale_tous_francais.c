#include <locale.h>
#include <stdio.h>
#include <time.h>

int main ()
{
   time_t heure_actuelle;
   struct tm *temps;
   char memoire_tampon[80];

   float valeur  ;

   time(&heure_actuelle );
   temps = localtime( &heure_actuelle );

   printf("----------------------\n");
   printf("Locale is : %s\n", setlocale(LC_ALL, "C"));
   strftime(memoire_tampon,80,"%c", temps );
   printf("Date is: %s\n", memoire_tampon);
   printf("Enter a real value (ex : 23.87) : ");
   //printf("Entrez une valeur réelle (ex : 23,87) : ");
   scanf("%f",&valeur);
   printf("Real value x 2 : %5.2f\n", 2*valeur);


   printf("----------------------\n");
   printf("Langue locale est : %s\n", setlocale(LC_ALL, "fr_FR.UTF-8"));
   strftime(memoire_tampon,80,"%c", temps );
   printf("La date est: %s\n", memoire_tampon);
   /* traitement des réels au format français */
   printf("Entrez une valeur réelle (ex : 23,87) : ");
   scanf("%f",&valeur);
   printf("Valeur réelle x 2 : %5.2f\n", 2*valeur);
   printf("----------------------\n");
}

