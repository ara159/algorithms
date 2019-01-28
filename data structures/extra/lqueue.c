#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../linked_list.c"

void lqueue_enqueue(struct list * l, int x){
    list_insert_last(l, x);
}

int lqueue_dequeue(struct list * l){
    struct node * n = l->head;
    if(n != NULL){
        int x = n->key;
        _list_delete(l, n);
        return x;
    }
    return LIST_EMPTY;
}
