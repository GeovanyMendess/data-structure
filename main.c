#include <stdlib.h>
#include <stdio.h>
#include "./stack/stack.h"

int main (int argc, char** argv) {

    stack *s;
    s = createStack();

    if(s!=NULL) {
        printf("Stack has been initialized.\n");
    } else { 
        printf("An error ocurred, please, try again.");
    }

    char *word_1 = "Olá, meu nome é Geovany.";
    char *word_2 = "Estudo na UNIFEI.";
    char *word_3 = "Faço ciência da computação.";

    push(s,word_1);
    push(s,word_2);
    push(s,word_3);

    printf("%s\n",pop(s));
    printf("%s\n",pop(s));
    printf("%s\n",pop(s));
    printf("%s\n",pop(s));

    exit(0);

}