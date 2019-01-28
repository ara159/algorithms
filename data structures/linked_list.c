#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define LIST_EMPTY INT_MIN

struct node {
    int key;
    struct node * next;
};

struct list {
    struct node * head;
};

struct node * create_node(int k){
    struct node * n = malloc(sizeof(struct node));
    n->key = k;
    return n;
}

struct list * create_list(void){
    struct list * l = malloc(sizeof(struct list));
    l->head = NULL;
    return l;
}

void print_list(struct list * l){
    struct node * a;
    a = l->head;
    while(a != NULL){
        printf("%d, ", a->key);
        a = a->next;
    }
    printf("\n");
}

int list_empty(struct list * l){
    return l->head == NULL;
}

struct node * list_insert(struct list * l, int x){
    struct node * n = create_node(x);
    if(list_empty(l))
        l->head = n;
    else{
        n->next = l->head;
        l->head = n;
    }
    return n;
}

struct node * list_insert_last(struct list * l, int x){
    struct node * n = create_node(x);
    if(list_empty(l))
        l->head = n;
    else{
        struct node * a = l->head;
        while(a->next != NULL)
            a = a->next;
        a->next = n;
    }
    return n;
}

struct node * list_search(struct list * l, int k){
    struct node * a = l->head;
    while(a != NULL && a->key != k){
        a = a->next;
    }
    return a;
}

int _list_delete(struct list * l, struct node * x){
    if(!list_empty(l) && x != NULL){
        if(x == l->head){
            l->head = x->next;
        }
        else{
            struct node * a = l->head;
            while(a->next != x){
                a = a->next;
            }
            a->next = x->next;
        }
        free(x);
        return 1;
    }
    else
        return 0;
}

void list_reverse(struct list * l){
    struct node * p, * a = l->head;
    while(a != NULL){
        p = a;
        a = a->next;
        list_insert(l, p->key);
        _list_delete(l, p);
    }
}

int list_delete(struct list * l, int k){
    struct node * x = list_search(l, k);
    return _list_delete(l, x);
}

void destroy_list(struct list * l){
    struct node * a, * p;
    a = l->head;
    while(a != NULL){
        p = a->next;
        free(a);
        a = p;
    }
}