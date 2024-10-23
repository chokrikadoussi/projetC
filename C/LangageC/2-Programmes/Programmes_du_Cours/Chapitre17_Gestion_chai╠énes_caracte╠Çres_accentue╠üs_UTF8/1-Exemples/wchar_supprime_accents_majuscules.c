/* ----------------------------------- */
/* wchar_supprime_accents_amjuscules.c */
/* ----------------------------------- */
#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */
#include <wctype.h> /* pour towupper() */

#define TAILLE_CH 20
#define TAILLE_TAB 1000
#define NON_TROUVE -1
void conv_maj_accentsW(wchar_t ChaineWide[], int conserve_accents_OK) ;
void supprime_accents_wchar(wchar_t ChaineLettreW[]) ;
void lire_chaine_whar(wchar_t ch[]);

/* --------------------------- */
/* --- programme principal --- */
/* --------------------------- */
int main()
{
  /* indique si on veut les majuscules accentuées = 1 ou non = 0 */
  int conserve_accents = 1              ;

  /* chaîns de caractères à convertir */
  wchar_t nom[100],nom1[100],nom2[100] ;

  /* fixe la valeur a UTF-8 pour les caractères accentués */
  setlocale (LC_ALL, "fr_FR.UTF-8") ; 
 
  wprintf(L"Nom    : ")  ;
  lire_chaine_whar(nom)     ;
     
  wprintf(L"\n");
  wprintf(L"Nom saisi                            : |%ls|\n",nom);

  /* On copie le nom d'origine des les 2 variables à modifier */
  wcscpy(nom1,nom);
  wcscpy(nom2,nom);

  /* indique qu'on veut les majuscules accentuées = 1 */
  conserve_accents = 1 ;
  conv_maj_accentsW(nom1,conserve_accents);
  wprintf(L"Nom en majuscule (accents conservés) : |%ls|\n",nom1);

  /* indique qu'on ne veut pas les majuscules accentuées = 0 */
  conserve_accents = 0 ;
  conv_maj_accentsW(nom2,conserve_accents);
  wprintf(L"Nom en majuscule (accents supprimés) : |%ls|\n",nom2);
 }

/* -------------------------------------------- */
/* procédure outil de lecture d'une chaine avec des espaces */
/* -------------------------------------------- */
void lire_chaine_whar(wchar_t ch[])
{
  int  i=0    ;
  wchar_t lettre ;

  while ((lettre = getwchar()) != L'\n')
  {
     ch[i++] = lettre; /* on range chaque caractère lu dans la chaine */
  }
  ch[i] = L'\0' ; /* on termine la chaine de caractère avec un caractère null */
}
/* -------------------------------------------- */
/* --- conversion en majuscules             --- */
/* --- avec conservation ou non des accents --- */
/* -------------------------------------------- */
void conv_maj_accentsW(wchar_t ChaineWide[], int conserve_accents_OK)
{
 int TailleChaineWide=0, i=0 ;
 wchar_t UnelettreWide[2]    ; /* chaine d'un seul caractère wide */

 TailleChaineWide = wcslen(ChaineWide);

 UnelettreWide[1] = '\0';
 for (i=0 ; i<TailleChaineWide ; i++)
 {
   UnelettreWide[0] = towupper(ChaineWide[i]);
   if (! conserve_accents_OK)
   {
     supprime_accents_wchar(UnelettreWide) ;
   }
   ChaineWide[i]    = UnelettreWide[0];
 }
}

