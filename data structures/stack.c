#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define QUEUE_EMPTY INT_MIN
#define QUEUE_FULL INT_MAX

struct stack {
    int top;
    int size;
    int * arrange;
};

struct stack * create_stack(int size){
    struct stack * s = malloc(sizeof(struct stack));
    s->arrange = malloc(sizeof(int)*size);
    s->size = size;
    s->top = -1;
    return s;
}

int stack_empty(struct stack * s){
    return s->top == -1;
}

int stack_full(struct stack * s){
    return s->top == s->size-1;
}

int stack_top(struct stack * s){
    if(!stack_empty(s))
        return s->arrange[s->top];
    else
        return QUEUE_EMPTY;
}

int push(struct stack * s, int x){
    if(!stack_full(s)){
        s->top++;
        s->arrange[s->top] = x;
        return 1;
    }
    else{
        return QUEUE_FULL;
    }
}

int pop(struct stack * s){
    if(!stack_empty(s)){
        int x = s->arrange[s->top];
        s->top--;
        return x;
    }
    else{
        return QUEUE_EMPTY;
    }
}

void destroy_stack(struct stack * s){
    free(s->arrange);
    free(s);
}