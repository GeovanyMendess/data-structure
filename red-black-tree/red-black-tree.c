#include <stdio.h>
#include <stdlib.h>
#include "red-black-tree.h"

/*These are functions available to the user*/

struct node {

    int key;
    char color;
    node *father;
    node *left;
    node *right;

};

struct rb_tree {

    node *sentinel;
    node *root;

};

/*Auxiliar functions
These functions couldn't be available toa user,
so they're only declared and implemented at the 
red-black-tree.c
*/

//Search for a node in a tree receiving a key and the tree. It return a pointer to the node if the key was found
//OBS: This is iterative method
node *searchTreeIt(rb_tree *tree, int key);
//Search for a node in a tree receiving a key and the root and return a pointer to the node founded
//OBS: This is iterative method
node *searchTreeIt(rb_tree *tree, int key) {

    node *node=tree->root;

    while((node!=tree->sentinel)&&(key!=node->key)) {
        if(key<node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return node;

}

//Find the sucessor of a non null node, returning NULL if the node is the greater,
// otherwise return a pointer to the sucessor 
node *sucessor(rb_tree *tree, node *node);
node *sucessor(rb_tree *tree, node *t_node) {

    node *aux;

    if(t_node!=tree->sentinel) {

        t_node=t_node->right;

        while(t_node->left!=tree->sentinel) {
            t_node=t_node->left;
        }
        return t_node;
    }

    aux=t_node->father;

    while((aux!=tree->sentinel)&&(aux->right==t_node)) {
        t_node=aux;
        aux=aux->father;
    }

    return aux;
}

//Makes a rotate to the left around a pivot
void leftRotate(rb_tree *tree, node *pivot);

void leftRotate(rb_tree *tree, node *pivot) {


        node *r_son=pivot->right; //Declaring the right son
        pivot->right=r_son->left;

        if(r_son->left!=tree->sentinel) { //Avoiding acess properties not initialized
            r_son->left->father=pivot; //Makes the more left grandchild of pivot his son
        }
        r_son->father=pivot->father;

        if(pivot->father==tree->sentinel) {
            tree->root=r_son;
        } else if(pivot==pivot->father->left) {
            pivot->father->left=r_son;
        } else {
            pivot->father->right=r_son;
        }

        r_son->left=pivot; //Makes the pivot the left child of his older right son
        pivot->father=r_son;

        return;

}

//Makes a rotate to the right around a pivot
void rightRotate(rb_tree *tree, node *pivot);
void rightRotate(rb_tree *tree, node *pivot) {  

        node *l_son=pivot->left; //Declaring the right son 
        pivot->left=l_son->right;

        if(l_son->right!=tree->sentinel) { //Avoiding acess properties not initialized
            l_son->right->father=pivot; //Makes the more left grandchild of pivot his son
        }
        l_son->father=pivot->father;

        if(pivot->father==tree->sentinel) {
            tree->root=l_son;
        } else if(pivot==pivot->father->left) {
            pivot->father->left=l_son;
        } else {
            pivot->father->right=l_son;
        }

        l_son->right=pivot; //Makes the pivot the left child of his older right son
        pivot->father=l_son;

        return;

}

//Function to fix the pointers in a red-black-tree delete operation
void transplantRB(rb_tree *tree,node *old_son, node *new_son);
void transplantRB(rb_tree *tree,node *old_son, node *new_son) {

    if(old_son->father==tree->sentinel) {
        tree->root=new_son;
    } else if(old_son==old_son->father->left) {
        old_son->father->left=new_son;
    } else {
        old_son->father->right=new_son;
    }
    new_son->father=old_son->father;

    return;

}

//Create a empty red black tree and return a pointer to the structure
rb_tree *createRbTree() {

    rb_tree *tree;
    node *s;

    tree=(rb_tree*)malloc(sizeof(rb_tree));

    if(!tree) {
        
        printf("The tree coudn't be initialized.\n");
        exit(1);

    }

    s=(node*)malloc(sizeof(node));

    if(!s) {
        
        printf("The sentinel coudn't be initialized.\n");
        exit(1);

    }

    s->father=NULL;
    s->left=NULL;
    s->right=NULL;
    s->color='b';
    s->key=-1000000;

    tree->sentinel=s;
    tree->root=s;

    return tree;

}

//Return a pointer to the tree root if there's exist
node *root(rb_tree *tree) {

    return(tree->root);

}

/*Auxiliar function to fix coloring inconsistencies*/
void fixupInsertRB(rb_tree *tree,node *newNode) {

    node *uncle;

    while(newNode->father->color=='r') {

        if(newNode->father==newNode->father->father->left) { //Father is a son from left of the grandfather

            uncle=newNode->father->father->right;

            if(uncle->color=='r') {

                newNode->father->color='b';
                uncle->color='b';
                newNode->father->father->color='r';
                newNode=newNode->father->father;

            } else if(newNode==newNode->father->right) {

                newNode=newNode->father;
                leftRotate(tree,newNode);

            } else {

                newNode->father->color='b';
                newNode->father->father->color='r';
                rightRotate(tree,newNode->father->father);

            }
            

        } else {  //Father is a son from right of the grandfather

            uncle=newNode->father->father->left;

            if(uncle->color=='r') {

                newNode->father->color='b';
                uncle->color='b';
                newNode->father->father->color='r';
                newNode=newNode->father->father;

            } else if(newNode==newNode->father->left) {

                newNode=newNode->father;
                rightRotate(tree,newNode);

            } else {

                newNode->father->color='b';
                newNode->father->father->color='r';
                leftRotate(tree,newNode->father->father);

            }

        }

    }

    tree->root->color='b';

}

/*### Inserting and deleting nodes ###*/
//Insert a node in a tree, setting left and right to NULL and father to his father
void insertRB(rb_tree *tree, int key) {

    node *newNode,*aux_1,*aux_2;

    newNode=(node*)malloc(sizeof(node));

    if(!newNode) {

        printf("The tree coudn't be initialized.\n");
        exit(1);

    }

    aux_1=tree->sentinel;
    aux_2=tree->root;

    while(aux_2!=tree->sentinel) {

        aux_1=aux_2;

        if(key<aux_2->key) {
            aux_2=aux_2->left;
        } else {
            aux_2=aux_2->right;
        }

    }
    newNode->father=aux_1;
    if(aux_1==tree->sentinel) {
        tree->root=newNode;
    } else if(key<aux_1->key) {
        aux_1->left=newNode;
    } else {
        aux_1->right=newNode;
    }

    newNode->left=tree->sentinel;
    newNode->right=tree->sentinel;
    newNode->key=key;
    newNode->color='r';

    fixupInsertRB(tree,newNode);

}

/*### Print tree functions ###*/
//Display the tree root, left and right elements, respectively 
void preOrderTreeWalk(rb_tree *tree,node *node) {

    if(node==tree->sentinel) {
        return;
    }
    printf("Key: %d Color: %c \n",node->key, node->color);
    preOrderTreeWalk(tree,node->left);
    preOrderTreeWalk(tree,node->right);

}
//Display the tree left, root and right elements, respectively 
void inOrderTreeWalk(rb_tree *tree,node *node) {

    if(node==tree->sentinel) {
        return;
    }
    preOrderTreeWalk(tree,node->left);
    printf("Key: %d Color: %c \n",node->key, node->color);
    preOrderTreeWalk(tree,node->right);

}
//Display the tree left, right and root elements, respectively 
void postOrderTreeWalk(rb_tree *tree,node *node) {
    
    if(node==tree->sentinel) {
        return;
    }
    preOrderTreeWalk(tree,node->left);
    preOrderTreeWalk(tree,node->right);
    printf("Key: %d Color: %c \n",node->key, node->color);

}

//Function to fix the colors after a node remotion
void deleteRbFixup(rb_tree *tree, node *sucessor);
void deleteRbFixup(rb_tree *tree, node *sucessor) {

    node *aux_1;

    while((sucessor!=tree->root)&&(sucessor->color=='b')&&(sucessor!=tree->sentinel)) {

        if(sucessor==sucessor->father->left) {
            aux_1=sucessor->father->right;
        }
        if(aux_1->color=='r') {
            aux_1->color='b';
            sucessor->father->color='r';
            leftRotate(tree,sucessor->father);
            aux_1=sucessor->father->right;
        }
        if((aux_1->left->color=='b')&&(aux_1->right->color=='b')) {
            aux_1->color='r';
            sucessor=sucessor->father;
        } else if(aux_1->right->color=='b') {
            aux_1->left->color='b';
            aux_1->color='r';
            rightRotate(tree,aux_1);
            aux_1=sucessor->father->right;
        }

    }

    return;

}

//Delete a node from a tree, keeping the rules of the structure
void deleteRB(rb_tree *tree, int key) {

    node *toDelNode, *aux_1, *aux_2;
    char toDelColor;

    toDelNode = searchTreeIt(tree,key);

    if(toDelNode!=tree->sentinel) {

        toDelColor=toDelNode->color; //Storing original color of the removed node r

        if(toDelNode->left==tree->sentinel) { //Is has right son
            aux_1=toDelNode->right;
            transplantRB(tree,toDelNode,toDelNode->right);
        } else if(toDelNode->right==tree->sentinel) { //Is has a left son
            aux_1 = toDelNode->left; 
            transplantRB(tree,toDelNode,toDelNode->left);
        } else { //The node has two sons
            aux_2=sucessor(tree,toDelNode);
            toDelColor=aux_2->color;
            aux_1=aux_2->right;
            if(aux_2->father==toDelNode) {
                aux_1->father=aux_2;
            } else {
                transplantRB(tree,aux_2,aux_2->right);
                aux_2->right=toDelNode->right;
                aux_2->right->father=aux_2;
            }

            transplantRB(tree,toDelNode,aux_2);
            aux_2->left=toDelNode->left;
            aux_2->left->father=aux_2;
            aux_2->color=toDelNode->color; 

        }

        if(toDelColor=='b') {
            deleteRbFixup(tree,aux_1);
        }

        return;

    } else {
        printf("The key isn't at the tree.\n");
    }

}

//Return the value of the root key
int rootKey(rb_tree *tree) {

    if(tree->root!=tree->sentinel) {
        return tree->root->key;
    } else {
        return -1000;
    }
    
}
