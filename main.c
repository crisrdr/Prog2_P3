#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_RAND 100 

int main(){
    Queue *q = NULL;
    int *ele;
    int i, n;
    Status st = OK;

    printf("Número de elementos a insertar en la pila: ");
    scanf("%d", &n);

    if ((ele = (int*) malloc (n*sizeof(int))) == NULL) return EXIT_FAILURE;

    if ((q = queue_new()) == NULL){
        free(ele);
        return EXIT_FAILURE;
    }

    srand(time(NULL));          
    for (i=0; i < n; i++){
        ele[i] = rand() % MAX_RAND + 1;               fprintf(stdout,"%d\n", ele[i]);
        /* st = squeue_push(q, &ele[i], int_cmp); */
        if (st == ERROR){
            queue_free(q);
            return EXIT_FAILURE;
        }
    }
    return 0;
}