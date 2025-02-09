//---------------------------------------
// Déclaration des Bibliothèques
//---------------------------------------

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

//---------------------------------------
// Déclaration des fonctions/procédures
//---------------------------------------

void Dijkstra(int Graph[MAX][MAX], int n, int start);
void afficherChemin(int pred[], int start, int node);

//---------------------------------------
// Procédure Principale
//---------------------------------------

int main() {
    int Graph[MAX][MAX] = {
        {0, 1, 2, INFINITY, INFINITY, INFINITY, INFINITY}, // A
        {1, 0, INFINITY, 3, INFINITY, INFINITY, INFINITY}, // B
        {2, INFINITY, 0, 3, 4, INFINITY, INFINITY},        // C
        {INFINITY, 3, 3, 0, INFINITY, 3, 2},               // D
        {INFINITY, INFINITY, 4, INFINITY, 0, INFINITY, 5}, // E
        {INFINITY, INFINITY, INFINITY, 3, INFINITY, 0, 4}, // F
        {INFINITY, INFINITY, INFINITY, 2, 5, 4, 0}         // G
    };
    int n = 7; // Nombre de sommets
    int u = 0; // Départ depuis A

    Dijkstra(Graph, n, u);

    return 0;
}

//----------------------------------------------------------------
//                      FONCTION/PROCEDURE
//----------------------------------------------------------------

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Printing the distance and paths
    for (i = 0; i < n; i++)
        if (i != start) {
            printf("\nDistance de %c à %c: %d", 'A' + start, 'A' + i, distance[i]);
            printf("\nChemin: ");
            afficherChemin(pred, start, i);
        }
}

void afficherChemin(int pred[], int start, int node) {
    if (node == start) {
        printf("%c ", 'A' + start);
        return;
    }
    afficherChemin(pred, start, pred[node]);
    printf("-> %c ", 'A' + node);
}
