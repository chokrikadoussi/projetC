#include <stdio.h>
#include <string.h>
#include <curses.h>

#define TAILLE_NOM 10
#define TAILLE_PRENOM 15
#define MAX_ETUDIANTS 100
#define ELEVE_NON_TROUVE -1

#define min(a,b) ((a) < (b) ? (a) : (b))
 
 /* --- definition des types globaux --- */
struct etudiant {
                  char nom[TAILLE_NOM]       ;
                  char prenom[TAILLE_PRENOM] ;
                  int age                    ;
                } ;
/* --- definition des variables globales --- */
int  nbeleves=0 ;
struct etudiant tab_eleves[MAX_ETUDIANTS];

 
/* --- parametre et variables affichage video --- */

 int Nb_Lignes=24,Nb_Colonnes=80,Origine_X=0,Origine_Y=0;

 int Lig_Debut,Col_Debut ;
 int Lig_Fin,Col_Fin     ;

 int Lig_Titre       ;
 int Lig_Deb_Affichage ;
 int Lig_Fin_Affichage ;
 int Lig_Message     ;
 int Lig_Erreur      ;
 
 int Col_Titre     ;
 int Col_Selection ;
 int Col_Message   ;
 int Col_Erreur    ;


/* --- definition preliminaire des procedures video --- */
void V_Activation_Video();
void V_Desactivation_Video();

WINDOW *V_Creation_Cadre_Menu(char Titre[]) ;
void V_Destruction_Cadre_Menu(WINDOW *Fenetre_Menu);

void V_Press_Key(WINDOW *Fenetre_Menu);

int V_Fonction_Menu(char Titre[],char *Tableau_Menu[],int Nb_Choix);

void V_ajout_eleves();
int V_saisie_eleve(WINDOW *Menu_Saisie_Eleve,struct etudiant *eleve);

void V_ouvrir_fichier() ;
void V_sauvegarder_fichier() ;


void V_affichage();
void V_affichage_liste_eleve(WINDOW *Menu_Affichage);

void V_Recherche();
 
 
/* --- definition preliminaire des procedures --- */
int  recherche_eleve(char nom_recherche[]);
 
int main()
{ 
  int Nb_Choix_Menu=6 ;
  static char *Tab_Menu[10]={
                     "Ouvrir fichier                     ",
                     "Sauvegarder dans fichier           ",
                     "Ajout d'une liste d'etudiants      ",
                     "Recherche un etudiant              ",
                     "Affichage de la liste des etudiants",
                     "QUITTER                            "
                   };
  char Titre_Menu[]="- Menu Principal -";
  int selection = -1 ;

  V_Activation_Video();
  
  
  while (selection != Nb_Choix_Menu-1 )
  {
     
     selection=V_Fonction_Menu(Titre_Menu,Tab_Menu,Nb_Choix_Menu);

     switch (selection)
     {
       /* --- Appel procedure chargement du fichier --- */
       case 0 : V_ouvrir_fichier();
                break ;
       /* --- Appel procedure sauvegarde du tableau --- */
       case 1 : V_sauvegarder_fichier();
                break ;
  
       case 2 : V_ajout_eleves();
                break ;
  
       /* --- Appel procedure saisie --- */
       case 3 : V_Recherche() ;
                break ;
  
       /* --- Appel procedure d'affichage --- */
       case 4 : V_affichage();
                break ;
                
       case 5 : printf("Au revoir \n");
                break ;
       default: printf("Erreur de saisie\n");
                break;                   
     }
  }
  
  V_Desactivation_Video();
}



