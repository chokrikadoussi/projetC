#include <locale.h>
#include <stdio.h>

int main ()
{
   float valeur  ;

   printf("----------------------\n");
   printf("Locale is : %s\n", setlocale(LC_ALL, "C"));
   printf("Enter a real value (ex : 23.87) : ");
   scanf("%f",&valeur);
   printf("Real value x 2 : %5.2f\n", 2*valeur);


   printf("----------------------\n");
   printf("Langue : %s\n", setlocale(LC_ALL,"fr_FR.UTF-8"));
   /* traitement des réels au format français */
   printf("Entrez une valeur réelle (ex : 23,87) : ");
   scanf("%f",&valeur);
   printf("Valeur réelle x 2 : %5.2f\n", 2*valeur);
   printf("----------------------\n");

}

