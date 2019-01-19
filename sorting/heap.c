#include <stdlib.h>

struct heap{
    int size;
    int length;
    int * arrange;
};

int parent(int i){
    return (i/2)-0.5;
}

int left(int i){
    return i*2+1;
}

int right(int i){
    return i*2+2;
}

struct heap * create_heap(int * arrange, int length){
    struct heap * h = malloc(sizeof(struct heap));
    h->arrange = arrange;
    h->length = length;
    h->size = length;
    return h;
}

void max_heapify_iterativo(struct heap h, int i){
    int maior, aux, l, r;
    while(1){
        l = left(i);
        r = right(i);
        
        if(l < h.size && h.arrange[l] > h.arrange[i]){
            maior = l;
        }
        else{
            maior = i;
        }

        if(r < h.size && h.arrange[r] > h.arrange[maior]){
            maior = r;
        }

        if(maior != i){
            aux = h.arrange[i];
            h.arrange[i] = h.arrange[maior];
            h.arrange[maior] = aux;
            i = maior;
        }else{
            break;
        }
    }
}

void max_heapify(struct heap * h, int i){
    int maior, aux;
    int l = left(i);
    int r = right(i);

    if(l < h->size && h->arrange[l] > h->arrange[i]){
        maior = l;
    }
    else{
        maior = i;
    }

    if(r < h->size && h->arrange[r] > h->arrange[maior]){
        maior = r;
    }
    
    if(maior != i){
        aux = h->arrange[i];
        h->arrange[i] = h->arrange[maior];
        h->arrange[maior] = aux;
        max_heapify(h, maior);
    }
}

void build_max_heapify(struct heap * h){
    for(int i = h->size/2; i >= 0; i--){
        max_heapify(h, i);
    }
}

void heapsort(struct heap * h){
    int aux;
    build_max_heapify(h);
    for(int i = h->size-1; i >= 0; i--){
        aux = h->arrange[i];
        h->arrange[i] = h->arrange[0];
        h->arrange[0] = aux;
        h->size--;
        max_heapify(h, 0);
    }
}
