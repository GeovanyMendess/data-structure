#include <stdlib.h>
#include <stdio.h>
#include "red-black-tree.h"

int main (int argc, char** argv) {

    rb_tree *t = createRbTree();

    insertRB(t,12); 
    insertRB(t,5); 
    insertRB(t,19); 
    insertRB(t,2); 
    insertRB(t,1); 
    insertRB(t,9); 
    insertRB(t,14); 
    insertRB(t,20); 
    insertRB(t,13);
    insertRB(t,12); 
    insertRB(t,5); 
    insertRB(t,19); 
    insertRB(t,2); 
    insertRB(t,1); 
    insertRB(t,9); 
    insertRB(t,14); 
    insertRB(t,20); 
    insertRB(t,13);

    deleteRB(t,14);
    deleteRB(t,2);
    deleteRB(t,9);
    deleteRB(t,12);
    deleteRB(t,12);

    // printf("%d\n",rootKey(t));
    inOrderTreeWalk(t,root(t));
    printf("\n\n\n");

    exit(0);

}