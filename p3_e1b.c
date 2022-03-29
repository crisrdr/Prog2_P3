#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorted_queue.h"

#define MAX_RAND 100 
#define MAX_ELE 10

/*--------PROTOTIPOS DE FUNCIONES PRIVADAS-------*/

int string_cmp(const void *s1, const void *s2);

int int_cmp(const void *c1, const void *c2);

int int_print (FILE *pf, const void *a);

/*----------------------------------------------*/

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
    ele[i] = rand() % MAX_RAND + 1;               fprintf(stdout,"\nNew ele: %d\n", ele[i]);
    st = squeue_push(q, &ele[i], int_cmp);
    if (st == ERROR){
      queue_free(q);
      return EXIT_FAILURE;
    }
    fprintf(stdout, "\n\nQueue: ");
    queue_print(stdout,q, int_print);
  }
  fprintf(stdout,"Ordered queue:\n");
  fprintf(stdout,"Queue size: %ld\n",queue_size(q));
  queue_print(stdout, q, int_print);

  fprintf(stdout,"First element: %d\n",*(int*)queue_pop(q));
  fprintf(stdout,"Seccond element: %d\n",*(int*)queue_pop(q));
  fprintf(stdout,"Third element: %d\n",*(int*)queue_pop(q));

  queue_free(q);
  return EXIT_SUCCESS;
}

/*--------DEFINICIONES DE FUNCIONES PRIVADAS-------*/

int string_cmp(const void *s1, const void *s2){
  return strcmp((char *)s1, (char *)s2);
}

int int_cmp(const void *c1, const void *c2){
  if (!c1 || !c2) return -1;

  return (*(int *)c1 - *(int *)c2);
}

int int_print (FILE *pf, const void *a){
    if (!pf || !a) return -1;

    return fprintf(pf, "%d ", *(int *)a);
}