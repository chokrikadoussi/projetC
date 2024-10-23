#include <stdio.h>
#include <curses.h>
#include <string.h>

WINDOW *Fenetre_Menu, *Sous_Fenetre_Menu ;
int Nb_Lignes=24,Nb_Colonnes=80,Origine_X=0,Origine_Y=0;

int main()
{
 int i ;
 char Titre_Menu_Principal[]="- Menu Principal -";
 
 int Ligne_Debut=1, Colonne_Debut=(Nb_Colonnes/2)-15 ;

 int Ligne_Titre     = Ligne_Debut ;
 int Ligne_Selection = Ligne_Debut+2;
 int Ligne_Quitter   = Ligne_Selection+10;
 int Ligne_Message   = Ligne_Quitter+3 ;
 
 int Colonne_Titre     = Colonne_Debut ;
 int Colonne_Selection = Colonne_Debut ;
 int Colonne_Quitter   = Colonne_Debut ;


 

 /* initialisation du systeme video */
 initscr();
 erase();


 Fenetre_Menu = newwin(Nb_Lignes,Nb_Colonnes,Origine_Y,Origine_X);
 
 
 
 wclear(Fenetre_Menu);
  
 box(Fenetre_Menu,0,0);

 wattron(Fenetre_Menu, A_BOLD); 
 mvwprintw(Fenetre_Menu,Ligne_Titre,Colonne_Titre,Titre_Menu_Principal);
 wattroff(Fenetre_Menu, A_BOLD);
 



 scrollok(Fenetre_Menu, TRUE); 
 idlok(Fenetre_Menu, FALSE);


 wsetscrreg(Fenetre_Menu, 2, 10);

 wrefresh(Fenetre_Menu);
 
 
 Sous_Fenetre_Menu = subwin(Fenetre_Menu, 5, Nb_Colonnes,Origine_Y,Origine_X+5);




/* Boucle d'affichage du Menu */

 for (i=1; i<15 ; i++)
 {
/*   wmove(Fenetre_Menu, Ligne_Selection+i,Colonne_Selection); */
 
  mvwprintw(Sous_Fenetre_Menu,i,Colonne_Selection,"%d: Affichage",i);
 /*  wprintw(my_window, "%d%d", x, y); */
 }

/*
for (i=0; i<15 ; i++) 
 wscrl(Fenetre_Menu,1);
*/


 wsetscrreg(Fenetre_Menu, 0, 10);

 wrefresh(Fenetre_Menu);
 


/* Boucle d'affichage du Menu */

 for (i=1; i<15 ; i++)
 {
   wmove(Fenetre_Menu, Ligne_Selection+i,Colonne_Selection);
 }




 wrefresh(Fenetre_Menu);

/* erase();
 refresh();*/
 endwin();
}


