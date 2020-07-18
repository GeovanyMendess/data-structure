#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree tree;
typedef struct node node; 

//Create a empty tree and return
tree *createTree();
//Return a pointer to the tree root if there's exist
node *root(tree *tree);


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
//Search for a node in a tree receiving a key and the tree and return 1 if it was found and 0 otherwise
//OBS: This is iterative method
int searchTreeIt(tree *tree, int key);

/*### Max and Min ###*/
//Finds the smallest element at the tree
node *min(node *root);
//Finds the greater element at the tree
node *max(node *root);

/*### Sucessor and predecessor ###*/
//Find the sucessor of a non null node, returning NULL if the node is the greater,
// otherwise return a pointer to the sucessor 
node *sucessor(node *node);
//Find the predecessor of a non null node, returning NULL if the node is the greater,
//otherwise return a pointer to the predecessor 
node *predecessor(node *node);

/*### Inserting and deleting nodes ###*/
//Insert a node in a tree, setting left and right to NULL and father to his father
void insertTree(tree *tree, int key);


#endif