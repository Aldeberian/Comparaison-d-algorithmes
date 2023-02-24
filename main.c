#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "comptage.h"

#define nbCases 1000000000
#define MAX 10

void testMinMax() {
    int * tab = (int *) malloc(nbCases * sizeof(int));
    clock_t start_time, end_time;
    double elapsed_time;
    int i;

    for(i=1; i<MAX; i++) {
        generationControlee(tab, nbCases, 0, pow(10,i));
        
        start_time = clock();
        algo2(tab, nbCases);
        end_time = clock();
        elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Pour des éléments allant de 0 à %0.1f", pow(10, i));
        for(int j=0;j<MAX-i;j++) {
            printf(" ");
        }
        printf("trier le tableau prend %f secondes\n", elapsed_time);
    }
}

void testTailleTab() {
    clock_t start_time, end_time;
    double elapsed_time;
    int i;

    for(i=1; i<MAX; i++) {
        
        int * tab = (int *) malloc(pow(10,i) * sizeof(int));
        generationControlee(tab, pow(10,i), 0, 100000000);
        
        start_time = clock();
        algo2(tab, pow(10,i));
        end_time = clock();
        elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Pour un tableau d'entiers inférieurs à 100 contenant %0.1f", pow(10, i));
        for(int j=0;j<MAX-i;j++) {
            printf(" ");
        }
        printf("cases, trier le tableau prend %f secondes\n", elapsed_time);
    }    
}

void testReverse() {
    int * tab = (int*) malloc(nbCases * sizeof(int));
    int i;

    // On remplit le tableau avec des valeurs décroissantes
    for(i=0; i<nbCases; i++) {
        tab[i] = nbCases - i;
    }
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();
    algo2(tab, nbCases);
    end_time = clock();
    elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Pour un tableau de %d entiers décroissants trier le tableau prend %f secondes\n", nbCases, elapsed_time);
}

void testTriee() {
    int * tab = (int*) malloc(nbCases * sizeof(int));
    int i;

    // On remplit le tableau avec des valeurs croissantes
    for(i=0; i<nbCases; i++) {
        tab[i] = i;
    }
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();
    algo2(tab, nbCases);
    end_time = clock();
    elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Pour un tableau de %d entiers croissants trier le tableau prend %f secondes\n", nbCases, elapsed_time);

}

void testAleatoire() {
    int * tab = (int*) malloc(nbCases * sizeof(int));
    int i;

    // On remplit le tableau avec des valeurs aléatoires
    for(i=0; i<nbCases; i++) {
        tab[i] = rand();
    }
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();
    algo2(tab, nbCases);
    end_time = clock();
    elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Pour un tableau de %d entiers aléatoires trier le tableau prend %f secondes\n", nbCases, elapsed_time);
}

//une fonction qui génère un tableau de nbCases rempli uniquement de 1 et de 2 dans un ordre aléatoire en utilisant les fonctions dans comptage.c
void testAleatoire2() {
    int * tab = (int*) malloc(nbCases * sizeof(int));
    int i;

    // On remplit le tableau avec des valeurs aléatoires
    for(i=0; i<nbCases; i++) {
        tab[i] = rand()%2 + 1;
    }
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();
    algo2(tab, nbCases);
    end_time = clock();
    elapsed_time= ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Pour un tableau de %d entiers aléatoires trier le tableau prend %f secondes\n", nbCases, elapsed_time);
}

int main(void) {
    testMinMax();
    return 0;
}

