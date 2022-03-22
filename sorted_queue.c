#include "sorted_queue.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------*/
SortedQueue *squeue_new() {
  return queue_new();  
}

/*--------------------------------------------------------------------------*/
void squeue_free(SortedQueue *q) {
  queue_free(q);
}

/**     ESTO ES LO QUE HAY QUE HACER
 * @brief  Inserta un elemento en la cola ordenada.
 *
 * DONE: Incluye aqui el pseudocodigo del algoritmo implementado.
 * ---------------------------------------------------------------
 * input: q
 * output: status
 * while queue_getFront(q)< ele do 
        queue_push(q, queue_pop(q))
    end 
    queue_push (q,ele)
    while queue_getFront(q)> ele do 
        queue_push(q, queue_pop(q))
    end
    return OK
 * ---------------------------------------------------------------
 * @param q, puntero a la cola.
 * @param ele, puntero al elemento a insertar.
 * @param pcmp, puntero a la funcion de comparacion.
 *
 * @return OK si la insercion se realiza con exito, ERROR en caso contrario.
 **/
Status squeue_push(SortedQueue *q, void *ele, p_queue_ele_cmp pcmp) {
  Status st = OK;

  if (!q || !ele) return ERROR;

  if (queue_isEmpty(q) == TRUE){
    st = queue_push(q, ele);
    return st;
  }                                                           fprintf(stdout,"OK1\n");

  while (pcmp (queue_getFront(q),ele) > 0){
    st = queue_push(q, queue_pop(q));
    if (!st) return st;
  }                                                           fprintf(stdout,"OK2\n");
  st = queue_push(q, queue_pop(q));
  if (!st) return st;
  while (pcmp(queue_getFront(q),ele) < 0){
    st = queue_push(q, queue_pop(q));
    if (!st) return st;
  }                                                           fprintf(stdout,"OK3\n");
  return st;
}

/*--------------------------------------------------------------------------*/
void *squeue_pop(SortedQueue *q) {
  return queue_pop(q);
}

/*--------------------------------------------------------------------------*/
void *squeue_getFront(const SortedQueue *q) {
  return queue_getFront(q);
}

/*--------------------------------------------------------------------------*/
void *squeue_getBack(const SortedQueue *q) {
  return queue_getBack(q);
}

/*--------------------------------------------------------------------------*/
Bool squeue_isEmpty(const SortedQueue *q) {
  return queue_isEmpty(q);
}

/*--------------------------------------------------------------------------*/
size_t squeue_size(const SortedQueue *q) {
  return queue_size(q);
}

/*--------------------------------------------------------------------------*/
int squeue_print(FILE *fp, const SortedQueue *q, p_queue_ele_print f) {
  return queue_print(fp, q, f);
}

