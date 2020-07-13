#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main (int argc, char** argv) {

    queue *q = createQueue();

    enqueue(q,"Geovany Carlos Mendes da Silva ");
    enqueue(q,"Luiz");
    enqueue(q,"Kleber");
    enqueue(q,"Guinha");
    
    first(q);
    dequeue(q);
    first(q);
    dequeue(q);
    first(q);
    dequeue(q);
    first(q);
    dequeue(q);
    first(q);
    dequeue(q);


    exit(0);

}