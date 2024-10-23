#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert_to_int(char Ch[]) ;
char *itoa(int j) ;

// --- Programme principal ---
int main()
{
  char Chaine[10]= "123456";
  char *Chaine2            ;
  int Nombre, nbconvert, taille;

  Nombre=convert_to_int(Chaine);

  printf("Chaine à traduire = |%s|\n",Chaine) ;
  printf("Retour de la fonction convert_to_int() : Nombre=|%d|\n",Nombre);
  printf("Retour de la fonction standard atoi()  : Nombre=|%d|\n",atoi(Chaine));
  printf("\n");

  /* --- Conversion de l'entier en une chaine --- */
  Nombre=654321;
  nbconvert = sprintf(Chaine,"%d",Nombre);
  printf("Entier à traduire = |%d|\n",Nombre) ;
  printf("Conversion entier -> char avec sprintf(): Chaine=|%s| taille=|%d|\n",Chaine,nbconvert);
  Chaine2 = itoa(Nombre)   ;
  taille  = strlen(Chaine2);
  printf("Conversion entier -> char avec itoa()   : Chaine=|%s| taille=|%d|\n",Chaine2,taille);
  printf("\n");
}

// --- Fonction de convertion équivalente à atoi() ---
// --- chaine numérique en entier                  ---
int convert_to_int(char Ch[])
{
  char Lettre;
  int Nb=0, Chiffre, longueur, i ;

  longueur = strlen(Ch);
  printf("---------------------\n");
  printf("Trace traitement : Longueur = %d\n",longueur);
  /* Boucle de traitement caractère numérique par caractère numérique */
  for (i=0; i < longueur ; i++)
  {
     Lettre = Ch[i];
     Chiffre = (int)Lettre  - 48;
     Nb = (Nb*10) + Chiffre ;

     printf("Trace traitement : %d : Lettre = |%c|  Chiffre=|%d| Nombre=|%d|\n",i,Lettre,Chiffre,Nb) ;
  }
  printf("---------------------\n");
  return Nb ;
}

// --- Fonction de convertion équivalente à sprintf() ---
// --- entier en chaine numérique                     ---
char *itoa(int j)
{
  char chaine[100], *retour;
  int taille;
  /* création d'une chaine à partir de l'entier */
  sprintf(chaine,"%d",j);
  /* Construction d'une chaine de la taille de l'entier */
  taille = strlen(chaine);
  retour = (char *) malloc(taille+1);
  strcpy(retour,chaine);

  return retour;
}

