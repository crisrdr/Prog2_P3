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
    ele[i] = rand() % MAX_RAND + 1;               fprintf(stdout,"%d\n", ele[i]);
    st = squeue_push(q, &ele[i], int_cmp);
    if (st == ERROR){
      queue_free(q);
      return EXIT_FAILURE;
    }
  }
fprintf(stdout,"OK 4\n");
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