/* ---------------------------------- */
/* Initialisation des variables video */
/* ---------------------------------- */
void V_Activation_Video()
{
 /* initialisation du systeme video */
 initscr();
 
 
 Nb_Lignes  = 24;
 Nb_Colonnes= 80;
 Origine_X  = 0 ;
 Origine_Y  = 0 ;

 Lig_Debut = 1               ;
 Col_Debut = (Nb_Colonnes/3) ;
 Lig_Fin   = Nb_Lignes-1     ;
 Col_Fin   = Nb_Colonnes-1   ;

 Lig_Titre     = Lig_Debut       ;
 Lig_Message   = Lig_Fin-1       ;
 Lig_Erreur    = Lig_Fin-2       ;
 
 Lig_Deb_Affichage = Lig_Debut+2 ;
 Lig_Fin_Affichage = Lig_Fin-3   ;
 
 Col_Titre     = Col_Debut     ;
 Col_Selection = Col_Debut/2   ;
 Col_Message   = Col_Debut/2   ;
 Col_Erreur    = Col_Debut/2   ;

 /* refresh(); */
}

/* ---------------------------------- */
/* Desactivation des variables video  */
/* ---------------------------------- */

void V_Desactivation_Video()
{
 endwin();
}



/* ----------------------------------- */
/* --- Creation du Cadre d'un Menu --- */
/* ----------------------------------- */
WINDOW *V_Creation_Cadre_Menu(char Titre[])
{

 WINDOW *Fenetre_Menu;


 /* effacement de l'ecran */
 erase();
 refresh();

 /* creation d'un fenetre avec bordure, et affichage */
 Fenetre_Menu = newwin(Nb_Lignes,Nb_Colonnes,Origine_Y,Origine_X);

 box(Fenetre_Menu,0,0);
   
 wclear(Fenetre_Menu);
  

 /* Affichage du Titre du Menu */

 wattron(Fenetre_Menu, A_BOLD); 
 mvwprintw(Fenetre_Menu,Lig_Titre,Col_Titre,Titre);
 wattroff(Fenetre_Menu, A_BOLD);
 
 box(Fenetre_Menu,0,0);
 wrefresh(Fenetre_Menu);
 
 return Fenetre_Menu ;
}


  
/* -------------------------------------- */
/* --- Destruction du Cadre d'un Menu --- */
/* -------------------------------------- */
void V_Destruction_Cadre_Menu(WINDOW *Fenetre_Menu)
{
 
 delwin(Fenetre_Menu);
 erase();
 refresh();

}



/* ------------------------------------- */
/* --- Frappe d'une touche d'un Menu --- */
/* ------------------------------------- */
void V_Press_Key(WINDOW *Fenetre_Menu)
{

  char bidon ;


 /* deplacement du curseur */
  mvwprintw(Fenetre_Menu,Lig_Message,Col_Message,"Appuyez sur ENTREE pour continuer ...");
 
  bidon=mvwgetch(Fenetre_Menu,Lig_Message, Col_Message);
}
 
 


