#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale */
#include <string.h>

/* déclaration de constantes */
#define TAILLE 100

/* --------------------------- */
/* --- Programme principal --- */
/* --------------------------- */
int main()
{
 wchar_t NomW[TAILLE] = {0}; 
 char Nom[TAILLE]  ;
 int TailleNom, TailleNomW, NbCaracteresConvertis ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur a UTF-8 */
 
 /* Saisie du Nom en caractères élargis */
 wprintf(L"Nom  : ") ; 
 wscanf(L"%ls",NomW)   ; 
 wprintf(L"Nom = |%ls|\n",NomW);

 TailleNomW = wcslen(NomW);
 wprintf(L"TailleNomW = %d caractère étendus (wcslen)\n",TailleNomW);

 /* conversion de Nom (multi-byte) en chaine de caractères élargis (4 octets par caractères) */
 NbCaracteresConvertis = wcstombs(Nom,NomW,TAILLE);
 wprintf(L"Conversion en multi-bytes : NbCaracteresConvertis = %d\n",NbCaracteresConvertis);

 TailleNom = strlen(Nom);
 wprintf(L"TailleNom en Octets (strlen) = %d\n",TailleNom);
}
