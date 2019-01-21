#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct node {
    int key;
    struct node * next;
};

struct list {
    struct node * head;
};

struct list * create_list(void){
    struct list * l = malloc(sizeof(struct list));
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

void list_insert(struct list * l, int x){
    if(list_empty(l)){
        l->head = malloc(sizeof(struct node));
        l->head->key = x;
    }
    else{
        struct node * n = malloc(sizeof(struct node));
        n->key = x;
        n->next = l->head;
        l->head = n;
    }
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
            free(x);
        }
        else{
            struct node * a = l->head;
            while(a->next != x){
                a = a->next;
            }
            a->next = a->next->next;
            free(x);
            return 1;
        }
    }else
        return 0;
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