/* ------------------------------------------------------------------ */
/* --- Fenetre d'affichage d'un menu et de retour de la selection --- */
/* ------------------------------------------------------------------ */
int V_Fonction_Menu(char Titre[],char *Tableau_Menu[],int Nb_Choix)
{
 
 char choix ;
 char nom[20],prenom[40] ;
 int age ;
 int i ;
 
 int Touche;
 char Nom_Touche[20]  ;
 int Validation_OK    ;
 int Indice_Choix = 0 ;
 
 WINDOW *Menu_Principal    ;
 
 
 Menu_Principal = V_Creation_Cadre_Menu(Titre);
 
 /* --- activation des fleches interpretees --- */
 keypad(Menu_Principal, TRUE);
 


/* Boucle d'affichage du Menu */

 for (i=0; i<Nb_Choix ; i++)
 {
   mvwprintw(Menu_Principal,Lig_Deb_Affichage+i,Col_Selection,Tableau_Menu[i]); 
 }

  
/* attributs video possible : 

 A_STANDOUT    Terminal's best highlighting mode.
 A_UNDERLINE   Underline.
 A_REVERSE     Reverse video.
 A_BLINK       Blinking.
 A_DIM         Half-bright.
 A_BOLD        Extra bright or bold.
 A_ALTCHARSET  Alternate character set.
 A_NORMAL      Normal attributes.Turns all video attributes off
 COLOR_PAIR (Number) 
                         Displays the color pair represented by Number. You must
                         have already
                         initialized the
                         color pair using the init_pair subroutine.
*/ 

 
 /* --- selection d'un choix du Menu --- */
 strcpy(Nom_Touche,"");
 Validation_OK=(strcmp(Nom_Touche,"^J")==0);

 Indice_Choix=0;

 while (! Validation_OK)
 {
  mvwprintw(Menu_Principal,Lig_Message,Col_Message,"Selection avec les fleches");

  /* on affiche la ligne selectionnee en inverse video */
  wattron(Menu_Principal, A_REVERSE);
  mvwprintw(Menu_Principal,Lig_Deb_Affichage+Indice_Choix,Col_Selection,Tableau_Menu[Indice_Choix]);
  wattroff(Menu_Principal, A_REVERSE);
 
  /* Les noms de touches sont :
  KEY_UP    fleche vers le haut
  KEY_DOWN  fleche vers le bas
  KEY_LEFT  fleche vers la gauche
  KEY_RIGHT fleche vers la droite
  ^J        Entree
  KEY_DC    Destruction caractere (DEL)
  KEY_IC    Insertion caractere   (INSERT)
  KEY_HOME  HOME
  KEY_END   FIN

  KEY_PPAGE Page precedente (Previous Page)
  KEY_NPAGE Page suivante   (Next Page)
  */

  /* on lit la touche (fleche) tapee */ 
  Touche=wgetch(Menu_Principal);
 
  /* --- on redessine la ligne et la boite --- */
 
  /* on efface la ligne de message */
  wmove(Menu_Principal,Lig_Message,Col_Message);
  wclrtoeol(Menu_Principal);
 
  /* on efface la ligne selectionne */
  wmove(Menu_Principal,Lig_Deb_Affichage+Indice_Choix,Col_Selection);
  wclrtoeol(Menu_Principal);
 
  /* on redessine la boite */
  box(Menu_Principal,0,0);
 
  /* on affiche (sans inverse video) la ligne selectionnee */
  mvwprintw(Menu_Principal,Lig_Deb_Affichage+Indice_Choix,Col_Selection,Tableau_Menu[Indice_Choix]);
  wrefresh(Menu_Principal);
 
 
  /* on recupere le nom de la touche frappe */
  strcpy(Nom_Touche,keyname(Touche));
 
  if (strcmp(Nom_Touche,"KEY_DOWN")==0)
  {
   if (Indice_Choix < Nb_Choix-1)
      Indice_Choix++ ;
  } 
  else if (strcmp(Nom_Touche,"KEY_UP")==0)
  {
   if (Indice_Choix > 0)
      Indice_Choix-- ;
  }
  else if ((strcmp(Nom_Touche,"KEY_PPAGE")==0)||(strcmp(Nom_Touche,"KEY_HOME")==0))
  {
   Indice_Choix = 0 ;
  }
  else if ((strcmp(Nom_Touche,"KEY_NPAGE")==0)||(strcmp(Nom_Touche,"KEY_END")==0))
  {
   Indice_Choix = Nb_Choix-1 ;
  }
  else if (strcmp(Nom_Touche,"^J")==0)
  {
   wmove(Menu_Principal,Lig_Message,Col_Message);
   wclrtoeol(Menu_Principal);
  }
  else
  {
   wmove(Menu_Principal,Lig_Message,Col_Message);
   wclrtoeol(Menu_Principal);
   mvwprintw(Menu_Principal,Lig_Message,Col_Message,"Frappe Incorrecte");
  }


  /* echo de la frappe */
  /*
  wmove(Menu_Principal,Lig_Message-1,Col_Message);
  wclrtoeol(Menu_Principal);
  mvwprintw(Menu_Principal,Lig_Message-1,Col_Message,"Touche = |%s| choix=%d",Nom_Touche,Indice_Choix);
  */

  Validation_OK=(strcmp(Nom_Touche,"^J")==0);
 }

 /* desactivation des fleches */
 keypad(Menu_Principal, FALSE);

 /* reactualise la fenetre */
 wrefresh(Menu_Principal);

 /* destruction de la Fentre_Menu_Principal */
 V_Destruction_Cadre_Menu(Menu_Principal);

 return Indice_Choix ;
}



