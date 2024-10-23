#include <ncurses.h>
#include <stdlib.h> // pour la fonction free()
#include <string.h>
#include <ctype.h>
#include <unistd.h> // Pour sleep
#include <errno.h>
/// include pour stat()
#include <sys/stat.h> 
#include <sys/types.h>
// include pour opendir()
#include <dirent.h> 
// include pour l'heure et la langue
#include <locale.h>
#include <time.h>
// include pour groupe et login
#include <pwd.h>
#include <grp.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/* ============================================= */
/* === Déclaration des constantes            === */
/* ============================================= */
/* === pour les fenêtres                     === */
#define AUCUNE 0    // Aucune touche
#define ENTER 10    // Touche ENTREE correspondant au code du caractère Line Feed (LF) correspondant à fin de ligne
#define ESCAPE 27   // Le caractère Escape a le code ASCI 27 en décimale ou 033 en octal 
#define REDIM 410   // 410 est le code de la touche générée lorsqu'on redimensionne le terminal
#define LARGEUR_COL_MENU 21
#define LARGEUR_ECRAN COLS
#define HAUTEUR_ECRAN LINES-2
/* --- la barre des menus ---*/
#define NB_LIGNES_MENU 1
#define NB_COLONNES_MENU LARGEUR_ECRAN
#define LIGNE_DEBUT_MENU 0
#define COLONNE_DEBUT_MENU 0
/* --- la barre des messages ---*/
#define NB_LIGNES_MESSAGES 1
#define NB_COLONNES_MESSAGES LARGEUR_ECRAN-1
#define LIGNE_DEBUT_MESSAGES HAUTEUR_ECRAN-1
#define COLONNE_DEBUT_MESSAGES 1
/* --- le pied de page ---*/
#define NB_LIGNES_PIED 2
#define NB_COLONNES_PIED LARGEUR_ECRAN-1
#define LIGNE_DEBUT_PIED HAUTEUR_ECRAN
#define COLONNE_DEBUT_PIED 1
/* --- la fenêtre de traitement ---*/
#define NB_LIGNES_TITRE_TRAITEMENT 1
#define NB_COLONNES_TITRE_TRAITEMENT LARGEUR_ECRAN-1
#define LIGNE_DEBUT_TITRE_TRAITEMENT LIGNE_DEBUT_MENU+2
#define COLONNE_DEBUT_TITRE_TRAITEMENT 1
/* --- la fenêtre de traitement ---*/
#define NB_LIGNES_TRAITEMENT HAUTEUR_ECRAN-NB_LIGNES_MESSAGES-NB_LIGNES_MENU-NB_LIGNES_TITRE_TRAITEMENT
#define NB_COLONNES_TRAITEMENT LARGEUR_ECRAN-1
#define LIGNE_DEBUT_TRAITEMENT LIGNE_DEBUT_TITRE_TRAITEMENT+1
#define COLONNE_DEBUT_TRAITEMENT 1
/* --- Les paires de couleurs---*/
#define COUL_PAIR_NORMAL 1
#define COUL_PAIR_INVERSE 2
#define COUL_PAIR_ERREUR 3
#define COUL_PAIR_INFO 4
#define COUL_PAIR_SAISIE 5
#define COUL_PAIR_EN_EVIDENCE 6
/* Délai attente pour certaines procédures */
#define DELAI_ATTENTE 0
/* === pour les élèves                     === */
#define NON_TROUVE -1
#define MAX_ELEVES 1000
#define T_MAX_NOM 20
#define T_MAX_PRENOM 20
#define T_MAX_NOMFICHIER 100
/* Pour la modification suppression */
#define ACTION_MODIFICATION 1
#define ACTION_SUPPRESSION 2
/* Pour le lignes ou colonnes des messages */
#define COL_MSG 4
#define LIG_MSG 2
/* Pour le lignes ou colonnes des invites de saisie */
#define COL_INV 4
#define LIG_INV 2
/* Pour le type de sauvegarde */
#define T_ENR_MEME_FICHIER 1
#define T_ENR_NOUV_FICHIER 2
/* Pour la selection d'objets */
#define T_OBJ_MAX_NOM 100
#define T_MAX_CHAINE 50
#define NB_MAX_OBJETS 1000
#define REPDATA "DATA"

/* ============================================= */
/* === Déclaration des types globaux         === */
/* ============================================= */
/* === pour les élèves                     === */
struct etudiant
    {
      char nom[T_MAX_NOM]      ;
      char prenom[T_MAX_PRENOM];
      int age                  ;
    };

/* ============================================= */
/* === Déclaration des variables globales    === */
/* ============================================= */
/* === pour les fenêtres                     === */
int MenuCourant=1;
int NbMenus=5;
int TabMenuPrincpaux[5]={3,4,3,3,5}; /* Nombre de choix pour chaque menu */
WINDOW *Barre_des_Menus=NULL,*Barre_des_Messages=NULL,*Pied_de_Page=NULL;   
WINDOW *Fenetre_de_Traitement_Titre=NULL, *Fenetre_de_Traitement_1=NULL, *Fenetre_de_Traitement_2=NULL;   
void Creation_MiseAJour_Fenetre_de_Traitement(int NumFenetre, int SupFenetre, int nblignes, int nbcolonnes, int ligne_deb, int colonne_deb,char libelle[]);
void Affiche_Fenetre_de_Traitement_Titre(int nblignes, int nbcolonnes, int ligne_deb, int colonne_deb,char titre[]);
/* === pour les élèves                     === */
struct etudiant tabeleves[MAX_ELEVES] ;
int nbeleves=0                        ;
int a_sauvegarder = 0                 ; /* booléen */
char NomFichier[T_MAX_NOMFICHIER]=""  ;
char alphabet_nom_prenom[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz -'";
char alphabet_age[]="0123456789";
/* === pour les fichiers et répertoires    === */
char TabListeObjetInfo[NB_MAX_OBJETS][T_OBJ_MAX_NOM];
char TabListeObjet[NB_MAX_OBJETS][T_OBJ_MAX_NOM];
int NbObjets=0;

/* ===================================================== */
/* === Déclaration préliminaires des sous-programmes === */
/* ===================================================== */
/* === pour les fenêtres                             === */
int Defilement_Menu(WINDOW **Elements,int Nombre,int Col_Debut_Menu);
void Suppression_Menu(WINDOW **Elements,int Nombre) ;
WINDOW **Dessine_Menu(int NumMenu) ;
void Dessine_Barre_des_Menus(WINDOW *Barre_des_Menus);
void Dessine_Pied_de_Page(WINDOW *Pied_de_Page) ;
void Initialisation_Curses();
void Affiche_Texte_Barre_des_Messages(char texte[], int paire_des_couleurs);
void Affiche_Element_Barre_des_Menus(char texte[], int col_position);
void Efface_Fenetre(WINDOW *fenetre) ;
WINDOW **Dessine_Liste_Objets(int LigneDeb, int ColDeb);
int Defilement_Liste_Objets(WINDOW **Elements,int Nombre,int Col_Debut_Menu);
/* === pour les élèves                     === */
int Saisie_Liste_Eleves()    ;
//int Affichage_Liste_Eleves(struct etudiant *tabelements, int nbelements) ;
//int Affichage_Liste_Eleves(struct etudiant *tabelements, int nbelements, char *TitreFenetre, int NbLignesLibresFindePage);
int Affichage_Liste_Eleves(struct etudiant *tabelements, int nbelements, char *TitreFenetre, int NbLignesLibresFindePage, int *NumDLigneAffichee);
int Sauvegarde_Liste_Eleves(int TypeEnr);
int Chargement_Liste_Eleves(char FichierACharger[]);
int Chargement_Par_Selection();
void Quitter();
void Modification_Suppression_Eleve(int action);
void Suppression_Eleve();
void Recherche_Eleve_Sur_Un_Champ(int ChampRecherche);
void Tri_Liste_Eleves_Sur_Des_Champs(int ChampTri)    ;
void conv_maj(char ch[])     ;
char * str_replace_all(char * chaine, char * motif_a_remplacer, char * motif_de_remplacement)   ;
char * supprime_accent(char * chaine) ;
void Lire_Chaine_Avec_Espaces(WINDOW *Fenetre, char ch[]) ;
void Lire_Chaine_Avec_Espaces_ch(WINDOW *Fenetre, char ch[]);
void trim(char *ch) ;
void supprime_espaces_multiples(char *ch) ;
void normalise_chaine(char ch[]) ;
int verif_chaine_dans_alphabet(char ch[], char alphabet[]);
void Saisie_Chaine_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], char ch[]);
void Saisie_Entier_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], int *pentier) ;
void Saisie_Caractere_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], char ch[]) ;
//void Affiche_Un_Eleve(struct etudiant eleve, int ligne,int deb_ligne,int deb_col);
void Affiche_Un_Eleve(struct etudiant eleve, int ligne,int deb_ligne,int deb_col,int num_eleve);
void Affiche_Element_Ligne_Traitement(int NumFenetre,char texte[], int ligne_position, int col_position);
void Affiche_Entete_Liste_Eleves(int ligne,int deb_ligne,int deb_col);
void verif_sauvegarde();
int RechercheMultiOccurrences(char prefixerech[T_MAX_NOM], int tabres[], int NumChampRech, int ValNum);
void Supprime_Tous_Les_Eleves();
void TraitementDate(time_t Temps, char *ChaineHeureDate);
void TraitementLoginGroup(int UID,int GID, char *ChaineInfo);
int Lister_Repertoire(char NomRep[]);
int Recupere_Objet_Info(char NomObjetInfo[]);


