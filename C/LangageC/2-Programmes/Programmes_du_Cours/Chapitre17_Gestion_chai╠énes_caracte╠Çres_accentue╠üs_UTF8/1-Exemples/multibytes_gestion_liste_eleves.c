#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>  /* pour le type wchar_t */
#include <locale.h> /* pour setlocale UTF8 */
#include <wctype.h> /* pour towupper() */
#include <string.h>

#define TAILLE_CH 20
#define TAILLE_TAB 1000
#define NON_TROUVE -1

/* ----Type etudiant global -------- */
struct etudiant {
    char  nom[TAILLE_CH]      ;
    char  prenom[2*TAILLE_CH] ;
    int   age                 ;
}; 
/* ----Variables globales-------- */
struct etudiant tabeleves[TAILLE_TAB] ;
int nbeleves = 0                      ;
int a_sauvegarder = 0                 ;
/* indique si on veut les majuscules accentuées = 1 ou non = 0 */
int conserve_accents = 0              ;
/* ----Declarations preliminaires-------- */
void saisie()                       ;
void affichage()                    ;
void conv_maj_accents(char ChaineOctets[], int conserve_accents_OK) ;
void sauvegarde()                   ;
void chargement()                   ;
void supprime_tous_les_eleves()     ;
void rechercher_eleve()             ;
int  recherche(char nomrech[])   ;
void modification()                 ;
void suppression()                  ;
void quitter()                      ;
void verif_sauvegarde()             ;
void supprime_accents(char ChaineLettre[]); 

