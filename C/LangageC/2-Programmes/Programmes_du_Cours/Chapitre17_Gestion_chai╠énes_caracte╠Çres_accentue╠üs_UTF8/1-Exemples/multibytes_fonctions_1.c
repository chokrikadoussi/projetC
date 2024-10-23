#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale */
#include <string.h>

/* déclaration de constantes */
#define TAILLE 100
#define TAILLE_CH_LETTRE 20

/* --------------------------- */
/* --- Programme principal --- */
/* --------------------------- */
int main()
{
 char Nom[TAILLE], LettreCh[TAILLE_CH_LETTRE]  ;
 int TailleNom, TailleNomW, NbCaracteresConvertis, NbOctetsCodageUTF8 ;
 wchar_t NomW[TAILLE] = {0}; // On initialise une chaîne de texte étendu.

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur a UTF-8 */
 
 /* Saisie du Nom en caractères élargis */
 printf("Nom  : ") ; 
 scanf("%s",Nom)   ; 
 printf("Nom = |%s|\n",Nom);
 
 TailleNom = strlen(Nom);
 printf("TailleNom en Octets (strlen) = %d\n",TailleNom);

 /* conversion de Nom (multi-byte) en chaine de caractères élargis (4 octets par caractères) */
 NbCaracteresConvertis = mbstowcs(NomW,Nom, TAILLE);
 printf("Conversion en caractère étendus : NbCaracteresConvertis = %d\n",NbCaracteresConvertis);

 TailleNomW = wcslen(NomW);
 printf("TailleNomW = %d caractère étendus (wcslen)\n",TailleNomW);


 /* Saisie d'un caractère accentué */
 printf("\nEntrez une lettre accentuée  : ") ;
 scanf("%s",LettreCh)   ; 
 NbOctetsCodageUTF8 =  mblen(LettreCh,TAILLE_CH_LETTRE);
 printf("Nombre d'octets nécessaires au codage UTF8 de |%s| = %d octet(s)\n",LettreCh,NbOctetsCodageUTF8);
}
