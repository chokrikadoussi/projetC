//-------------------------------------//
//        LIBRAIRIES 
//-------------------------------------//

#include <stdio.h>
#include <string.h>
//-------------------------------------//
//        VARIABLES GLOBALES 
//-------------------------------------//

#define INF 999  // Une grande valeur pour représenter l'infini
#define NB_SOMMETS 7  // Nombre total de sommets (A, B, C, D, E, F, G)

// Tableau contenant les noms des sommets (A, B, C, ... I)
char *sommets[NB_SOMMETS] = {"Aa", "Bb", "Cc", "Dd", "Ee", "Ff", "Gg"};

//-------------------------------------//
//        DECLARATION DES FONCTIONS 
//-------------------------------------//
void afficherMatrice(int graph[][NB_SOMMETS]);
void initialiserDijkstra(int parent_tab[], int distance_tab[], int dep);  // ✅ Correction ici
void initialiserVisited(int visited_tab[]);
int sommetMinDistance(int distance_tab[], int visited_tab[]);
void dijkstra(int graph[][NB_SOMMETS], int parent_tab[], int distance_tab[], int visited_tab[], int dep, int arr);
void afficherChemin(int parent_tab[], int sommet) ;
int verifSommet(char sommet[]);
int donnerSommet(char sommet[]) ;


//-------------------------------------//
//        PROGRAMME PRINCIPAL 
//-------------------------------------//

int main() {
    
    int graph[NB_SOMMETS][NB_SOMMETS] = {
        {  0,   1,   2, INF, INF, INF, INF },  
        {  1,   0, INF,   2, INF,   3, INF },  
        {  2, INF,   0,   3,   4, INF, INF },  
        { INF,   2,   3,   0,   2,   3,   3 },  
        { INF, INF,   4,   2,   0, INF,   5 },  
        { INF,   3, INF,   3, INF,   0,   4 },  
        { INF, INF, INF,   3,   5,   4,   0 }
    };

    // affichage de la matrice
    afficherMatrice(graph);

    


    //         DIJKSTRA
    /*
    // version avec int
    int depart;
    printf("Entrez le sommet de depart (0-%d) : ", NB_SOMMETS - 1);
    scanf("%d", &depart);
    // controle de saisie
    while( depart < 0 || depart >= NB_SOMMETS)
    {
        printf("Entrez le sommet de depart (0-%d) : ", NB_SOMMETS - 1);
        scanf("%d", &depart);
    }

    int arrivee;
    printf("Entrez le sommet d'arrivee (0-%d) : ", NB_SOMMETS - 1);
    scanf("%d", &arrivee);
    // controle de saisie
    while( arrivee < 0 || arrivee >= NB_SOMMETS)
    {
        printf("Entrez le sommet de arrivee (0-%d) : ", NB_SOMMETS - 1);
        scanf("%d", &arrivee);
    }
    */
    // version string
    char entree_utilisateur[100];
    printf("Entrez le sommet de depart (ex: Aa, Bb) : ");
    scanf("%s", entree_utilisateur);

    int depart = -1; // Initialisation à une valeur invalide

    while (depart == -1) // Tant que le sommet est invalide
    {
        if (verifSommet(entree_utilisateur)) 
        {
            depart = donnerSommet(entree_utilisateur); // Récupère l'index
        } 
        else 
        {
            printf("Erreur de saisie ! Entrez un sommet de depart valide (ex: Aa, Bb) : ");
            scanf("%s", entree_utilisateur);
        }
    }

    printf("Entrez le sommet d'arrivee (ex: Aa, Bb) : ");
    scanf("%s", entree_utilisateur);

    int arrivee = -1; // Initialisation à une valeur invalide

    while (arrivee == -1) // Tant que le sommet est invalide
    {
        if (verifSommet(entree_utilisateur)) 
        {
            arrivee = donnerSommet(entree_utilisateur); // recuperere l'index
        } 
        else 
        {
            printf("Erreur de saisie ! Entrez un sommet d'arrivee valide (ex: Aa, Bb) : ");
            scanf("%s", entree_utilisateur);
        }
    }
    

    // initialisation des tableaux
    int parent_tab[NB_SOMMETS];
    int distance_tab[NB_SOMMETS];
    int visited_tab[NB_SOMMETS];

    // lancement de dijkstra
    dijkstra(graph, parent_tab, distance_tab, visited_tab,depart,arrivee);

    // afficher
    printf("\n=======================================\n");
    printf("   RESULTATS DE L'ALGORITHME DIJKSTRA\n");
    printf("=========================================\n");

    

    // Vérification si un chemin existe
    if (distance_tab[arrivee] == INF) {
        printf(" Aucun chemin disponible entre %s et %s.\n", sommets[depart], sommets[arrivee]);
    } 
    else 
    {
        printf(" Un chemin a ete trouve !\n");
        printf("Distance minimale entre %s et %s : %d\n", sommets[depart], sommets[arrivee], distance_tab[arrivee]);
        
        printf("Chemin optimal : ");
        afficherChemin(parent_tab, arrivee);
        printf("\n");
    }

    printf("----------------------------------------\n\n");



   

}


//-------------------------------------//
//        CREATION DE FONCTION 
//-------------------------------------//


