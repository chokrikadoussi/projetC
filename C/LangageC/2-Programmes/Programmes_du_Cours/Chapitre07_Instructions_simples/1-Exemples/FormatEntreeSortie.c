#include <stdio.h>
#include <string.h>

int main()
{
   int a ,longueur,code;
   float x ;
   double y ;
   int *pt ;
   char nom[10],prenom[10];
   int age ;
   int mois,jour,annee;
   unsigned short int si;
   
   a=28 ;   
   printf("28 au format :\n");   
   printf("d=%d i=%i o=%o x=%x X=%X u=%u\n",a,a,a,a,a,a);

   a=-1 ;   
   printf("-1 au format :\n");   
   printf("d=%d i=%i o=%o x=%x X=%X u=%u\n",a,a,a,a,a,a);

   x=2.3e-4 ;
   y=2.3e-5 ;
   
   printf("2.3 au format f : %f  %f \n",x,y);
   printf("2.3 au format e : %e  %E \n",x,y);
   printf("2.3 au format g : %g  %G \n",x,y);
   
   pt=&a;
   printf("adresse de a : %p\n",pt);
   
      
   a=24 ;
   printf("--- Affichage d'un entier %d ---\n",a);
   printf("%%d   =|%d|\n",a);
   printf("%%5d  =|%5d|\n",a);
   printf("%%-5d =|%-5d|\n",a);
   printf("%%05d =|%05d|\n",a);   
   printf("%%#5d =|%#5d|\n",a);
   printf("%%#5o =|%#5o|\n",a);
   printf("%%#5x =|%#5x|\n",a);
      

   y=25.4234 ;
   printf("--- Affichage du reel %f ---\n",y);
   printf("%%f      =|%f|\n",y);
   printf("%%10f    =|%10f|\n",y);
   printf("%%10.3f  =|%10.3f|\n",y);
   printf("%%+10.3f =|%+10.3f|\n",y);
   printf("%%010.3f =|%010.3f|\n",y);
   printf("%%-10.3f =|%-10.3f|\n",y);
   
   strcpy(nom,"Bonjour") ;
   longueur=12;
   printf("--- Affichage d'une chaine %s ---\n",nom);
   printf("%%s      =|%s|\n",nom);
   printf("%%10s    =|%10s|\n",nom);
   printf("%%+10s   =|%+10s|\n",nom);
   printf("%%-10s   =|%-10s|\n",nom);
   printf("%%5s     =|%5s|\n",nom);
   printf("%%*s     =|%*s|\n",longueur,nom);
   
   code=printf("resultats=%5.2f et %4d\n",y,a);
   printf("Nb elements=%d\n",code);
   
   printf("Entre la date (04/01/2000):");
   scanf("%2d/%2d/%4d",&jour,&mois,&annee);
   printf("jour=%d mois=%d annee=%d\n",jour,mois,annee);
   fflush(stdin);
   
   printf("Entrez Nom  Prenom  Age :");
   scanf("%10s %10s %d",nom,prenom,&age);
   printf("Nom=|%s|lg=%d prenom=|%s| lg=%d age=|%d|\n",nom,strlen(nom),prenom,strlen(prenom),age);
   fflush(stdin);
      
   printf("Entrez un nombre reel (12.54) :");
   scanf("%f",&x);
   printf("x=|%f|\n",x);
   fflush(stdin);
      
   printf("Entrez un nombre reel (12.5432) :");
   scanf("%10f",&x);
   printf("x=|%20f|\n",x);
   fflush(stdin);   
   
   si=65535;
   printf("short int : %hu\n",si);

     
}