/* --------------------------- */
/* --- programme principal --- */
/* --------------------------- */
int main()
{
  int choix = -1         ;
  struct etudiant eleve  ;

  /* fixe la valeur a UTF-8 pour les caractères accentués */
  setlocale (LC_ALL, "fr_FR.UTF-8") ; 
 
  /* --- Menu --- */
  while (choix != 0)
  {
   printf("-1-Saisie\n")         ;
   printf("-2-Affichage\n")      ;
   printf("-3-Sauvegarde\n")     ;
   printf("-4-Chargement\n")     ;
   printf("-5-Vider la liste\n") ;
   printf("-6-Rechercher\n")     ;
   printf("-7-Modifier\n")       ;
   printf("-8-Supprimer\n")      ;
   printf("-0-Quitter\n")        ;
   printf("Choix : ")            ;
   scanf("%d",&choix)            ;

   switch(choix)
   {
    case 1 : saisie()    ;
             break       ;
    case 2 : affichage() ;
             break       ;
    case 3 : sauvegarde();
             break       ;
    case 4 : chargement();
             break       ;
    case 5 : supprime_tous_les_eleves()     ;
             break       ;
    case 6 : rechercher_eleve() ;
             break              ;
    case 7 : modification()     ;
             break              ;
    case 8 : suppression()      ;
             break              ;
    case 0 : quitter()   ;
             break       ;
    default : printf("Erreur de saisie\n");
             break                        ;
   }
  }
}
/* ----------------------------------- */
/* --- saisie d'une liste d'élèves --- */
/* ----------------------------------- */
void saisie()
{
  struct etudiant eleve ;
  int i = nbeleves;

  strcpy(eleve.nom,"\0");

  while ( strcmp(eleve.nom,"FIN") != 0  )
  {
    printf("nom : ");
    scanf("%s",eleve.nom)              ;
    conv_maj_accents(eleve.nom,conserve_accents);

    if  ( strcmp(eleve.nom,"FIN") != 0  )
    {
     printf("Prénom : ");
     scanf("%s",eleve.prenom)  ;
     conv_maj_accents(eleve.prenom,conserve_accents)   ;
     printf("Age : ")         ;
     scanf("%d", &eleve.age)  ;
     tabeleves[i++] = eleve   ;
    }
  }
  nbeleves = i ;
  printf("%d élève(s) saisi(s)\n",nbeleves);
  a_sauvegarder=1;
}
/* --------------------------------- */
/* --- affichage des élèves      --- */
/* --------------------------------- */
void affichage()
{
  struct etudiant eleve;
  int i ;

  if (nbeleves == 0)
    printf("Aucun élève à afficher\n");
  else
  {
   for (i=0; i<nbeleves;i++)
   {
     eleve = tabeleves[i];
     printf("%-20s %-20s %4d\n",eleve.nom, eleve.prenom, eleve.age);
   }
  }
}
/* --------------------------------- */
/* --- sauvegarde d'un fichier   --- */
/* --------------------------------- */
void sauvegarde()
{
  struct etudiant eleve;
  int i ;
  FILE *f1;
  char nomfichier[200];

  if (nbeleves == 0)
    printf("Aucun élève à sauvegarder\n");
  else
  {
   printf("Nom du fichier de sauvegarde : ");
   scanf("%s",nomfichier);
   f1=fopen(nomfichier,"w");
   for (i=0; i<nbeleves;i++)
   {
     eleve = tabeleves[i];
     fprintf(f1,"%s %s %d\n",eleve.nom, eleve.prenom, eleve.age);
   }
   fclose(f1);
   printf("%d élève(s) sauvegardé(s)\n",nbeleves);
  }
  a_sauvegarder=0;
}
/* --------------------------------- */
/* --- chargement d'un fichier   --- */
/* --------------------------------- */
void chargement()
{
  struct etudiant eleve ;
  int i = 0, lectureOK;
  FILE *f1;
  char nomfichier[200], reponse[TAILLE_CH] ;

  verif_sauvegarde();
  
  printf("Nom du fichier à charger : ");
  scanf("%s",nomfichier);

  f1 = fopen(nomfichier,"r");

  while ( ! feof(f1)  )
  {
    lectureOK = fscanf(f1,"%s %s %d\n",eleve.nom, eleve.prenom, &eleve.age) ;
    if (lectureOK != EOF)
    {
     conv_maj_accents(eleve.nom,conserve_accents);
     conv_maj_accents(eleve.prenom,conserve_accents);
     tabeleves[i++] = eleve   ;
    }
  }
  fclose(f1);
  nbeleves = i ;
  printf("%d élève(s) lu(s)\n",nbeleves);
}
/* ---------------------------------------- */
/* --- suppression de tous les élèves   --- */
/* ---------------------------------------- */
void supprime_tous_les_eleves()
{
 nbeleves      = 0 ;
 a_sauvegarder = 1 ;
 printf("Tous les élèves ont été supprimés\n");
}
/* ------------------------------- */
/* --- recherche d'un élève    --- */
/* ------------------------------- */
int  recherche(char nomrech[])
{
  struct etudiant eleve;
  int i, numcase = NON_TROUVE ;

  for (i=0; i<nbeleves;i++)
  {
     eleve = tabeleves[i];

    if (strcmp(eleve.nom,nomrech) == 0)
    {
      numcase=i;
    }
  }
  return numcase ;
}
/* ------------------------------- */
/* --- modification d'un élève --- */
/* ------------------------------- */
void  modification()
{
    int numero ;
    char nom[TAILLE_CH];
    struct etudiant eleve ;

    if (nbeleves == 0)
        printf("Aucun élève actuellement pour la modification\n");
    else
    {
      printf("Entrez un nom de la personne à modifier : ");
      scanf("%s",nom);
      conv_maj_accents(nom,conserve_accents);
      numero = recherche(nom);
      if (numero == NON_TROUVE)
      {
         printf("Aucune modification : %s n'a pas été trouvé\n",nom);
      }
      else
      {
         eleve = tabeleves[numero];

         printf("nom actuel : %s --",eleve.nom);
         printf("Nouveau nom : ");
         scanf("%s",eleve.nom);
         conv_maj_accents(eleve.nom,conserve_accents);

         printf("prénom actuel : %s --",eleve.prenom);
         printf("Nouveau prénom : ");
         scanf("%s",eleve.prenom);
         conv_maj_accents(eleve.prenom,conserve_accents);

         printf("âge actuel : %d --",eleve.age);
         printf("Nouvel âge : ");
         scanf("%d",&eleve.age);

         tabeleves[numero] = eleve ;
         a_sauvegarder=1;
      }
    }
}
/* ------------------------------ */
/* --- suppression d'un élève --- */
/* ------------------------------ */
void  suppression()
{
    int numero, i ;
    char nom[TAILLE_CH];
    struct etudiant eleve ;

    if (nbeleves == 0)
        printf("Aucun élève actuellement pour la suppression\n");
    else
    {
      printf("Entrez le nom de la personne à supprimer : ");
      scanf("%s",nom);
      conv_maj_accents(nom,conserve_accents);
      numero = recherche(nom);
      if (numero == NON_TROUVE)
      {
         printf("Aucune suppression : %s n'a pas été trouvé\n",nom);
      }
      else
      {
        eleve = tabeleves[numero];
        printf("Elève %s %s %d supprimé !\n",eleve.nom, eleve.prenom, eleve.age);
        for (i=numero ; i<nbeleves ; i++)
        {
            tabeleves[i] = tabeleves[i+1];
        }
        nbeleves-- ;
        a_sauvegarder=1;
      }
    }
}
/* --------------------------- */
/* --- procédure quitter   --- */  
/* --------------------------- */
void quitter()
{
  verif_sauvegarde()     ;
  printf("Au revoir\n")  ;
}
/* ------------------------------------ */
/* --- vérification du lancement    --- */
/* --- automatique de la sauvegarde --- */
/* ------------------------------------ */
void verif_sauvegarde()
{
  char reponse[TAILLE_CH], Unelettre='\0';

  if (a_sauvegarder)
  {
    printf("Vos données sont modifiées. Voulez-vous faire une sauvegarde ? (o/n) : ");
    scanf("%s",reponse);
    Unelettre = toupper(reponse[0]);
    if (Unelettre == 'O')
    {
      sauvegarde();
    }
  }
}
/* ---------------------------- */
/* --- recherche d'un élève --- */
/* ---------------------------- */
void rechercher_eleve()
{
   char  nom[TAILLE_CH]      ;
   struct etudiant eleve        ;
   int numero = NON_TROUVE      ;
   
   if (nbeleves == 0)
     printf("Aucun élève actuellement pour la recherche\n");
   else
   {
     printf("Entrez un nom à rechercher : ");
     scanf("%s",nom);
     conv_maj_accents(nom,conserve_accents);
     numero = recherche(nom);
     if (numero == NON_TROUVE)
     {
       printf("%s n'a pas été trouvé\n",nom);
     }
     else
     {
        eleve = tabeleves[numero];
        printf("%s %s %d\n",eleve.nom, eleve.prenom, eleve.age);
     }
   }
}
/* -------------------------------------------- */
/* --- conversion en majuscules             --- */
/* --- avec conservation ou non des accents --- */
void conv_maj_accents(char ChaineOctets[], int conserve_accents_OK)
{
 /* déclarations */
 int i ;
 int TailleChaineOctets,TailleChaineWide ;
 int nbcarUnelettreWide, NbCaracteresConvertis ;
 int TailleUnCaractereWide ;
 char *UnelettreOctet      ;
 char ChaineOctetsMajuscules[TAILLE_CH] = {0} ;
 /* variables de caractères wide : 1 caractère est sur 4 octets */
 wchar_t ChaineWide[TAILLE_CH] ;
 wchar_t UnelettreWide[2] ; /* chaine d'un caractère wide */

 /* initialisation */
 ChaineWide[0]='\0';
 TailleUnCaractereWide = sizeof(wchar_t) ; // calcul de la taille du type wchar_t)
 /* création de la chaine de caractères multi-bytes : 1 caractères ASCII sur 1 octet
 Les caractères accentués UTF8 sur 2 à 4 octets */ 
 UnelettreOctet = (char *) malloc (TailleUnCaractereWide * TAILLE_CH);
 /* conversion de ChaineOctets (multi-byte) en chaine de caractères élargis (4 octets par caractères) */
 NbCaracteresConvertis = mbstowcs(ChaineWide,ChaineOctets, TAILLE_CH);
 TailleChaineOctets=strlen(ChaineOctets); 
 TailleChaineWide = wcslen(ChaineWide);

 UnelettreWide[1] = '\0';
 /* boucle de traitement de chaque caractère élargi (de type wide_t ) */
 for (i=0;i<TailleChaineWide;i++)
 {
   UnelettreWide[0] = towupper(ChaineWide[i]);
   nbcarUnelettreWide = wcstombs(UnelettreOctet,UnelettreWide,TailleUnCaractereWide);
   if (! conserve_accents_OK)
   {
     supprime_accents(UnelettreOctet) ;
   }
   strcat(ChaineOctetsMajuscules,UnelettreOctet);
 }
 strcpy(ChaineOctets,ChaineOctetsMajuscules);
}
/* ------------------------------- */
/* --- suppression des accents --- */
/* ------------------------------- */
void supprime_accents(char ChaineLettre[])
{
  /* ------------------------ */
  /* ---- les lettres A ----- */
  /* ------------------------ */
  /* traitement des accents du A */
  if ( (strcmp(ChaineLettre,"À")==0) || (strcmp(ChaineLettre,"Á")==0) || (strcmp(ChaineLettre,"Â")==0) || (strcmp(ChaineLettre,"Ã")==0) || (strcmp(ChaineLettre,"Ä")==0) || (strcmp(ChaineLettre,"Å")==0) )
  {
       strcpy(ChaineLettre,"A");
  }
  /* traitement des accents du a */
  else if ( (strcmp(ChaineLettre,"à")==0) || (strcmp(ChaineLettre,"á")==0) || (strcmp(ChaineLettre,"â")==0) || (strcmp(ChaineLettre,"ã")==0) || (strcmp(ChaineLettre,"ä")==0) || (strcmp(ChaineLettre,"å")==0) )
  {
       strcpy(ChaineLettre,"a");
  }
  /* traitement des autres accents du A */
  else if ( (strcmp(ChaineLettre,"Ā")==0) || (strcmp(ChaineLettre,"Ă")==0) || (strcmp(ChaineLettre,"Ą")==0) || (strcmp(ChaineLettre,"Ǎ")==0) || (strcmp(ChaineLettre,"Ǻ")==0))
  {
       strcpy(ChaineLettre,"A");
  }
  /* traitement des autres accents du a */
  else if ( (strcmp(ChaineLettre,"ā")==0) || (strcmp(ChaineLettre,"ă")==0) || (strcmp(ChaineLettre,"ą")==0) || (strcmp(ChaineLettre,"ǎ")==0) || (strcmp(ChaineLettre,"ǻ")==0))
  {
       strcpy(ChaineLettre,"a");
  }
  /* traitement des accents du AE */
  else if ( (strcmp(ChaineLettre,"Æ")==0) || (strcmp(ChaineLettre,"Ǽ")==0) )
  {
       strcpy(ChaineLettre,"AE");
  }
  /* traitement des accents du ae */
  else if ( (strcmp(ChaineLettre,"æ")==0) || (strcmp(ChaineLettre,"ǽ")==0) )
  {
       strcpy(ChaineLettre,"ae");
  }
  /* ------------------------ */
  /* ---- les lettres E ----- */
  /* ------------------------ */
  /* traitement des accents du E */
  else if ( (strcmp(ChaineLettre,"È")==0) || (strcmp(ChaineLettre,"É")==0) || (strcmp(ChaineLettre,"Ê")==0) || (strcmp(ChaineLettre,"Ë")==0) )
  {
       strcpy(ChaineLettre,"E");
  }
  else if ( (strcmp(ChaineLettre,"è")==0) || (strcmp(ChaineLettre,"é")==0) || (strcmp(ChaineLettre,"ê")==0) || (strcmp(ChaineLettre,"ë")==0) )
  {
       strcpy(ChaineLettre,"e");
  }
  /* traitement des autres accents du E */
  else if ( (strcmp(ChaineLettre,"Ē")==0) || (strcmp(ChaineLettre,"Ẽ")==0) || (strcmp(ChaineLettre,"Ė")==0) || (strcmp(ChaineLettre,"Ę")==0) || (strcmp(ChaineLettre,"Ě")==0) || (strcmp(ChaineLettre,"Ĕ")==0) )
  {
       strcpy(ChaineLettre,"E");
  }
  /* traitement des autres accents du e */
  else if ( (strcmp(ChaineLettre,"ē")==0) || (strcmp(ChaineLettre,"ẽ")==0) || (strcmp(ChaineLettre,"ė")==0) || (strcmp(ChaineLettre,"ę")==0) || (strcmp(ChaineLettre,"ě")==0) || (strcmp(ChaineLettre,"ĕ")==0) )
  {
       strcpy(ChaineLettre,"e");
  }
  /* ------------------------ */
  /* ---- les lettres I ----- */
  /* ------------------------ */
  /* traitement des accents du I */
  else if ( (strcmp(ChaineLettre,"Ì")==0) || (strcmp(ChaineLettre,"Í")==0) || (strcmp(ChaineLettre,"Î")==0) || (strcmp(ChaineLettre,"Ï")==0) )
  {
       strcpy(ChaineLettre,"I");
  }
  /* traitement des accents du i */
  else if ( (strcmp(ChaineLettre,"ì")==0) || (strcmp(ChaineLettre,"í")==0) || (strcmp(ChaineLettre,"î")==0) || (strcmp(ChaineLettre,"ï")==0) )
  {
       strcpy(ChaineLettre,"i");
  }
  /* traitement des autres accents du I */
  else if ( (strcmp(ChaineLettre,"Ĩ")==0) || (strcmp(ChaineLettre,"Ī")==0) || (strcmp(ChaineLettre,"Ĭ")==0) || (strcmp(ChaineLettre,"Į")==0) || (strcmp(ChaineLettre,"İ")==0) || (strcmp(ChaineLettre,"Ǐ")==0) )
  {
       strcpy(ChaineLettre,"I");
  }
  /* traitement des autres accents du i */
  else if ( (strcmp(ChaineLettre,"ĩ")==0) || (strcmp(ChaineLettre,"ī")==0) || (strcmp(ChaineLettre,"ĭ")==0) || (strcmp(ChaineLettre,"į")==0) || (strcmp(ChaineLettre,"ị")==0) || (strcmp(ChaineLettre,"ǐ")==0) || (strcmp(ChaineLettre,"ı")==0) )
  {
       strcpy(ChaineLettre,"i");
  }
  /* ------------------------ */
  /* ---- les lettres O ----- */
  /* ------------------------ */
  /* traitement des accents du O */
  else if ( (strcmp(ChaineLettre,"Ò")==0) || (strcmp(ChaineLettre,"Ó")==0) || (strcmp(ChaineLettre,"Ô")==0) || (strcmp(ChaineLettre,"Ö")==0) || (strcmp(ChaineLettre,"Õ")==0) || (strcmp(ChaineLettre,"Ø")==0) || (strcmp(ChaineLettre,"Ǿ")==0) || (strcmp(ChaineLettre,"Ǒ")==0) )
  {
       strcpy(ChaineLettre,"O");
  }
  /* traitement des accents du o */
  else if ( (strcmp(ChaineLettre,"ò")==0) || (strcmp(ChaineLettre,"ó")==0) || (strcmp(ChaineLettre,"ô")==0) || (strcmp(ChaineLettre,"ö")==0) || (strcmp(ChaineLettre,"õ")==0) || (strcmp(ChaineLettre,"ø")==0) || (strcmp(ChaineLettre,"ǿ")==0) || (strcmp(ChaineLettre,"ǒ")==0) )
  {
       strcpy(ChaineLettre,"o");
  }
  /* traitement des autres accents du O */
  else if ( (strcmp(ChaineLettre,"Ō")==0) || (strcmp(ChaineLettre,"Ŏ")==0) || (strcmp(ChaineLettre,"Ő")==0) || (strcmp(ChaineLettre,"Ơ")==0) )
  {
       strcpy(ChaineLettre,"O");
  }
  /* traitement des autres accents du o */
  else if ( (strcmp(ChaineLettre,"ō")==0) || (strcmp(ChaineLettre,"ŏ")==0) || (strcmp(ChaineLettre,"ő")==0) || (strcmp(ChaineLettre,"ơ")==0) )
  {
       strcpy(ChaineLettre,"o");
  }
  /* traitement des accents du OE */
  else if ( (strcmp(ChaineLettre,"Œ")==0) )
  {
       strcpy(ChaineLettre,"OE");
  }
  /* traitement des accents du oe */
  else if ( (strcmp(ChaineLettre,"œ")==0) )
  {
       strcpy(ChaineLettre,"oe");
  }
  /* ------------------------ */
  /* ---- les lettres U ----- */
  /* ------------------------ */
  /* traitement des accents du U */
  else if ( (strcmp(ChaineLettre,"Ù")==0) || (strcmp(ChaineLettre,"Ú")==0) || (strcmp(ChaineLettre,"Û")==0) || (strcmp(ChaineLettre,"Ü")==0) )
  {
       strcpy(ChaineLettre,"U");
  }
  /* traitement des accents du U */
  else if ( (strcmp(ChaineLettre,"ù")==0) || (strcmp(ChaineLettre,"ú")==0) || (strcmp(ChaineLettre,"û")==0) || (strcmp(ChaineLettre,"ü")==0) )
  {
       strcpy(ChaineLettre,"u");
  }
  /* traitement des autres accents du U */
  else if ( (strcmp(ChaineLettre,"Ũ")==0) || (strcmp(ChaineLettre,"Ū")==0) || (strcmp(ChaineLettre,"Ŭ")==0) || (strcmp(ChaineLettre,"Ů")==0) || (strcmp(ChaineLettre,"Ű")==0) || (strcmp(ChaineLettre,"Ų")==0) || (strcmp(ChaineLettre,"Ư")==0) )
  {
       strcpy(ChaineLettre,"U");
  }
  /* traitement des autres accents du U */
  else if ( (strcmp(ChaineLettre,"Ǔ")==0) || (strcmp(ChaineLettre,"Ǖ")==0) || (strcmp(ChaineLettre,"Ǘ")==0) || (strcmp(ChaineLettre,"Ǚ")==0) || (strcmp(ChaineLettre,"Ǜ")==0) )
  {
       strcpy(ChaineLettre,"U");
  }
  /* traitement des autres accents du u */
  else if ( (strcmp(ChaineLettre,"ũ")==0) || (strcmp(ChaineLettre,"ū")==0) || (strcmp(ChaineLettre,"ŭ")==0) || (strcmp(ChaineLettre,"ů")==0) || (strcmp(ChaineLettre,"ű")==0) || (strcmp(ChaineLettre,"ų")==0)  || (strcmp(ChaineLettre,"ư")==0))
  {
       strcpy(ChaineLettre,"u");
  }
  /* traitement des autres accents du u */
  else if ( (strcmp(ChaineLettre,"ǔ")==0) || (strcmp(ChaineLettre,"ǖ")==0) || (strcmp(ChaineLettre,"ǘ")==0) || (strcmp(ChaineLettre,"ǚ")==0) || (strcmp(ChaineLettre,"ǜ")==0) )
  {
       strcpy(ChaineLettre,"u");
  }
  /* ------------------------ */
  /* ---- les lettres Y ----- */
  /* ------------------------ */
  /* traitement des accents du Y */
  else if ( (strcmp(ChaineLettre,"Ý")==0) || (strcmp(ChaineLettre,"Ÿ")==0) )
  {
       strcpy(ChaineLettre,"Y");
  }
  /* traitement des accents du y */
  else if ( (strcmp(ChaineLettre,"ý")==0) || (strcmp(ChaineLettre,"ÿ")==0) )
  {
       strcpy(ChaineLettre,"y");
  }
  /* ------------------------ */
  /* ---- les lettres C ----- */
  /* ------------------------ */
  /* traitement des accents du Ç */
  else if ( (strcmp(ChaineLettre,"Ç")==0) || (strcmp(ChaineLettre,"Ć")==0) || (strcmp(ChaineLettre,"Ĉ")==0) || (strcmp(ChaineLettre,"Ċ")==0) || (strcmp(ChaineLettre,"Č")==0) )
  {
       strcpy(ChaineLettre,"C");
  }
  /* traitement des accents du c */
  else if ( (strcmp(ChaineLettre,"ç")==0) || (strcmp(ChaineLettre,"ć")==0) || (strcmp(ChaineLettre,"ĉ")==0) || (strcmp(ChaineLettre,"ċ")==0) || (strcmp(ChaineLettre,"č")==0) )
  {
       strcpy(ChaineLettre,"c");
  }
  /* ------------------------ */
  /* ---- les lettres D ----- */
  /* ------------------------ */
  /* traitement des accents du Ð */
  else if ( (strcmp(ChaineLettre,"Ð")==0) || (strcmp(ChaineLettre,"Ď")==0)   )
  {
       strcpy(ChaineLettre,"D");
  }
  else if ( (strcmp(ChaineLettre,"đ")==0) || (strcmp(ChaineLettre,"ď")==0)   )
  {
       strcpy(ChaineLettre,"d");
  }
  /* ------------------------ */
  /* ---- les lettres F ----- */
  /* ------------------------ */
  /* traitement des accents du ƒ */
  else if ( (strcmp(ChaineLettre,"ƒ")==0) )
  {
       strcpy(ChaineLettre,"f");
  }
  /* ------------------------ */
  /* ---- les lettres N ----- */
  /* ------------------------ */
  /* traitement des accents du N */
  else if ( (strcmp(ChaineLettre,"Ñ")==0) || (strcmp(ChaineLettre,"Ń")==0) || (strcmp(ChaineLettre,"Ņ")==0) || (strcmp(ChaineLettre,"Ň")==0) )
  {
       strcpy(ChaineLettre,"N");
  }
  /* traitement des accents du n */
  else if ( (strcmp(ChaineLettre,"ñ")==0) || (strcmp(ChaineLettre,"ń")==0) || (strcmp(ChaineLettre,"ņ")==0) || (strcmp(ChaineLettre,"ň")==0) || (strcmp(ChaineLettre,"ŉ")==0) )
  {
       strcpy(ChaineLettre,"n");
  }
  /* ------------------------ */
  /* ---- les lettres G ----- */
  /* ------------------------ */
  /* traitement des accents du G */
  else if ( (strcmp(ChaineLettre,"Ĝ")==0) || (strcmp(ChaineLettre,"Ğ")==0) || (strcmp(ChaineLettre,"Ġ")==0) || (strcmp(ChaineLettre,"Ģ")==0) )
  {
       strcpy(ChaineLettre,"G");
  }
  /* traitement des accents du g */
  else if ( (strcmp(ChaineLettre,"ĝ")==0) || (strcmp(ChaineLettre,"ğ")==0) || (strcmp(ChaineLettre,"ġ")==0) || (strcmp(ChaineLettre,"ģ")==0) )
  {
       strcpy(ChaineLettre,"g");
  }
  /* ------------------------ */
  /* ---- les lettres H ----- */
  /* ------------------------ */
  /* traitement des accents du H */
  else if ( (strcmp(ChaineLettre,"Ĥ")==0) || (strcmp(ChaineLettre,"Ħ")==0) )
  {
       strcpy(ChaineLettre,"H");
  }
  /* traitement des accents du h */
  else if ( (strcmp(ChaineLettre,"ĥ")==0) || (strcmp(ChaineLettre,"ħ")==0) )
  {
       strcpy(ChaineLettre,"h");
  }
  /* ------------------------ */
  /* ---- les lettres IJ ----- */
  /* ------------------------ */
  /* traitement des accents du IJ */
  else if ( (strcmp(ChaineLettre,"Ĳ")==0) )
  {
       strcpy(ChaineLettre,"IJ");
  }
  /* traitement des accents du ij */
  else if ( (strcmp(ChaineLettre,"ĳ")==0) )
  {
       strcpy(ChaineLettre,"ij");
  }
  /* ------------------------ */
  /* ---- les lettres J ----- */
  /* ------------------------ */
  /* traitement des accents du J */
  else if ( (strcmp(ChaineLettre,"Ĵ")==0) )
  {
       strcpy(ChaineLettre,"J");
  }
  /* traitement des accents du j */
  else if ( (strcmp(ChaineLettre,"ĵ")==0) )
  {
       strcpy(ChaineLettre,"j");
  }
  /* ------------------------ */
  /* ---- les lettres K ----- */
  /* ------------------------ */
  /* traitement des accents du K */
  else if ( (strcmp(ChaineLettre,"Ķ")==0) )
  {
       strcpy(ChaineLettre,"K");
  }
  /* traitement des accents du k */
  else if ( (strcmp(ChaineLettre,"ķ")==0) )
  {
       strcpy(ChaineLettre,"k");
  }
  /* ------------------------ */
  /* ---- les lettres L ----- */
  /* ------------------------ */
  /* traitement des accents du L */
  else if ( (strcmp(ChaineLettre,"Ĺ")==0) || (strcmp(ChaineLettre,"Ļ")==0) || (strcmp(ChaineLettre,"Ľ")==0) || (strcmp(ChaineLettre,"Ŀ")==0)|| (strcmp(ChaineLettre,"Ł")==0)  )
  {
       strcpy(ChaineLettre,"L");
  }
  /* traitement des accents du l */
  else if ( (strcmp(ChaineLettre,"ĺ")==0) || (strcmp(ChaineLettre,"ļ")==0) || (strcmp(ChaineLettre,"ľ")==0) || (strcmp(ChaineLettre,"ŀ")==0)|| (strcmp(ChaineLettre,"ł")==0)  )
  {
       strcpy(ChaineLettre,"l");
  }
  /* ------------------------ */
  /* ---- les lettres R ----- */
  /* ------------------------ */
  /* traitement des accents du R */
  else if ( (strcmp(ChaineLettre,"Ŕ")==0) || (strcmp(ChaineLettre,"Ŗ")==0) || (strcmp(ChaineLettre,"Ř")==0) )
  {
       strcpy(ChaineLettre,"R");
  }
  /* traitement des accents du r */
  else if ( (strcmp(ChaineLettre,"ŕ")==0) || (strcmp(ChaineLettre,"ŗ")==0) || (strcmp(ChaineLettre,"ř")==0) )
  {
       strcpy(ChaineLettre,"r");
  }
  /* ------------------------ */
  /* ---- les lettres S ----- */
  /* ------------------------ */
  /* traitement des accents du S */
  else if ( (strcmp(ChaineLettre,"Ś")==0) || (strcmp(ChaineLettre,"Ŝ")==0) || (strcmp(ChaineLettre,"Ş")==0) || (strcmp(ChaineLettre,"Š")==0))
  {
       strcpy(ChaineLettre,"S");
  }
  /* traitement des accents du s */
  else if ( (strcmp(ChaineLettre,"ś")==0) || (strcmp(ChaineLettre,"ŝ")==0) || (strcmp(ChaineLettre,"ş")==0) || (strcmp(ChaineLettre,"š")==0))
  {
       strcpy(ChaineLettre,"s");
  }
  /* traitement des accents du ß */
  else if ( (strcmp(ChaineLettre,"ß")==0) )
  {
       strcpy(ChaineLettre,"S");
  }
  /* traitement des accents du ſ */
  else if ( (strcmp(ChaineLettre,"ſ")==0) )
  {
       strcpy(ChaineLettre,"s");
  }
  /* ------------------------ */
  /* ---- les lettres T ----- */
  /* ------------------------ */
  /* traitement des accents du T */
  else if ( (strcmp(ChaineLettre,"Ţ")==0) || (strcmp(ChaineLettre,"Ť")==0) || (strcmp(ChaineLettre,"Ŧ")==0) )
  {
       strcpy(ChaineLettre,"T");
  }
  /* traitement des accents du t */
  else if ( (strcmp(ChaineLettre,"ţ")==0) || (strcmp(ChaineLettre,"ť")==0) || (strcmp(ChaineLettre,"ŧ")==0) )
  {
       strcpy(ChaineLettre,"t");
  }
  /* ------------------------ */
  /* ---- les lettres W ----- */
  /* ------------------------ */
  /* traitement des accents du W */
  else if ( (strcmp(ChaineLettre,"Ŵ")==0) )
  {
       strcpy(ChaineLettre,"W");
  }
  /* traitement des accents du w */
  else if ( (strcmp(ChaineLettre,"ŵ")==0) )
  {
       strcpy(ChaineLettre,"w");
  }
  /* ------------------------ */
  /* ---- les lettres Y ----- */
  /* ------------------------ */
  /* traitement des accents du Y */
  else if ( (strcmp(ChaineLettre,"Ŷ")==0) || (strcmp(ChaineLettre,"Ÿ")==0) )
  {
       strcpy(ChaineLettre,"Y");
  }
  /* traitement des accents du y */
  else if ( (strcmp(ChaineLettre,"ŷ")==0) || (strcmp(ChaineLettre,"ÿ")==0) )
  {
       strcpy(ChaineLettre,"y");
  }
  /* ------------------------ */
  /* ---- les lettres Z ----- */
  /* ------------------------ */
  /* traitement des accents du Z */
  else if ( (strcmp(ChaineLettre,"Ź")==0) || (strcmp(ChaineLettre,"Ż")==0) || (strcmp(ChaineLettre,"Ž")==0) )
  {
       strcpy(ChaineLettre,"Z");
  }
  /* traitement des accents du z */
  else if ( (strcmp(ChaineLettre,"ź")==0) || (strcmp(ChaineLettre,"ż")==0) || (strcmp(ChaineLettre,"ž")==0) )
  {
       strcpy(ChaineLettre,"z");
  }
}
