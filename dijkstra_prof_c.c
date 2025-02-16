#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NBSOMMETS 1000
#define TAILLE_NOM_FICHIER 100
#define TAILLE_NOM 50
#define NB_COLONNES 2
#define NON_TROUVE -1
#define INCONNU -1
#define INFINI 99999

/* --- Type type_couleur --- */
enum type_couleur {
    blanc,
    noir
};

/* --- Structure d'un sommet --- */
struct sommet {
    char nom[TAILLE_NOM];
    int pere;
    int poids;
    enum type_couleur couleur;
};

/* --- Procédures et fonctions utilitaires --- */
int chargement_sommets();
int choix_sommet(char texte[]);
int chargement_arcs();

/* --- Procédures et fonctions de l'algorithme --- */
void dijkstra_initialise(int num_sommet_depart);
int dijkstra_recherche_sommet_poids_min();
void dijkstra_colorier_sommet(int num_sommet);
void dijkstra_calcule_poids_sommets_adjacents(int num_sommet);
void dijkstra_affiche_plus_court_chemin(int num_sommet);

/* --- Tableau des sommets --- */
struct sommet tab_sommets[NBSOMMETS];

/* --- Tableau des arcs valués --- */
int tab_arcs[NBSOMMETS][NBSOMMETS];

/* -- Tableau des noms des arcs -- */
char *tab_arcs_noms[NBSOMMETS][NBSOMMETS];

/* --- Variables globales --- */
int nbsommets = 0;
char NomFichier[TAILLE_NOM_FICHIER];

/* === Programme principal === */
int main() {
    char sommet_depart[TAILLE_NOM], sommet_arrivee[TAILLE_NOM];
    int num_sommet_depart, num_sommet_arrivee;
    int num_sommet_poids_min;

    if (chargement_sommets() != NON_TROUVE) {
        if (chargement_arcs() != NON_TROUVE) {
            num_sommet_depart = choix_sommet("de départ");
            if (num_sommet_depart != NON_TROUVE) {
                num_sommet_arrivee = choix_sommet("d'arrivée");
                if (num_sommet_arrivee != NON_TROUVE) {
                    /* === Algorithme de Dijkstra === */
                    /* --- Initialisation des sommets --- */
                    dijkstra_initialise(num_sommet_depart);

                    /* --- Recherche du sommet de poids minimal --- */
                    while ((num_sommet_poids_min = dijkstra_recherche_sommet_poids_min()) != NON_TROUVE) {
                        /* Ce sommet est colorié en noir */
                        dijkstra_colorier_sommet(num_sommet_poids_min);

                        /* On met à jour le poids des sommets adjacents */
                        dijkstra_calcule_poids_sommets_adjacents(num_sommet_poids_min);
                    }

                    /* Affiche le plus court chemin */
                    /* à partir du sommet d'arrivée */
                    dijkstra_affiche_plus_court_chemin(num_sommet_arrivee);
                }
            }
        }
    }
    return 0;
}

/* === Sous-programmes === */
/* --- Chargement du tableau des sommets --- */
int chargement_sommets() {
    FILE *fsommets;
    char NomFichierSommets[TAILLE_NOM_FICHIER], nom[TAILLE_NOM];
    int code_retour=0  ;   
    printf("Nom du graphe : ")              ;   
    scanf("%s",NomFichier)                  ;   
    strcpy(NomFichierSommets,NomFichier)    ;   
    strcat(NomFichierSommets,"_sommets.txt");   
    fsommets=fopen(NomFichierSommets,"r")   ;   
    if (fsommets == NULL)   
    { code_retour=NON_TROUVE                ;     
    printf("fichier %s non trouvé\n",NomFichierSommets);   
    }   
    else   
    { 
        while (!feof(fsommets))      
            if (fscanf(fsommets,"%s",nom) != EOF)        
                strcpy(tab_sommets[nbsommets++].nom,nom) ;      
                fclose(fsommets);   
    }   
    
    return code_retour ; 
    } 
    /* --- Sélection d'un sommet --- */
int choix_sommet(char texte[]) {
    int i, choix;
    
    for (i = 0; i < nbsommets; i++) {
        printf("%2d: %-*s", i + 1, TAILLE_NOM, tab_sommets[i].nom);
        if (((i + 1) % NB_COLONNES) == 0)
            printf("\n");
    }
    
    printf("\nSaisissez le numéro du sommet ");
    printf("%s :", texte);
    scanf("%d", &choix);
    printf("\n");

    choix--;

    if ((choix >= nbsommets) || (choix < 0)) {
        printf("Choix erroné !\n");
        choix = NON_TROUVE;
    }

    return choix;
}

