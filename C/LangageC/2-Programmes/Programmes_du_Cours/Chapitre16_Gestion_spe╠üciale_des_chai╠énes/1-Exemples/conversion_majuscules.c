/* ----------------------------- */
/* conversion_majuscules.c       */
/* ----------------------------- */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
 
char * str_replace_all(char * chaine, char * motif_a_remplacer, char * motif_de_remplacement)   ;
char * supprime_accent(char * chaine) ;
void conv_min_maj(char * chaine)      ;

int main()
{
    char chaine1[1000] = "anaïs léry, frédérique èphémâreùÙ";
    char *chaine2;
 
    printf("AVANT : |%s|\n", chaine1)  ;
    /* appel de la fonction */
    chaine2 = supprime_accent(chaine1) ;
    conv_min_maj(chaine2)              ;
    printf("APRES : |%s|\n", chaine2)  ;

}

/* =============================================================================== */
/* remplace toutes les occurrences de  motif_a_remplacer par motif_de_remplacement */
/* =============================================================================== */
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

// =================================================
// --- fonction outil de suppression des accents ---
// =================================================
char * supprime_accent(char * chaine)
{
  char * chaine_retour = chaine, *motif_a_remplacer, *motif_de_remplacement ;
  size_t  nb_elements ;
  int i               ;

  /* tableau de tous les caractères accentués à remplacer */
  const char * tab_caracteres_a_remplacer[]     = {"À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "ß", "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ï", "ñ", "ò", "ó", "ô", "õ", "ö", "ø", "ù", "ú", "û", "ü", "ý", "ÿ", "Ā", "ā", "Ă", "ă", "Ą", "ą", "Ć", "ć", "Ĉ", "ĉ", "Ċ", "ċ", "Č", "č", "Ď", "ď", "Đ", "đ", "Ẽ", "ẽ", "Ē", "ē", "Ĕ", "ĕ", "Ė", "ė", "Ę", "ę", "Ě", "ě", "Ĝ", "ĝ", "Ğ", "ğ", "Ġ", "ġ", "Ģ", "ģ", "Ĥ", "ĥ", "Ħ", "ħ", "Ĩ", "ĩ", "Ī", "ī", "Ĭ", "ĭ", "Į", "į", "İ", "ı", "Ĳ", "ĳ", "Ĵ", "ĵ", "Ķ", "ķ", "Ĺ", "ĺ", "Ļ", "ļ", "Ľ", "ľ", "Ŀ", "ŀ", "Ł", "ł", "Ń", "ń", "Ņ", "ņ", "Ň", "ň", "ŉ", "Ō", "ō", "Ŏ", "ŏ", "Ő", "ő", "Œ", "œ", "Ŕ", "ŕ", "Ŗ", "ŗ", "Ř", "ř", "Ś", "ś", "Ŝ", "ŝ", "Ş", "ş", "Š", "š", "Ţ", "ţ", "Ť", "ť", "Ŧ", "ŧ", "Ũ", "ũ", "Ū", "ū", "Ŭ", "ŭ", "Ů", "ů", "Ű", "ű", "Ų", "ų", "Ŵ", "ŵ", "Ŷ", "ŷ", "Ÿ", "ÿ", "Ź", "ź", "Ż", "ż", "Ž", "ž", "ſ", "ƒ", "Ơ", "ơ", "Ư", "ư", "Ǎ", "ǎ", "Ǐ", "ǐ", "Ǒ", "ǒ", "Ǔ", "ǔ", "Ǖ", "ǖ", "Ǘ", "ǘ", "Ǚ", "ǚ", "Ǜ", "ǜ", "Ǻ", "ǻ", "Ǽ", "ǽ", "Ǿ", "ǿ"};
  /* tableau de tous les caractères sans accent de remplacement */
  const char * tab_caracteres_de_remplacement[] = {"A", "A", "A", "A", "A", "A", "AE", "C", "E", "E", "E", "E", "I", "I", "I", "I", "D", "N", "O", "O", "O", "O", "O", "O", "U", "U", "U", "U", "Y", "s", "a", "a", "a", "a", "a", "a", "ae", "c", "e", "e", "e", "e", "i", "i", "i", "i", "n", "o", "o", "o", "o", "o", "o", "u", "u", "u", "u", "y", "y", "A", "a", "A", "a", "A", "a", "C", "c", "C", "c", "C", "c", "C", "c", "D", "d", "D", "d", "E", "e", "E", "e", "E", "e", "E", "e", "E", "e", "E", "e", "G", "g", "G", "g", "G", "g", "G", "g", "H", "h", "H", "h", "I", "i", "I", "i", "I", "i", "I", "i", "I", "i", "IJ", "ij", "J", "j", "K", "k", "L", "l", "L", "l", "L", "l", "L", "l", "l", "l", "N", "n", "N", "n", "N", "n", "n", "O", "o", "O", "o", "O", "o", "OE", "oe", "R", "r", "R", "r", "R", "r", "S", "s", "S", "s", "S", "s", "S", "s", "T", "t", "T", "t", "T", "t", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "W", "w", "Y", "y", "Y", "y", "Z", "z", "Z", "z", "Z", "z", "s", "f", "O", "o", "U", "u", "A", "a", "I", "i", "O", "o", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "A", "a", "AE", "ae", "O", "o"};

  nb_elements  = sizeof(tab_caracteres_de_remplacement) / sizeof(*tab_caracteres_de_remplacement) ;
  /* boucle de traitement de tous les caractères */
  for (i = 0 ; i < nb_elements ; i++)
  {
     motif_a_remplacer     = (char * ) tab_caracteres_a_remplacer[i]     ;
     motif_de_remplacement = (char * ) tab_caracteres_de_remplacement[i] ;
     chaine_retour = str_replace_all(chaine, motif_a_remplacer, motif_de_remplacement) ;
     if (chaine_retour != NULL)
     {
       chaine = chaine_retour;
     }
  }
  return chaine;
}

// =================================================
// --- fonction outil de conversion en majuscules ---
// =================================================
void conv_min_maj(char * chaine)
{
  int taille, i ;
  taille =strlen(chaine);
  for (i = 0 ; i < taille ; i++)
  {
    chaine[i] = toupper(chaine[i]);
  }

}


