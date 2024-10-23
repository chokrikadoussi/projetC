#include <stdio.h>
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 char Initiale   = 'é'       ; /* Erreur de compilation */
 char texte1[50] = "Anaïs" ;

 /* positionnement de la table de codage */
 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur a UTF-8 */

 printf("--- Valeurs initialisées ---\n");
 printf("Initiale = %c\n",Initiale) ; /* Erreur d'exécution */
 printf("texte1   = %s\n",texte1)   ;
}


