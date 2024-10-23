#include <stdio.h>
#include <curses.h>
#include <string.h>

WINDOW *Fenetre_Menu ;
int Nb_Lignes=24,Nb_Colonnes=80,Origine_X=0,Origine_Y=0;

int Menu_principal(char Titre[],char *Menu[],int Nb_Choix);

int main()
{

 int Choix_Menu_Principal=6 ;
 static char *Menu_Principal[10]={
                     "-1- Ouvrir fichier",
                     "-2- Sauvegarder dans fichier",
                     "-3- Recherche un etudiant",
                     "-4- Ajout d'une liste d'etudiants",
                     "-5- Affichage de la liste des etudiants",
                     "-Q- QUITTER"
                   };
 char Titre_Menu_Principal[]="- Menu Principal -";



 int selection ;
 
 
 
 
/* soft labels  
 slk_init(1);
 */
 
 
 

 /* initialisation du systeme video */
 initscr();
 erase();
/* refresh(); */

 

 selection=Menu_principal(Titre_Menu_Principal,Menu_Principal,Choix_Menu_Principal);
 
  mvwprintw(Fenetre_Menu,20,2,"choix=%d",selection);
  wrefresh(Fenetre_Menu);

 erase();
 refresh();
 endwin();
}


int Menu_principal(char Titre[],char *Menu[],int Nb_Choix)
{
 int Ligne_Debut=1, Colonne_Debut=(Nb_Colonnes/2)-15 ;

 int Ligne_Titre     = Ligne_Debut ;
 int Ligne_Selection = Ligne_Debut+2;
 int Ligne_Quitter   = Ligne_Selection+Nb_Choix+2;
 int Ligne_Message   = Ligne_Quitter+3 ;
 
 int Colonne_Titre     = Colonne_Debut ;
 int Colonne_Selection = Colonne_Debut ;
 int Colonne_Quitter   = Colonne_Debut ;
 
 char choix ;
 char nom[20],prenom[40] ;
 int age ;
 int i ;
 
 int Touche;
 char Nom_Touche[20] ;
 int Validation_OK ;
 int Indice_Choix=0 ;
 
 /* creation d'un fenetre avec bordure, et affichage */
 Fenetre_Menu = newwin(Nb_Lignes,Nb_Colonnes,Origine_Y,Origine_X);
 
 
 
 wclear(Fenetre_Menu);
  
 box(Fenetre_Menu,0,0);
/* wrefresh(Fenetre_Menu); */
 
/* 
 mvwaddch(Fenetre_Menu, 10, 15, 'M');
 mvwaddch(Fenetre_Menu, 10, 16, 'e');
 mvwaddch(Fenetre_Menu, 10, 17, 'n');
 mvwaddch(Fenetre_Menu, 10, 18, 'u');
 */


keypad(Fenetre_Menu, TRUE);
 
/* wprintw(Fenetre_Menu,"Menu Principal %d",1); */

/* Affichage du Titre du Menu */

 wattron(Fenetre_Menu, A_BOLD); 
 mvwprintw(Fenetre_Menu,Ligne_Titre,Colonne_Titre,Titre);
 wattroff(Fenetre_Menu, A_BOLD);
 

/* Boucle d'affichage du Menu */

 for (i=0; i<Nb_Choix ; i++)
 {
   mvwprintw(Fenetre_Menu,Ligne_Selection+i,Colonne_Selection,Menu[i]); 
 }

/* 
 mvwprintw(Fenetre_Menu,Ligne_Quitter+1,Colonne_Debut,"Choix : ");
*/
 
 /* deplacement du curseur */
 /* wmove(Fenetre_Menu,Ligne_Quitter+1, Colonne_Debut+strlen("Choix : ")); */
 
 /* scanf("%c",&choix); */

/* 
 choix=mvwgetch(Fenetre_Menu,Ligne_Quitter+1, Colonne_Debut+strlen("Choix : "));
 
 
 mvwprintw(Fenetre_Menu,Ligne_Quitter+2,Colonne_Debut,"Choix = %c",choix);
  
  
 wrefresh(Fenetre_Menu);
*/
  
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
                         Displays the color pair represented by Number. You must have already
                         initialized the
                         color pair using the init_pair subroutine.

*/ 

/* 
 wattron(Fenetre_Menu, A_UNDERLINE);
 mvwprintw(Fenetre_Menu,Ligne_Quitter+3,Colonne_Debut,"Nom:");
 wattroff(Fenetre_Menu, A_UNDERLINE);
   
 mvwscanw(Fenetre_Menu,Ligne_Quitter+3,Colonne_Debut+10,"%s",nom);


 wattron(Fenetre_Menu, A_UNDERLINE);
 mvwprintw(Fenetre_Menu,Ligne_Quitter+4,Colonne_Debut,"Prenom:");
 wattroff(Fenetre_Menu, A_UNDERLINE);
   
 mvwscanw(Fenetre_Menu,Ligne_Quitter+4,Colonne_Debut+10,"%s",prenom);

 wattron(Fenetre_Menu, A_UNDERLINE); 
 mvwprintw(Fenetre_Menu,Ligne_Quitter+5,Colonne_Debut,"Age:");
 wattroff(Fenetre_Menu, A_UNDERLINE); 
   
 mvwscanw(Fenetre_Menu,Ligne_Quitter+5,Colonne_Debut+10,"%d",&age);
 
 beep();
 
 
 mvwprintw(Fenetre_Menu,Ligne_Quitter+6,Colonne_Debut,"Nom=%s Prenom=%s age=%d",nom,prenom,age);
*/


 scrollok(Fenetre_Menu, TRUE);



/*   wsetscrreg(Menu_Affichage, Lig_Selection-Lig_Titre, Lig_Fin-Lig_Selection-4); */



for (i=0; i<4 ; i++) 
 scroll(Fenetre_Menu);
 
 
 
 
/* --- selection d'un choix du Menu --- */

keypad(Fenetre_Menu, TRUE);

strcpy(Nom_Touche,"");
Validation_OK=(strcmp(Nom_Touche,"^J")==0);

Indice_Choix=0;

while (! Validation_OK)
{
/*
 mvwprintw(Fenetre_Menu,Ligne_Selection+10,Colonne_Debut,"Selection avec les fleches");
*/

 wattron(Fenetre_Menu, A_REVERSE);
 mvwprintw(Fenetre_Menu,Ligne_Selection+Indice_Choix,Colonne_Debut,Menu[Indice_Choix]);
 wattroff(Fenetre_Menu, A_REVERSE);
 
/*
 Touche=mvwgetch(Fenetre_Menu,Ligne_Selection, Colonne_Debut);
*/
/* Les nom de touches sont :
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
 
 Touche=wgetch(Fenetre_Menu);
 
 wmove(Fenetre_Menu,Ligne_Message,Colonne_Debut);
 wclrtoeol(Fenetre_Menu);
 
 wmove(Fenetre_Menu,Ligne_Selection+Indice_Choix,Colonne_Debut);
 wclrtoeol(Fenetre_Menu);
 box(Fenetre_Menu,0,0);
 mvwprintw(Fenetre_Menu,Ligne_Selection+Indice_Choix,Colonne_Debut,Menu[Indice_Choix]);
 wrefresh(Fenetre_Menu);
 
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
 else if ((strcmp(Nom_Touche,"KEY_PPAGE")==0)||(strcmp(Nom_Touche,"KEY_HOME")==0) )
 {
   Indice_Choix=0 ;
 }
 else if ((strcmp(Nom_Touche,"KEY_NPAGE")==0)|| (strcmp(Nom_Touche,"KEY_END")==0))
 {
   Indice_Choix=Nb_Choix-1 ;
 }
 else
 {
 wmove(Fenetre_Menu,Ligne_Message,Colonne_Debut);
 wclrtoeol(Fenetre_Menu);
 mvwprintw(Fenetre_Menu,Ligne_Message,Colonne_Debut,"Frappe Incorrecte");
 }



 wmove(Fenetre_Menu,Ligne_Quitter+7,Colonne_Debut);
 wclrtoeol(Fenetre_Menu);
 mvwprintw(Fenetre_Menu,Ligne_Quitter+7,Colonne_Debut,"Touche = |%s| choix=%d",Nom_Touche,Indice_Choix);


 Validation_OK=(strcmp(Nom_Touche,"^J")==0);


}
 
keypad(Fenetre_Menu, FALSE);

wrefresh(Fenetre_Menu);

return Indice_Choix ;

}
