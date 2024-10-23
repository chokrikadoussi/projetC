#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h>

int convert_wchar_int(wchar_t ChW[]) ;

// --- Programme principal ---
int main()
{
  wchar_t ChaineW[10]   = L"123456"       ;
  int Nombre, nbconvert;

  setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur a UTF-8 */

  Nombre=convert_wchar_int(ChaineW);

  wprintf(L"ChaineW à traduire = |%ls|\n",ChaineW) ;
  printf("Retour de la fonction convert_wchar_int : Nombre=|%d|\n",Nombre);
  printf("\n");

  /* --- Conversion de l'entier en un wchar_t --- */
  Nombre=654321;
  nbconvert = swprintf(ChaineW,100,L"%d",Nombre);
  wprintf(L"Entier à traduire = |%d|\n",Nombre) ;
  wprintf(L"Conversion entier -> wchar_t avec swprintf : ChaineW=|%ls| taille=|%d|\n",ChaineW,nbconvert);
  printf("\n");
}

// --- Fonction de convertion ---
int convert_wchar_int(wchar_t ChW[])
{
  wchar_t LettreW;
  int Nb=0, Chiffre, longueur, i ;

  longueur = wcslen(ChW);
  printf("---------------------\n");
  printf("Trace traitement : Longueur = %d\n",longueur);
  /* Boucle de traitement caractère numérique par caractère numérique */
  for (i=0; i < longueur ; i++)
  {
     LettreW = ChW[i];
     Chiffre = (int)LettreW  - 48;
     Nb = (Nb*10) + Chiffre ;

     wprintf(L"Trace traitement : %d : LettreW = |%lc|  Chiffre=|%d| Nombre=|%d|\n",i,LettreW,Chiffre,Nb) ;
  }
  printf("---------------------\n");
  return Nb ;
}

