#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */

#define TAILLE 100                                                                 
                                                                                
int main()
{
 wchar_t LettreW, *ptrw        ;
 wchar_t Nom[TAILLE] = {0},  Prenom[TAILLE] = {0},  NomComplet[2*TAILLE] = {0}   ;
 wchar_t NomCmp[TAILLE]         ;
 wchar_t Motif1[TAILLE] = {0}, Motif2[TAILLE] = {0}, Motif3[TAILLE] = {0}, Motif4[TAILLE] = {0} ;
 int index, resultat ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur à UTF-8 */

 wprintf(L"--- Saisie et affichage ---\n");
 wprintf(L"Entrez une lettre accentuée : ");
 wscanf(L"%lc",&LettreW)            ;
 wprintf(L"LettreW = %lc\n",LettreW)  ;
 
 wprintf(L"Entrez un nom avec des accents : ");
 wscanf(L"%ls",Nom)              ;
 wprintf(L"Nom   = %ls\n",Nom)   ;

 wprintf(L"Entrez un prénom avec des accents : ");
 wscanf(L"%ls",Prenom)              ;
 wprintf(L"Prénom   = %ls\n",Prenom)   ;

 wprintf(L"Longueur de Nom : %d\n",wcslen(Nom));
 
 wcscpy(NomComplet,Nom);
 wcscat(NomComplet,L" ");
 wcscat(NomComplet,Prenom);
 wprintf(L"NomComplet   = %ls\n",NomComplet)   ;

 ptrw = wcschr(Nom, LettreW );                                                  
 wprintf(L"sous-chaîne débutant à '%lc' dans \"%ls\" : \"%ls\"\n",LettreW, Nom, ptrw );                                   

 ptrw = wcsrchr(Nom, LettreW );                                                  
 wprintf(L"sous-chaîne débutant à '%lc' en fin de \"%ls\" : \"%ls\"\n",LettreW, Nom, ptrw );                                   

 wprintf(L"Entrez un nom avec des accents à comparer : ");
 wscanf(L"%ls",NomCmp)              ;
 wprintf(L"Nom   = %ls\n",NomCmp)   ;
 resultat = wcscmp(Nom,NomCmp)      ;
 if (resultat == 0)
   wprintf(L"%ls et %ls sont identiques\n", Nom, NomCmp);
 else if (resultat < 0)
   wprintf(L"%ls < %ls \n", Nom, NomCmp);
 else 
   wprintf(L"%ls > %ls \n", Nom, NomCmp);

 wcscpy(Nom, L"Dupont")   ;
 wcscpy(Motif1, L"pntDu") ;
 wcscpy(Motif2, L"pnt")   ;
 wcscpy(Motif3, L"pntu")  ;
 wcscpy(Motif4, L"up")    ;

 index=wcsspn(Nom,Motif1);
 wprintf(L"Les %d premiers caractères de \"%ls\" sont trouvés dans \"%ls\"\n",index, Nom, Motif1);

 index=wcscspn(Nom,Motif2);
 wprintf(L"Les %d premiers caractères de \"%ls\" ne sont trouvés pas dans \"%ls\"\n",index, Nom, Motif2);
                        
 ptrw=wcspbrk(Nom,Motif3);
 wprintf(L"sous-chaîne débutant par l'un des caractères de \"%ls\" dans \"%ls\" : \"%ls\"\n",Motif3, Nom, ptrw );                                   

 ptrw=wcsstr(Nom,Motif4);
 wprintf(L"sous-chaîne débutant par \"%ls\" dans \"%ls\" : \"%ls\"\n",Motif4, Nom, ptrw ); 
}


