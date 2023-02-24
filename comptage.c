#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "comptage.h"

//Génère nbCases entiers positifs complètement aléatoires

void generationAleatoire(int * tab, const int nbCases) {
    
    srand(time(NULL)); //initialisation du random

    int nb;

    for(int i=0; i<nbCases; i++) {
        nb = rand();
        tab[i]=nb;
    }

}

//Génère un tableau des valeurs comprises entre min et max

int * generationControlee(int * tab, const int nbCases, const int min, const int max) { 
    
    srand(time(NULL)); //initialisation du random

    int nb;

    for(int i=0; i<nbCases; i++) {
        nb = min + rand() % (max - min + 1);
        tab[i]=nb;
    }

    return tab;

}

//Prend un tableau déclaré mais non initialisé en argument et génère min-max cases comprenant toutes les valeurs de min à max dans un ordre aléatoire

int * generationComplete(int * tab, const int min, const int max) {
    srand(time(NULL)); //initialisation du random

    tab = (int *) calloc( max+min+1, sizeof(int) );

    int IdCase;
    if(min==0) {
        for(int i=min+1; i<max; i++) {
            IdCase = min + rand() % (max - min + 1);
            while(tab[IdCase-min]!=0) {
            IdCase = min + rand() % (max - min + 1);
            }
            tab[IdCase-min]=i;
        }
    }
    else {
        for(int i=min; i<max; i++) {
            IdCase = min + rand() % (max - min + 1);
            while(tab[IdCase]!=0) {
                IdCase = min + rand() % (max - min + 1);
            }
            tab[IdCase]=i;    
            }
    }

    printf("max : %d\n", max);

    return tab;

}

int * comptage(int * tab, int nbCases) {
    int min, max;
    int i,j;

    trouverMinMax(tab, nbCases, &min, &max);

    int * rangement = (int *) calloc (max-min+1, sizeof(int));

    for(i=0; i<nbCases; i++) {
        rangement[tab[i]-min]++;
    }

    j=0;
    for(i=0; i<max-min+1; i++) {
        while(rangement[i]!=0) {
            tab[j]=i+min;
            j++;
            rangement[i]--;
        }
    }
    free(rangement);

    return tab;
}

void trouverMinMax(const int * tab, const int nbCases, int * min, int * max) {
    *min=tab[0];
    *max=tab[0];
    for(int i=0; i<nbCases; i++) {
       if(tab[i] > *max) {
            *max=tab[i];
       }
       if(tab[i] < *min) {
            *min=tab[i];
       } 
    }
}

void afficherTab(const int * tab, const int nbCases) {
    printf("Tableau : ");
    for(int i=0; i<nbCases; i++) {
        printf("%d ", tab[i]);        
    }
    printf("\n");
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

void algo2 (int tab [], int nb ){
    int* cpt;
    int min = tab [0] , max = tab [0];
    int i,j;
    for(i=1; i<nb; i++){
        if(min > tab[i]) min = tab[i];
        if(max < tab[i]) max = tab[i];
    }
    cpt = (int *) calloc ((max -min +1) , sizeof (int ));
    if(cpt == NULL ){
        printf ("pb aloc mémoire \n");
        exit (1);
    }
    for(i = 0; i<nb; i++){
        cpt[tab[i]-min ]++;
    }
    j=0;
    for(i=0; i< max -min +1 ; i++){
        while (cpt[i ]!=0){
            tab[j] = i+min;
            j++;
            cpt[i]--;
        }
    }
    free(cpt );
    }