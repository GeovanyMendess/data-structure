#include <stdlib.h>
#include <stdio.h>
#include "./stack/stack.h"

int main (int argc, char** argv) {

    stack *s;
    s = createStack();

    if(s!=NULL) {
        printf("Stack has been initialized.");
    } else { 
        printf("An error ocurred, please, try again.");
    }

    exit(0);

}