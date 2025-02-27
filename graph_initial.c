#include <stdio.h>

#define NB_SOMMETS 9
#define INFINI 99999

// Indices : A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7, I=8
int matrice[NB_SOMMETS][NB_SOMMETS] = {
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

int main() 
{
    // Affichage pour vérifier
    printf("Matrice d’adjacence (A..I) :\n");
    for(int i = 0; i < NB_SOMMETS; i++){
        for(int j = 0; j < NB_SOMMETS; j++){
            if(matrice[i][j] == INFINI) {
                printf("INF\t");
            } else {
                printf("%d\t", matrice[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
