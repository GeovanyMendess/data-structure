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

    // Copy the content of word to text
    element->text=word;

    // Put the node in the stack
    element->next = s->top;
    s->top = element;

    return(element->text);

}

char *pop(stack *s){

    node *aux;
    char *poped;

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

int empties(stack *s) {

    node *aux;
    int count=0;

    while(s->top!=NULL){
        aux=s->top;
        s->top=s->top->next;
        count++;
        free(aux);
    }

    return(count);
}

int isEmpty(stack *s) {

    if(s->top!=NULL){
        return(1);
    } else {
        return(0);
    }
}

void show(stack *s){

    stack *aux;
    char *printAux;

    aux=(stack*)malloc(sizeof(stack));
    if(!aux){
        printf("The stack coudn't be initialized.");
        exit(1);
    }

    aux->top=NULL;

    while(s->top!=NULL){
        printAux = pop(s);
        printf("%s\n",printAux);
        push(aux,printAux);
    }
    while(aux->top!=NULL){
        push(s,pop(aux));
    }
    
    free(aux);
}