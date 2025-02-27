#include <stdio.h>

#define NB_SOMMETS 9
#define INFINI 99999

// Tableau contenant les noms des sommets (A, B, C, ... I)
char sommets[NB_SOMMETS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

// Matrice des distances entre les sommets
int distances[NB_SOMMETS][NB_SOMMETS] = {
    //    A      B      C      D      E      F      G      H      I
    {    0,     6,     4,     3,  INFINI, INFINI, INFINI, INFINI, INFINI }, // A
    {INFINI,    0,  INFINI, INFINI,    3,     3,  INFINI, INFINI, INFINI }, // B
    {INFINI,    1,     0,  INFINI, INFINI, INFINI, INFINI, INFINI, INFINI }, // C
    {INFINI,INFINI,    2,     0,     4,  INFINI, INFINI,    3,  INFINI }, // D
    {INFINI,INFINI,INFINI, INFINI,    0,     5,  INFINI,    5,  INFINI }, // E
    {INFINI,INFINI,INFINI, INFINI,INFINI,    0,  INFINI, INFINI,    8   }, // F
    {INFINI,INFINI,INFINI, INFINI,INFINI, INFINI,    0,  INFINI,    4   }, // G
    {INFINI,INFINI,INFINI, INFINI,INFINI, INFINI,    2,     0,    7   }, // H
    {INFINI,INFINI,INFINI, INFINI,INFINI, INFINI, INFINI, INFINI,    0   }  // I
};

// Fonction pour afficher les sommets
void afficher_sommets() {
    printf("Sommets : ");
    for (int i = 0; i < NB_SOMMETS; i++) {
        printf("%c ", sommets[i]);
    }
    printf("\n");
}

// Fonction pour afficher la matrice des distances
void afficher_distances() {
    printf("\nMatrice des distances :\n    ");
    for (int i = 0; i < NB_SOMMETS; i++) {
        printf("%c\t", sommets[i]); // Affichage des noms des colonnes
    }
    printf("\n");

    for (int i = 0; i < NB_SOMMETS; i++) {
        printf("%c | ", sommets[i]); // Affichage des noms des lignes
        for (int j = 0; j < NB_SOMMETS; j++) {
            if (distances[i][j] == INFINI) {
                printf("INF\t");  // Affichage des valeurs infinies
            } else {
                printf("%d\t", distances[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    afficher_sommets();
    afficher_distances();
    return 0;
}
