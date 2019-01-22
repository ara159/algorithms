#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct doubly_node {
    int key;
    struct doubly_node * next;
    struct doubly_node * previus;
};

struct doubly_list {
    struct doubly_node * head;
};

struct doubly_node * create_dnode(int k){
    struct doubly_node * n = malloc(sizeof(struct doubly_node));
    n->key = k;
    n->next = NULL;
    n->previus = NULL;
    return n;
}

struct doubly_list * create_dlist(){
    struct doubly_list * d = malloc(sizeof(struct doubly_list));
    return d;
}

void print_dlist(struct doubly_list * d){
    struct doubly_node * a = d->head;
    while(a != NULL){
        printf("%d, ", a->key);
        a = a->next;
    }
    printf("\n");
}

int dlist_empty(struct doubly_list * d){
    return d->head == NULL;
}

struct doubly_node * dlist_search(struct doubly_list * d, int k){
    struct doubly_node * x = d->head;
    while(x != NULL && x->key != k)
        x = x->next;
    return x;
}

void _dlist_insert(struct doubly_list * d, struct doubly_node * x){
    x->next = d->head;
    if(!dlist_empty(d))
        d->head->previus = x;
    d->head = x;
    x->previus = NULL;
}

void dlist_insert(struct doubly_list * d, int k){
    struct doubly_node * x = create_dnode(k);
    _dlist_insert(d, x);
}

void _dlist_delete(struct doubly_list * d, struct doubly_node * x){
    if(x->previus != NULL)
        x->previus->next = x->next;
    else
        d->head = x->next;
    if(x->next != NULL)
        x->next->previus = x->previus;
    free(x);
}

int dlist_delete(struct doubly_list * d, int x){
    struct doubly_node * n = dlist_search(d, x);
    if(n != NULL){
        _dlist_delete(d, n);
        return 1;
    }
    else
        return 0;
}

void destroy_dlist(struct doubly_list * d){
    struct doubly_node * a = d->head;
    struct doubly_node * p;
    while(a != NULL){
        p = a;
        a = a->next;
        free(p);
    }
    free(d);
}