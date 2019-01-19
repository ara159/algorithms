void insertionsort(int * arrange, int size){
    int chave, aux, i, j;
    for(i = 1; i < size; i++){
        chave = arrange[i];
        j = i-1;
        while(j >= 0 && arrange[j] > chave){
            arrange[j+1] = arrange[j];
            j--;
        }
        arrange[j+1] = chave;
    }
}