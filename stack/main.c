#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#define MAX_TEXT_SIZE 100

/*Prototypes*/
//Display the menu
void displayMenu();

int main (int argc, char** argv) {

    stack *s;
    int option;
    char in[MAX_TEXT_SIZE];

    //Initializing stack
    s = createStack();

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
                word_size = strlen(in);
                newText=(char*)malloc(word_size*sizeof(in));
                //Coping the content of a pointer to another, avoiding get same element ever
                strcpy(newText,in);
                push(s,newText);
                printf("\n Text inserted ! \n\n");
                break;
            case 2:
                printf("\n Removed element: %s\n\n",pop(s));
                break;    
            case 3:
                printf("\n Element at the top: %s\n\n",top(s));
                break;
            case 4:
                empties(s);
                printf("\n The stack is empty now!\n\n");
                break;
            case 5:
                if(isEmpty(s)==1) {
                    printf("\n The stack is empty.\n\n");
                } else {
                    printf("\n The stack isn't empty.\n\n");
                }
                break;
            case 6:
                printf("\n Stack:\n\n");
                show(s);
                break;
            case 7:
                printf("\n Thank you for use this tool, I hope it was usefull =).\n\n");
                break;        
            default:
                break;
        }

    } while(option!=7);

    exit(0);

}

void displayMenu() {

    printf("\n Please, choose one option: \n\n");
    printf("╔═══╦════════════════════════════╗\n║ 1 ║ Insert element             ║\n║ 2 ║ Remove element             ║\n");
    printf("║ 3 ║ Display top                ║\n║ 4 ║ Empties Stack              ║\n║ 5 ║ Verify if is empty         ║\n");
    printf("║ 6 ║ Display all data structure ║\n║ 7 ║ Exit menu                  ║\n╚═══╩════════════════════════════╝\n");        
            
    return;        
}
