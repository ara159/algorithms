#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct dnode {
    int key;
    struct dnode * next;
    struct dnode * previus;
};

struct dlist {
    struct dnode * head;
};

struct dnode * create_dnode(int k){
    struct dnode * n = malloc(sizeof(struct dnode));
    n->key = k;
    n->next = NULL;
    n->previus = NULL;
    return n;
}

struct dlist * create_dlist(){
    struct dlist * d = malloc(sizeof(struct dlist));
    return d;
}

void print_dlist(struct dlist * d){
    struct dnode * a = d->head;
    while(a != NULL){
        printf("%d, ", a->key);
        a = a->next;
    }
    printf("\n");
}

int dlist_empty(struct dlist * d){
    return d->head == NULL;
}

struct dnode * dlist_search(struct dlist * d, int k){
    struct dnode * x = d->head;
    while(x != NULL && x->key != k)
        x = x->next;
    return x;
}

void _dlist_insert(struct dlist * d, struct dnode * x){
    x->next = d->head;
    if(!dlist_empty(d))
        d->head->previus = x;
    d->head = x;
    x->previus = NULL;
}

void dlist_insert(struct dlist * d, int k){
    struct dnode * x = create_dnode(k);
    _dlist_insert(d, x);
}

void _dlist_delete(struct dlist * d, struct dnode * x){
    if(x->previus != NULL)
        x->previus->next = x->next;
    else
        d->head = x->next;
    if(x->next != NULL)
        x->next->previus = x->previus;
    free(x);
}

int dlist_delete(struct dlist * d, int x){
    struct dnode * n = dlist_search(d, x);
    if(n != NULL){
        _dlist_delete(d, n);
        return 1;
    }
    else
        return 0;
}

void destroy_dlist(struct dlist * d){
    struct dnode * a = d->head;
    struct dnode * p;
    while(a != NULL){
        p = a;
        a = a->next;
        free(p);
    }
    free(d);
}