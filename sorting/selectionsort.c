void selectionsort(int * arrange, int size){
    int aux, min, i, j;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i; j < size; j++){
            if(arrange[j] < arrange[min]){
                min = j;
            }
        }
        aux = arrange[i];
        arrange[i] = arrange[min];
        arrange[min] = aux;
    }
}