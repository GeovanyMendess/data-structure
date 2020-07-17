#ifndef STACK_H
#define STACK_H

//Defining the stack structure and the node
//Each node stores one number, as an id and a string  
typedef struct linked_list linked_list;
typedef struct node node;

//Create a list structure and return a pointer
linked_list *createList();
//Insert an element in ascending order to make easy the search later and return the list length
int ascInsert(linked_list *l, int key, char *content);
//Display all elements at the list
void show(linked_list *l);
//Display the head of the list 
void head(linked_list *l);
//Find if a key is inside the list, returning 1 if's there and 0 otherwise
int isInside(linked_list *l, int key);
//Removes an element with an specific key
void removeElement(linked_list *l, int key);
//Returns the length of the list
int len(linked_list *l);
//Concatenate two lists and return it in a new list pointer
linked_list *unionList(linked_list *l1,linked_list *l2);
//Empties a list
void empties(linked_list *l);



#endif