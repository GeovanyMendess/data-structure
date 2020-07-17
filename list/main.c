#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"

int main (int argc, char** argv) {

    linked_list *l=createList();
    linked_list *l2=createList();
    linked_list *l3;

    if(!!l){
        printf("It's okay.\n");
    }

    ascInsert(l,1,"");
    ascInsert(l,10,"");
    ascInsert(l,4,"");
    ascInsert(l,3,"");
    ascInsert(l,9,"");
    ascInsert(l,8,"");
    ascInsert(l,3,"");

    ascInsert(l2,14,"");
    ascInsert(l2,10,"");
    ascInsert(l2,2,"");
    ascInsert(l2,5,"");
    ascInsert(l2,6,"");
    ascInsert(l2,8,"");
    ascInsert(l2,4,"");

    l3 = unionList(l,l2);

    // show(l);
    // show(l2);
    show(l3);
    empties(l3);
    show(l3);

    exit(0);

}