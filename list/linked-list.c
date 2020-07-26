#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"

struct node {

    int key;
    char *content;
    node *next;

};

struct linked_list {

    int length;
    node *head;

};

//Create a list structure and return a pointer
linked_list *createList(){

    linked_list *l;

    l=(linked_list*)malloc(sizeof(linked_list));

    if(!l){
        printf("The list coudn't be initialized.");
        exit(1);
    }

    l->length=0;
    l->head=NULL;

    return(l);

}

//Insert an element in ascending order to make easy the search later and return the list length
int ascInsert(linked_list *l, int key, char *content) {

    node *new_node, *aux;
    new_node = (node*)malloc(sizeof(node));

    if(!new_node){
        printf("The list coudn't be initialized.\n");
        exit(1);
    }

    new_node->key=key;
    new_node->content=content;

    if(l->head!=NULL){

        aux = l->head;

        while((aux->next!=NULL)&&(new_node->key>=aux->next->key)){
            aux=aux->next;
        }
        
        //For the case where the element must be insert in the first position of the lsit
        if((l->head==aux)&&(new_node->key<aux->key)){
            new_node->next=aux;
            l->head=new_node;

        } else {
            new_node->next=aux->next;
            aux->next=new_node;
        }

    } else {

        new_node->next=NULL;
        l->head=new_node;

    }

    l->length++;

    return(l->length);

}

int isInside(linked_list *l, int key) {

    node *aux;
    aux=l->head;

    while((aux!=NULL)&&(aux->key!=key)) {

        aux=aux->next;

    }

    if((aux!=NULL)&&(aux->key==key)) {
        return 1;
    } else {
        return 0;
    }

}

//Display all elements at the list
void show(linked_list *l){

    node *aux;
    aux = l->head;

    while(aux!=NULL) {
        printf("%d\n%s\n",aux->key,aux->content);
        aux=aux->next;
    }

    return;

}

//Display the head of the list 
void head(linked_list *l) {

    if(l->head!=NULL){
        printf("%d\n",l->head->key);
        printf("%s\n",l->head->content);
    }

    return;

}

//Removes an element with an specific key
void removeElement(linked_list *l, int key) {

    node *aux,*rmv;
    aux=l->head;

    if((l->head!=NULL)&&(l->head->key==key)){

        l->head=l->head->next;
        free(aux);

    } else {

        while((aux->next!=NULL)&&(key!=aux->next->key)){

            aux=aux->next;

        }

        //Found the key
        if(aux->next!=NULL) {

            rmv=aux->next;
            aux->next=aux->next->next;
            free(rmv);
            printf("Element sucefully removed.\n");

        } else {

            printf("The element isn't in this list.\n");

        }

    }

    l->length--;

    return;

}

//Returns the length of the list
int len(linked_list *l) {

    return(l->length);

}

//Concatenate two lists and return it in a new list pointer
linked_list *unionList(linked_list *l1,linked_list *l2) {

    node *aux_1, *aux_2, *aux_3;
    linked_list *l3;

    l3=(linked_list*)malloc(sizeof(linked_list));

    if(!l3) {
        printf("The list coudn't be initialized.\n");
        exit(1);
    }

    if((!!l1)&&(!!l2)){

        if((l1->head!=NULL)&&(l2->head!=NULL)) {

            aux_1=l1->head;
            aux_2=l2->head;

            l3->length = 0;

            while((aux_1!=NULL)&&(aux_2!=NULL)) {   

                node *new_node;   
                
                new_node = (node*)malloc(sizeof(node));

                if(!new_node) {
                    printf("The list coudn't be initialized.\n");
                    exit(1);
                }      
            

                if(aux_1->key<aux_2->key) {

                    new_node->key=aux_1->key;
                    new_node->content=aux_1->content;
                    aux_1=aux_1->next;
                    
                } else {

                    new_node->key=aux_2->key;
                    new_node->content=aux_2->content;
                    aux_2=aux_2->next;

                }

                if(l3->length==0) {
                    l3->head = new_node;
                    aux_3=l3->head;
                }
                aux_3->next=new_node;
                aux_3=aux_3->next;
                l3->length++;
            }

            while(aux_1!=NULL) {

                node *new_node;   
                
                new_node = (node*)malloc(sizeof(node));

                if(!new_node) {
                    printf("The list coudn't be initialized.\n");
                    exit(1);
                }

                new_node->key=aux_1->key;
                new_node->content=aux_1->content;
                aux_1=aux_1->next;  

                if(l3->length==0) {
                    l3->head = new_node;
                    aux_3=l3->head;
                }


                aux_3->next=new_node;
                aux_3=aux_3->next; 
                l3->length++;   

            }

            while(aux_2!=NULL) {

                node *new_node;   
                
                new_node = (node*)malloc(sizeof(node));

                if(!new_node) {
                    printf("The list coudn't be initialized.\n");
                    exit(1);
                }

                new_node->key=aux_2->key;
                new_node->content=aux_2->content;
                aux_2=aux_2->next;

                if(l3->length==0) {
                    l3->head = new_node;
                    aux_3=l3->head;
                }
                
                aux_3->next=new_node;
                aux_3=aux_3->next; 
                l3->length++;        

            }

            return(l3);

        } else {

            printf("One of the lists is empty.\n");

            if(l1->head==NULL) {
                return(l2);
            } else {
                return(l1);
            }

        }

    } else {

        printf("Coudn't use empty list.\n");
        return(l3);        

    }

}

//Empties a list
void empties(linked_list *l) {

    node *aux;

    while(l->head!=NULL) {

        aux = l->head;
        l->head = l->head->next;
        free(aux);
    }

    printf("Esvaziou\n");

    return;

}
