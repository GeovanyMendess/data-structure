#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree tree;
typedef struct node node; 

//Create a empty tree and return
tree *createTree();
//Return a pointer to the tree root if there's exist
node *root(tree *tree);
//Display the value in the tree root
void rootValue(tree *tree);


/*### Print tree functions ###*/
//Display the tree root, left and right elements, respectively 
void preOrderTreeWalk(node *node);
//Display the tree left, root and right elements, respectively 
void inOrderTreeWalk(node *node);
//Display the tree left, right and root elements, respectively 
void postOrderTreeWalk(node *node);

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
void insertTree(tree *tree, int key);
//Delete a node from a tree, keeping the rules of the structure
void treeDelete(tree *tree, int key);


#endif