/* -------------------------- */
/* wchar_str_replace_toutes.c */
/* -------------------------- */
#include <string.h>
#include <stdio.h>
#include <wchar.h>   /* Pour les fonctions de chaines wchar_t */
#include <wctype.h>  /* Pour les fonctions de caractères wchar_t */
#include <locale.h>  /* pour la fonction setlocale */
 
wchar_t * wchar_str_replace_all(wchar_t * chaine, wchar_t * motif_a_remplacer, wchar_t * motif_de_remplacement) ;

int main()
{
    wchar_t texte2[100] = L"essai dés textes dés remplacements dés mots";
 
   setlocale (LC_ALL, "fr_FR.UTF-8") ; /* Valeur à UTF-8 */
    
   wprintf(L"AVANT : |%ls|\n",texte2);
    
    if (wchar_str_replace_all(texte2, L"dés", L"des différents") != NULL)
       wprintf(L"Remplacement effectué.\n");
        
    wprintf(L"APRES : |%ls|\n",texte2);
 
}

/* remplace toutes les occurrences de  motif_a_remplacer par motif_de_remplacement */
wchar_t * wchar_str_replace_all(wchar_t * chaine, wchar_t * motif_a_remplacer, wchar_t * motif_de_remplacement)
{
    wchar_t * pt_motif_a_remplacer = wcsstr(chaine, motif_a_remplacer), * chaine_retour = NULL;
    int taille_pt_motif_a_remplacer, taille_motif_a_remplacer, taille_motif_de_remplacement ;
 
    while (pt_motif_a_remplacer != NULL)
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
        /* on prépare pour la prochaine itération */
        pt_motif_a_remplacer = wcsstr(chaine, motif_a_remplacer);
        /* on met à jour la chaine de retour */        
        chaine_retour = chaine;

    }

    return chaine_retour;
}
