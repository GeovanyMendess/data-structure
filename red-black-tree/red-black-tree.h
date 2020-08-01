#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef struct rb_tree rb_tree;
typedef struct node node; 

//Create a empty red black tree and return a pointer to the structure
rb_tree *createRbTree();
//Return a pointer to the tree root if there's exist
node *root(rb_tree *tree);

//Return the value of the root key
int rootKey(rb_tree *tree);


/*### Print tree functions ###*/
//All of these receive the tree and the root
//Display the tree root, left and right elements, respectively 
void preOrderTreeWalk(rb_tree *tree,node *node);
//Display the tree left, root and right elements, respectively 
void inOrderTreeWalk(rb_tree *tree,node *node);
//Display the tree left, right and root elements, respectively 
void postOrderTreeWalk(rb_tree *tree,node *node);

/*### Search Methods ###*/
//Search for a node in a tree receiving a key and the root and return 1 if it was found and 0 otherwise
//OBS: This is recursive method
int searchTree(node *node, int key);

/*### Max and Min ###*/
//Finds the smallest element at the tree
void min(node *root);
//Finds the greater element at the tree
void max(node *root);

/*### Inserting and deleting nodes ###*/
//Insert a node in a tree, setting left and right to NULL and father to his father
void insertRB(rb_tree *tree, int key);
//Delete a node from a tree, keeping the rules of the structure
void deleteRB(rb_tree *tree, int key);

/*Auxiliar function to fix coloring inconsistencies*/
void fixupInsertRB(rb_tree *tree,node *newNode);

#endif