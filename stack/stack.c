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

char *push(stack *s,char *word) {

    // Getting word size
    int word_size = strlen(word);

    node *element;

    element = (node*)malloc(sizeof(node));

    // Checks if node has been initialized
    if(!element) {
        printf("The node coudn't be initialized.");
        exit(1);
    }

    // Initialize the string text
    element->text=(char*)malloc(sizeof(char)*word_size);

    // Copy the content of word to text
    memcpy(element->text,word,word_size+1);

    // Put the node in the stack
    element->next = s->top;
    s->top = element;

    return(element->text);

}

char *pop(stack *s){

    node *aux;
    char *poped;
    int top_length;

    if(s->top!=NULL){

        poped=s->top->text;

        aux = s->top;
        s->top = s->top->next;

        free(aux);

        return(poped);

    } else {

        return("Stack empty.");
    }
}

char *top(stack *s){

    if(s->top!=NULL){
        return(s->top->text);
    } else {
        return("Stack empty.");
    }
}

