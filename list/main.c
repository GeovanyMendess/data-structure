#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked-list.h"
#define MAX_TEXT_SIZE 100

/*Prototypes*/
//Display the menu
void displayMenu();

int main (int argc, char** argv) {

    linked_list *l;
    int option;
    int key;
    char in[MAX_TEXT_SIZE];

    //Initializing stack
    l = createList();

    do {
        int word_size;
        char *newText;
        displayMenu();
        scanf("%d",&option);
        system("clear"); 
        switch (option) {   
            case 1:
                printf("\n Type your text (just one word with max 100 characteres)\n\n");
                scanf("%s",in);
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                word_size = strlen(in);
                newText=(char*)malloc(word_size*sizeof(in));
                //Coping the content of a pointer to another, avoiding get same element ever
                strcpy(newText,in);
                ascInsert(l,key,newText);
                printf("\n Element at the list ! \n\n");
                break;
            case 2:
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                removeElement(l,key);
                break;    
            case 3:
                printf("\n Linked-list: \n\n");
                show(l);
                break;
            case 4:
                empties(l);
                printf("\n The list is empty now!\n\n");
                break;
            case 5:
                printf("\n The head of the list: \n\n");
                head(l);
                break;
            case 6:
                printf("\n List length: %d.\n\n",len(l));
                break;
            case 7:
                do{
                    
                    printf("\n Type the key (an positive integer).\n\n");
                    scanf("%d",&key);

                }while(key<0);
                if(isInside(l,key)) {
                    printf("Element found\n\n");
                } else {
                    printf("Element not found\n\n");
                }
                break;  
            case 8:
                printf("\n Thank you for use this tool, I hope it was usefull =).\n\n");
                break;        
            default:
                break;
        }

    } while(option!=8);

    exit(0);

}

void displayMenu() {

    printf("\n Please, choose one option: \n\n");
    printf("╔═══╦════════════════════════════╗\n║ 1 ║ Insert element             ║\n║ 2 ║ Remove element             ║\n");
    printf("║ 3 ║ Display all list           ║\n║ 4 ║ Empties list               ║\n║ 5 ║ Display the list head      ║\n");
    printf("║ 6 ║ List length                ║\n║ 7 ║ Includes                   ║\n║ 8 ║ Exit menu                  ║\n");
    printf("╚═══╩════════════════════════════╝\n");        
            
    return;        
}