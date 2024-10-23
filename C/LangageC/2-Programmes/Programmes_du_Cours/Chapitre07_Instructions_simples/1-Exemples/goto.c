#include <stdio.h>

int main()
{
	int age ;

saisie:	printf("Entrez votre age : ");
        scanf("%d",&age);


test : printf("Test");

    if (age < 60)
    {
    	age = age -20 ;
	      goto error  ;
    }
	
	if (age > 65)
	   goto saisie  ;
	else
	   goto test  ;

    
error: printf("Erreur ! \n");


}