/* ------------------------------------------------- */
/* --- fonction Video de chargement d'un fichier --- */
/* ------------------------------------------------- */
void V_ouvrir_fichier()
{
  char NomFichier[50]     ;
  FILE *entree            ;
  struct etudiant studtmp ;
  int erreur ,i=0         ;
  
  char Titre_Ouvrir_Fichier[]="--- Chargement d'un Fichier ---";

  WINDOW *Menu_Ouvrir_Fichier ;

 
  Menu_Ouvrir_Fichier = V_Creation_Cadre_Menu(Titre_Ouvrir_Fichier);
  

  /* affichage et saisie du Nom du Fichier */
  wattron(Menu_Ouvrir_Fichier, A_UNDERLINE);
  mvwprintw(Menu_Ouvrir_Fichier,Lig_Deb_Affichage,Col_Selection,"Nom du Fichier:");
  wattroff(Menu_Ouvrir_Fichier, A_UNDERLINE);

  mvwscanw(Menu_Ouvrir_Fichier,Lig_Deb_Affichage,Col_Selection+17,"%s",NomFichier);
   
  
  entree=fopen(NomFichier,"r");
 
  if (entree == NULL)
  {
    mvwprintw(Menu_Ouvrir_Fichier,Lig_Erreur,Col_Erreur,"Pb acces fichier %s",NomFichier);
  }
  else
  {
    while ( (! feof(entree)) && (nbeleves < MAX_ETUDIANTS) )
    {
      erreur=fscanf(entree,"%s %s %d",studtmp.nom,studtmp.prenom,&studtmp.age);
      if (erreur != EOF)
      {
        tab_eleves[nbeleves++]=studtmp ;
      }
    }
    if (! (nbeleves < MAX_ETUDIANTS) )
    {
      mvwprintw(Menu_Ouvrir_Fichier,Lig_Erreur,Col_Erreur,"Fichier trop gros, Nb Max d'eleves=%d",MAX_ETUDIANTS);
    }
  }
  
  fclose(entree);

  
 V_affichage_liste_eleve(Menu_Ouvrir_Fichier);
  
 wrefresh(Menu_Ouvrir_Fichier);

 V_Destruction_Cadre_Menu(Menu_Ouvrir_Fichier);

}

/* ------------------------------------------------- */
/* --- fonction Video de sauvegarde d'un fichier --- */
/* ------------------------------------------------- */
void V_sauvegarder_fichier()
{
  char NomFichier[50]     ;
  FILE *sortie            ;
  struct etudiant studtmp ;
  int i                   ;
  char Titre_Sauve_Fichier[]="--- Sauvegarde d'un Fichier ---";

  WINDOW *Menu_Sauve_Fichier ;

 
  Menu_Sauve_Fichier = V_Creation_Cadre_Menu(Titre_Sauve_Fichier);
  

  /* affichage et saisie du Nom du Fichier */
  wattron(Menu_Sauve_Fichier, A_UNDERLINE);
  mvwprintw(Menu_Sauve_Fichier,Lig_Deb_Affichage,Col_Selection,"Nom du Fichier:");
  wattroff(Menu_Sauve_Fichier, A_UNDERLINE);

  mvwscanw(Menu_Sauve_Fichier,Lig_Deb_Affichage,Col_Selection+17,"%s",NomFichier);
  
  sortie=fopen(NomFichier,"w");
 
  if (sortie == NULL)
  {
    mvwprintw(Menu_Sauve_Fichier,Lig_Erreur,Col_Erreur,"Pb acces fichier %s",NomFichier);
  }
  else
  {
    for (i=0 ; i<nbeleves ; i++)
    {
      studtmp=tab_eleves[i] ;
      fprintf(sortie,"%s %s %d\n",studtmp.nom,studtmp.prenom,studtmp.age);
    }
    mvwprintw(Menu_Sauve_Fichier,Lig_Deb_Affichage+2,Col_Selection,"Nb enregistrements ecrits : %d",nbeleves);
  }
  
  fclose(sortie);
  
  mvwprintw(Menu_Sauve_Fichier,Lig_Message,Col_Message,"Nb eleves sauvegardes: %d",nbeleves);

  V_Press_Key(Menu_Sauve_Fichier) ;
  
  wrefresh(Menu_Sauve_Fichier);

  V_Destruction_Cadre_Menu(Menu_Sauve_Fichier);
}



