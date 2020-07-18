#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"


struct node {

    int key;
    node *father;
    node *left;
    node *right;

};

struct tree {

    node *root;

};

//Create a empty tree and return
tree *createTree() {

    tree *newTree;

    newTree=(tree*)malloc(sizeof(tree));

    if(!newTree) {

        printf("The tree coudn't be initialized.\n");
        exit(1);

    }

    newTree->root = NULL;

    return(newTree);

}

//Return a pointer to the tree root if there's exist
node *root(tree *tree) {

    return(tree->root);
    
}

/*###Print tree functions###*/
//Display the tree root, left and right elements, respectively 
void preOrderTreeWalk(node *node) {

    if(node==NULL) {
        return;
    }
    printf("%d ",node->key);
    preOrderTreeWalk(node->left);
    preOrderTreeWalk(node->right);
}

//Display the tree left, root and right elements, respectively 
void inOrderTreeWalk(node *node) {
    
    if(node==NULL) {
        return;
    }
    inOrderTreeWalk(node->left);
    printf("%d ",node->key);
    inOrderTreeWalk(node->right);
}

//Display the tree left, right and root elements, respectively 
void postOrderTreeWalk(node *node) {

    if(node==NULL) {
        return;
    }
    postOrderTreeWalk(node->left);
    postOrderTreeWalk(node->right);
    printf("%d ",node->key);

}

//Search for a node in a tree receiving a key and the root and return 1 if it was found and 0 otherwise
//OBS: This is recursive method
int searchTree(node *node, int key) {

    if((node==NULL)||(node->key==key)) {
            if((node!=NULL)&&(node->key==key)) {
                return 1;
            } else {
                 return 0;
            }
    }
    if(key<node->key) {
        return searchTree(node->left,key);
    } else {
        return searchTree(node->right,key);
    }

}

//Search for a node in a tree receiving a key and the root and return a pointer to the node founded
//OBS: This is iterative method
int searchTreeIt(tree *tree, int key) {

    node *node=tree->root;

    while((node!=NULL)&&(key!=node->key)) {
        if(key<node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if((node!=NULL)&&(node->key==key)) {
        return 1;
    } else {
        return 0;
    }

}

//Finds the smallest element at the tree
node *min(node *root) {

    if(root!=NULL) {

        while(root->left!=NULL) {
            root = root->left;
        }
    }

    return root;
}

//Finds the greater element at the tree
node *max(node *root) {

        if(root!=NULL) {

        while(root->right!=NULL) {
            root = root->right;
        }
    }

    return root;
}

//Find the sucessor of a non null node, returning NULL if the node is the greater, 
//otherwise return a pointer to the sucessor 
node *sucessor(node *t_node) {

    node *aux;

    if(t_node!=NULL) {

        t_node=t_node->right;

        while(t_node->left!=NULL) {
            t_node=t_node->left;
        }
        return t_node;
    }

    aux=t_node->father;

    while((aux!=NULL)&&(aux->right==t_node)) {
        t_node=aux;
        aux=aux->father;
    }

    return aux;
}

//Find the predecessor of a non null node, returning NULL if the node is the greater,
//otherwise return a pointer to the predecessor 
node *predecessor(node *t_node) {

    node *aux;

    if(t_node!=NULL) {

        t_node=t_node->left;

        while(t_node->right!=NULL) {
            t_node=t_node->right;
        }

        return t_node;
    }

    aux=t_node->father;

    while((aux!=NULL)&&(aux->left==t_node)) {
        t_node=aux;
        aux=aux->father;
    }

    return aux;
}

/*### Inserting and deleting nodes ###*/
//Insert a node in a tree, setting left and right to NULL and father to his father
void insertTree(tree *tree, int key) {

    node *new_node, *walk, *father;

    new_node=(node*)malloc(sizeof(node));

    if(!new_node) {
        printf("The node coudn't be initialized.\n");
        exit(1);
    }

    new_node->key=key;
    new_node->left=NULL;
    new_node->right=NULL;

    walk=tree->root;

    father = NULL;

    while(walk!=NULL) {

        father = walk;

        if(key<walk->key) {
            walk=walk->left;
        } else {
            walk=walk->right;
        }
    }

    new_node->father=father;

    if(father==NULL) {
        tree->root=new_node;        //Is the root
    } else if(key<father->key) {
        father->left=new_node;
    } else {
        father->right=new_node;
    }

    return;

}


