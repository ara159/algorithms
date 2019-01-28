#include <stdlib.h>
#include <limits.h>
#include "../linked_list.c"

void lstack_push(struct list * l, int x){
    list_insert(l, x);
}

int lstack_pop(struct list * l){
    struct node * n = l->head;
    if(n != NULL){
        int x = n->key;
        _list_delete(l, l->head);
        return x;
    }
    return LIST_EMPTY;
}