/* ---------------------------------------- */
/* --- saisie video d'une liste d'eleve --- */
/* ---------------------------------------- */
void V_ajout_eleves()
{
  struct etudiant studtmp ;
  int termine ;
  char Titre_Saisie[]="--- Ajout d'une liste d'eleves ---";

  WINDOW *Menu_Saisie_Eleve ;

  
  Menu_Saisie_Eleve = V_Creation_Cadre_Menu(Titre_Saisie);

  termine = 0 ;
   
  while ((! termine) && (nbeleves < MAX_ETUDIANTS) )
  {
   termine=V_saisie_eleve(Menu_Saisie_Eleve,&studtmp);

   if (! termine)
   {      
     tab_eleves[nbeleves]=studtmp ;
     nbeleves++ ;
   }   
  }
  if (! (nbeleves < MAX_ETUDIANTS) )
  {
      printf("Nb Maximum d'eleves = %d Atteint !\n",MAX_ETUDIANTS);
  }

  printf("Nombre d'eleves=%d\n",nbeleves);

  
 wrefresh(Menu_Saisie_Eleve);
   
 V_Destruction_Cadre_Menu(Menu_Saisie_Eleve);
  

}

/* ------------------------------- */
/* --- saisie video d'un eleve --- */
/* ------------------------------- */
int V_saisie_eleve(WINDOW *Menu_Saisie_Eleve,struct etudiant *eleve)
{
 struct etudiant studtmp={"","",0} ;
 int retour, termine=-1 ;
 
 /* affichage et saisie du Nom */
 wattron(Menu_Saisie_Eleve, A_UNDERLINE);
 mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage,Col_Selection,"Nom:");
 wattroff(Menu_Saisie_Eleve, A_UNDERLINE);

 mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage,Col_Selection+25,"(ENTREE pour terminer)");

 mvwscanw(Menu_Saisie_Eleve,Lig_Deb_Affichage,Col_Selection+8,"%s",studtmp.nom);

 /* on teste si la personne a tape ENTREE sans rien saisir */
 termine=((strcmp(studtmp.nom,""))==0) ;


 if (! termine)
 {
   /* affichage et saisie du Prenom */
   wattron(Menu_Saisie_Eleve, A_UNDERLINE);
   mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage+1,Col_Selection,"Prenom:");
   wattroff(Menu_Saisie_Eleve, A_UNDERLINE);
   
   mvwscanw(Menu_Saisie_Eleve,Lig_Deb_Affichage+1,Col_Selection+8,"%s",studtmp.prenom);

   /* affichage et saisie de l'age */
   wattron(Menu_Saisie_Eleve, A_UNDERLINE); 
   mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage+2,Col_Selection,"Age:");
   wattroff(Menu_Saisie_Eleve, A_UNDERLINE); 
   
   mvwscanw(Menu_Saisie_Eleve,Lig_Deb_Affichage+2,Col_Selection+8,"%d",&studtmp.age);
 
 }
 
 retour=termine ;
 *eleve=studtmp ;
 
 mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage,Col_Selection,"              ");
 mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage+1,Col_Selection,"              ");
 mvwprintw(Menu_Saisie_Eleve,Lig_Deb_Affichage+2,Col_Selection,"              ");
 
 wrefresh(Menu_Saisie_Eleve);

 return retour ;

}

