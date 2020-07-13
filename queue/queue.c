#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int id_increment=1;

struct node {

    int id;
    char *name;
    node *next;

};

struct queue {

    int length;
    node *first;
    node *last;

};

queue *createQueue() {

    queue *q;

    q=(queue*)malloc(sizeof(queue));

    if(!q) {
        printf("The queue coudn't be initialized.");
        exit(1);
    }

    q->length=0;
    q->first=NULL;
    q->last=NULL;

    return(q);

}

int enqueue(queue *q,char *name) {

    node *new_node;

    new_node=(node*)malloc(sizeof(node));

    if(!new_node) {
        printf("The node coudn't be initialized.\n");
        exit(1);
    }

    new_node->name=name;
    new_node->id=id_increment++;
    new_node->next=NULL;
    q->length++;

    //Empty queue
    if(q->first==NULL){
        q->first=new_node;
        q->last=new_node;
    } else {
        q->last->next=new_node;
        q->last=new_node;
    }

    return(new_node->id);
}

void dequeue(queue *q) {

    node *aux;

    if(q->first!=NULL) {

        aux=q->first;

        if(q->first==q->last){  
            q->first=NULL;
            q->last=NULL;
        } else {
            q->first=q->first->next;
        }

        q->length--;

        free(aux);

    } else {

        printf("Empty queue.\n");

    }

    return;

}

int isEmpty(queue *q){

    if(q->first==NULL) {
        return(1);
    } else {
        return(0);
    }

}

void first(queue *q) {

    if(q->first!=NULL){ 

        printf("id: %d\n",q->first->id);
        printf("Name: %s\n",q->first->name);

    } else {

        printf("Empty queue.\n");

    }
}

void empties(queue *q){

    node *aux;

    printf("Empting queue . . .\n");

    while(q->first!=NULL){

        aux = q->first;
        q->first = q->first->next;
        free(aux);

    }

    printf("Queue empty!\n");

    q->last=NULL;

}






