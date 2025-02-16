#include <stdio.h>

#define INF         999  // Définition d'une valeur infinie
#define NB_SOMMETS  4          // Nombre de sommets


// Declaration des fonctions
void initialiserDijkstra(int parent_tab[], int distance_tab[]);
void initialiserVisited(int visited_tab[]);
int sommetMinDistance(int distance[], int visited[]);

int main() {
    // Matrice d'adjacence représentant le graphe

    int matrice[NB_SOMMETS][NB_SOMMETS] = {
        {  0,   2,   1, INF },  
        { INF,   0, 4,   3 },  
        { INF, 4,   0,   1 },  
        { INF,   3,   1,   0 }
    };

    int parent[NB_SOMMETS], distance[NB_SOMMETS],visited[NB_SOMMETS];
    int i,res;
    initialiserDijkstra(parent,distance);
    initialiserVisited(visited);
    res = sommetMinDistance(distance,visited);
    printf("%d",res);
    /*
    for (i = 0; i < NB_SOMMETS;i++)
     {
         printf("%d  ",visited[i]);
     }
    */
    /*
    // Affichage de la matrice
    printf("Matrice d'adjacence du graphe :\n");
    for (int i = 0; i < NB_SOMMETS; i++) {
        for (int j = 0; j < NB_SOMMETS; j++) {
            if (matrice[i][j] == INF)
                printf(" INF ");  // Affichage plus lisible
            else
                printf(" %2d  ", matrice[i][j]);
        }
        printf("\n");
    }
    */
    
}


//-------------------------------------//
//        CREATION DE FONCTION 
//-------------------------------------//

void initialiserDijkstra(int parent_tab[], int distance_tab[])
{
     // Initialisation des tableaux distances et parents
     int i;
     for (i = 0; i < NB_SOMMETS; i++)
     {
         parent_tab[i] = -1;
     }
     distance_tab[0] = 0;
     for (i = 1; i < NB_SOMMETS; i++)
     {
         distance_tab[i] = INF;
     }
     // Vérification (décommenter pour tester)
     /*
     for (i = 0; i < NB_SOMMETS; i++)
     {
         printf("%d - ", distance_tab[i]);
     }
     */
}


void initialiserVisited(int visited_tab[])
{
    int i ;
    for (i = 0; i < NB_SOMMETS; i++)
    {
        visited_tab[i] = 0;
    }
}


int sommetMinDistance(int distance[], int visited[]) {
    int i;
    int min = INF;
    int pos_mini = -1; // Mettre -1 pour éviter de renvoyer une valeur incorrecte
    /*Condition visited[i] == 0 && distance[i] < min dans le bon ordre :
    On vérifie d’abord que le sommet n’a pas été visité (visited[i] == 0).
    Puis on compare distance[i] avec min.
    */

    // mettre un boolean à la place
    for (i = 0; i < NB_SOMMETS; i++) {
        if (visited[i] == 0 && distance[i] < min) 
        { // Vérifier d'abord si le sommet est non visité
            pos_mini = i;
            min = distance[i];
        }
    }
    u
    return pos_mini; // Retourner l'indice du sommet avec la plus petite distance non visitée
}


void mettreAJourDistances()
{
    int i;

    for (i = 0; i < NB_SOMMETS; i++)
    {
        // Vérifier si `i` est un voisin et qu'on n'est pas sur `pos_mini` lui-même
        if (graph[pos_mini][i] != INF && graph[pos_mini][i] != 0)
        {
            // Mettre à jour la distance SEULEMENT si on trouve un chemin plus court
            if (distance[pos_mini] + graph[pos_mini][i] < distance[i])
            {
                distance[i] = distance[pos_mini] + graph[pos_mini][i];
                parent[i] = pos_mini;
            }
        }
    }
}