/* --- Chargement des tableaux des arcs --- */
int chargement_arcs() 
{
    FILE *farcs, *farcsnoms;
    char NomFichierArcs[TAILLE_NOM_FICHIER], NomFichierNomsArcs[TAILLE_NOM_FICHIER];
    char nomarcs[TAILLE_NOM];
    int code_retour = 0, i, j;

    strcpy(NomFichierArcs, NomFichier);
    strcpy(NomFichierNomsArcs, NomFichier);
    strcat(NomFichierArcs, "_arcs.txt");
    strcat(NomFichierNomsArcs, "_noms.txt");

    if ((farcs = fopen(NomFichierArcs, "r")) == NULL) {
        code_retour = NON_TROUVE;
        printf("fichier %s non trouvé\n", NomFichierArcs);
    } 
    else if ((farcsnoms = fopen(NomFichierNomsArcs, "r")) == NULL) {
        code_retour = NON_TROUVE;
        printf("fichier %s non trouvé\n", NomFichierNomsArcs);
    } 
    else {
        for (i = 0; i < nbsommets; i++) {
            for (j = 0; j < nbsommets; j++) {
                fscanf(farcs, "%d", &tab_arcs[i][j]);
                fscanf(farcsnoms, "%s", nomarcs);
                tab_arcs_noms[i][j] = (char *)malloc(strlen(nomarcs) + 1);
                strcpy(tab_arcs_noms[i][j], nomarcs);
            }
        }
        fclose(farcs);
        fclose(farcsnoms);
    }
    
    return code_retour;
}

/* --- DIJKSTRA : Initialisation des sommets --- */
void dijkstra_initialise(int num_sommet_depart) {
    int i, ponderation;

    for (i = 0; i < nbsommets; i++) {
        ponderation = (i == num_sommet_depart) ? 0 : INFINI;
        tab_sommets[i].poids = ponderation;
        tab_sommets[i].pere = INCONNU;
        tab_sommets[i].couleur = blanc;
    }
}

/* --- DIJKSTRA : Recherche du sommet de poids minimal --- */
int dijkstra_recherche_sommet_poids_min() {
    int i, num_sommet = NON_TROUVE, poids_min = INFINI;

    for (i = 0; i < nbsommets; i++) {
        if ((tab_sommets[i].couleur == blanc) && (tab_sommets[i].poids < poids_min)) {
            poids_min = tab_sommets[i].poids;
            num_sommet = i;
        }
    }
    return num_sommet;
}

/* --- DIJKSTRA : Colorier un sommet en noir --- */
void dijkstra_colorier_sommet(int num_sommet) {
    tab_sommets[num_sommet].couleur = noir;
}

/* --- DIJKSTRA : Calcul du poids des sommets adjacents --- */
void dijkstra_calcule_poids_sommets_adjacents(int num_sommet) {
    int num_adjacent, nouveau_poids;

    for (num_adjacent = 0; num_adjacent < nbsommets; num_adjacent++) {
        nouveau_poids = tab_sommets[num_sommet].poids + tab_arcs[num_sommet][num_adjacent];

        if ((tab_sommets[num_adjacent].couleur == blanc) && (nouveau_poids < tab_sommets[num_adjacent].poids)) {
            tab_sommets[num_adjacent].poids = nouveau_poids;
            tab_sommets[num_adjacent].pere = num_sommet;
        }
    }
}

/*---DIJKSTRA procédure d'affichage du plus court chemin---*/
void dijkstra_affiche_plus_court_chemin(int sommet_arrivee) {
    int num_s = sommet_arrivee, nbsommets_local = 1, i;
    int num_s1, num_s2, sommet_depart;
    int tab_chemin_inverse[NBSOMMETS + 1];

    if (tab_sommets[sommet_arrivee].poids == INFINI) {
        printf("Aucun chemin n'existe !\n");
    } 
    else {
        tab_chemin_inverse[0] = sommet_arrivee;

        while (num_s != INCONNU) {
            tab_chemin_inverse[nbsommets_local++] = num_s;
            sommet_depart = num_s;
            num_s = tab_sommets[num_s].pere;
        }

        printf("Plus court chemin pour aller\n");
        printf("   de %s\n", tab_sommets[sommet_depart].nom);
        printf("   à  %s\n", tab_sommets[sommet_arrivee].nom);

        for (i = nbsommets_local - 1; i > 0; i--) {
            num_s1 = tab_chemin_inverse[i];

            if (num_s1 == sommet_arrivee) {
                printf("Vous êtes arrivé à %s, ", tab_sommets[num_s1].nom);
                printf("vous avez parcouru %d m\n", tab_sommets[sommet_arrivee].poids);
            } 
            else {
                num_s2 = tab_chemin_inverse[i - 1];
                printf("De %s ", tab_sommets[num_s1].nom);
                printf("suivre %s ", tab_arcs_noms[num_s1][num_s2]);
                printf("vers %s ", tab_sommets[num_s2].nom);
                printf("(%d m)\n", tab_arcs[num_s1][num_s2]);
            }
        }
        
    }
}
