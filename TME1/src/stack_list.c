#include "list.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct list_type* stack;


int init_stack(){

  stack = (struct list_type*)malloc(sizeof(struct list_type));
  
  if(stack==NULL){
    fprintf(stderr,"Malloc error -- line : %d, file : %s \n",__LINE__,__FILE__);
    return EXIT_FAILURE;
  }
  else{
    init_list(stack);     
    return EXIT_SUCCESS;
    }
}


int push(void* element){
  insert_head(stack, element); 
  return EXIT_SUCCESS;
}

void* pop(){
  return extract_head(stack);
}

int size(){
  return list_size(stack);
}
