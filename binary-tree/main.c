#include <stdlib.h>
#include <stdio.h>
#include "binary-tree.h"

int main (int argc, char** argv) {

    tree *t = createTree();

    insertTree(t,12); //
    insertTree(t,5); //
    insertTree(t,19);
    insertTree(t,2); //
    insertTree(t,1); //
    insertTree(t,9);
    insertTree(t,14); //
    insertTree(t,20); //
    insertTree(t,13);
    insertTree(t,17); //
    insertTree(t,21); //
    insertTree(t,15);
    insertTree(t,18);
    insertTree(t,16);

    treeDelete(t,14);
    treeDelete(t,17);
    treeDelete(t,21);
    treeDelete(t,14);
    treeDelete(t,12);
    treeDelete(t,12);
    treeDelete(t,1);
    treeDelete(t,5);
    treeDelete(t,2);
    treeDelete(t,20);
    treeDelete(t,13);



    preOrderTreeWalk(root(t));
    printf("\n\n\n");
    inOrderTreeWalk(root(t));
    printf("\n\n\n");
    postOrderTreeWalk(root(t));

    exit(0);

}