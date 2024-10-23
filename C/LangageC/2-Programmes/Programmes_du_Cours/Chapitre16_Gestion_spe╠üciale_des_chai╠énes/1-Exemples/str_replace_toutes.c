/* ------------------------- */
/* str_replace_toutes.c      */
/* ------------------------- */
#include <string.h>
#include <stdio.h>
 
char * str_replace_all(char * chaine, char * motif_a_remplacer, char * motif_de_remplacement)   ;

int main()
{
    char texte2[100] = "essai dd textes dd différents remplacements dd mots";

    printf("AVANT : |%s|\n",texte2);
 
    if (str_replace_all(texte2, "dd", "des") != NULL)
        printf("remplacement effectue.\n");
        
    printf("APRES : |%s|\n",texte2);

}
/* remplace toutes les occurrences de  motif_a_remplacer par motif_de_remplacement */
char * str_replace_all(char * chaine, char * motif_a_remplacer, char * motif_de_remplacement)
{
    char * pt_motif_a_remplacer = strstr(chaine, motif_a_remplacer), * chaine_retour = NULL;
    int taille_pt_motif_a_remplacer, taille_motif_a_remplacer, taille_motif_de_remplacement ;
 
    while (pt_motif_a_remplacer != NULL)
    {
        taille_pt_motif_a_remplacer  = strlen(pt_motif_a_remplacer)  ;
        taille_motif_a_remplacer     = strlen(motif_a_remplacer)     ;
        taille_motif_de_remplacement = strlen(motif_de_remplacement) ;
 
        if (taille_motif_a_remplacer != taille_motif_de_remplacement)
        {
            /* ajuster la taille pour pouvoir placer motif_de_remplacement */
            memmove(pt_motif_a_remplacer + taille_motif_de_remplacement, pt_motif_a_remplacer + taille_motif_a_remplacer, taille_pt_motif_a_remplacer);
        }
        /* remplacer par motif_de_remplacement */
        strncpy(pt_motif_a_remplacer, motif_de_remplacement, taille_motif_de_remplacement);
        /* on prépare pour la prochaine itération */
        pt_motif_a_remplacer = strstr(chaine, motif_a_remplacer);
        /* on met a jour la chaine de retour */        
        chaine_retour = chaine;
    }
 
    return chaine_retour;
}



