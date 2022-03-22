#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "sorted_queue.h"

#define MAX_RAND 100 

int string_cmp(const void *s1, const void *s2) {
return strcmp((char *)s1, (char *)s2);
}

int main(){
  Queue *q = NULL;
  int *ele;
  int i, n;
  Status st = OK;

  if ((q = queue_new()) == NULL) return -1;
  
  fprintf(stdout,"Inserta un numero de elementos en la TAD: \n");
  scanf("%d", &n);

  ele = (int*) malloc (n*sizeof(int));
  
  srand(time(NULL));
  for (i=0; i < n; i++){
    ele[i] = rand() % MAX_RAND + 1;
    st = squeue_push(q, &ele[i], string_cmp);
    if (st == ERROR){
      queue_free(q);
      return 1;
    }
  }

  queue_free(q);
  return 0;
}
