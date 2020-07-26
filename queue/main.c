#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#define MAX_TEXT_SIZE 100

/*Prototypes*/
//Display the menu
void displayMenu();

int main (int argc, char** argv) {

    queue *q;
    int option;
    char in[MAX_TEXT_SIZE];

    //Initializing stack
    q = createQueue();

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
                enqueue(q,newText);
                printf("\n Element in queue ! \n\n");
                break;
            case 2:
                printf("\n Removed element: %s\n\n",dequeue(q));
                break;    
            case 3:
                printf("\n First element: %s\n\n");
                first(q);
                break;
            case 4:
                empties(q);
                printf("\n The queue is empty now!\n\n");
                break;
            case 5:
                if(isEmpty(q)==1) {
                    printf("\n The queue is empty.\n\n");
                } else {
                    printf("\n The queue isn't empty.\n\n");
                }
                break;
            case 6:
                printf("\n Thank you for use this tool, I hope it was usefull =).\n\n");
                break;        
            default:
                break;
        }

    } while(option!=6);

    exit(0);

}

void displayMenu() {

    printf("\n Please, choose one option: \n\n");
    printf("╔═══╦════════════════════════════╗\n║ 1 ║ Insert element             ║\n║ 2 ║ Remove element             ║\n");
    printf("║ 3 ║ Display first              ║\n║ 4 ║ Empties queue              ║\n║ 5 ║ Verify if is empty         ║\n");
    printf("║ 6 ║ Exit menu                  ║\n╚═══╩════════════════════════════╝\n");        
            
    return;        
}