/* ============================== */
/* === Programme principal    === */
/* ============================== */
int main()
{    int key = AUCUNE ;    
     int NbChoixMenu  ;
     int Element_selectionne=0, choix=0 ;        
     WINDOW **Elements_des_Menus=NULL   ;        
     int nblignes=0,nbcolonnes=0,ligne_deb=0,colonne_deb=0;
     char libelle[100] ;
     int AffichageMenuImmediat=0, NumDLigneAffichee=0 ;
     
     setlocale(LC_ALL,"fr_FR.UTF-8"); /* Prise en charge des caractères accentués UTF8 */
     
     Initialisation_Curses() ;   
     bkgd(COLOR_PAIR(COUL_PAIR_NORMAL))     ;
     
     /* Création de la sous-fenêtre Barre_des_Menus */
     nblignes        = NB_LIGNES_MENU     ;
     nbcolonnes      = NB_COLONNES_MENU   ;
     ligne_deb       = LIGNE_DEBUT_MENU   ;
     colonne_deb     = COLONNE_DEBUT_MENU ;
     Barre_des_Menus = subwin(stdscr,nblignes,nbcolonnes,ligne_deb,colonne_deb);
     
     /* Création de la sous-fenêtre Barre_des_Messages */
     nblignes           = NB_LIGNES_MESSAGES     ;
     nbcolonnes         = NB_COLONNES_MESSAGES   ;
     ligne_deb          = LIGNE_DEBUT_MESSAGES   ;
     colonne_deb        = COLONNE_DEBUT_MESSAGES ;
     Barre_des_Messages = subwin(stdscr,nblignes,nbcolonnes,ligne_deb,colonne_deb); 

     /* Affichage de la sous-fenêtre Barre_des_Menus */
     Dessine_Barre_des_Menus(Barre_des_Menus);

     /* Création de la sous-fenêtre Pied_de_Page */
     nblignes           = NB_LIGNES_PIED     ;
     nbcolonnes         = NB_COLONNES_PIED   ;
     ligne_deb          = LIGNE_DEBUT_PIED   ;
     colonne_deb        = COLONNE_DEBUT_PIED ;
     Pied_de_Page = subwin(stdscr,nblignes,nbcolonnes,ligne_deb,colonne_deb); 

     /* Affichage de la sous-fenêtre Pied_de_Page */
     Dessine_Pied_de_Page(Pied_de_Page);

     /* Rafraichissement de l'écran */
     refresh();    
     
     while ((key!=ESCAPE) && (key!='q') && (key!='Q'))
     {     
         /* On efface la Barre_des_Messages */
         Efface_Fenetre(Barre_des_Messages)          ;
         /* On efface la Fenetre_de_Traitement_Titre */
         Efface_Fenetre(Fenetre_de_Traitement_Titre) ;
         /* On efface la Fenetre_de_Traitement_1 */
         Efface_Fenetre(Fenetre_de_Traitement_1)     ;
         /* On efface la Fenetre_de_Traitement_2 */
         Efface_Fenetre(Fenetre_de_Traitement_2)     ;

         AffichageMenuImmediat = 0          ;
         Efface_Fenetre(Barre_des_Messages) ;   
         Elements_des_Menus   = Dessine_Menu(MenuCourant)                        ;
         NbChoixMenu          = TabMenuPrincpaux[MenuCourant-1]                  ;          
         Element_selectionne  = Defilement_Menu(Elements_des_Menus,NbChoixMenu,0);            

         choix=Element_selectionne+1;
         switch(choix)
         {
           case -1 : case 0 : 
                     Affiche_Texte_Barre_des_Messages("Aucune rubrique sélectionnée. ENTER pour continuer. ESC ou 'q' pour quitter.",COUL_PAIR_ERREUR);
                     break ;
           case 11 : AffichageMenuImmediat = Saisie_Liste_Eleves() ;           
                     break ;
           case 12 : AffichageMenuImmediat = Affichage_Liste_Eleves(NULL,0,"",0,&NumDLigneAffichee) ;
                     break ;
           case 13 : Quitter()    ;
                     key=ESCAPE   ;
                     break ;
           case 21 : AffichageMenuImmediat = Chargement_Liste_Eleves("")  ;
                     break ;
           case 22 : AffichageMenuImmediat = Chargement_Par_Selection()   ;
                     break ;
           case 23 : AffichageMenuImmediat = Sauvegarde_Liste_Eleves(T_ENR_MEME_FICHIER)  ;
                   break ;
           case 24 : AffichageMenuImmediat = Sauvegarde_Liste_Eleves(T_ENR_NOUV_FICHIER)  ;
                   break ;
           case 31 : Modification_Suppression_Eleve(ACTION_MODIFICATION);
                     break ;
           case 32 : Modification_Suppression_Eleve(ACTION_SUPPRESSION) ;
                     break ;
           case 33 : Supprime_Tous_Les_Eleves()           ;
                     break ;
           case 41 : Recherche_Eleve_Sur_Un_Champ(1) ;
                     break ;
           case 42 : Recherche_Eleve_Sur_Un_Champ(2) ;
                     break ;
           case 43 : Recherche_Eleve_Sur_Un_Champ(3) ;
                     break ;
           case 51 : Tri_Liste_Eleves_Sur_Des_Champs(1)   ;
                     break ;
           case 52 : Tri_Liste_Eleves_Sur_Des_Champs(2)   ;
                     break ;
           case 53 : Tri_Liste_Eleves_Sur_Des_Champs(3)   ;
                     break ;
           case 54 : Tri_Liste_Eleves_Sur_Des_Champs(12)  ;
                     break ;
           case 55 : Tri_Liste_Eleves_Sur_Des_Champs(123) ;
                     break ;
           default : 
                     Affiche_Texte_Barre_des_Messages("Rubrique non reconnue. ENTER pour continuer. ESC ou 'q' pour quitter.",COUL_PAIR_ERREUR);
                     break ;
         }

      /* lecture d'un touche saisie si ESC n'a pas été sélectionné */
      /* et que le menu ne doit pas être affiché immédiatement */ 
      if ((key!=ESCAPE) && (key!='q') && (key!='Q') && (!AffichageMenuImmediat))
      {
        Affiche_Texte_Barre_des_Messages("ENTER pour accéder aux menus. ESC ou 'q' pour quitter l'application.",COUL_PAIR_ERREUR);
        key=getch();
        if ((key == ESCAPE) || (key == 'q') || (key == 'Q'))
        {
          Quitter();
        }
      }      
      /* On rafraîchit la fenêtre des messages */
      wrefresh(Barre_des_Messages);
      /* On simule une modification de l'écran pour le rafraichir totalement */
      touchwin(stdscr);            
      refresh();      
     }

     delwin(Barre_des_Menus); 
     delwin(Barre_des_Messages);    
     delwin(Fenetre_de_Traitement_Titre);    
     delwin(Fenetre_de_Traitement_1);    
     delwin(Fenetre_de_Traitement_2);    
     endwin();
     return 0;
}
/* ===================================================================== */
/* === Gestion du défilement des menus déroulants via les flèches    === */
/* ===================================================================== */
int Defilement_Menu(WINDOW **Elements,int Nombre,int Col_Debut_Menu)
{    
  int key         ;    
  int selected=0  ;
  int NbChoixMenu ;
    
  while (1) 
  {        
    key=getch();        
    if (key==KEY_DOWN || key==KEY_UP) // Flèche en bas ey en haut
    {            
      wbkgd(Elements[selected+1],COLOR_PAIR(COUL_PAIR_INVERSE));            
      wnoutrefresh(Elements[selected+1]);            
      if (key==KEY_DOWN) 
      {                
        selected=(selected+1) % Nombre;            
      } 
      else 
      {                
         selected=(selected+Nombre-1) % Nombre;            
      }            
      wbkgd(Elements[selected+1],COLOR_PAIR(COUL_PAIR_NORMAL));            
      wnoutrefresh(Elements[selected+1]);            
      doupdate();        
    }
    else if (key==KEY_LEFT) // Flèche à gauche
    {            
      Suppression_Menu(Elements,Nombre+1);            
      touchwin(stdscr);            
      refresh(); 
                 
      MenuCourant=MenuCourant-1;           
      if (MenuCourant == 0) MenuCourant=NbMenus;
                 
      Elements=Dessine_Menu(MenuCourant);            
      NbChoixMenu = TabMenuPrincpaux[MenuCourant-1];          

      return Defilement_Menu(Elements,NbChoixMenu,LARGEUR_COL_MENU-Col_Debut_Menu);        
    } 
    else if (key==KEY_RIGHT) // Flèche à droite
    {            
      Suppression_Menu(Elements,Nombre+1);            
      touchwin(stdscr);            
      refresh(); 
                 
      MenuCourant=MenuCourant+1;
      if (MenuCourant == NbMenus+1) MenuCourant=1;
                
      Elements=Dessine_Menu(MenuCourant);            
      NbChoixMenu = TabMenuPrincpaux[MenuCourant-1];          

      return Defilement_Menu(Elements,NbChoixMenu,LARGEUR_COL_MENU-Col_Debut_Menu);        
    } 
    else if ((key==ESCAPE) || (key=='q') || (key=='Q'))
    {            
       return -1;        
    } 
    else if (key==ENTER) 
    { 
      return selected + (MenuCourant*10);
    }    
  }
}
/* ======================================== */
/* === Suppression de menu déroulant    === */
/* ======================================== */
void Suppression_Menu(WINDOW **Elements,int Nombre)
{    int i;    
     for (i=0;i<Nombre;i++)
     {   if (Elements[i] != NULL)
             delwin(Elements[i]);
     } 
     if (Elements != NULL) free(Elements);
}
/* ===================================== */
/* === Dessin des menus déroulant    === */
/* ===================================== */
WINDOW **Dessine_Menu(int NumMenu)
{    
  int i;    
  WINDOW **Elements=NULL;  
  int start_col ;
  int NbChoixMenu ;
  
  start_col = (NumMenu-1)*LARGEUR_COL_MENU ;
  
  NbChoixMenu = TabMenuPrincpaux[NumMenu-1];          

  Elements=(WINDOW **)malloc((NbChoixMenu+1)*sizeof(WINDOW *));    
  Elements[0]=newwin(NbChoixMenu+2,LARGEUR_COL_MENU-1,1,start_col);    

  wbkgd(Elements[0],COLOR_PAIR(COUL_PAIR_INVERSE));    
  box(Elements[0],ACS_VLINE,ACS_HLINE);
  
  for (i=1 ; i<=NbChoixMenu ; i++)        
    Elements[i]=subwin(Elements[0],1,LARGEUR_COL_MENU-3,i+1,start_col+1);  

  if (NumMenu == 1)
  {
    wprintw(Elements[1],"Saisie")      ;
    wprintw(Elements[2],"Affichage")   ;
    wprintw(Elements[3],"Quitter")     ;
  }
  else if (NumMenu == 2)
  {
    wprintw(Elements[1],"Ouvrir")           ;
    wprintw(Elements[2],"Sélectionner ...") ;
    wprintw(Elements[3],"Enregistrer")      ;
    wprintw(Elements[4],"Enregistrer sous") ;
  }
  else if (NumMenu == 3)
  {
    wprintw(Elements[1],"Modifier")           ;
    wprintw(Elements[2],"Supprimer un élève") ;
    wprintw(Elements[3],"Supprimer tout")     ;
  }
  else if (NumMenu == 4)
  {
    wprintw(Elements[1],"Par nom")     ;
    wprintw(Elements[2],"Par prénom")  ;
    wprintw(Elements[3],"Par âge")     ;
  }
  else 
  {
    wprintw(Elements[1],"Par nom")             ;
    wprintw(Elements[2],"Par prénom")          ;
    wprintw(Elements[3],"Par âge")             ;
    wprintw(Elements[4],"Par nom,prénom")      ;
    wprintw(Elements[5],"Par nom,prénom,âge")  ;
  }

  wbkgd(Elements[1],COLOR_PAIR(COUL_PAIR_NORMAL));    
  wrefresh(Elements[0]);    
  return Elements;
}
/* ===================================== */
/* === Dessin de la barre des menus  === */
/* ===================================== */
void Dessine_Barre_des_Menus(WINDOW *Barre_des_Menus)
{    
  wbkgd(Barre_des_Menus,COLOR_PAIR(COUL_PAIR_INVERSE));
  
  Affiche_Element_Barre_des_Menus("Principal",0)                 ;
  Affiche_Element_Barre_des_Menus("Fichier"  ,LARGEUR_COL_MENU)  ;
  Affiche_Element_Barre_des_Menus("Edition"  ,2*LARGEUR_COL_MENU);
  Affiche_Element_Barre_des_Menus("Recherche",3*LARGEUR_COL_MENU);
  Affiche_Element_Barre_des_Menus("Tri"      ,4*LARGEUR_COL_MENU);
}
/* ===================================== */
/* === Dessin de la fenêtre en bas   === */
/* ===================================== */
void Dessine_Pied_de_Page(WINDOW *Pied_de_Page)
{    
  wbkgd(Pied_de_Page,COLOR_PAIR(COUL_PAIR_NORMAL));

  Efface_Fenetre(Pied_de_Page) ;

  wattron(Pied_de_Page,COLOR_PAIR(COUL_PAIR_NORMAL)) ;    
  waddstr(Pied_de_Page,"Validez un choix en appuyant sur la touche ENTER. ESC ou 'q' pour quitter.\n")              ;    
  waddstr(Pied_de_Page,"Dans les menus utilisez les flèches (haut,bas) ou entre les menus (gauche,droite).") ;    
  wattroff(Pied_de_Page,COLOR_PAIR(COUL_PAIR_NORMAL));            

  wrefresh(Pied_de_Page) ;
}
/* =============================================================== */
/* === Dessin de la liste des fichiers sous la forme de menus  === */
/* =============================================================== */
WINDOW **Dessine_Liste_Objets(int LigneDeb, int ColDeb)
{    
  int i                  ;    
  WINDOW **Elements=NULL ;  
  int start_col          ;
  int NbChoixMenu        ;
  int nblignes=1,nbcolonnes=0,ligne_deb,colonne_deb ;
  int NumMenu=1          ;

  NbChoixMenu=NbObjets;

  /* Calcul de la largeur de la fenêtre de la liste des fichiers */
  for (i=0;i<NbObjets;i++)
  {
       nbcolonnes = MAX(nbcolonnes,strlen(TabListeObjetInfo[i]));
  }
  nbcolonnes+=2;

  Elements=(WINDOW **)malloc((NbChoixMenu+1)*sizeof(WINDOW *));    
  nblignes=MIN(30,NbObjets+2) ;
  Elements[0]=subwin(Fenetre_de_Traitement_1,nblignes,nbcolonnes+2,LigneDeb+2,ColDeb+2);  

  wbkgd(Elements[0],COLOR_PAIR(COUL_PAIR_INVERSE));    
  box(Elements[0],ACS_VLINE,ACS_HLINE);

  nblignes=1 ;
  for (i=1 ; i<=NbChoixMenu ; i++)        
    Elements[i]=subwin(Elements[0],nblignes,nbcolonnes+0,i+LigneDeb+2,ColDeb+4-1);  

  if (NumMenu == 1)
  {
    for (i=0;i<NbObjets;i++)
    {
       mvwprintw(Elements[i+1],0,1, TabListeObjetInfo[i]) ;  
    }
  }
  wbkgd(Elements[1],COLOR_PAIR(COUL_PAIR_NORMAL));    
  wrefresh(Elements[0]);    
  return Elements;
}
/* =============================================================== */
/* === Défilement dans la liste des fichiers avec les flèches  === */
/* =============================================================== */
int Defilement_Liste_Objets(WINDOW **Elements,int Nombre,int Col_Debut_Menu)
{    
  int key;    
  int selected=0;
  int NbChoixMenu ;
    
  while (1) 
  {        
    key=getch();        
    if (key==KEY_DOWN || key==KEY_UP) 
    {            
      wbkgd(Elements[selected+1],COLOR_PAIR(COUL_PAIR_INVERSE));            
      wnoutrefresh(Elements[selected+1]);            
      if (key==KEY_DOWN) 
      {                
        selected=(selected+1) % Nombre;            
      } 
      else 
      {                
         selected=(selected+Nombre-1) % Nombre;            
      }            
      wbkgd(Elements[selected+1],COLOR_PAIR(COUL_PAIR_NORMAL));            
      wnoutrefresh(Elements[selected+1]);            
      doupdate();        
    }
    else if ((key==ESCAPE) || (key=='q') || (key=='Q'))
    {            
       return -1;        
    } 
    else if (key==ENTER) 
    { 
      return selected ;
    }    
  }
}
/* ================================ */
/* === Initialisation de curses === */
/* ================================ */
void Initialisation_Curses()
{        
  initscr();        
  start_color();
  /* paires des couleurs du texte et du fond du texte */   
  init_pair(COUL_PAIR_NORMAL,COLOR_WHITE,COLOR_BLUE)       ;        
  init_pair(COUL_PAIR_INVERSE,COLOR_BLUE,COLOR_WHITE)      ;        
  init_pair(COUL_PAIR_ERREUR,COLOR_RED,COLOR_WHITE)        ;        
  init_pair(COUL_PAIR_INFO,COLOR_WHITE,COLOR_MAGENTA)      ;        
  init_pair(COUL_PAIR_SAISIE,COLOR_BLACK,COLOR_WHITE)      ;        
  init_pair(COUL_PAIR_EN_EVIDENCE,COLOR_RED,COLOR_WHITE)   ;        
  curs_set(0);        
  noecho();        
  keypad(stdscr,TRUE);
}
/* ================================================= */
/* === Affiche la fenêtre du titre de traitement === */
/* ================================================= */
void Affiche_Fenetre_de_Traitement_Titre(int nblignes, int nbcolonnes, int ligne_deb, int colonne_deb,char titre[])
{ 
  int taille_titre, pos_col;
  
  touchwin(stdscr);            
  refresh();      
  /* Création de la sous-fenêtre des traitements */
  if (Fenetre_de_Traitement_Titre == NULL)
      Fenetre_de_Traitement_Titre=subwin(stdscr,nblignes,nbcolonnes,ligne_deb,colonne_deb); 
  else
  { /* Effacement de la fenêtre de titre du traitement */
     Efface_Fenetre(Fenetre_de_Traitement_Titre) ;
  }
  wbkgd(Fenetre_de_Traitement_Titre,COLOR_PAIR(COUL_PAIR_INVERSE));
  wattron(Fenetre_de_Traitement_Titre,COUL_PAIR_INVERSE)    ;  
  
  taille_titre = strlen(titre);
  pos_col = (nbcolonnes / 2) - (taille_titre / 2);
  mvwprintw(Fenetre_de_Traitement_Titre, 0, pos_col, titre) ;  
  wattroff(Fenetre_de_Traitement_Titre,COUL_PAIR_NORMAL)   ; 
  
  wrefresh(Fenetre_de_Traitement_Titre);
}
// =========================================================
// --- Création/Mise à jour de la fenêtre de traitements ---
// =========================================================
void Creation_MiseAJour_Fenetre_de_Traitement(int NumFenetre, int SupFenetre, int nblignes, int nbcolonnes, int ligne_deb, int colonne_deb,char libelle[])
{ 
  WINDOW *fenetre ;
  
  if (NumFenetre == 2 )
     fenetre = Fenetre_de_Traitement_2 ;
  else
     fenetre = Fenetre_de_Traitement_1 ;
    
  touchwin(stdscr);            
  refresh();      
  
  if (SupFenetre)
  {
     werase(fenetre)   ;
     wrefresh(fenetre) ;
     delwin(fenetre)   ;
     fenetre=NULL      ;
  }
  
  /* Création de la sous-fenêtre des traitements */
  if (fenetre == NULL)
      fenetre=subwin(stdscr,nblignes,nbcolonnes,ligne_deb,colonne_deb); 
  else
  {  /* Effacement de la fenêtre de traitement */
     Efface_Fenetre(fenetre) ;
  }
  box(fenetre, ACS_VLINE, ACS_HLINE);
  wattron(fenetre,COLOR_PAIR(COUL_PAIR_EN_EVIDENCE))    ;  
  mvwprintw(fenetre, 0, 1, libelle)                     ;  
  wattroff(fenetre,COLOR_PAIR(COUL_PAIR_EN_EVIDENCE))   ; 
  
  wrefresh(fenetre);
  
  if (NumFenetre == 2 )
     Fenetre_de_Traitement_2 = fenetre ;
  else
     Fenetre_de_Traitement_1 = fenetre ;
}
// ===================================
// --- Saisie d'une liste d'élèves ---
// ===================================
int Saisie_Liste_Eleves()
{
  struct etudiant eleve ;
  int i = nbeleves ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb, nblignes, nbcolonnes, ligne_deb, colonne_deb;
  char libelle_fenetre[200], texte_message[200];
  int nbsaisie=0;
  char *chaine_retour;
  char chage[10];
  int AffichageMenuImmediat=1;
  int SupprInitialeFenetre=1;

  /* Initialisation des champs */
  strcpy(eleve.nom," ")   ;
  strcpy(eleve.prenom," ");
  eleve.age = -1          ;

  /* Création ou mise à jour de la sous-fenêtre des traitements */
  Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
  Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
  Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
  Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

  strcpy(libelle_fenetre,"SAISIE D'UNE LISTE D'ÉLÈVES");
  Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

  /* Couleurs de la fenêtre de traitement en mode normal */
  wbkgd(Fenetre_de_Traitement_1,COLOR_PAIR(COUL_PAIR_NORMAL));

  while (strcmp(eleve.nom,"") != 0 )
  {
    strcpy(eleve.nom,"")    ;
    strcpy(eleve.prenom,"") ;
    eleve.age = 0           ;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_INV)+3 ; // Pour 3 items saisis
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Nombre d'élèves saisis : %d élève(s)   ",nbsaisie);
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
    SupprInitialeFenetre=0;
    
    /* --- Affichage des différents champs comme masque de saisie --- */
    mvwprintw(Fenetre_de_Traitement_1, LIG_INV+0, COL_INV,"Nom    :                               (ENTER pour terminer la saisie )");
    mvwprintw(Fenetre_de_Traitement_1, LIG_INV+1, COL_INV,"Prénom : ");   
    mvwprintw(Fenetre_de_Traitement_1, LIG_INV+2, COL_INV,"Age    : ");   
    /* --- Saisie du nom --- */
    Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+0,COL_INV,"Nom    : ",eleve.nom) ;
    if (strcmp(eleve.nom,"") != 0 )
    {
      normalise_chaine(eleve.nom) ;
      if (verif_chaine_dans_alphabet(eleve.nom,alphabet_nom_prenom))
      {
        /* --- Saisie du prénom --- */
        Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+1,COL_INV,"Prénom : ",eleve.prenom) ;
        if (strcmp(eleve.prenom,"") != 0 )
        {
          normalise_chaine(eleve.prenom) ;
          if (verif_chaine_dans_alphabet(eleve.prenom,alphabet_nom_prenom))
          {
            /* --- Saisie de l'age --- */
            Saisie_Entier_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+2,COL_INV,"Age    : ",&eleve.age) ;
            sprintf(chage,"%d",eleve.age);
            if ( (eleve.age != 0 ) && (verif_chaine_dans_alphabet(chage,alphabet_age)) )
            {
              sprintf(texte_message,"Dernier élève saisi : %s\t%s\t%d",eleve.nom,eleve.prenom,eleve.age);
              Affiche_Texte_Barre_des_Messages(texte_message, COUL_PAIR_INFO);

              nbsaisie++;
              tabeleves[i++] = eleve ;
            }
            if (nbsaisie != 0) a_sauvegarder = 1  ;
            
          }  
        }
      }
    }  // Fin du if (strcmp(eleve.nom,"") != 0 )
    if ((strcmp(eleve.nom,"") == 0 ) || (!verif_chaine_dans_alphabet(eleve.nom,alphabet_nom_prenom)) )
    {
      Affiche_Texte_Barre_des_Messages("Le format du nom est erroné", COUL_PAIR_ERREUR);
    }
    else if ((strcmp(eleve.prenom,"") == 0 ) || (!verif_chaine_dans_alphabet(eleve.prenom,alphabet_nom_prenom)) )
    {
      Affiche_Texte_Barre_des_Messages("Le format du prénom est erroné", COUL_PAIR_ERREUR);
    }
    else if ( (eleve.age == 0 ) || (!verif_chaine_dans_alphabet(chage,alphabet_age)) )
    {
      Affiche_Texte_Barre_des_Messages("Le format de l'âge est erroné", COUL_PAIR_ERREUR);  
    }
  } // Fin du while (strcmp(eleve.nom,"") != 0 )
  nbeleves = i ; /* On mémorise le nombre d'él!ves dans la variables globales */

  return AffichageMenuImmediat;
}
// ======================================
// --- Affichage d'une liste d'élèves ---
// ======================================
int Affichage_Liste_Eleves(struct etudiant *tabelements, int nbelements, char *TitreFenetre, int NbLignesLibresFindePage, int *NumDLigneAffichee)
{
   struct etudiant eleve ;
   int i=0, NbElevesAffiches=0 ;
   int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
   int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
   char libelle_fenetre[200], texte_message[200];
   int AffichageMenuImmediat=0;
   int SupprInitialeFenetre=1;
   int maxnblignes, nblignesFenetre;
   int maxnbelements, nbelementsAafficher ;
   char StopSaisie = ' ';

   /* Création ou mise à jour de la sous-fenêtre des traitements */
   Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
   Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
   Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
   Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

   strcpy(libelle_fenetre,"AFFICHAGE DE LA LISTE DES ÉLÈVES");
   Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

  if (tabelements == NULL)
  {
    tabelements = tabeleves ;
    nbelements  = nbeleves  ;
  }
  if (nbelements == 0)
  {
    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = nbelements+5;
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève à afficher",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    nblignes    = nbelements+3                        ;
    maxnblignes = LINES - 7 - NbLignesLibresFindePage ;
    
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
 
    NbElevesAffiches = 0 ;
    while ((NbElevesAffiches < nbelements) && (StopSaisie != 'q'))
    {
      maxnbelements = maxnblignes-3;
      nbelementsAafficher=MIN(nbelements-NbElevesAffiches,maxnbelements);
      nblignesFenetre = MIN(nbelementsAafficher+3,maxnblignes)       ;
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      if (strcmp(TitreFenetre,"") == 0) // Aucun Titre particulier n'a été indiqué
      {
        sprintf(libelle_fenetre,"   Affichage de %d élève(s)   ",nbelements);
      }
      else
      {
        strcpy(libelle_fenetre,TitreFenetre);
      }
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignesFenetre,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
      Affiche_Entete_Liste_Eleves(-1,LIG_MSG,COL_MSG);
   
      for (i = 0 ; i<nbelementsAafficher ; i++)
      {
        eleve = tabelements[NbElevesAffiches];
        Affiche_Un_Eleve(eleve,i,LIG_MSG,COL_MSG,NbElevesAffiches);
        NbElevesAffiches++;
      } 
      wrefresh(Fenetre_de_Traitement_1);

      if (NbElevesAffiches < nbelements)
      {
        sprintf(texte_message,"Appuyer sur ENTER pour afficher la page suivante, ou 'q' pour quitter l'affichage et poursuivre");
        Affiche_Texte_Barre_des_Messages(texte_message, COUL_PAIR_INFO);
        StopSaisie = getch();        
      }
    }
  } 
  *NumDLigneAffichee = ligne_deb + nblignesFenetre ;
  
  return AffichageMenuImmediat;
}
// =========================================
// --- Affichage de l'entête de la liste ---
// =========================================
void Affiche_Entete_Liste_Eleves(int ligne,int deb_ligne,int deb_col)
{ 
  int pos1, pos2, pos3, pos4 ;

  wattron(Fenetre_de_Traitement_1,A_UNDERLINE);  

  pos1=(0*LARGEUR_COL_MENU)+deb_col;
  pos2=(1*LARGEUR_COL_MENU)+deb_col;
  pos3=(2*LARGEUR_COL_MENU)+deb_col;
  pos4=(3*LARGEUR_COL_MENU)+deb_col;
  
  Affiche_Element_Ligne_Traitement(1,"Numéro",ligne+deb_ligne,pos1) ;
  Affiche_Element_Ligne_Traitement(1,"Nom",ligne+deb_ligne,pos2)    ;
  Affiche_Element_Ligne_Traitement(1,"Prénom",ligne+deb_ligne,pos3) ;
  Affiche_Element_Ligne_Traitement(1,"Age",ligne+deb_ligne,pos4)    ;

  wattroff(Fenetre_de_Traitement_1,A_UNDERLINE); 

  touchwin(Fenetre_de_Traitement_1)            ;
}
// ============================
// --- Affichage d'un élève ---
// ============================
void Affiche_Un_Eleve(struct etudiant eleve, int ligne,int deb_ligne,int deb_col,int num_eleve)
{ 
  char texte[100];
  int pos1, pos2, pos3, pos4 ;
  
  pos1=(0*LARGEUR_COL_MENU)+deb_col;
  pos2=(1*LARGEUR_COL_MENU)+deb_col;
  pos3=(2*LARGEUR_COL_MENU)+deb_col;
  pos4=(3*LARGEUR_COL_MENU)+deb_col;
  
  sprintf(texte,"%6d",num_eleve+1)  ;
  Affiche_Element_Ligne_Traitement(1,texte,ligne+deb_ligne,pos1)        ;
  Affiche_Element_Ligne_Traitement(1,eleve.nom,ligne+deb_ligne,pos2)    ;
  Affiche_Element_Ligne_Traitement(1,eleve.prenom,ligne+deb_ligne,pos3) ;
  sprintf(texte,"%3d",eleve.age);
  Affiche_Element_Ligne_Traitement(1,texte,ligne+deb_ligne,pos4)        ;
}
// ===========================
// --- Quitter le logiciel ---
// ===========================
void Quitter()
{
    /* On vérifie si il y a une sauvegarde a faire avant de charger le nouveau fichier en mémoire */
    verif_sauvegarde() ;

    Affiche_Texte_Barre_des_Messages("Au revoir !",COUL_PAIR_INFO);
}
// =========================================
// --- Modification d'un élève ---
// =========================================
void Modification_Suppression_Eleve(int action)
{
//  char nomrecherche[T_MAX_NOM];
  int SupprInitialeFenetre, numero ;
  struct etudiant eleve, eleve_sauve ;
  struct etudiant TabListeElevesTrouves[MAX_ELEVES] ;
  int TabIndicesRecherche[MAX_ELEVES]     ;
  int ChampRecherche=1, NbOccurrences=0;
  int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
  char libelle_fenetre[100], TypeRecherche[10]="N", ChaineRecherche[100]="", lettreRecherche=' ';
  char TitreFenetre[100] ;
  char texte[100], texteN[100], texteP[100], texteA[100] ;
  int SaisieOK=0, SaisieVide=0, SaisieValide=1;
  int AgeRecherche=0, i=0, NbLignesLibresFindePage=7, NumDLigneAffichee=0, NumEleve ;
  char chage[10];
  int ChampsModifies=0;
  char reponse[10];
  char texte_titre_action[100], texte_action_1[100],texte_action_2[100],texte_action_3[100];
  int continuer_saisie = 1 ;

  if (action == ACTION_SUPPRESSION)
  {
     strcpy(texte_titre_action,"SUPPRESSION") ;
     strcpy(texte_action_1,"supprimer")       ;
     strcpy(texte_action_2,"suppression")     ;
     strcpy(texte_action_3,"supprimé")        ;
  }
  else
  {
     strcpy(texte_titre_action,"MODIFICATION");
     strcpy(texte_action_1,"modifier")        ;
     strcpy(texte_action_2,"modification")    ;
     strcpy(texte_action_3,"modifié")         ;
  }
  if (nbeleves == 0)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    sprintf(libelle_fenetre,"%s D'UN ÉLÈVE",texte_titre_action);
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 message affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève pour la recherche",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    /* On demande la nature de la recherche et l'élément à rechercher */
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    sprintf(libelle_fenetre,"%s D'UN ÉLÈVE",texte_titre_action);
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    while (continuer_saisie)
    {
      continuer_saisie = 0 ;
      SaisieValide     = 1 ;
      SaisieVide       = 0 ;
 
      if (Barre_des_Messages != NULL)
      {
        werase(Barre_des_Messages);
        wrefresh(Barre_des_Messages);
      }

      SupprInitialeFenetre=1;
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      nblignes    = (2*LIG_INV)+2 ; // Pour 2 items saisis
      nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
      ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
      colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;

      sprintf(libelle_fenetre,"   Critères de recherche de l'élève à %s ",texte_action_1);
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
    
      /* --- Affichage du masque de saisie --- */
      mvwprintw(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Recherche par Nom (n), Prénom (p), Age (a) :          (ENTER = par Nom)");

      Saisie_Caractere_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Recherche par Nom (n), Prénom (p), Age (a) : ",TypeRecherche) ;
      normalise_chaine(TypeRecherche) ;

      if (strcmp(TypeRecherche,"") ==0) strcpy(TypeRecherche,"N");
      lettreRecherche = TypeRecherche[0] ;
    
      switch(lettreRecherche)
      {
         case 'N' :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+1,COL_INV,"Premiers caractères du nom : ",ChaineRecherche) ;
                     normalise_chaine(ChaineRecherche) ;
                     ChampRecherche=1;
                     break ;
         case 'P' :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+1,COL_INV,"Premiers caractères du prénom : ",ChaineRecherche) ;
                     normalise_chaine(ChaineRecherche) ;
                     ChampRecherche=2;
                     break ;
         case 'A' :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+1,COL_INV,"Age    : ",ChaineRecherche) ;
                     ChampRecherche=3;
                     break ;
      } 

      SaisieVide    = (strcmp(ChaineRecherche,"")==0);
      if (strcmp(TypeRecherche,"A")==0) 
         AgeRecherche   = atoi(ChaineRecherche);

      if ((strcmp(TypeRecherche,"N")==0) || (strcmp(TypeRecherche,"P")==0))
      {
        SaisieValide    = verif_chaine_dans_alphabet(ChaineRecherche,alphabet_nom_prenom) ;
      }
      else
      {
        SaisieValide    = verif_chaine_dans_alphabet(ChaineRecherche,alphabet_age)  ;
      }

      SaisieOK    = (!SaisieVide) && (SaisieValide)       ;

      if (!SaisieOK)
      {
        if (SaisieVide)
        {
          continuer_saisie = 0; 
        
          /* Création ou mise à jour de la sous-fenêtre des traitements */
          Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
          Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
          Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
          Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

          sprintf(libelle_fenetre,"%s D'UN ÉLÈVE",texte_titre_action);
          Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

          SupprInitialeFenetre=1;
          /* Création ou mise à jour de la sous-fenêtre des traitements */
          nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
          nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
          ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
          colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
          sprintf(libelle_fenetre,"   Aucun élève   ");
          Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
          Affiche_Element_Ligne_Traitement(1,"Aucune saisie n'a été effectuée",LIG_MSG,COL_MSG);
          wrefresh(Fenetre_de_Traitement_1);
          
        }
        else if (!SaisieValide)
        { 
          continuer_saisie = 1; 
          strcpy(ChaineRecherche,"");
          strcpy(chage,"");
          AgeRecherche=0;
        

          if (strcmp(TypeRecherche,"N")==0)
          {
            sprintf(texte,"Le format du nom est erroné. SaisieValide=|%d|",SaisieValide);
            Affiche_Texte_Barre_des_Messages(texte, COUL_PAIR_ERREUR);
          }
          else if (strcmp(TypeRecherche,"P")==0)
          {
            sprintf(texte,"Le format du prénom est erroné. SaisieValide=|%d|",SaisieValide);
            Affiche_Texte_Barre_des_Messages(texte, COUL_PAIR_ERREUR);
          }
          else if (strcmp(TypeRecherche,"A")==0)
          {
            sprintf(texte,"Le format de l'âge est erroné. SaisieValide=|%d|",SaisieValide);
            Affiche_Texte_Barre_des_Messages(texte, COUL_PAIR_ERREUR);
          } 
          getch();
        } 
      } // Fin du if (!SaisieOK && !SaisiePrenomOK && !SaisieAgeOK)
    } // Fin du while


    if (SaisieOK)
    {
      // Si ChampRecherche == 1 => Recherche par nom
      // Si ChampRecherche == 2 => Recherche par prénom
      // Si ChampRecherche == 3 => Recherche par Age => La Valeur Numérique doit être indiquée
      NbOccurrences = RechercheMultiOccurrences(ChaineRecherche, TabIndicesRecherche, ChampRecherche, AgeRecherche);

      if (NbOccurrences == 0)
      {
        SupprInitialeFenetre=1;
        /* Création ou mise à jour de la sous-fenêtre des traitements */
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
        nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
        ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
        colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
        sprintf(libelle_fenetre,"   Aucun élève   ");
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

        switch(ChampRecherche)
        {
         case 1 :  sprintf(texte,"Aucun élève avec un nom commençant par %s n'a été trouvé !",ChaineRecherche);
                   break ;
         case 2 :  sprintf(texte,"Aucun élève avec un prénom commençant par %s n'a été trouvé !",ChaineRecherche);
                   break ;
         case 3 :  sprintf(texte,"Aucun élève avec un age de %d ans n'a été trouvé !",AgeRecherche);
                   break ;
        }
        Affiche_Element_Ligne_Traitement(1,texte,LIG_MSG,COL_MSG);
        wrefresh(Fenetre_de_Traitement_1);
      }
      else
      {
       for (i = 0 ; i < NbOccurrences ; i++)
       {
          numero = TabIndicesRecherche[i] ;
          TabListeElevesTrouves[i]   = tabeleves[numero] ;
       }
       switch(ChampRecherche)
       {
         case 1 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un nom commençant par %s  ",NbOccurrences,ChaineRecherche);
                   break ;
         case 2 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un prénom commençant par %s  ",NbOccurrences,ChaineRecherche);
                   break ;
         case 3 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un age de %d ans  ",NbOccurrences,AgeRecherche);
                   break ;
       }
     
       Affichage_Liste_Eleves(TabListeElevesTrouves,NbOccurrences,TitreFenetre,NbLignesLibresFindePage,&NumDLigneAffichee) ;

       /* Création ou mise à jour de la sous-fenêtre des traitements */
       Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
       Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
       Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
       Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

       sprintf(libelle_fenetre,"%s D'UN ÉLÈVE",texte_titre_action);
       Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

       SupprInitialeFenetre=1;
       /* Création ou mise à jour de la sous-fenêtre des traitements */
       nblignes    = (2*LIG_INV)+1 ; // Pour 1 item saisi
       nbcolonnes  = NB_COLONNES_TRAITEMENT          ;
       ligne_deb   = NumDLigneAffichee               ;
       colonne_deb = COLONNE_DEBUT_TRAITEMENT        ;

       sprintf(libelle_fenetre,"   Saisie du numéro de l'élève   ");
       Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
       NumEleve=0;
       sprintf(texte,"Numéro de l'élève à %s :                               (ENTER pour annuler la saisie )",texte_action_1);
       mvwprintw(Fenetre_de_Traitement_2,LIG_INV,COL_INV,texte); 
       sprintf(texte,"Numéro de l'élève à %s : ",texte_action_1);
       
       touchwin(stdscr);            
       refresh();      
       
       Saisie_Entier_dans_Fenetre(Fenetre_de_Traitement_2,LIG_INV,COL_INV,texte,&NumEleve) ;
       
       if (NumEleve<=0)
       {
         SupprInitialeFenetre=1;
         nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
         sprintf(libelle_fenetre,"   Saisie du numéro de l'élève   ");
         Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

         Affiche_Element_Ligne_Traitement(2,"Saisie annulée",LIG_MSG,COL_MSG);
         wrefresh(Fenetre_de_Traitement_1);
       }
       else if (NumEleve>NbOccurrences)
       {
         SupprInitialeFenetre=1;
         nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
         sprintf(libelle_fenetre,"   Saisie du numéro de l'élève   ");
         Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

         sprintf(texte,"Le numéro %d est supérieur au numéro %d du dernier élève trouvé",NumEleve,NbOccurrences);
         Affiche_Element_Ligne_Traitement(2,texte,LIG_MSG,COL_MSG);
         wrefresh(Fenetre_de_Traitement_2);
       }
       else // Le numéro est valide
       {
         /* On récupère l'indice de cet élève dans le tableau tabeleves */
         numero = TabIndicesRecherche[NumEleve-1] ;
         /* On récupère l'élève */
         eleve = tabeleves[numero];
         /* On sauvegarde les valeusr des champs avant modification */
         eleve_sauve = eleve ;

         if (action == ACTION_SUPPRESSION)
         {
           SupprInitialeFenetre=1; 
           nblignes    = (2*LIG_INV)+4 ; // Pour 4 items affichés ou saisis
           sprintf(libelle_fenetre,"   Confirmation de la suppression de l'élève numéro %d   ",NumEleve);
           Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

           /* --- Affichage des différents champs comme masque de saisie --- */
           sprintf(texteN,"Nom    : %-*s",T_MAX_NOM,eleve.nom);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+0,COL_INV,texteN);
           sprintf(texteP,"Prénom : %-*s",T_MAX_NOM,eleve.prenom);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+1,COL_INV,texteP);   
           sprintf(texteA,"Age    : %-*d",T_MAX_NOM,eleve.age);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+2,COL_INV,texteA);   
           wrefresh(Fenetre_de_Traitement_2);
           
           sprintf(texte,"Voulez-vous %s cet élève (o/n) : ",texte_action_1);
           Saisie_Caractere_dans_Fenetre(Fenetre_de_Traitement_2,LIG_INV+3,COL_INV,texte,reponse) ;
           normalise_chaine(reponse) ;

           if (reponse[0] == 'O') /* On effectue la suppression */
           {
             for (i = numero ; i < nbeleves-1 ; i++)
             {
               tabeleves[i] = tabeleves[i+1] ;
             }
             nbeleves--;

             SupprInitialeFenetre=1; 
             nblignes    = (2*LIG_MSG)+3 ; // Pour 3 items affichés
             sprintf(libelle_fenetre,"   L'élève numéro %d à été %s   ",NumEleve,texte_action_3);
             Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

             /* --- Affichage des différents champs comme masque de saisie --- */
             sprintf(texteN,"Nom    : %-*s",T_MAX_NOM,eleve.nom);
             mvwprintw(Fenetre_de_Traitement_2,LIG_MSG+0,COL_MSG,texteN);
             sprintf(texteP,"Prénom : %-*s",T_MAX_NOM,eleve.prenom);
             mvwprintw(Fenetre_de_Traitement_2,LIG_MSG+1,COL_MSG,texteP);   
             sprintf(texteA,"Age    : %-*d",T_MAX_NOM,eleve.age);
             mvwprintw(Fenetre_de_Traitement_2,LIG_MSG+2,COL_MSG,texteA);   
             wrefresh(Fenetre_de_Traitement_2);

             a_sauvegarder = 1 ;

           }
           else
           {
             SupprInitialeFenetre=1;
             nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
             sprintf(libelle_fenetre,"   Aucune %s   ",texte_action_2);
             Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

             sprintf(texte,"Aucun élève n'a été %s",texte_action_3);
             Affiche_Element_Ligne_Traitement(2,texte,LIG_MSG,COL_MSG);
             wrefresh(Fenetre_de_Traitement_2);

             a_sauvegarder = 0 ;

           }
         }
         else /* Cas de la modification */
         {
           SupprInitialeFenetre=1; 
           nblignes    = (2*LIG_INV)+3 ; // Pour 3 items saisis
           sprintf(libelle_fenetre,"   Nouvelles valeurs de l'élève (ENTER pour laisser les valeurs inchangées)   ");
           Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

           /* --- Affichage des différents champs comme masque de saisie --- */
           sprintf(texteN,"Nom actuel    : %-*s     Nouveau nom    : ",T_MAX_NOM,eleve.nom);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+0,COL_INV,texteN);
           sprintf(texteP,"Prénom actuel : %-*s     Nouveau prénom : ",T_MAX_NOM,eleve.prenom);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+1,COL_INV,texteP);   
           sprintf(texteA,"Age actuel    : %-*d     Nouvel age     : ",T_MAX_NOM,eleve.age);
           mvwprintw(Fenetre_de_Traitement_2,LIG_INV+2,COL_INV,texteA);   
           wrefresh(Fenetre_de_Traitement_2);

           /* --- Saisie du nom --- */
           Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_2,LIG_INV+0,COL_INV,texteN,eleve.nom) ;
           if (strcmp(eleve.nom,"") != 0 )
           {
             normalise_chaine(eleve.nom) ;
             if (verif_chaine_dans_alphabet(eleve.nom,alphabet_nom_prenom))
             {
               /* --- Saisie du prénom --- */
               Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_2,LIG_INV+1,COL_INV,texteP,eleve.prenom) ;
               if (strcmp(eleve.prenom,"") != 0 )
               {
                 normalise_chaine(eleve.prenom) ;
                 if (verif_chaine_dans_alphabet(eleve.prenom,alphabet_nom_prenom))
                 {
                   /* --- Saisie de l'age --- */
                   Saisie_Entier_dans_Fenetre(Fenetre_de_Traitement_2,LIG_INV+2,COL_INV,texteA,&eleve.age) ;
                   sprintf(chage,"%d",eleve.age);
                   if ( (eleve.age != 0 ) && (verif_chaine_dans_alphabet(chage,alphabet_age)) )
                   {
                     ChampsModifies= (strcmp(eleve.nom,eleve_sauve.nom) != 0) || (strcmp(eleve.prenom,eleve_sauve.prenom) != 0) || (eleve.age != eleve_sauve.age) ;
                     /* On met à jour le tableau des élèves */
                     tabeleves[numero] = eleve;
                     /* On met à jour le tableau résultat de la recherche précédente */
                     TabListeElevesTrouves[NumEleve-1] = eleve ;
                   }
                   if (ChampsModifies) a_sauvegarder = 1  ; 
                 }  
               }
             }
           }  // Fin du if (strcmp(eleve.nom,"") != 0 )
           if ((strcmp(eleve.nom,"") == 0 ) || (!verif_chaine_dans_alphabet(eleve.nom,alphabet_nom_prenom)) )
           {
             Affiche_Texte_Barre_des_Messages("Le format du nom est erroné", COUL_PAIR_ERREUR);
           }
           else if ((strcmp(eleve.prenom,"") == 0 ) || (!verif_chaine_dans_alphabet(eleve.prenom,alphabet_nom_prenom)) )
           {
             Affiche_Texte_Barre_des_Messages("Le format du prénom est erroné", COUL_PAIR_ERREUR);
           }
           else if ( (eleve.age == 0 ) || (!verif_chaine_dans_alphabet(chage,alphabet_age)) )
           {
             Affiche_Texte_Barre_des_Messages("Le format de l'âge est erroné", COUL_PAIR_ERREUR);  
           }
           else if (! ChampsModifies)
           {
             SupprInitialeFenetre=1;
             nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
             sprintf(libelle_fenetre,"   Aucune %s de l'élève   ",texte_action_2);
             Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

             sprintf(texte,"Aucun champ n'a été %s",texte_action_3);
             Affiche_Element_Ligne_Traitement(2,texte,LIG_MSG,COL_MSG);
             wrefresh(Fenetre_de_Traitement_2);
           }
           else
           {
             /* On affiche une fenêtre de confirmation de la modification */
             SupprInitialeFenetre=1;
             nblignes    = (2*LIG_INV)+3 ; // Pour 3 items affichés sou la même forme que la saisie
             sprintf(libelle_fenetre,"   Elève numéro %d %s   ",NumEleve,texte_action_3);
             Creation_MiseAJour_Fenetre_de_Traitement(2,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

             sprintf(texteN,"Acien nom     : %-*s -> Nouveau nom    : %-*s",T_MAX_NOM,eleve_sauve.nom,T_MAX_NOM,eleve.nom)      ;
             mvwprintw(Fenetre_de_Traitement_2,LIG_INV+0,COL_INV,texteN)               ;
             sprintf(texteP,"Ancien prénom : %-*s -> Nouveau prénom : %-*s",T_MAX_NOM,eleve_sauve.prenom,T_MAX_NOM,eleve.prenom);
             mvwprintw(Fenetre_de_Traitement_2,LIG_INV+1,COL_INV,texteP)               ;   
             sprintf(texteA,"Ancien age    : %-*d -> Nouvel age     : %-*d",T_MAX_NOM,eleve_sauve.age,T_MAX_NOM,eleve.age)      ;
             mvwprintw(Fenetre_de_Traitement_2,LIG_INV+2,COL_INV,texteA)               ;   
             wrefresh(Fenetre_de_Traitement_2);     
           }
         }

       }
      }
    }     
  }
}
// ======================================
// --- Suppression de tous les élèves ---
// ======================================
void Supprime_Tous_Les_Eleves()
{
  int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
  int SupprInitialeFenetre = 1;
  char libelle_fenetre[100], reponse[10];

  if (nbeleves == 0)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,"SUPPRESSION DE TOUS LES ÉLÈVES");

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève à supprimer",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,"SUPPRESSION DE TOUS LES ÉLÈVES");

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;

    sprintf(libelle_fenetre,"   Confirmation de la suppression de tous les élèves   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

    Saisie_Caractere_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Voulez-vous supprimer tous les élèves (o/n) : ",reponse) ;
    normalise_chaine(reponse) ;

    if (reponse[0] == 'O') /* On effectue la suppression */
    {
      nbeleves = 0 ;
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
      sprintf(libelle_fenetre,"   Suppression de tous les élèves   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

      /* --- Affichage des différents champs comme masque de saisie --- */
      mvwprintw(Fenetre_de_Traitement_1,LIG_MSG,COL_MSG,"Tous les élèves ont été supprimés");
      wrefresh(Fenetre_de_Traitement_1);

      a_sauvegarder = 1 ;

    }
    else
    {
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,"   Aucune suppression   ");
      mvwprintw(Fenetre_de_Traitement_1,LIG_MSG,COL_MSG,"Aucun élève n'a été supprimé");
      wrefresh(Fenetre_de_Traitement_1);

      a_sauvegarder = 0 ;
    }
  }
}
// =========================================
// --- Sauvegarde de la liste des élèves ---
// =========================================
int Sauvegarde_Liste_Eleves(int TypeEnr)
{
  FILE *f1                          ;
  char *ch_nom, *ch_prenom ;
  struct etudiant eleve ;
  int i ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
  int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
  char libelle_fenetre[200], texte_message[200];
  int AffichageMenuImmediat=0;
  int SupprInitialeFenetre=1;
  char FASauvegarder[T_MAX_NOMFICHIER] ;

  if (TypeEnr == T_ENR_MEME_FICHIER) // Cas du menu Enregistrer => avec le même nom que le chargement)
  {
    if (strcmp(NomFichier,"")==0) TypeEnr=T_ENR_NOUV_FICHIER ; // On demande le nom la première fois
  }

  /* Création ou mise à jour de la sous-fenêtre des traitements */
  Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
  Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
  Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
  Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

  strcpy(libelle_fenetre,"SAUVEGARDE DE LA LISTE DES ÉLÈVES");
  Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);
  if (nbeleves == 0)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = nbeleves+5;
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève à sauvegarder",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Sauvegarde de %d élève(s)   ",nbeleves);
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

    if (TypeEnr == T_ENR_NOUV_FICHIER) // On demande le nom du fichier
    {
      /* --- Affichage du nom du fichier comme masque de saisie --- */
      mvwprintw(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Nom du fichier de sauvegarde :                        (ENTER sauvegarde dans le fichier par défaut ou termine la saisie)");
      Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Nom du fichier de sauvegarde : ",NomFichier) ;
    }
    if ((strcmp(NomFichier,"")==0) && (TypeEnr == T_ENR_NOUV_FICHIER))
    {
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
   
      sprintf(libelle_fenetre,"   Aucune sauvegarde   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
      sprintf(texte_message,"Aucun nom de fichier saisi");
      Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

      wrefresh(Fenetre_de_Traitement_1);
    }
    else
    {
      /* On ajoute l'extension .txt si aucune extension n'est indiquée */
      if (strstr(NomFichier,".") == NULL) strcat(NomFichier,".txt");

      sprintf(FASauvegarder,"%s/%s",REPDATA,NomFichier);
      f1=fopen(FASauvegarder,"w");
      if (f1 == NULL) // Problème d'ouverture du fichier
      {
        /* Création ou mise à jour de la sous-fenêtre des traitements */
        SupprInitialeFenetre=1;
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    
        sprintf(libelle_fenetre,"   Aucune sauvegarde   ");
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
        sprintf(texte_message,"Problème d'écriture du fichier : %s dans le répertoire %s",NomFichier,REPDATA);
        Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

        wrefresh(Fenetre_de_Traitement_1);
      }
      else
      {
        for (i = 0 ; i<nbeleves ; i++)
        {
          eleve = tabeleves[i];
          /* On remplace les espaces par des soulignés dans les châines AVANT l'écriture */
          ch_nom    = str_replace_all(eleve.nom," ","_")    ;
          ch_prenom = str_replace_all(eleve.prenom," ","_") ;
          fprintf(f1,"%s %s %d\n",eleve.nom,eleve.prenom,eleve.age);
        }
        fclose(f1);
        /* On affiche un message d'information dans la fenêtre de traitement */
        /* Création ou mise à jour de la sous-fenêtre des traitements */
        SupprInitialeFenetre=1;
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
        sprintf(libelle_fenetre,"   Sauvegarde de %d élève(s)   ",nbeleves);
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
        sprintf(texte_message,"Sauvegarde de %d élève(s) dans le fichier : %s du répertoire %s",nbeleves,NomFichier,REPDATA);
        Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

        wrefresh(Fenetre_de_Traitement_1);
      }
     a_sauvegarder = 0 ;
   }
  } 
  return AffichageMenuImmediat;
}
// =========================================
// --- Chargement de la liste des élèves ---
// =========================================
int Chargement_Liste_Eleves(char FichierACharger[])
{
    FILE *f1                             ;
    char *NomFichierTmp, FACharger[T_MAX_NOMFICHIER]   ;
    char *ch_nom, *ch_prenom             ;
    struct etudiant eleve                ;
    int i=0, retour ;
    int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
    int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
    char libelle_fenetre[200], texte_message[200];
    int AffichageMenuImmediat=0;
    int SupprInitialeFenetre=1;

    char chage[10];
    int LectureOK=0, NomValide=0,PrenomValide=0,AgeValide=0;
    int nberreurschargement=0;
    struct etudiant TabElevesErreurs[MAX_ELEVES] ;

    /* On vérifie si il y a une sauvegarde a faire avant de charger le nouveau fichier en mémoire */
    verif_sauvegarde() ;

    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"CHARGEMENT D'UNE LISTE D'ÉLÈVES");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    NomFichier[0]='\0'    ;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_INV)+1 ; // Pour 1 item saisi
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;

    /* On conserve la nom du fichier à charger dans une variable locale */
    strcpy(FACharger,FichierACharger);
    
    if (strcmp(FACharger,"") != 0)
    {
      /* On retire le répertoire du nom pour avoir la même forme que la saisie */
      NomFichierTmp = strstr(FACharger,"/");
      NomFichierTmp++;
      /* On initialise NomFichier */
      strcpy(NomFichier,NomFichierTmp);
    }
    else
    {
      sprintf(libelle_fenetre,"   Chargement d'élève(s)   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

      /* --- Affichage du nom du fichier comme masque de saisie --- */
      mvwprintw(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Nom du fichier à ouvrir :                               (ENTER pour terminer la saisie )");
      Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Nom du fichier à ouvrir : ",NomFichier) ;
    }
    if (strcmp(NomFichier,"")==0)
    {
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    
      sprintf(libelle_fenetre,"   Aucun chargement   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
      sprintf(texte_message,"Aucun nom de fichier saisi");
      Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

      wrefresh(Fenetre_de_Traitement_1);
    }
    else
    {
      /* On ajoute l'extension .txt si aucune extension n'est indiquée */
      if (strstr(NomFichier,".")==NULL) strcat(NomFichier,".txt");
      
      if (strcmp(FACharger,"")==0)
      {
        sprintf(FACharger,"%s/%s",REPDATA,NomFichier); /* On Construit le chemin du fichier à lire */
      }
      f1=fopen(FACharger,"r");
      if (f1 == NULL) // Problème d'ouverture du fichier
      {
        /* Création ou mise à jour de la sous-fenêtre des traitements */
        SupprInitialeFenetre=1;
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    
        sprintf(libelle_fenetre,"   Aucun chargement   ");
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
        sprintf(texte_message,"Problème de lecture du fichier : %s",NomFichier);
        Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

        wrefresh(Fenetre_de_Traitement_1);
      }
      else
      {
        while ( ! feof(f1) )
        {
          LectureOK=0;

          strcpy(eleve.nom,"")    ;
          strcpy(eleve.prenom,"") ;
          eleve.age = 0           ;

          retour = fscanf(f1,"%s %s %s", eleve.nom, eleve.prenom, chage);
          /* Conversion de la chaine en entier */
          eleve.age = atoi(chage);
          
          if (retour != EOF)
          {
            /* On remplace les soulignés par des espaces */
            ch_nom    = str_replace_all(eleve.nom,"_"," ")    ;
            ch_prenom = str_replace_all(eleve.prenom,"_"," ") ;

            /* On normalise les noms et prénoms */
            normalise_chaine(eleve.nom);
            normalise_chaine(eleve.prenom);

            /* On vérifie la validité des noms, prénoms et age */            
            NomValide    = verif_chaine_dans_alphabet(eleve.nom,alphabet_nom_prenom)    ;
            PrenomValide = verif_chaine_dans_alphabet(eleve.prenom,alphabet_nom_prenom) ;
            sprintf(chage,"%d",eleve.age);
            AgeValide = (eleve.age != 0 ) && (verif_chaine_dans_alphabet(chage,alphabet_age)) ;
            
            LectureOK = NomValide && PrenomValide && AgeValide ;
 
            if (LectureOK) /* Tous les champs sont valides */
            {
              tabeleves[i++] = eleve ;
            }
            else /* un des champs comporte une erreur => on conserve l'élève pour affichage ultérieur */
            {
              TabElevesErreurs[nberreurschargement++] = eleve ;
            }
          }
        }
        fclose(f1);
        nbeleves = i ;

        SupprInitialeFenetre=1;
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
        if (nberreurschargement != 0)
        {
          nblignes+=nberreurschargement;
          nblignes++;
        }
        sprintf(libelle_fenetre,"   Chargement de %d élève(s)   ",nbeleves);
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
        sprintf(texte_message,"Chargement de %d élève(s) à partir du fichier : %s",nbeleves,NomFichier);
        Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

        if (nberreurschargement != 0)
        {
          sprintf(libelle_fenetre,"   %d élève(s) avec un format erroné pour l'un des champs",nberreurschargement);
          Affiche_Element_Ligne_Traitement(1,libelle_fenetre,3,4);
          for (i=0 ; i<nberreurschargement ; i++)
          {
              eleve=TabElevesErreurs[i] ;
              sprintf(texte_message,"   -> Erreur pour : %s\t%s\t%d",eleve.nom,eleve.prenom,eleve.age);
              Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG+2+i,COL_MSG);
          } 
        }
        wrefresh(Fenetre_de_Traitement_1);
      }
    }
    return AffichageMenuImmediat;
}
// =========================================
// --- Chargement de la liste des élèves ---
// =========================================
int Chargement_Par_Selection()
{
    int AffichageMenuImmediat=0;
    int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
    int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
    char libelle_fenetre[200], texte_message[200];
    int SupprInitialeFenetre=1;
    int Element_selectionne=0;
    char FichierACharger[100]="";
    int code_retour = 0 ;
    int MenuCourant=1;
    WINDOW **Elements_des_Objets=NULL;


    /* On vérifie si il y a une sauvegarde a faire avant de charger le nouveau fichier en mémoire */
    verif_sauvegarde() ;

    sprintf(texte_message,"Déplacez vous avec les flèches. Appuyer sur ENTER pour sélectionner le fichier");
    Affiche_Texte_Barre_des_Messages(texte_message, COUL_PAIR_INFO);


    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"SÉLECTION D'UN FICHIER");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = NB_LIGNES_TRAITEMENT-5 ;
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Sélectionnez un fichier à ouvrir dans la liste du répertoire %s ci-dessous   ",REPDATA);
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

    /* On récupère la liste des fichiers .txt ou .data du répertoire DATA */
    NbObjets=0;
    code_retour = Recupere_Objet_Info(REPDATA);

    if (code_retour != 0)
    {
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    
      sprintf(libelle_fenetre,"   Aucun chargement   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
      sprintf(texte_message,"Erreur d'accès au répertoire %s : %s",REPDATA,strerror(code_retour));
      Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

      wrefresh(Fenetre_de_Traitement_1);
    }
    else if (NbObjets == 0)
    {
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    
      sprintf(libelle_fenetre,"   Aucun chargement   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
      sprintf(texte_message,"Aucun fichier trouvé dans le répertoire %s",REPDATA);
      Affiche_Element_Ligne_Traitement(1,texte_message,LIG_MSG,COL_MSG);

      wrefresh(Fenetre_de_Traitement_1);
    }
    else
    {
      Elements_des_Objets   = Dessine_Liste_Objets(ligne_deb,colonne_deb)  ;
      Element_selectionne   = Defilement_Liste_Objets(Elements_des_Objets,NbObjets,0);            

      strcpy(FichierACharger,TabListeObjet[Element_selectionne]);

      AffichageMenuImmediat = Chargement_Liste_Eleves(FichierACharger);
    }
    touchwin(stdscr);            
    refresh();      

    return AffichageMenuImmediat;
}
// =============================================
// --- Vérification d'une sauvegarde à faire ---
// =============================================
void verif_sauvegarde()
{
  char reponse[10];
  int SupprInitialeFenetre ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb;
  int nblignes, nbcolonnes, ligne_deb, colonne_deb;
  char libelle_fenetre[100] ;
  int AffichageMenuImmediat ;

  if (nbeleves != 0)
  {  
    if (a_sauvegarder)
    { 
      if (Fenetre_de_Traitement_1 != NULL) werase(Fenetre_de_Traitement_1);
      if (Fenetre_de_Traitement_2 != NULL) werase(Fenetre_de_Traitement_2);
      if (Fenetre_de_Traitement_1 != NULL) wrefresh(Fenetre_de_Traitement_1);
      if (Fenetre_de_Traitement_2 != NULL) wrefresh(Fenetre_de_Traitement_2);
    
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
      Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
      Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
      Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

      strcpy(libelle_fenetre,"VÉRIFICATION D'UNE SAUVEGARDE À FAIRE");
      Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

      /* Création ou mise à jour de la sous-fenêtre des traitements */
      SupprInitialeFenetre=1;
      nblignes    = (2*LIG_INV)+2 ; // Pour 2 items saisis
      nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
      ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
      colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
      sprintf(libelle_fenetre,"   Sauvegarde à faire   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

      /* --- Affichage du nom du fichier comme masque de saisie --- */
      mvwprintw(Fenetre_de_Traitement_1, LIG_INV+0,COL_INV,"Des données ont été modifiées");
      Saisie_Caractere_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV+1,COL_INV,"Voulez-vous faire une sauvegarde (o/n) : ",reponse) ;
      normalise_chaine(reponse) ;

      if (reponse[0] == 'O')
      {
        AffichageMenuImmediat = Sauvegarde_Liste_Eleves(T_ENR_MEME_FICHIER)  ;
      }
      else
      {
        a_sauvegarder = 0 ;
      }
    }
  }  
}
// ============================================
// --- Recherche multi-occurence d'un élève ---
// ============================================
int RechercheMultiOccurrences(char prefixerech[T_MAX_NOM], int tabres[], int NumChampRech, int ValNum)
{
  struct etudiant eleve ;
  int i, numrech = NON_TROUVE, nbocc=0 ;
  int taille_prefixe, trouve = 0 ;
  
  for (i = 0 ; i<nbeleves ; i++)
  {
     eleve = tabeleves[i];
     // Si NumChampRech == 1 => Recherche par nom
     if (NumChampRech == 1)
     {
        taille_prefixe = strlen(prefixerech) ;
        trouve = (strncmp(eleve.nom,prefixerech,taille_prefixe) == 0) ;
     }
     else if (NumChampRech == 2)
     {
        taille_prefixe = strlen(prefixerech) ;
        trouve = (strncmp(eleve.prenom,prefixerech,taille_prefixe) == 0) ;
     }
     if (NumChampRech == 3)
     {
        trouve = (eleve.age == ValNum) ;
     }
       
     if (trouve)
     {
       tabres[nbocc++] = i ;
     }
  }
  return nbocc ;
}
// =========================================
// --- Recherche d'un élève ---
// =========================================
void Recherche_Eleve_Sur_Un_Champ(int ChampRecherche)
{
  struct etudiant TabListeElevesTrouves[MAX_ELEVES] ;
  int TabIndicesRecherche[MAX_ELEVES]     ;
  int SupprInitialeFenetre, numero ;
  int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
  char libelle_fenetre[100], ChaineRecherche[100]="", texte[100], TitreFenetre[100];
  int NbOccurrences,i, AgeRecherche=0 ;
  int SaisieOK=0, SaisieVide=0, SaisieValide=1;
  int NumDLigneAffichee=0 ;
  int continuer_saisie = 1 ;
   
  if (nbeleves == 0)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"RECHERCHE D'UN ÉLÈVE");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = 5 ; // Pour 1 item affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève à rechercher",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"RECHERCHE D'UN ÉLÈVE");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    while (continuer_saisie)
    {
      continuer_saisie = 0 ;
      SaisieValide     = 1 ;
      SaisieVide       = 0 ;

      if (Barre_des_Messages != NULL)
      {
        werase(Barre_des_Messages);
        wrefresh(Barre_des_Messages);
      }
    
      SupprInitialeFenetre=1;
      /* Création ou mise à jour de la sous-fenêtre des traitements */
      nblignes    = (2*LIG_INV)+1 ; // Pour 1 item saisi
      nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
      ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
      colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
      sprintf(libelle_fenetre,"   Recherche d'un élève   ");
      Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
      SupprInitialeFenetre=1;

      switch(ChampRecherche)
      {
        case 1 :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Premiers caractères du nom : ",ChaineRecherche) ;
                  normalise_chaine(ChaineRecherche) ;
                  break ;
        case 2 :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Premiers caractères du prénom : ",ChaineRecherche) ;
                  normalise_chaine(ChaineRecherche) ;
                  break ;
        case 3 :  Saisie_Chaine_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Age : ",ChaineRecherche) ;
                  break ;
      }
      SaisieVide    = (strcmp(ChaineRecherche,"")==0);
      if (ChampRecherche==3) 
         AgeRecherche   = atoi(ChaineRecherche);

      if ((ChampRecherche==1) || (ChampRecherche==2))
      {
        SaisieValide    = verif_chaine_dans_alphabet(ChaineRecherche,alphabet_nom_prenom) ;
      }
      else
      {
        SaisieValide    = verif_chaine_dans_alphabet(ChaineRecherche,alphabet_age)  ;
      }

      SaisieOK    = (!SaisieVide) && (SaisieValide)       ;
      
      if (!SaisieOK)
      {
        if (SaisieVide)
        {
          continuer_saisie = 0; 
        
          /* Création ou mise à jour de la sous-fenêtre des traitements */
          Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
          Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
          Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
          Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

          strcpy(libelle_fenetre,"RECHERCHE D'UN ÉLÈVE");
          Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

          SupprInitialeFenetre=1;
          /* Création ou mise à jour de la sous-fenêtre des traitements */
          nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiche
          nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
          ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
          colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
          sprintf(libelle_fenetre,"   Aucun élève   ");
          Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
          Affiche_Element_Ligne_Traitement(1,"Aucune saisie n'a été effectuée",LIG_MSG,COL_MSG);
          wrefresh(Fenetre_de_Traitement_1);
        }
        else if (!SaisieValide)
        { 
          continuer_saisie = 1; 
          strcpy(ChaineRecherche,"");
          AgeRecherche=0;
            
          if (ChampRecherche==1)
          {
            Affiche_Texte_Barre_des_Messages("Le format du nom est erroné", COUL_PAIR_ERREUR);
          }
          else if (ChampRecherche==2)
          {
            Affiche_Texte_Barre_des_Messages("Le format du prénom est erroné", COUL_PAIR_ERREUR);
          }
          else if (ChampRecherche==3)
          {
            Affiche_Texte_Barre_des_Messages("Le format de l'âge est erroné", COUL_PAIR_ERREUR);  
          } 
          getch();
        }
      }
    }
    
    if (SaisieOK)
    {
      // Si ChampRecherche == 1 => Recherche par nom
      // Si ChampRecherche == 2 => Recherche par prénom
      // Si ChampRecherche == 3 => Recherche par Age => La Valeur Numérique doit être indiquée
      NbOccurrences = RechercheMultiOccurrences(ChaineRecherche, TabIndicesRecherche, ChampRecherche, AgeRecherche);
    
      if (NbOccurrences == 0)
      {
        SupprInitialeFenetre=1;
        /* Création ou mise à jour de la sous-fenêtre des traitements */
        nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiche
        nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
        ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
        colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
        sprintf(libelle_fenetre,"   Aucun élève   ");
        Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

        switch(ChampRecherche)
        {
         case 1 :  sprintf(texte,"Aucun élève avec un nom commençant par %s n'a été trouvé !",ChaineRecherche);
                   break ;
         case 2 :  sprintf(texte,"Aucun élève avec un prénom commençant par %s n'a été trouvé !",ChaineRecherche);
                   break ;
         case 3 :  sprintf(texte,"Aucun élève avec un age de %d ans n'a été trouvé !",AgeRecherche);
                   break ;
        }
        Affiche_Element_Ligne_Traitement(1,texte,LIG_MSG,COL_MSG);
        wrefresh(Fenetre_de_Traitement_1);
      }
      else
      {
        for (i = 0 ; i < NbOccurrences ; i++)
        {
          numero = TabIndicesRecherche[i] ;
          TabListeElevesTrouves[i]   = tabeleves[numero] ;
        }
        switch(ChampRecherche)
        {
         case 1 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un nom commençant par %s  ",NbOccurrences,ChaineRecherche);
                   break ;
         case 2 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un prénom commençant par %s  ",NbOccurrences,ChaineRecherche);
                   break ;
         case 3 :  sprintf(TitreFenetre,"  %d élèves() trouvés avec un age de %d ans  ",NbOccurrences,AgeRecherche);
                   break ;
        }
     
        Affichage_Liste_Eleves(TabListeElevesTrouves,NbOccurrences,TitreFenetre,0,&NumDLigneAffichee) ;
        
      } // Fin du if (NbOccurrences == 0)
    } // FIN du  if ((((ChampRecherche==1) || (ChampRecherche==2)) &&(strcmp(ChaineRecherche,"")==0)) ...
  } // Fin du if (nbeleves == 0)
}
// =========================================
// --- Tri d'une liste d'élèves ---
// =========================================
void Tri_Liste_Eleves_Sur_Des_Champs(int ChampTri)
{
  int i,j ;
  struct etudiant eleve ;
  int nblignes, nbcolonnes, ligne_deb, colonne_deb ;
  int Tnblignes, Tnbcolonnes, Tligne_deb, Tcolonne_deb ;
  char libelle_fenetre[100], texte[100] ;
  int a_inverser = 0, SupprInitialeFenetre = 1 ;
  char ClefTri1[200]="", ClefTri2[200]="", tmpchaine[200]="", OrdreTri[100]="C";;
  
  if (nbeleves == 0)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"TRI DE LA LISTE D'ÉLÈVES");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiche
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Aucun élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Aucun élève à trier",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else if (nbeleves == 1)
  {
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"TRI DE LA LISTE D'ÉLÈVES");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiche
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Un seul élève   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
  
    Affiche_Element_Ligne_Traitement(1,"Pas de tri effectué, il n'y a qu'un seul élève",LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);
  }
  else
  {
    /* On demande si l'odre est croissant ou décroissant */
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"TRI DE LA LISTE D'ÉLÈVES");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_INV)+1 ; // Pour 1 item saisi
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;

    sprintf(libelle_fenetre,"   Ordre du tri   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);
    SupprInitialeFenetre=1;
    
    /* --- Affichage du masque de saisie --- */
    mvwprintw(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Tri par ordre croissant (c) ou décroissant (d) :         (ENTER = croissant par défaut)");
   
    Saisie_Caractere_dans_Fenetre(Fenetre_de_Traitement_1,LIG_INV,COL_INV,"Tri par odre croissant (c) ou décroissant (d) : ",OrdreTri) ;
    normalise_chaine(OrdreTri) ;
  
    /* Si la saisie est vide, l'odre est par défaut croissant */
    if (strcmp(OrdreTri,"") ==0) strcpy(OrdreTri,"C");
    
    /* ------------ */  
    /* Tri à bulles */
    /* ------------ */
    /* Boucle principale */  
    for (i=nbeleves-1 ; i>0 ; i-- )
    {
       /* Boucle d'inversion */
       for ( j=1 ; j<=i ; j++ )
       {
          strcpy(ClefTri1,"");
          strcpy(ClefTri2,"");

          /* On sélectionne la clef de tri */          
          if (ChampTri == 1) // Tri par le champ nom
          {
            strcpy(ClefTri1,tabeleves[j-1].nom) ;
            strcpy(ClefTri2,tabeleves[j].nom)   ;
          }
          else if (ChampTri == 2) // Tri par le champ prenom
          {
            strcpy(ClefTri1,tabeleves[j-1].prenom) ;
            strcpy(ClefTri2,tabeleves[j].prenom)   ;
          }
          else if (ChampTri == 3) // Tri par le champ prenom
          {
            sprintf(ClefTri1,"%4d",tabeleves[j-1].age) ;
            sprintf(ClefTri2,"%4d",tabeleves[j].age)   ;
          }
          else if (ChampTri == 12) // Tri par nom et prenom
          {
            strcpy(ClefTri1,tabeleves[j-1].nom)    ;
            strcat(ClefTri1,tabeleves[j-1].prenom) ;

            strcpy(ClefTri2,tabeleves[j].nom)      ;
            strcat(ClefTri2,tabeleves[j].prenom)   ;
          }
          else if (ChampTri == 123) // Tri par nom, prenom et age
          {
            strcpy(ClefTri1,tabeleves[j-1].nom)         ;
            strcat(ClefTri1,tabeleves[j-1].prenom)      ;
            sprintf(tmpchaine,"%4d",tabeleves[j-1].age) ;
            strcat(ClefTri1,tmpchaine)                  ;

            strcpy(ClefTri2,tabeleves[j].nom)           ;
            strcat(ClefTri2,tabeleves[j].prenom)        ;
            sprintf(tmpchaine,"%4d",tabeleves[j].age)   ;
            strcat(ClefTri2,tmpchaine)                  ;
          }
          else
          {
            strcpy(ClefTri1,"") ;
            strcpy(ClefTri2,"") ;
          }
          
          /* On vérifie si il doit y avoir inversion */
          if (strcmp(OrdreTri,"C") !=0) // Par ordre décroissant
             a_inverser = (strcmp(ClefTri1,ClefTri2) < 0);
          else  // Par ordre croissant      
             a_inverser = (strcmp(ClefTri1,ClefTri2) > 0);

          if (a_inverser)
          {
            eleve          = tabeleves[j]   ;
            tabeleves[j]   = tabeleves[j-1] ;
            tabeleves[j-1] = eleve          ;
          }
       }
    }

    /* Création ou mise à jour de la sous-fenêtre des traitements */
    Tnblignes    = NB_LIGNES_TITRE_TRAITEMENT     ;
    Tnbcolonnes  = NB_COLONNES_TITRE_TRAITEMENT   ;
    Tligne_deb   = LIGNE_DEBUT_TITRE_TRAITEMENT   ;
    Tcolonne_deb = COLONNE_DEBUT_TITRE_TRAITEMENT ;

    strcpy(libelle_fenetre,"TRI DE LA LISTE D'ÉLÈVES");
    Affiche_Fenetre_de_Traitement_Titre(Tnblignes,Tnbcolonnes,Tligne_deb,Tcolonne_deb,libelle_fenetre);

    SupprInitialeFenetre=1;
    /* Création ou mise à jour de la sous-fenêtre des traitements */
    nblignes    = (2*LIG_MSG)+1 ; // Pour 1 item affiché
    nbcolonnes  = NB_COLONNES_TRAITEMENT              ;
    ligne_deb   = LIGNE_DEBUT_TRAITEMENT + Tnblignes  ;
    colonne_deb = COLONNE_DEBUT_TRAITEMENT            ;
    
    sprintf(libelle_fenetre,"   Liste triée des élèves   ");
    Creation_MiseAJour_Fenetre_de_Traitement(1,SupprInitialeFenetre,nblignes,nbcolonnes,ligne_deb,colonne_deb,libelle_fenetre);

    if (strcmp(OrdreTri,"C") != 0)
        strcpy(OrdreTri,"décroissant");
    else
        strcpy(OrdreTri,"croissant");

    switch(ChampTri)
    {
      case 1  :  sprintf(texte,"%d élèves ont été triés selon l'ordre alphabétique %s de leur nom.",nbeleves,OrdreTri);
                 break ;
      case 2  :  sprintf(texte,"%d élèves ont été triés selon l'ordre alphabétique %s de leur prénom.",nbeleves,OrdreTri);
                 break ;
      case 3  :  sprintf(texte,"%d élèves ont été triés selon l'ordre %s de leur age.",nbeleves,OrdreTri);
                 break ;
      case 12  : sprintf(texte,"%d élèves ont été triés selon l'ordre %s du nom et du prénom.",nbeleves,OrdreTri);
                 break ;
      case 123 : sprintf(texte,"%d élèves ont été triés selon l'ordre %s du nom, du prénom et de l'âge.",nbeleves,OrdreTri);
                 break ;
   }
    Affiche_Element_Ligne_Traitement(1,texte,LIG_MSG,COL_MSG);
    wrefresh(Fenetre_de_Traitement_1);

    a_sauvegarder = 1 ;
  }  
}
// ==============================
// --- Sous-programmes Outils ---
// ==============================
// --------------------------
void conv_maj(char ch[])
{
  int i, taille ;
  
  taille = strlen(ch);
  for (i=0 ; i< taille ; i++)
  {
    ch[i] = toupper(ch[i]);
  }
}
// --------------------------
void Affiche_Texte_Barre_des_Messages(char texte[], int paire_des_couleurs)
{
  Efface_Fenetre(Barre_des_Messages) ;

  wattron(Barre_des_Messages,COLOR_PAIR(paire_des_couleurs)) ;    
  waddstr(Barre_des_Messages,texte)                          ;    
  wattroff(Barre_des_Messages,COLOR_PAIR(paire_des_couleurs));            

  wrefresh(Barre_des_Messages) ;
}
// --------------------------
void Affiche_Element_Barre_des_Menus(char texte[], int col_position)
{
  wmove(Barre_des_Menus,0,col_position);    
  waddstr(Barre_des_Menus,"Menu ");    
  wattron(Barre_des_Menus,COLOR_PAIR(COUL_PAIR_EN_EVIDENCE));    
  waddstr(Barre_des_Menus,texte);    
  wattroff(Barre_des_Menus,COLOR_PAIR(COUL_PAIR_EN_EVIDENCE));
}
// --------------------------
void Affiche_Element_Ligne_Traitement(int NumFenetre,char texte[], int ligne_position, int col_position)
{
  WINDOW *fenetre ;
  
  if (NumFenetre == 2 )
     fenetre = Fenetre_de_Traitement_2 ;
  else
     fenetre = Fenetre_de_Traitement_1 ;

  wmove(fenetre,ligne_position,col_position);    
  waddstr(fenetre,texte);    
}
// --------------------------
void Saisie_Chaine_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], char ch[])
{
  echo();      /* Active l'écho de la saisie */
  curs_set(1); /* Rend visible le curseur    */
   
  mvwprintw(fenetre, ligne, col,invite);   
  wattron(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));  
  /* On lit tout sauf la fin de ligne => lecture d'une chaîne avec les espaces */
  wscanw(fenetre,"%[^\n]",ch);
  wattroff(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));
  
  noecho()     ;   /* Désactive l'écho de la saisie */
  curs_set(0)  ;   /* Rend invisible le curseur     */
}
// --------------------------
void Saisie_Caractere_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], char ch[])
{
  char lettre ;
  
  echo();      /* Active l'écho de la saisie */
  curs_set(1); /* Rend visible le curseur    */
  mvwprintw(fenetre, ligne, col,invite);   
  wattron(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));  
  /* On lit un seul caractère */
  lettre = wgetch(fenetre) ;
  if (lettre == ENTER)
     strcpy(ch,"");
  else
     sprintf(ch,"%c",lettre);
     
  wattroff(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));
  noecho()     ;   /* Désactive l'écho de la saisie */
  curs_set(0)  ;   /* Rend invisible le curseur     */
  /* On attend DELAI_ATTENTE secondes */
  sleep(DELAI_ATTENTE);
  
}
// --------------------------
void Saisie_Entier_dans_Fenetre(WINDOW *fenetre, int ligne, int col, char invite[], int *pentier)
{
  echo();      /* Active l'écho de la saisie */
  curs_set(1); /* Rend visible le curseur    */

  mvwprintw(fenetre, ligne, col,invite);   
  wattron(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));  
  /* On lit tout sauf la fin de ligne => lecture d'une chaîne avec les espaces */
  wscanw(fenetre,"%d",pentier);
  wattroff(fenetre,COLOR_PAIR(COUL_PAIR_SAISIE));
  
  noecho()     ;   /* Désactive l'écho de la saisie */
  curs_set(0)  ;   /* Rend invisible le curseur    */

}
// --------------------------
void Efface_Fenetre(WINDOW *fenetre)
{
  wbkgd(fenetre,COLOR_PAIR(COUL_PAIR_NORMAL));

  werase(fenetre)   ;       
  wrefresh(fenetre) ;        
}
/* =============================================================================== */
/* Remplace toutes les occurrences de  motif_a_remplacer par motif_de_remplacement */
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
            /* Ajuster la taille pour pouvoir placer motif_de_remplacement */
            memmove(pt_motif_a_remplacer + taille_motif_de_remplacement, pt_motif_a_remplacer + taille_motif_a_remplacer, taille_pt_motif_a_remplacer);
        }
        /* Remplacer par motif_de_remplacement */
        strncpy(pt_motif_a_remplacer, motif_de_remplacement, taille_motif_de_remplacement);
        /* On prépare pour la prochaine itération */
        pt_motif_a_remplacer = strstr(chaine, motif_a_remplacer);
        /* On met a jour la chaine de retour */
        chaine_retour = chaine;
    }

    return chaine_retour;
}
// =================================================
// --- fonction outil de suppression des accents ---
// =================================================
char *supprime_accent(char * chaine)
{
  char * chaine_retour = chaine, *motif_a_remplacer, *motif_de_remplacement ;
  size_t  nb_elements ;
  int i               ;

  /* tableau de tous les caractères accentués à remplacer */
  const char * tab_caracteres_a_remplacer[]     = {"À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "ß", "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ï", "ñ", "ò", "ó", "ô", "õ", "ö", "ø", "ù", "ú", "û", "ü", "ý", "ÿ", "Ā", "ā", "Ă", "ă", "Ą", "ą", "Ć", "ć", "Ĉ", "ĉ", "Ċ", "ċ", "Č", "č", "Ď", "ď", "Đ", "đ", "Ẽ", "ẽ", "Ē", "ē", "Ĕ", "ĕ", "Ė", "ė", "Ę", "ę", "Ě", "ě", "Ĝ", "ĝ", "Ğ", "ğ", "Ġ", "ġ", "Ģ", "ģ", "Ĥ", "ĥ", "Ħ", "ħ", "Ĩ", "ĩ", "Ī", "ī", "Ĭ", "ĭ", "Į", "į", "İ", "ı", "Ĳ", "ĳ", "Ĵ", "ĵ", "Ķ", "ķ", "Ĺ", "ĺ", "Ļ", "ļ", "Ľ", "ľ", "Ŀ", "ŀ", "Ł", "ł", "Ń", "ń", "Ņ", "ņ", "Ň", "ň", "ŉ", "Ō", "ō", "Ŏ", "ŏ", "Ő", "ő", "Œ", "œ", "Ŕ", "ŕ", "Ŗ", "ŗ", "Ř", "ř", "Ś", "ś", "Ŝ", "ŝ", "Ş", "ş", "Š", "š", "Ţ", "ţ", "Ť", "ť", "Ŧ", "ŧ", "Ũ", "ũ", "Ū", "ū", "Ŭ", "ŭ", "Ů", "ů", "Ű", "ű", "Ų", "ų", "Ŵ", "ŵ", "Ŷ", "ŷ", "Ÿ", "ÿ", "Ź", "ź", "Ż", "ż", "Ž", "ž", "ſ", "ƒ", "Ơ", "ơ", "Ư", "ư", "Ǎ", "ǎ", "Ǐ", "ǐ", "Ǒ", "ǒ", "Ǔ", "ǔ", "Ǖ", "ǖ", "Ǘ", "ǘ", "Ǚ", "ǚ", "Ǜ", "ǜ", "Ǻ", "ǻ", "Ǽ", "ǽ", "Ǿ", "ǿ"};
  /* tableau de tous les caractères sans accent de remplacement */
  const char * tab_caracteres_de_remplacement[] = {"A", "A", "A", "A", "A", "A", "AE", "C", "E", "E", "E", "E", "I", "I", "I", "I", "D", "N", "O", "O", "O", "O", "O", "O", "U", "U", "U", "U", "Y", "s", "a", "a", "a", "a", "a", "a", "ae", "c", "e", "e", "e", "e", "i", "i", "i", "i", "n", "o", "o", "o", "o", "o", "o", "u", "u", "u", "u", "y", "y", "A", "a", "A", "a", "A", "a", "C", "c", "C", "c", "C", "c", "C", "c", "D", "d", "D", "d", "E", "e", "E", "e", "E", "e", "E", "e", "E", "e", "E", "e", "G", "g", "G", "g", "G", "g", "G", "g", "H", "h", "H", "h", "I", "i", "I", "i", "I", "i", "I", "i", "I", "i", "IJ", "ij", "J", "j", "K", "k", "L", "l", "L", "l", "L", "l", "L", "l", "l", "l", "N", "n", "N", "n", "N", "n", "n", "O", "o", "O", "o", "O", "o", "OE", "oe", "R", "r", "R", "r", "R", "r", "S", "s", "S", "s", "S", "s", "S", "s", "T", "t", "T", "t", "T", "t", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "W", "w", "Y", "y", "Y", "y", "Z", "z", "Z", "z", "Z", "z", "s", "f", "O", "o", "U", "u", "A", "a", "I", "i", "O", "o", "U", "u", "U", "u", "U", "u", "U", "u", "U", "u", "A", "a", "AE", "ae", "O", "o"};

  nb_elements  = sizeof(tab_caracteres_de_remplacement) / sizeof(*tab_caracteres_de_remplacement) ;
  /* Boucle de traitement de tous les caractères */
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
// ======================================================================
// --- fonction outil de suppression des espaces au début et à la fin ---
// ======================================================================
void trim(char *ch)
{
      char chaine1[200] ;
      int i = 0, j = 0 , k = 0 , taille = 0 ;

      if (strcmp(ch,"") != 0) /* On teste si la chaine n'est pas vide */
      {
         /* --- suppression des espaces en début de chaine --- */
         while (isspace(ch[i++])); /* On passe les espaces du début */
         taille = strlen(ch);
         /* recopie des caractères APRES les espaces */

         for (j=i-1 ; j<taille ; j++) chaine1[k++] = ch[j]; 
         chaine1[k++] = '\0' ; /* On finalise la chaine */
         strcpy(ch,chaine1)  ; /* On recopie la chaine traitée dans ch */
         /* --- suppression des espaces en fin de chaine --- */
         i = strlen(ch);
         while (isspace(ch[--i])); /* On passe les espaces */
         ch[++i] = '\0' ; /* On finalise la chaine */
      }
}
// ===========================================================
// --- fonction outil de suppression des espaces multiples ---
// ===========================================================
void supprime_espaces_multiples(char *ch)
{
      char chaine1[300] ;
      int i = 0, j = 0 , taille = 0, espace_rencontre=0 ;

      if (strcmp(ch,"") != 0) /* On teste si la chaine n'est pas vide */
      {
         taille = strlen(ch);
         
         for (i=0 ; i< taille ; i++)
         {
            if (ch[i]!= ' ')
            {
                chaine1[j++]=ch[i];
                espace_rencontre=0;
            }
            else /* c'est un caractère espace */
            {
              if (!espace_rencontre) /* c'est le premier espace de la série */
              {
                 chaine1[j++]=ch[i] ;
                 espace_rencontre=1 ; /* le prochaine espace ne sera pas traité */

              }
            }
         }
         chaine1[j]='\0';
         strcpy(ch,chaine1);
      }
}
// ==================================================================
// --- fonction outil de normalisation d'une chaîne de caractères ---
// ==================================================================

void normalise_chaine(char ch[])
{
  char *chaine_retour ;
  
  chaine_retour = supprime_accent(ch) ; /* chaine_retour pointe sur ch qui est modifié */
  conv_maj(ch);
  trim(ch);
  supprime_espaces_multiples(ch) ;
  chaine_retour = str_replace_all(ch, "_", " ") ;
  chaine_retour = str_replace_all(ch, "-", " ") ;
  chaine_retour = str_replace_all(ch, "'", " ") ;
}
// ============================================================================================
// --- fonction outil de vérification que les caractères d'une chaînes sont dans un alphabet ---
// ============================================================================================
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
// ======================================================================
// --- fonctions pour la récupération des informations sur un fichier ---
// ======================================================================
int Recupere_Objet_Info(char NomObjetInfo[])
{
 int code_erreur;
 struct stat TableInode ;
 off_t Taille ;
 short int Type_Objet,Proprietaire,Groupe ;
 /* Variable pour la date */
 char date_heure[T_MAX_CHAINE];
 /* Variable pour le nom de l'utilisateur */
 char Info_Login[T_OBJ_MAX_NOM];
 char InfoFicRep[100]="", texte[100]="";
 int code_retour=0;

 char *NomObjetInfoSansRepData=NULL ;

 /* Lecture des informations sur l'objet */
 code_erreur = stat(NomObjetInfo,&TableInode); 

 if (code_erreur == -1)
 {
   code_retour = errno ;
 }
 else
 { /* On récupère les informations */
   Type_Objet   = (TableInode.st_mode & S_IFMT);
   Proprietaire = TableInode.st_uid  ;
   Groupe       = TableInode.st_gid  ;
   Taille       = TableInode.st_size ;

   /* Appel du traitement du Login et du Groupe */
   TraitementLoginGroup(Proprietaire,Groupe,Info_Login) ;

   /* Appel du traitement de la date */
   TraitementDate(TableInode.st_mtime, date_heure) ;
   
   /* Affichage des informations */ 
   if (Type_Objet == S_IFDIR)
   { /* Liste du répertoire */
     code_retour = Lister_Repertoire(NomObjetInfo);
   }
   else
   {
      // On ne prend que les fichiers avec l'extension .txt ou .data
     if ((strstr(NomObjetInfo,".txt") != NULL) || (strstr(NomObjetInfo,".data") != NULL))
     {
       NomObjetInfoSansRepData = strstr(NomObjetInfo,"/") ;
       NomObjetInfoSansRepData++ ;
     
       strcpy(texte,"");
       /* Informations du fichier ou le répertoire */
       strcpy(InfoFicRep,"");
       sprintf(texte,"%-*s ",(int)strlen(date_heure),date_heure);
       strcat(InfoFicRep,texte);
       sprintf(texte,"%10d ",(int)Taille);
       strcat(InfoFicRep,texte);
       sprintf(texte,"%-*s",(int)strlen(NomObjetInfoSansRepData),NomObjetInfoSansRepData);
       strcat(InfoFicRep,texte);
       strcpy(TabListeObjetInfo[NbObjets],InfoFicRep);
       strcpy(TabListeObjet[NbObjets],NomObjetInfo);
       NbObjets++;
     }
   }
 }
 return code_retour ;
}
/* -------------------------------------- */
void TraitementLoginGroup(int UID,int GID, char *ChaineInfo)
/* -------------------------------------- */
{
 /* Variables pour l'utilisateur */
 char NomLogin[T_OBJ_MAX_NOM],NomGroupe[T_OBJ_MAX_NOM];
 struct passwd UserInfo ;
 struct group GroupInfo ;

 /* --- Traitement du login  --- */
 if (getpwuid(UID) == NULL)
 {
   sprintf(NomLogin,"%8d",UID);
 }
 else
 {
   UserInfo = *getpwuid(UID)         ;
   strcpy(NomLogin, UserInfo.pw_name);
 }

 /* --- Traitement du groupe --- */
 if (getgrgid(GID) == NULL)
 {
   sprintf(NomGroupe,"%8d",GID);
 }
 else
 {
   GroupInfo = *getgrgid(GID)       ;
   strcpy(NomGroupe, GroupInfo.gr_name);
 }
 /* Mise en forme finale */
 sprintf(ChaineInfo,"%8s %8s",NomLogin,NomGroupe);

}
/* ----------------------------- */
void TraitementDate(time_t Temps, char *ChaineHeureDate)
/* ----------------------------- */
{
   /* Variables pour la date */
   time_t nb_sec_TU;
   struct tm heure_jour_mois       ;
   int secondes,minutes,heure,j_mois,mois,annee;
   char ChaineDate[T_MAX_CHAINE],ChaineHeure[T_MAX_CHAINE];
   char nom_mois[T_MAX_CHAINE]       ;

   /* Positionnement de l'environnement */
   /* LANG=fr ou fr_FR                  */
   //setlocale(LC_ALL,"");
   setlocale(LC_ALL,"fr_FR.UTF-8"); /* Prise en charge des caractères accentués UTF8 */
      
   /* récupération du nombre de secondes     */
   /* ecoulees depuis 1/1/1970 a 0h 0mn 0sec */
   nb_sec_TU = Temps;
        
   /* récupération des informations */
   heure_jour_mois = *localtime(&nb_sec_TU);

   /* Récupération des champs */
   secondes = heure_jour_mois.tm_sec  ; 
   minutes  = heure_jour_mois.tm_min  ;
   heure    = heure_jour_mois.tm_hour ;
   j_mois = heure_jour_mois.tm_mday       ;
   mois   = heure_jour_mois.tm_mon +1     ;
   annee  = heure_jour_mois.tm_year +1900 ;

   /* récupération du nom du mois */
   strftime(nom_mois,T_MAX_CHAINE,"%B",&heure_jour_mois);
   /* Mise en forme finale de l'heure et de la date */
   sprintf(ChaineHeure,"%02d:%02d",heure,minutes);
   sprintf(ChaineDate ,"%02d-%s-%4d",j_mois,nom_mois,annee);
   sprintf(ChaineHeureDate ,"%s   %s",ChaineDate,ChaineHeure);
}
// ================================================================
// --- fonctions pour la récupération du contenu d'un répertoire ---
// ================================================================
int Lister_Repertoire(char NomRep[])
{
 DIR *Rep  ; /* Descripteur du répertoire */
 struct dirent *Objet ; /* une entrée dans le répertoire */
 char NomObjet[T_OBJ_MAX_NOM],TmpNom[T_OBJ_MAX_NOM];
 int code_retour=0;

 /* Ouverture du répertoire */
 Rep = opendir(NomRep);

 if (Rep == NULL)
 {
   code_retour = errno ;
 }
 else
 {
   do
   {
     /* Lecture d'une entrée dans le répertoire */
     Objet = readdir(Rep);

     if (Objet!=NULL)
     {  /* On récupère le nom de l'objet */
        strcpy(NomObjet,(*Objet).d_name);
        /* On affiche les informations */
        if ((strcmp(NomObjet,".")!=0)&&(strcmp(NomObjet,"..")!=0))
        {
           strcpy(TmpNom,NomRep);
           strcat(TmpNom,"/");
           //strcpy(TmpNom,"");
           strcat(TmpNom,NomObjet);
           strcpy(NomObjet,TmpNom);
           Recupere_Objet_Info(NomObjet); 
        }
     }
   }
   while(Objet!=NULL);

   /* Fermeture du répertoire */
   closedir(Rep);
 }
 return code_retour ;
}