/* ------------------------------- */
/* --- suppression des accents --- */
/* ------------------------------- */
void supprime_accents_wchar(wchar_t ChaineLettreW[])
{
  /* ------------------------ */
  /* ---- les lettres A ----- */
  /* ------------------------ */
  /* traitement des accents du A */
  if ( (wcscmp(ChaineLettreW,L"À")==0) || (wcscmp(ChaineLettreW,L"Á")==0) || (wcscmp(ChaineLettreW,L"Â")==0) || (wcscmp(ChaineLettreW,L"Ã")==0) || (wcscmp(ChaineLettreW,L"Ä")==0) || (wcscmp(ChaineLettreW,L"Å")==0) )
  {
       wcscpy(ChaineLettreW,L"A");
  }
  /* traitement des accents du a */
  else if ( (wcscmp(ChaineLettreW,L"à")==0) || (wcscmp(ChaineLettreW,L"á")==0) || (wcscmp(ChaineLettreW,L"â")==0) || (wcscmp(ChaineLettreW,L"ã")==0) || (wcscmp(ChaineLettreW,L"ä")==0) || (wcscmp(ChaineLettreW,L"å")==0) )
  {
       wcscpy(ChaineLettreW,L"a");
  }
  /* traitement des autres accents du A */
  else if ( (wcscmp(ChaineLettreW,L"Ā")==0) || (wcscmp(ChaineLettreW,L"Ă")==0) || (wcscmp(ChaineLettreW,L"Ą")==0) || (wcscmp(ChaineLettreW,L"Ǎ")==0) || (wcscmp(ChaineLettreW,L"Ǻ")==0))
  {
       wcscpy(ChaineLettreW,L"A");
  }
  /* traitement des autres accents du a */
  else if ( (wcscmp(ChaineLettreW,L"ā")==0) || (wcscmp(ChaineLettreW,L"ă")==0) || (wcscmp(ChaineLettreW,L"ą")==0) || (wcscmp(ChaineLettreW,L"ǎ")==0) || (wcscmp(ChaineLettreW,L"ǻ")==0))
  {
       wcscpy(ChaineLettreW,L"a");
  }
  /* traitement des accents du AE */
  else if ( (wcscmp(ChaineLettreW,L"Æ")==0) || (wcscmp(ChaineLettreW,L"Ǽ")==0) )
  {
       wcscpy(ChaineLettreW,L"AE");
  }
  /* traitement des accents du ae */
  else if ( (wcscmp(ChaineLettreW,L"æ")==0) || (wcscmp(ChaineLettreW,L"ǽ")==0) )
  {
       wcscpy(ChaineLettreW,L"ae");
  }
  /* ------------------------ */
  /* ---- les lettres E ----- */
  /* ------------------------ */
  /* traitement des accents du E */
  else if ( (wcscmp(ChaineLettreW,L"È")==0) || (wcscmp(ChaineLettreW,L"É")==0) || (wcscmp(ChaineLettreW,L"Ê")==0) || (wcscmp(ChaineLettreW,L"Ë")==0) )
  {
       wcscpy(ChaineLettreW,L"E");
  }
  else if ( (wcscmp(ChaineLettreW,L"è")==0) || (wcscmp(ChaineLettreW,L"é")==0) || (wcscmp(ChaineLettreW,L"ê")==0) || (wcscmp(ChaineLettreW,L"ë")==0) )
  {
       wcscpy(ChaineLettreW,L"e");
  }
  /* traitement des autres accents du E */
  else if ( (wcscmp(ChaineLettreW,L"Ē")==0) || (wcscmp(ChaineLettreW,L"Ẽ")==0) || (wcscmp(ChaineLettreW,L"Ė")==0) || (wcscmp(ChaineLettreW,L"Ę")==0) || (wcscmp(ChaineLettreW,L"Ě")==0) || (wcscmp(ChaineLettreW,L"Ĕ")==0) )
  {
       wcscpy(ChaineLettreW,L"E");
  }
  /* traitement des autres accents du e */
  else if ( (wcscmp(ChaineLettreW,L"ē")==0) || (wcscmp(ChaineLettreW,L"ẽ")==0) || (wcscmp(ChaineLettreW,L"ė")==0) || (wcscmp(ChaineLettreW,L"ę")==0) || (wcscmp(ChaineLettreW,L"ě")==0) || (wcscmp(ChaineLettreW,L"ĕ")==0) )
  {
       wcscpy(ChaineLettreW,L"e");
  }
  /* ------------------------ */
  /* ---- les lettres I ----- */
  /* ------------------------ */
  /* traitement des accents du I */
  else if ( (wcscmp(ChaineLettreW,L"Ì")==0) || (wcscmp(ChaineLettreW,L"Í")==0) || (wcscmp(ChaineLettreW,L"Î")==0) || (wcscmp(ChaineLettreW,L"Ï")==0) )
  {
       wcscpy(ChaineLettreW,L"I");
  }
  /* traitement des accents du i */
  else if ( (wcscmp(ChaineLettreW,L"ì")==0) || (wcscmp(ChaineLettreW,L"í")==0) || (wcscmp(ChaineLettreW,L"î")==0) || (wcscmp(ChaineLettreW,L"ï")==0) )
  {
       wcscpy(ChaineLettreW,L"i");
  }
  /* traitement des autres accents du I */
  else if ( (wcscmp(ChaineLettreW,L"Ĩ")==0) || (wcscmp(ChaineLettreW,L"Ī")==0) || (wcscmp(ChaineLettreW,L"Ĭ")==0) || (wcscmp(ChaineLettreW,L"Į")==0) || (wcscmp(ChaineLettreW,L"İ")==0) || (wcscmp(ChaineLettreW,L"Ǐ")==0) )
  {
       wcscpy(ChaineLettreW,L"I");
  }
  /* traitement des autres accents du i */
  else if ( (wcscmp(ChaineLettreW,L"ĩ")==0) || (wcscmp(ChaineLettreW,L"ī")==0) || (wcscmp(ChaineLettreW,L"ĭ")==0) || (wcscmp(ChaineLettreW,L"į")==0) || (wcscmp(ChaineLettreW,L"ị")==0) || (wcscmp(ChaineLettreW,L"ǐ")==0) || (wcscmp(ChaineLettreW,L"ı")==0) )
  {
       wcscpy(ChaineLettreW,L"i");
  }
  /* ------------------------ */
  /* ---- les lettres O ----- */
  /* ------------------------ */
  /* traitement des accents du O */
  else if ( (wcscmp(ChaineLettreW,L"Ò")==0) || (wcscmp(ChaineLettreW,L"Ó")==0) || (wcscmp(ChaineLettreW,L"Ô")==0) || (wcscmp(ChaineLettreW,L"Ö")==0) || (wcscmp(ChaineLettreW,L"Õ")==0) || (wcscmp(ChaineLettreW,L"Ø")==0) || (wcscmp(ChaineLettreW,L"Ǿ")==0) || (wcscmp(ChaineLettreW,L"Ǒ")==0) )
  {
       wcscpy(ChaineLettreW,L"O");
  }
  /* traitement des accents du o */
  else if ( (wcscmp(ChaineLettreW,L"ò")==0) || (wcscmp(ChaineLettreW,L"ó")==0) || (wcscmp(ChaineLettreW,L"ô")==0) || (wcscmp(ChaineLettreW,L"ö")==0) || (wcscmp(ChaineLettreW,L"õ")==0) || (wcscmp(ChaineLettreW,L"ø")==0) || (wcscmp(ChaineLettreW,L"ǿ")==0) || (wcscmp(ChaineLettreW,L"ǒ")==0) )
  {
       wcscpy(ChaineLettreW,L"o");
  }
  /* traitement des autres accents du O */
  else if ( (wcscmp(ChaineLettreW,L"Ō")==0) || (wcscmp(ChaineLettreW,L"Ŏ")==0) || (wcscmp(ChaineLettreW,L"Ő")==0) || (wcscmp(ChaineLettreW,L"Ơ")==0) )
  {
       wcscpy(ChaineLettreW,L"O");
  }
  /* traitement des autres accents du o */
  else if ( (wcscmp(ChaineLettreW,L"ō")==0) || (wcscmp(ChaineLettreW,L"ŏ")==0) || (wcscmp(ChaineLettreW,L"ő")==0) || (wcscmp(ChaineLettreW,L"ơ")==0) )
  {
       wcscpy(ChaineLettreW,L"o");
  }
  /* traitement des accents du OE */
  else if ( (wcscmp(ChaineLettreW,L"Œ")==0) )
  {
       wcscpy(ChaineLettreW,L"OE");
  }
  /* traitement des accents du oe */
  else if ( (wcscmp(ChaineLettreW,L"œ")==0) )
  {
       wcscpy(ChaineLettreW,L"oe");
  }
  /* ------------------------ */
  /* ---- les lettres U ----- */
  /* ------------------------ */
  /* traitement des accents du U */
  else if ( (wcscmp(ChaineLettreW,L"Ù")==0) || (wcscmp(ChaineLettreW,L"Ú")==0) || (wcscmp(ChaineLettreW,L"Û")==0) || (wcscmp(ChaineLettreW,L"Ü")==0) )
  {
       wcscpy(ChaineLettreW,L"U");
  }
  /* traitement des accents du U */
  else if ( (wcscmp(ChaineLettreW,L"ù")==0) || (wcscmp(ChaineLettreW,L"ú")==0) || (wcscmp(ChaineLettreW,L"û")==0) || (wcscmp(ChaineLettreW,L"ü")==0) )
  {
       wcscpy(ChaineLettreW,L"u");
  }
  /* traitement des autres accents du U */
  else if ( (wcscmp(ChaineLettreW,L"Ũ")==0) || (wcscmp(ChaineLettreW,L"Ū")==0) || (wcscmp(ChaineLettreW,L"Ŭ")==0) || (wcscmp(ChaineLettreW,L"Ů")==0) || (wcscmp(ChaineLettreW,L"Ű")==0) || (wcscmp(ChaineLettreW,L"Ų")==0) || (wcscmp(ChaineLettreW,L"Ư")==0) )
  {
       wcscpy(ChaineLettreW,L"U");
  }
  /* traitement des autres accents du U */
  else if ( (wcscmp(ChaineLettreW,L"Ǔ")==0) || (wcscmp(ChaineLettreW,L"Ǖ")==0) || (wcscmp(ChaineLettreW,L"Ǘ")==0) || (wcscmp(ChaineLettreW,L"Ǚ")==0) || (wcscmp(ChaineLettreW,L"Ǜ")==0) )
  {
       wcscpy(ChaineLettreW,L"U");
  }
  /* traitement des autres accents du u */
  else if ( (wcscmp(ChaineLettreW,L"ũ")==0) || (wcscmp(ChaineLettreW,L"ū")==0) || (wcscmp(ChaineLettreW,L"ŭ")==0) || (wcscmp(ChaineLettreW,L"ů")==0) || (wcscmp(ChaineLettreW,L"ű")==0) || (wcscmp(ChaineLettreW,L"ų")==0)  || (wcscmp(ChaineLettreW,L"ư")==0))
  {
       wcscpy(ChaineLettreW,L"u");
  }
  /* traitement des autres accents du u */
  else if ( (wcscmp(ChaineLettreW,L"ǔ")==0) || (wcscmp(ChaineLettreW,L"ǖ")==0) || (wcscmp(ChaineLettreW,L"ǘ")==0) || (wcscmp(ChaineLettreW,L"ǚ")==0) || (wcscmp(ChaineLettreW,L"ǜ")==0) )
  {
       wcscpy(ChaineLettreW,L"u");
  }
  /* ------------------------ */
  /* ---- les lettres Y ----- */
  /* ------------------------ */
  /* traitement des accents du Y */
  else if ( (wcscmp(ChaineLettreW,L"Ý")==0) || (wcscmp(ChaineLettreW,L"Ÿ")==0) )
  {
       wcscpy(ChaineLettreW,L"Y");
  }
  /* traitement des accents du y */
  else if ( (wcscmp(ChaineLettreW,L"ý")==0) || (wcscmp(ChaineLettreW,L"ÿ")==0) )
  {
       wcscpy(ChaineLettreW,L"y");
  }
  /* ------------------------ */
  /* ---- les lettres C ----- */
  /* ------------------------ */
  /* traitement des accents du Ç */
  else if ( (wcscmp(ChaineLettreW,L"Ç")==0) || (wcscmp(ChaineLettreW,L"Ć")==0) || (wcscmp(ChaineLettreW,L"Ĉ")==0) || (wcscmp(ChaineLettreW,L"Ċ")==0) || (wcscmp(ChaineLettreW,L"Č")==0) )
  {
       wcscpy(ChaineLettreW,L"C");
  }
  /* traitement des accents du c */
  else if ( (wcscmp(ChaineLettreW,L"ç")==0) || (wcscmp(ChaineLettreW,L"ć")==0) || (wcscmp(ChaineLettreW,L"ĉ")==0) || (wcscmp(ChaineLettreW,L"ċ")==0) || (wcscmp(ChaineLettreW,L"č")==0) )
  {
       wcscpy(ChaineLettreW,L"c");
  }
  /* ------------------------ */
  /* ---- les lettres D ----- */
  /* ------------------------ */
  /* traitement des accents du Ð */
  else if ( (wcscmp(ChaineLettreW,L"Ð")==0) || (wcscmp(ChaineLettreW,L"Ď")==0)   )
  {
       wcscpy(ChaineLettreW,L"D");
  }
  else if ( (wcscmp(ChaineLettreW,L"đ")==0) || (wcscmp(ChaineLettreW,L"ď")==0)   )
  {
       wcscpy(ChaineLettreW,L"d");
  }
  /* ------------------------ */
  /* ---- les lettres F ----- */
  /* ------------------------ */
  /* traitement des accents du ƒ */
  else if ( (wcscmp(ChaineLettreW,L"ƒ")==0) )
  {
       wcscpy(ChaineLettreW,L"f");
  }
  /* ------------------------ */
  /* ---- les lettres N ----- */
  /* ------------------------ */
  /* traitement des accents du N */
  else if ( (wcscmp(ChaineLettreW,L"Ñ")==0) || (wcscmp(ChaineLettreW,L"Ń")==0) || (wcscmp(ChaineLettreW,L"Ņ")==0) || (wcscmp(ChaineLettreW,L"Ň")==0) )
  {
       wcscpy(ChaineLettreW,L"N");
  }
  /* traitement des accents du n */
  else if ( (wcscmp(ChaineLettreW,L"ñ")==0) || (wcscmp(ChaineLettreW,L"ń")==0) || (wcscmp(ChaineLettreW,L"ņ")==0) || (wcscmp(ChaineLettreW,L"ň")==0) || (wcscmp(ChaineLettreW,L"ŉ")==0) )
  {
       wcscpy(ChaineLettreW,L"n");
  }
  /* ------------------------ */
  /* ---- les lettres G ----- */
  /* ------------------------ */
  /* traitement des accents du G */
  else if ( (wcscmp(ChaineLettreW,L"Ĝ")==0) || (wcscmp(ChaineLettreW,L"Ğ")==0) || (wcscmp(ChaineLettreW,L"Ġ")==0) || (wcscmp(ChaineLettreW,L"Ģ")==0) )
  {
       wcscpy(ChaineLettreW,L"G");
  }
  /* traitement des accents du g */
  else if ( (wcscmp(ChaineLettreW,L"ĝ")==0) || (wcscmp(ChaineLettreW,L"ğ")==0) || (wcscmp(ChaineLettreW,L"ġ")==0) || (wcscmp(ChaineLettreW,L"ģ")==0) )
  {
       wcscpy(ChaineLettreW,L"g");
  }
  /* ------------------------ */
  /* ---- les lettres H ----- */
  /* ------------------------ */
  /* traitement des accents du H */
  else if ( (wcscmp(ChaineLettreW,L"Ĥ")==0) || (wcscmp(ChaineLettreW,L"Ħ")==0) )
  {
       wcscpy(ChaineLettreW,L"H");
  }
  /* traitement des accents du h */
  else if ( (wcscmp(ChaineLettreW,L"ĥ")==0) || (wcscmp(ChaineLettreW,L"ħ")==0) )
  {
       wcscpy(ChaineLettreW,L"h");
  }
  /* ------------------------ */
  /* ---- les lettres IJ ----- */
  /* ------------------------ */
  /* traitement des accents du IJ */
  else if ( (wcscmp(ChaineLettreW,L"Ĳ")==0) )
  {
       wcscpy(ChaineLettreW,L"IJ");
  }
  /* traitement des accents du ij */
  else if ( (wcscmp(ChaineLettreW,L"ĳ")==0) )
  {
       wcscpy(ChaineLettreW,L"ij");
  }
  /* ------------------------ */
  /* ---- les lettres J ----- */
  /* ------------------------ */
  /* traitement des accents du J */
  else if ( (wcscmp(ChaineLettreW,L"Ĵ")==0) )
  {
       wcscpy(ChaineLettreW,L"J");
  }
  /* traitement des accents du j */
  else if ( (wcscmp(ChaineLettreW,L"ĵ")==0) )
  {
       wcscpy(ChaineLettreW,L"j");
  }
  /* ------------------------ */
  /* ---- les lettres K ----- */
  /* ------------------------ */
  /* traitement des accents du K */
  else if ( (wcscmp(ChaineLettreW,L"Ķ")==0) )
  {
       wcscpy(ChaineLettreW,L"K");
  }
  /* traitement des accents du k */
  else if ( (wcscmp(ChaineLettreW,L"ķ")==0) )
  {
       wcscpy(ChaineLettreW,L"k");
  }
  /* ------------------------ */
  /* ---- les lettres L ----- */
  /* ------------------------ */
  /* traitement des accents du L */
  else if ( (wcscmp(ChaineLettreW,L"Ĺ")==0) || (wcscmp(ChaineLettreW,L"Ļ")==0) || (wcscmp(ChaineLettreW,L"Ľ")==0) || (wcscmp(ChaineLettreW,L"Ŀ")==0)|| (wcscmp(ChaineLettreW,L"Ł")==0)  )
  {
       wcscpy(ChaineLettreW,L"L");
  }
  /* traitement des accents du l */
  else if ( (wcscmp(ChaineLettreW,L"ĺ")==0) || (wcscmp(ChaineLettreW,L"ļ")==0) || (wcscmp(ChaineLettreW,L"ľ")==0) || (wcscmp(ChaineLettreW,L"ŀ")==0)|| (wcscmp(ChaineLettreW,L"ł")==0)  )
  {
       wcscpy(ChaineLettreW,L"l");
  }
  /* ------------------------ */
  /* ---- les lettres R ----- */
  /* ------------------------ */
  /* traitement des accents du R */
  else if ( (wcscmp(ChaineLettreW,L"Ŕ")==0) || (wcscmp(ChaineLettreW,L"Ŗ")==0) || (wcscmp(ChaineLettreW,L"Ř")==0) )
  {
       wcscpy(ChaineLettreW,L"R");
  }
  /* traitement des accents du r */
  else if ( (wcscmp(ChaineLettreW,L"ŕ")==0) || (wcscmp(ChaineLettreW,L"ŗ")==0) || (wcscmp(ChaineLettreW,L"ř")==0) )
  {
       wcscpy(ChaineLettreW,L"r");
  }
  /* ------------------------ */
  /* ---- les lettres S ----- */
  /* ------------------------ */
  /* traitement des accents du S */
  else if ( (wcscmp(ChaineLettreW,L"Ś")==0) || (wcscmp(ChaineLettreW,L"Ŝ")==0) || (wcscmp(ChaineLettreW,L"Ş")==0) || (wcscmp(ChaineLettreW,L"Š")==0))
  {
       wcscpy(ChaineLettreW,L"S");
  }
  /* traitement des accents du s */
  else if ( (wcscmp(ChaineLettreW,L"ś")==0) || (wcscmp(ChaineLettreW,L"ŝ")==0) || (wcscmp(ChaineLettreW,L"ş")==0) || (wcscmp(ChaineLettreW,L"š")==0))
  {
       wcscpy(ChaineLettreW,L"s");
  }
  /* traitement des accents du ß */
  else if ( (wcscmp(ChaineLettreW,L"ß")==0) )
  {
       wcscpy(ChaineLettreW,L"S");
  }
  /* traitement des accents du ſ */
  else if ( (wcscmp(ChaineLettreW,L"ſ")==0) )
  {
       wcscpy(ChaineLettreW,L"s");
  }
  /* ------------------------ */
  /* ---- les lettres T ----- */
  /* ------------------------ */
  /* traitement des accents du T */
  else if ( (wcscmp(ChaineLettreW,L"Ţ")==0) || (wcscmp(ChaineLettreW,L"Ť")==0) || (wcscmp(ChaineLettreW,L"Ŧ")==0) )
  {
       wcscpy(ChaineLettreW,L"T");
  }
  /* traitement des accents du t */
  else if ( (wcscmp(ChaineLettreW,L"ţ")==0) || (wcscmp(ChaineLettreW,L"ť")==0) || (wcscmp(ChaineLettreW,L"ŧ")==0) )
  {
       wcscpy(ChaineLettreW,L"t");
  }
  /* ------------------------ */
  /* ---- les lettres W ----- */
  /* ------------------------ */
  /* traitement des accents du W */
  else if ( (wcscmp(ChaineLettreW,L"Ŵ")==0) )
  {
       wcscpy(ChaineLettreW,L"W");
  }
  /* traitement des accents du w */
  else if ( (wcscmp(ChaineLettreW,L"ŵ")==0) )
  {
       wcscpy(ChaineLettreW,L"w");
  }
  /* ------------------------ */
  /* ---- les lettres Y ----- */
  /* ------------------------ */
  /* traitement des accents du Y */
  else if ( (wcscmp(ChaineLettreW,L"Ŷ")==0) || (wcscmp(ChaineLettreW,L"Ÿ")==0) )
  {
       wcscpy(ChaineLettreW,L"Y");
  }
  /* traitement des accents du y */
  else if ( (wcscmp(ChaineLettreW,L"ŷ")==0) || (wcscmp(ChaineLettreW,L"ÿ")==0) )
  {
       wcscpy(ChaineLettreW,L"y");
  }
  /* ------------------------ */
  /* ---- les lettres Z ----- */
  /* ------------------------ */
  /* traitement des accents du Z */
  else if ( (wcscmp(ChaineLettreW,L"Ź")==0) || (wcscmp(ChaineLettreW,L"Ż")==0) || (wcscmp(ChaineLettreW,L"Ž")==0) )
  {
       wcscpy(ChaineLettreW,L"Z");
  }
  /* traitement des accents du z */
  else if ( (wcscmp(ChaineLettreW,L"ź")==0) || (wcscmp(ChaineLettreW,L"ż")==0) || (wcscmp(ChaineLettreW,L"ž")==0) )
  {
       wcscpy(ChaineLettreW,L"z");
  }
}
