#include <stdlib.h>
#include <stdio.h>
#include "red-black-tree.h"

/*Prototypes*/
//Display the menu
void displayMenu();

int main (int argc, char** argv) {

    rb_tree *t = createRbTree();
    int option;
    int key;

    do {
        displayMenu();
        scanf("%d",&option);
        system("clear"); 
        switch (option) {   
            case 0:
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                insertRB(t,key);
                printf("\n Element at the tree ! \n\n");
                break;
            case 1:
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                deleteRB(t,key);
                break;    
            case 2:
                printf("\n Tree: \n\n");
                preOrderTreeWalk(t,root(t));
                break;
            case 3:
                printf("\n Tree: \n\n");
                inOrderTreeWalk(t,root(t));
                break;
            case 4:
                printf("\n Tree: \n\n");
                postOrderTreeWalk(t,root(t));
                break;
            case 5:
                rootKey(t);
                break;
            case 6:
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                if(searchTree(root(t),key)) {
                    printf("Element found\n\n");
                } else {
                    printf("Element not found\n\n");
                }
                break;
            case 7:
                min(root(t));
                break;
            case 8:
                max(root(t));
                break;    
            case 9:
                printf("\n Thank you for use this tool, I hope it was usefull =).\n\n");
                break;        
            default:
                break;
        }

    } while(option!=9);

    exit(0);

}

void displayMenu() {

    printf("\n Please, choose one option: \n\n");
    printf("╔═══╦════════════════════════════╗\n║ 0 ║ Insert element             ║\n║ 1 ║ Remove element             ║\n");
    printf("║ 2 ║ Display in pre order       ║\n║ 3 ║ Display in order           ║\n║ 4 ║ Display in pos order       ║\n");
    printf("║ 5 ║ Tree root                  ║\n║ 6 ║ Includes                   ║\n║ 7 ║ Min                        ║\n");
    printf("║ 8 ║ Max                        ║\n║ 9 ║ Exit menu                  ║\n╚═══╩════════════════════════════╝\n");        
            
    return;        
}