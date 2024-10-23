/* ----------------------------- */
/* verif_chaine_dans_alphabet.c  */
/* ----------------------------- */
#include <stdio.h>
#include <string.h>

int verif_chaine_dans_alphabet(char ch[], char alphabet[]);
void affiche_caracteres_absents_alphabet(char ch[], char alphabet[]);


int main()
{
  char alpabet[]="ABab ;" ;
  int nbcarAlphabet       ;
  char saisie[100]        ;
  int i,taille, ChaineDansAlphabet ;
  
  nbcarAlphabet=strlen(alpabet);
  
  printf("Entrez une chaine de caractères : ");
  scanf("%[^\n]",saisie); /* Lit tous les caractères sauf la fin de ligne (LF) */
  
  printf("Vérification que la chaîne |%s| ne contient \n",saisie);
  printf("que des caractères parmi : |%s|\n",alpabet);
  
  ChaineDansAlphabet=verif_chaine_dans_alphabet(saisie, alpabet);
  if (ChaineDansAlphabet)
     printf("Tous les caractères de la chaîne sont dans l'alphabet\n");
  else
  {
     printf("Certains caractères de la chaîne sont absent de l'alphabet\n");
     affiche_caracteres_absents_alphabet(saisie, alpabet);
  }
  
}

// ================================================================
// --- fonction de vérification que les caractères d'une chaîne ---
// --- sont dans un alphabet ---
// ================================================================
int verif_chaine_dans_alphabet(char ch[], char alphabet[])
{
  int verificationOK = 1, trouve = 0       ;
  char lettre, calphabet                   ;
  int taillech, taillealpha, i = 0, j = 0  ;

  taillech    = strlen(ch)         ;
  taillealpha = strlen(alphabet)   ;

  i=0;
  while ((i < taillech) && (verificationOK))
  {
    lettre = ch[i] ;
    trouve = 0     ;
    j = 0          ;
    while ((j < taillealpha) && (!trouve))
    {
      calphabet = alphabet[j];
      if (calphabet == lettre) trouve=1;
      j++;
    }
    /* Quand on sort de la boucle précédente si trouve est FAUX  */
    /* alors lettre n'a pas été trouvé dans alphabet */
    if (!trouve) verificationOK = 0;
    i++;
  }
  return verificationOK ;
}
// ==================================================================
// --- fonction d'affichage des caractères absents de l'alphabet ---
// ==================================================================
void affiche_caracteres_absents_alphabet(char ch[], char alphabet[])
{
  int trouve = 0       ;
  char lettre, calphabet                   ;
  int taillech, taillealpha, i = 0, j = 0  ;

  taillech    = strlen(ch)         ;
  taillealpha = strlen(alphabet)   ;

  i=0;
  while (i < taillech)
  {
    lettre = ch[i] ;
    trouve = 0     ;
    j = 0          ;
    while ((j < taillealpha) && (!trouve))
    {
      calphabet = alphabet[j];
      if (calphabet == lettre) trouve=1;
      j++;
    }
    /* Quand on sort de la boucle précédente si trouve est FAUX  */
    /* alors lettre n'a pas été trouvé dans alphabet */
    if (!trouve)
      printf("-> le caractère %c absent de l'aphabet\n",lettre);
    i++;
  }
}