// afficher la matrice d'adjacence
void afficherMatrice(int graph[][NB_SOMMETS]) 
{
    printf("Matrice d'adjacence du graphe :\n");
    for (int i = 0; i < NB_SOMMETS; i++) 
    {
        for (int j = 0; j < NB_SOMMETS; j++) 
        {
            if (graph[i][j] == INF)
            {
                printf(" INF ");
            }
                
            else
            {
                printf(" %3d ", graph[i][j]);
            }       
        }
        printf("\n");
    }
}

void initialiserDijkstra(int parent_tab[], int distance_tab[], int dep) 
{
    int i;
    for (i = 0; i < NB_SOMMETS; i++) 
    {
        parent_tab[i] = -1;
        distance_tab[i] = INF; // on met toutes les distances à INF
    }

    distance_tab[dep] = 0;  //  le sommet de départ a une distance 0
}




void initialiserVisited(int visited_tab[])
{
    // aucun sommet n'est visité au depart
    int i ;
    for (i = 0; i < NB_SOMMETS; i++)
    {
        visited_tab[i] = 0;
    }
}


int sommetMinDistance(int distance_tab[],int visited_tab[])
{
    // trouver le sommet minimal
    // Sommet sélectionné : A (car distance minimale = 0)
    int min = INF, i, posi= -1;

    for (i = 0; i < NB_SOMMETS;i++)
    {
        if(distance_tab[i] < min && visited_tab[i]==0)
        {
            min = distance_tab[i];
            posi = i;
        }
    }
    return posi; // // la selection d'un sommet est permis grace à la position
    //  au prochain tour : 
    //Sommet sélectionné : B (distance 1, plus petite parmi non visités)
}

/*
dans le programme 
// le sommet est bien visité 
visited_tab[posi] = 1;
=> pourquoi ne pas mettre  dans la fonction sommetMinDistanc = regle en informatique chaque fonction n'est effectue qu'une seule chose
*/

void mettreAJourDistances(int graph[][NB_SOMMETS], int distance_tab[], int parent_tab[], int visited_tab[], int posi)
{
    int i;

    for (i = 0; i < NB_SOMMETS; i++) 
    {
        /*si le sommet n'est pas visité  = 0
        et que le sommet est voisin (!= INF) du sommet selectionné
        */
        if (visited_tab[i] == 0 && graph[posi][i] != INF)
        {
            /*
            exemple pour les voisins de A : B C
            B : 0 + 1 = 1 (remplace INF)
            C : 0 + 2 = 2 (remplace INF)
            et la prochaine fois il y aura une comparaison entre ces valeurs et les valeurs prochaines pour ne conserver que la distance minimale
            */
            if (distance_tab[posi] + graph[posi][i] < distance_tab[i]) 
            {
                distance_tab[i] = distance_tab[posi] + graph[posi][i];
                parent_tab[i] = posi; // tour 1 : le parent est A
            }

            /* l'objectif est de trouver la distance optimale
            si prenons B : ces voisins non visiité sont D F
            si 1+2 < INF alors tu remplace => ok : du coup distance[i] = 1 + 2 
            ensuite 
            si 1+3 < 3 alors tu remplace => ko 
            */
        }
    }

}


int trouve(int visited_tab[])
{ // l'objectif est de savoir si on a visité tous les sommets et que l'on mettent fin à l'algo
    int i ;
    for (i = 0; i < NB_SOMMETS; i++)
    {
        if (visited_tab[i]==0)
        {
            return  0;
        }
    }
    return 1; // tous les sommets ont été visités
}

void dijkstra(int graph[][NB_SOMMETS], int parent_tab[], int distance_tab[], int visited_tab[], int dep,int arr)
{
    int pos;
    // initialisation
    initialiserDijkstra(parent_tab,distance_tab,dep);
    initialiserVisited(visited_tab);
    // boucle tantque tous les sommets ne seront pas visités
   
    while (!trouve(visited_tab)) 
    {
        pos = sommetMinDistance(distance_tab, visited_tab);
        if (pos == arr)
        {
            return ; // stopper l'algo car pas besoin de visité tous les autres sommets
        }
        if (pos == -1) break; // se premunir du coup ou tous les somments encore accessibles sont à INF = l'algo ne peut plus avancé
        visited_tab[pos] = 1; // sommet marqué comme visité
        mettreAJourDistances(graph, distance_tab, parent_tab, visited_tab, pos);
    }
    
}

// pour le controle de saisie
int verifSommet(char sommet[]) 
{
    int i;
    for (i = 0; i < NB_SOMMETS; i++) 
    {
        if (strcmp(sommet, sommets[i]) == 0) 
        {
            return 1; // Le sommet existe
        }
    }
    return 0; // le sommet n'existe pas 
}

int donnerSommet(char sommet[]) 
{
    int i;
    for (i = 0; i < NB_SOMMETS; i++) 
    {
        if (strcmp(sommet, sommets[i]) == 0) 
        {
             return i; // Retourne l'index du sommet
        }
    }
    return -1; // Indique que le sommet n'existe pas
}




// -----------------------------

void afficherChemin(int parent_tab[], int sommet) 
{
    if (parent_tab[sommet] == -1) {
        printf("%s", sommets[sommet]);
        return;
    }
    afficherChemin(parent_tab, parent_tab[sommet]);
    printf(" -> %s", sommets[sommet]);
}


