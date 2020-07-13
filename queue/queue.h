
#ifndef STACK_H
#define STACK_H

//Defining the stack structure and the node
//Each node stores one number, as an id and a string  
typedef struct queue queue;
typedef struct node node;

//Create a void queue structure and returns a pointer to it
queue *createQueue();
//Puts one element at the end of the queue and returns the id of the node
int enqueue(queue *q,char *name);
//Removes the first element
void dequeue(queue *q);
//Display the first element
void first(queue *q);
//Return 1 if queue is empty and 0 otherwise
int isEmpty(queue *q); 
//Empties the queue
void empties(queue *q);

#endif