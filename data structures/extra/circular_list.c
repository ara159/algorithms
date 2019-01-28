#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list.c"

struct cdlist{
    struct dnode * null;
};

struct cdlist * create_cdlist(){
    struct cdlist * n = malloc(sizeof(struct cdlist));
    n->null = malloc(sizeof(struct dnode));
    n->null->next = n->null;
    n->null->previus = n->null;
    return n;
}

void print_cdlist(struct cdlist * d){
    struct dnode * a = d->null->next;
    while(a != d->null){
        printf("%d, ", a->key);
        a = a->next;
    }
    printf("\n");
}

int cdlist_empty(struct cdlist * d){
    return d->null->next == d->null;
}

struct dnode * cdlist_search(struct cdlist * d, int k){
    struct dnode * x = d->null->next;
    while(x != d->null && x->key != k)
        x = x->next;
    return x;
}

void _cdlist_insert(struct cdlist * d, struct dnode * x){
    x->next = d->null->next;
    d->null->next->previus = x;
    d->null->next = x;
    x->previus = d->null;
}

void cdlist_insert(struct cdlist * d, int k){
    struct dnode * x = create_dnode(k);
    _cdlist_insert(d, x);
}

void _cdlist_delete(struct cdlist * c, struct dnode * x){
    x->previus->next = x->next;
    x->next->previus = x->previus;
}

int cdlist_delete(struct cdlist * d, int x){
    struct dnode * n = cdlist_search(d, x);
    if(n != d->null){
        _cdlist_delete(d, n);
        return 1;
    }
    else
        return 0;
}

// it's destroy the list x, and union is now, list d
void cdlist_union(struct cdlist * d, struct cdlist * x){
    d->null->previus->next = x->null->next;
    x->null->next->previus = d->null->previus;
    d->null->previus = x->null->previus;
    x->null->previus->next = d->null;
    free(x->null);
    free(x);
}

void destroy_cdlist(struct cdlist * d){
    struct dnode * a = d->null->next;
    struct dnode * p;
    while(a != d->null){
        p = a;
        a = a->next;
        free(p);
    }
    free(d);
}