/* ---------------------------------------- */
/* --- fonction de recherche d'un eleve --- */
/* ---------------------------------------- */
int recherche_eleve(char nom_recherche[])
{
  struct etudiant studtmp   ;
  int trouve, i , num_case_retour=ELEVE_NON_TROUVE;

  trouve = 0 ;
  i = 0 ;
   
  while ((! trouve) && (i < nbeleves)  )
  { 
   studtmp=tab_eleves[i++] ;
   trouve=((strcmp(studtmp.nom,nom_recherche))==0) ;

   if (trouve)
   {   
     num_case_retour=i-1 ;
   }   
  }
  return num_case_retour ;
}


/* ------------------------------------------------- */
/* --- fonction Video de recherche d'un eleve    --- */
/* ------------------------------------------------- */
void V_Recherche()
{
  char nom_eleve[TAILLE_NOM] ;
  int numero_case =-1;

  struct etudiant eleve ;
  
  int erreur ,i=0         ;
  
  char Titre_Recherche[]="--- Recherche d'un eleve ---";

  WINDOW *Menu_Recherche ;

 
  Menu_Recherche = V_Creation_Cadre_Menu(Titre_Recherche);
  

  /* affichage et saisie du Nom du Fichier */
  wattron(Menu_Recherche, A_UNDERLINE);
  mvwprintw(Menu_Recherche,Lig_Deb_Affichage,Col_Selection,"Nom de l'eleve:");
  wattroff(Menu_Recherche, A_UNDERLINE);

  mvwscanw(Menu_Recherche,Lig_Deb_Affichage,Col_Selection+17,"%s",nom_eleve);

  numero_case=recherche_eleve(nom_eleve);
  if (numero_case == ELEVE_NON_TROUVE)
  {
    mvwprintw(Menu_Recherche,Lig_Erreur,Col_Erreur,"Aucun %s n'a ete trouve",nom_eleve);
  }
  else
  {
    eleve=tab_eleves[numero_case] ;
    
    /* affichage du Nom */
    wattron(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+2,Col_Selection,"Nom:");
    wattroff(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+2,Col_Selection+10,"%s",eleve.nom);

    /* affichage du Prenom */
    wattron(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+3,Col_Selection,"Prenom:");
    wattroff(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+3,Col_Selection+10,"%s",eleve.prenom);
   
    /* affichage de l'age */
    wattron(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+4,Col_Selection,"Age:");
    wattroff(Menu_Recherche, A_UNDERLINE);
    mvwprintw(Menu_Recherche,Lig_Deb_Affichage+4,Col_Selection+10,"%d",eleve.age);
    
  }
  
 V_Press_Key(Menu_Recherche);
 
 wrefresh(Menu_Recherche);

 V_Destruction_Cadre_Menu(Menu_Recherche);

}


/* --------------------------------------------------------- */
/* --- procedure d'affichage video des eleves            --- */
/* --------------------------------------------------------- */
void V_affichage()
{
 char Titre_Affichage[]="--- Affichage de la liste des eleves ---";
 WINDOW *Menu_Affichage ;

 
 Menu_Affichage = V_Creation_Cadre_Menu(Titre_Affichage);
 wrefresh(Menu_Affichage);


 V_affichage_liste_eleve(Menu_Affichage);

   
 V_Destruction_Cadre_Menu(Menu_Affichage);   

}

/* --------------------------------------------------------- */
/* --- procedure d'affichage video d'un liste d'eleves   --- */
/* --------------------------------------------------------- */

