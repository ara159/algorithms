#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../stack.c"

#define QS_MAX 0;

struct qs{
    int * arrange;
    int size;
    struct stack * s1;
    struct stack * s2;
};

struct qs * create_qs(int size){
    struct qs * n = malloc(sizeof(struct qs));
    n->arrange = malloc(sizeof(int)*size);
    n->s1 = create_stack(size);
    n->s2 = create_stack(size);
    n->size = size;
    return n;
}

void print_qs(struct qs * q){
    printf("qs: ");
    for(int i = 0; i < q->size; i++)
        printf("%d, ", q->arrange[i]);
    printf("\n");
}

int qs_enqueue(struct qs * q, int x){
    if(!stack_full(q->s1)){
        if(stack_empty(q->s1))
            push(q->s1, 0);
        else
            push(q->s1, (stack_top(q->s1)+1) % q->size);
        q->arrange[stack_top(q->s1)] = x;
        return 1;
    }
    else
        return QS_MAX;
}

int qs_dequeue(struct qs * q){
    if(!stack_empty(q->s1)){
        while(!stack_empty(q->s1))
            push(q->s2, pop(q->s1));
        int x = q->arrange[pop(q->s2)];
        while(!stack_empty(q->s2))
            push(q->s1, pop(q->s2));
        printf("out: %d\n", x);
        return x;
    }
}

void destroy_qs(struct qs * q){
    destroy_stack(q->s1);
    destroy_stack(q->s2);
    free(q->arrange);
    free(q);
}