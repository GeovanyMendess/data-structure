#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

struct node{

    char *text;
    node *next;

};

struct stack{

    node *top;

};

stack *createStack() {

    stack *s;
    s = (stack*)malloc(sizeof(stack));

    if(!s) {
        printf("The stack coudn't be initialized.");
        exit(1);
    }
    s->top = NULL;
    return(s); 
}