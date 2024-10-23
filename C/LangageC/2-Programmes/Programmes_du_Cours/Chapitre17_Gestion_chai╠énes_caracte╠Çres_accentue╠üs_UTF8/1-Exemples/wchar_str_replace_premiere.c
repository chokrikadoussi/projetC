/* ------------------------------- */
/* wchar_str_replace_premiere.c    */
/* ------------------------------- */
#include <string.h>
#include <stdio.h>
#include <wchar.h>   /* Pour les fonctions de chaines wchar_t */
#include <wctype.h>  /* Pour les fonctions de caractères wchar_t */
#include <locale.h>  /* pour la fonction setlocale */
 
wchar_t * wchar_str_replace_first(wchar_t * chaine, wchar_t * motif_a_remplacer, wchar_t * motif_de_remplacement) ;

int main()
{
    wchar_t texte1[100] = L"Le texte à modifier !";
 
   setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur à UTF-8 */
    
   wprintf(L"AVANT : |%ls|\n",texte1);
    
    if (wchar_str_replace_first(texte1, L"à modifier", L"à été modifié") != NULL)
        wprintf(L"Remplacement effectué.\n");
        
    wprintf(L"APRES : |%ls|\n",texte1);
 
}

/* remplace la première occurrence de  motif_a_remplacer par motif_de_remplacement */
wchar_t * wchar_str_replace_first(wchar_t * chaine, wchar_t * motif_a_remplacer, wchar_t * motif_de_remplacement)
{
    wchar_t * pt_motif_a_remplacer = wcsstr(chaine, motif_a_remplacer), * chaine_retour = NULL;
    int taille_pt_motif_a_remplacer, taille_motif_a_remplacer, taille_motif_de_remplacement ;
 
    if (pt_motif_a_remplacer != NULL)
    {
        taille_pt_motif_a_remplacer  = wcslen(pt_motif_a_remplacer)  ;
        taille_motif_a_remplacer     = wcslen(motif_a_remplacer)     ;
        taille_motif_de_remplacement = wcslen(motif_de_remplacement) ;
 
        if (taille_motif_a_remplacer != taille_motif_de_remplacement)
        {
            /* ajuster la taille pour pouvoir placer motif_de_remplacement */
            wmemmove(pt_motif_a_remplacer + taille_motif_de_remplacement, pt_motif_a_remplacer + taille_motif_a_remplacer, taille_pt_motif_a_remplacer);
        }
        /* remplacer par motif_de_remplacement */
        wcpncpy(pt_motif_a_remplacer, motif_de_remplacement, taille_motif_de_remplacement);
        /* on met a jour la chaine de retour */        
        chaine_retour = chaine;
    }
 
    return chaine_retour;
}
