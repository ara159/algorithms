#include <limits.h>

void merge(int * arrange, int p, int q, int r){
    int i, j;
    int n1 = q-p+1;
    int n2 = r-q;
    int R[n2+1], L[n1+1];
    
    for(i = 0; i < n1; i++){
        L[i] = arrange[p+i];
    }
    
    for(int j = 0; j < n2; j++){
        R[j] = arrange[q+j+1];
    }
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    i = j = 0;

    for(int k = p; k < r+1; k++){
        if(L[i] < R[j]){
            arrange[k] = L[i];
            i++;
        }else{
            arrange[k] = R[j];
            j++;
        }
    }
}

void _mergesort(int * arrange, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        _mergesort(arrange, p, q);
        _mergesort(arrange, q+1, r);
        merge(arrange, p, q, r);
    }
}

void mergesort(int * arrange, int size){
    _mergesort(arrange, 0, size-1);
}
