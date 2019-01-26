#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list.c"

struct circular_dlist{
    struct doubly_node * null;
};

struct circular_dlist * create_circular_dlist(){
    struct circular_dlist * n = malloc(sizeof(struct circular_dlist));
    n->null = malloc(sizeof(struct doubly_node));
    n->null->next = n->null;
    n->null->previus = n->null;
    return n;
}

void print_cdlist(struct circular_dlist * d){
    struct doubly_node * a = d->null->next;
    while(a != d->null){
        printf("%d, ", a->key);
        a = a->next;
    }
    printf("\n");
}

int cdlist_empty(struct circular_dlist * d){
    return d->null->next == d->null;
}

struct doubly_node * cdlist_search(struct circular_dlist * d, int k){
    struct doubly_node * x = d->null->next;
    while(x != d->null && x->key != k)
        x = x->next;
    return x;
}

void _cdlist_insert(struct circular_dlist * d, struct doubly_node * x){
    x->next = d->null->next;
    d->null->next->previus = x;
    d->null->next = x;
    x->previus = d->null;
}

void cdlist_insert(struct circular_dlist * d, int k){
    struct doubly_node * x = create_dnode(k);
    _cdlist_insert(d, x);
}

void _cdlist_delete(struct circular_dlist * c, struct doubly_node * x){
    x->previus->next = x->next;
    x->next->previus = x->previus;
}

int cdlist_delete(struct circular_dlist * d, int x){
    struct doubly_node * n = cdlist_search(d, x);
    if(n != d->null){
        _cdlist_delete(d, n);
        return 1;
    }
    else
        return 0;
}

void destroy_cdlist(struct circular_dlist * d){
    struct doubly_node * a = d->null->next;
    struct doubly_node * p;
    while(a != d->null){
        p = a;
        a = a->next;
        free(p);
    }
    free(d);
}