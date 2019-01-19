void bubblesort(int * arrange, int size){
    int aux, i, j;
    for(i = size-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(arrange[j] > arrange[j+1]){
                aux = arrange[j];
                arrange[j] = arrange[j+1];
                arrange[j+1] = aux;
            }
        }
    }
}