#include <stdlib.h>
#include <stdio.h>
#include "binary-tree.h"

int main (int argc, char** argv) {

    tree *t = createTree();

    insertTree(t,14);
    insertTree(t,97);
    insertTree(t,84);
    insertTree(t,93);
    insertTree(t,20);
    insertTree(t,52);
    insertTree(t,82);
    insertTree(t,56);
    insertTree(t,56);
    insertTree(t,60);
    insertTree(t,57);
    insertTree(t,18);
    insertTree(t,78);
    insertTree(t,81);
    insertTree(t,85);
    insertTree(t,97);

    preOrderTreeWalk(root(t));
    printf("\n\n\n");
    inOrderTreeWalk(root(t));
    printf("\n\n\n");
    postOrderTreeWalk(root(t));

    exit(0);

}