void V_affichage_liste_eleve(WINDOW *Menu_Affichage)
{
 int i=0,j=0;
 struct etudiant studtmp ;
 int Prem_eleve=0, Dern_eleve=Lig_Fin_Affichage-2 ;
 int nb_lignes_dessus, nb_lignes_dessous ;
 int Touche           ;
 char Nom_Touche[20]  ;
 int Validation_OK    ;


 mvwprintw(Menu_Affichage,Lig_Message,Col_Message,"Defilement=Fleches ou ENTREE=Terminer");

   
 /* --- activation des fleches interpretees --- */
 keypad(Menu_Affichage, TRUE);
 
 /* --- selection d'un choix du Menu --- */
 strcpy(Nom_Touche,"");
 Validation_OK=(strcmp(Nom_Touche,"^J")==0);


 while (! Validation_OK)
 {
   j=0 ;
   
   if (Prem_eleve >= nbeleves)
      Prem_eleve = nbeleves-1    ;
      
   if (Dern_eleve >= nbeleves)
      Dern_eleve = nbeleves-1    ;
   

   /* Boucle d'affichage de la liste */
   for (i=Prem_eleve ; i<=Dern_eleve ; i++)
   { 
     studtmp = tab_eleves[i] ;
     mvwprintw(Menu_Affichage,Lig_Deb_Affichage+j,Col_Selection,"%-4d :  %-10s %-15s %-3d",i+1,studtmp.nom,studtmp.prenom,studtmp.age);     
     j++ ;
   } 
   
   wmove(Menu_Affichage,Lig_Message,Col_Message);   

  /* on lit la touche (fleche) tapee */ 
  Touche=wgetch(Menu_Affichage);
  
  /* on recupere le nom de la touche frappe */
  strcpy(Nom_Touche,keyname(Touche));
 
  if (strcmp(Nom_Touche,"KEY_DOWN")==0)
  {
   if (Dern_eleve < nbeleves-1)
   {
     Prem_eleve++ ;
     Dern_eleve++ ;
   }
  } 
  else if (strcmp(Nom_Touche,"KEY_UP")==0)
  {
   if (Prem_eleve > 0)
   {
     Prem_eleve--;
     Dern_eleve--;
   }
  }
  else if (strcmp(Nom_Touche,"KEY_PPAGE")==0)
  {
    nb_lignes_dessus=min(Lig_Fin_Affichage-2,Prem_eleve);
    Prem_eleve=Prem_eleve - nb_lignes_dessus ;
    Dern_eleve=Dern_eleve - nb_lignes_dessus ;
  }
  else if (strcmp(Nom_Touche,"KEY_NPAGE")==0)
  {
    nb_lignes_dessous=min(Lig_Fin_Affichage-2,nbeleves-Dern_eleve-1);
    Prem_eleve=Prem_eleve + nb_lignes_dessous ;
    Dern_eleve=Dern_eleve + nb_lignes_dessous ;
  }
  else if (strcmp(Nom_Touche,"KEY_END")==0)
  {
     Prem_eleve = nbeleves-(Lig_Fin_Affichage-2)-1 ;
     Dern_eleve = nbeleves-1 ;
     if (Prem_eleve < 0)
     {
       Prem_eleve = 0 ;
     }
  }  
  else if (strcmp(Nom_Touche,"KEY_HOME")==0)
  {
     Prem_eleve = 0 ;
     Dern_eleve=Lig_Fin_Affichage-2 ;
     if (Dern_eleve >= nbeleves)
     {
       Dern_eleve = nbeleves-1 ;
     }
  }
  else if (strcmp(Nom_Touche,"^J")==0)
  {
   wmove(Menu_Affichage,Lig_Message,Col_Message);
   wclrtoeol(Menu_Affichage);
  }
  else
  {
   wmove(Menu_Affichage,Lig_Message,Col_Message);
   wclrtoeol(Menu_Affichage);
   mvwprintw(Menu_Affichage,Lig_Message,Col_Message,"Frappe Incorrecte");
  }


  /* echo de la frappe */
  /*wmove(Menu_Affichage,Lig_Message,Col_Message);
  wclrtoeol(Menu_Affichage);
  mvwprintw(Menu_Affichage,Lig_Message,Col_Message,"Touche=|%s| Prem %d Dern %d",Nom_Touche,Prem_eleve,Dern_eleve);
  */

  Validation_OK=(strcmp(Nom_Touche,"^J")==0);
 }

 /* desactivation des fleches */
 keypad(Menu_Affichage, FALSE);

    
 wrefresh(Menu_Affichage);

}



 
  

