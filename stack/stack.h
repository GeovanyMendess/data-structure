
#ifndef STACK_H
#define STACK_H

// Defining the stack structure and the node 
typedef struct stack stack;
typedef struct node node;

//Create a stack structure and return it pointing the top to NULL
stack *createStack();
//Push one string to the top of the stack and returns a point to the node containing the string pushed
char *push(stack *s,char *word);
//Remove the element from the top of the stack and return that
char *pop(stack *s);
//Return the element at the top of the stack
char *top(stack *s);
//Empties the stack and return the number of elements removed
int empties(stack *s);
//Return 1 if stack is empty and 0 otherwise
int isEmpty(stack *s);
//Display the data structure without brake rules of stack acess
void show(stack *s);

#endif