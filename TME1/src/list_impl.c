#include <list.h>
#include <stdlib.h>
#include <stdio.h>


void init_list(struct list_type *l) {
	l->head = NULL;
	l->tail = NULL;
}
	
	

void insert_head(struct list_type *l, void* element) {
  cell* new_cell = malloc(sizeof(cell));
  new_cell->content = element;
  new_cell->previous = NULL;
  new_cell->next = l->head;
  if (l->head != NULL)
    l->head->previous = new_cell;
  l->head = new_cell;
  if (l->tail == NULL)
    l->tail = l->head;
}

void* extract_head(struct list_type *l) {
  
  if(l!=NULL && l->head!=NULL && l->tail!=NULL){

    cell* old_head;
    old_head = l->head;

    void* content;
    content = old_head->content;
    
    if(l->head->next!=NULL){
      l->head->next->previous = NULL;
      l->head = l->head->next;
      free(old_head);
    }    
    else{ 
       free(l->head);
    }
    
    return content;
  }
  return NULL;
}


void* extract_tail(struct list_type *l) {

  if(l!=NULL && l->head!=NULL && l->tail!=NULL){

    cell* old_tail;
    old_tail = l->tail;

    void* content;
    content = old_tail->content;

    if(l->tail->previous!=NULL){
      l->tail = l->tail->previous;     
      l->tail->next = NULL;
      free(old_tail);
    }
    else{
      free(l->tail);
      l->head = NULL;
      l->tail = NULL;
    }
  return content;
  }
  
  return NULL;
}


int list_size(struct list_type  *l){
  
  cell* current;  
  int size;
  size = 0;

  while(current!=NULL){
    size++;
    current=current->next;
  }
  
  return size;
}
	
