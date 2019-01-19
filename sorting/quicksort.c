#include <time.h>

int partition(int * arrange, int p, int r){
    int x = arrange[r];
    int i = p-1;
    int aux;

    for(int j = p; j < r; j++){
        if(arrange[j] <= x){
            i++;
            aux = arrange[i];
            arrange[i] = arrange[j];
            arrange[j] = aux;
        }
    }

    aux = arrange[r];
    arrange[r] = arrange[i+1];
    arrange[i+1] = aux;

    return i+1;
}

void _quicksort(int * arrange, int p, int r){
    if(p < r){
        int q = partition(arrange, p, r);
        _quicksort(arrange, p, q-1);
        _quicksort(arrange, q+1, r);
    }
}

void quicksort(int * arrange, int size){
    _quicksort(arrange, 0, size-1);
}

//----------------------------------------
// Versão aleatória

int randomized_partition(int * arrange, int p, int r){
    int i = rand() % (r - p) + p + 1;
    int aux = arrange[p];
    arrange[p] = arrange[i];
    arrange[i] = aux;
    return partition(arrange, p, r);
}

int _randomized_quicksort(int * arrange, int p, int r){
    if(p < r){
        int q = randomized_partition(arrange, p, r);
        _randomized_quicksort(arrange, p, q-1);
        _randomized_quicksort(arrange, q+1, r);
    }
}

int randomized_quicksort(int * arrange, int size){
    time_t t;
    srand((unsigned) time(&t));
    _randomized_quicksort(arrange, 0, size-1);
}