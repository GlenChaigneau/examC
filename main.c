#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// On set les variables pour pouvoir les modifier plus facilement
#define M 8
#define N 8
int v = 0;

// On déclare les tableaux que l'on va utiliser
int tableauJoueur[M][N];
int tableauTest[M][N];


// Fonction copie qui copie aléatoirement des valeurs du tableau solution dans le tableau tableauJoueur composé entièrement de 2.

void copie(int tableauJoueur[M][N], int tableauSolution[M][N]){
    int i, j, k;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            tableauJoueur[i][j] = 2;
        }
    }
    for(k=0; k<8; ++k){
        i = rand()%8;
        j = rand()%8;
        tableauJoueur[i][j] = tableauSolution[i][j];
    }
}

// Fonction afficher qui affiche le tableauJoueur.

void afficher(int tableauJoueur[M][N]){
    int i, j;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
}

// Fonction verifierLigne qui vérifie si sur la ligne i il n'y a pas plus de deux fois la même valeur a la suite, et qu'il y a autant de 0 que de 1.

int verifierLigne(int tableauJoueur[M][N], int i){
    int j, k;
    int compteur0 = 0;
    int compteur1 = 0;
    for(j=0; j<8; ++j){
        if(tableauJoueur[i][j] == 0)
            compteur0++;
        if(tableauJoueur[i][j] == 1)
            compteur1++;
        if(tableauJoueur[i][j] == 1 && tableauJoueur[i][j+1] == 1 && tableauJoueur[i][j+2] == 1 )
            return 0;
        if(tableauJoueur[i][j] == 0 && tableauJoueur[i][j+1] == 0 && tableauJoueur[i][j+2] == 0 )
            return 0;
    }
    if(compteur0 != compteur1)
        return 0;
    return 1;
}

// Fonction verifierColonne qui vérifie si sur la colonne j il n'y a pas plus de deux fois la même valeur a la suite, et qu'il y a autant de 0 que de 1.

int verifierColonne(int tableauJoueur[M][N], int j){
    int i, k;
    int compteur0 = 0;
    int compteur1 = 0;
    for(i=0; i<8; ++i){
        if(tableauJoueur[i][j] == 0)
            compteur0++;
        if(tableauJoueur[i][j] == 1)
            compteur1++;
        if(tableauJoueur[i][j] == 1 && tableauJoueur[i+1][j] == 1 && tableauJoueur[i+2][j] == 1 )
            return 0;
        if(tableauJoueur[i][j] == 0 && tableauJoueur[i+1][j] == 0 && tableauJoueur[i+2][j] == 0 )
            return 0;
    }
    if(compteur0 != compteur1)
        return 0;
    return 1;
}

// Fonction verifierLigneColonne qui vérifie si sur la ligne i et la colonne j il n'y a pas plus de deux fois la même valeur a la suite, et qu'il y a autant de 0 que de 1.

int verifierLigneColonne(int tableauJoueur[M][N], int i, int j){
    if(verifierLigne(tableauJoueur, i) == 0)
        return 0;
    if(verifierColonne(tableauJoueur, j) == 0)
        return 0;
    return 1;
}

// - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire) qui renvoie 1 si la grille est gagnée, 0 sinon

int verifierGrille(int tableauJoueur[M][N]){
    int i, j, k;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            if(tableauJoueur[i][j] != 0 && tableauJoueur[i][j] != 1)
                return 0;
            if(verifierLigneColonne(tableauJoueur, i, j) == 0)
                return 0;
        }
    }
    return 1;
}
void saisir(int tableauJoueur[M][N]){
    int i, j, k;
    printf("Saisir i, j, v : ");
    scanf("%d %d %d", &i, &j, &v);
    if(i<0 || i>7 || j<0 || j>7){
        printf("Coordonnees invalides");
        printf("\n");
        saisir(tableauJoueur);
    }
    if(tableauJoueur[i][j] != 2){
        printf("Case deja remplie");
        printf("\n");
        saisir(tableauJoueur);
    }
    if(verifierLigneColonne(tableauJoueur, i, j) == 0){
        printf("Regles du Takuzu non respectees");
        printf("\n");
        saisir(tableauJoueur);
    }
    tableauJoueur[i][j] = v;
}
// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");

    int solution[8][8] = {
            {1,1,0,1, 0,1,0,0},
            {0,0,1,0, 1,0,1,1},
            {0,1,0,0, 1,1,0,1},
            {1,0,1,1, 0,0,1,0},

            {1,0,1,0, 0,1,1,0},
            {0,1,0,1, 1,0,0,1},
            {1,1,0,0, 1,0,1,0},
            {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i)
    {
        for(j=0; j<8; ++j)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
    printf("---------------------------------");
    printf("\n");
    //toucher le code entre les commentaires

    printf("    TAKUZU");
    printf("\n");
    int tableauJoueur[M][N];
    int tableauTest[M][N];
    copie(tableauJoueur, solution);
    afficher(tableauJoueur);
    do {
        for (i = 0; i < 8; ++i) {
            for (j = 0; j < 8; ++j)
                tableauTest[i][j] = tableauJoueur[i][j];
        }
        saisir(tableauJoueur);
        verifierLigneColonne(tableauJoueur, i, j);
        afficher(tableauJoueur);
    } while (verifierGrille(tableauJoueur) == 0);

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
