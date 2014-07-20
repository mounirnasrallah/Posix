#include "list.h"
#include "fifo.h"
#include <stdlib.h>
#include <stdio.h>

struct list_type* fifo;

int init_queue(){
  fifo = (struct list_type*)malloc(sizeof(struct list_type));
  
  if(fifo==NULL){
    fprintf(stderr,"Malloc error -- line : %d, file %s ",__LINE__,__FILE__);
    return EXIT_FAILURE;
  }
  else{
    init_list(fifo);
    return EXIT_SUCCESS;
  }
}


int queue(void* element){
  insert_head(fifo, element);
  return EXIT_SUCCESS;
}


void* dequeue(){
  return extract_tail(fifo);
}

int size(){
  return list_size(fifo);
}
