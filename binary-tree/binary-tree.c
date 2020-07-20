#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"

/*Auxiliar functions, only visible inside the binary-tree.c*/
/*### Sucessor and predecessor ###*/
//Find the sucessor of a non null node, returning NULL if the node is the greater,
// otherwise return a pointer to the sucessor 
node *sucessor(node *node);
//Find the predecessor of a non null node, returning NULL if the node is the greater,
//otherwise return a pointer to the predecessor 
node *predecessor(node *node);

/*### Removing a node###*/
//Change a sub-tree son of a node inside the tree by other sub-tree 
void transplant(tree *tree,node *old_son, node *new_son);

//Search for a node in a tree receiving a key and the tree. It return a pointer to the node if the key was found
//OBS: This is iterative method
node *searchTreeIt(tree *tree, int key);

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

//Finds the smallest element at the tree
int min(node *root) {

    if(root!=NULL) {

        while(root->left!=NULL) {
            root = root->left;
        }
    }

    return root->key;
}

//Finds the greater element at the tree
int max(node *root) {

        if(root!=NULL) {

        while(root->right!=NULL) {
            root = root->right;
        }
    }

    return root->key;
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
/*Auxiliar functions*/
//Change a sub-tree son of a node inside the tree by other sub-tree
//This is an auxiliar function to remove nodes with two sons in a tree 
void transplant(tree *tree,node *old_son, node *new_son) {

    if((old_son!=NULL)&&(old_son->father==NULL)){
        tree->root=new_son;
    } else if(old_son==old_son->father->left) {
        old_son->father->left=new_son;
    } else {
        old_son->father->right=new_son;
    }
    if(new_son!=NULL) {
    new_son->father=old_son->father; 
}

    return;

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

//Search for a node in a tree receiving a key and the root and return a pointer to the node founded
//OBS: This is iterative method
node *searchTreeIt(tree *tree, int key) {

    node *node=tree->root;

    while((node!=NULL)&&(key!=node->key)) {
        if(key<node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return node;

}

void treeDelete(tree *tree, int key) {

    node *to_remove=searchTreeIt(tree,key);
    node *firstSucessor;

    if(to_remove!=NULL) {

        if(to_remove->left==NULL) {
            transplant(tree,to_remove,to_remove->right);
        } else if(to_remove->right==NULL) {
            transplant(tree,to_remove,to_remove->left);
        } else {

            firstSucessor=sucessor(to_remove);

            if(firstSucessor->father!=to_remove) {
                transplant(tree,firstSucessor,firstSucessor->right);
                firstSucessor->right=to_remove->right;
                firstSucessor->right->father=firstSucessor;
            }

            transplant(tree,to_remove,firstSucessor);
            firstSucessor->left=to_remove->left;
            firstSucessor->left->father=firstSucessor;
        }

        free(to_remove);

    } else {
        printf("This key isn't at the tree = (\n");
    }
        return;
}


