void countingsort(int * A, int * B, int size, int k){
    int C[k+1];

    for(int i = 0; i <= k; i++){
        C[i] = 0;
    }

    for(int j = 0; j < size; j++){
        C[A[j]] = C[A[j]]+1;
    }

    for(int i = 1; i <= k; i++){
        C[i] += C[i-1];
    }
    
    for(int j = size-1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
