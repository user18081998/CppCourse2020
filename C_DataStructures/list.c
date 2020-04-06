#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_init(List *list){
  list->size=0;
  list->head=NULL;
  list->tail=NULL;
  return;
}

int list_ins_next(List *list, ListElmt *element,int data){
  ListElmt *newE=(ListElmt *)malloc(sizeof(*newE));
  if(list==NULL || newE==NULL)
    return -1;
  newE->value=data;
  //handle insertion at head of list
  if(element==NULL){
    if(list->size==0)
      list->tail=newE; //if list empty new is gona be head and tail
    newE->next=list->head;
    list->head=newE;
    list->size++;
    return 0;
  }
  else {
    if(element->next==NULL) //handle insertion at tail
        list->tail=newE;
      newE->next=element->next;
      element->next=newE;
      list->size++;
      return 0;
  }
}

int list_rem_next(List *list, ListElmt *element,int *data){
  ListElmt *oldE;
  if(list->size==0)
    return -1;
  if(element==NULL){ //handle removal from head
    *data=list->head->value;
    oldE=list->head;
    list->head=list->head->next;
    if(list->size==1)
      list->tail=NULL;
  }
  else {
    if(element->next==NULL)
      return -1;
    *data=element->next->value;
    oldE=element->next;
    element->next=element->next->next;
    if(element->next==NULL)
      list->tail=element;
  }
  free(oldE);
  list->size--;
  return 0;
}

void list_destroy(List *list){
  int *data;
  while(list->size > 0){
    if(list_rem_next(list,NULL,data)==0)
      free(data);
  }
  memset(list,0,sizeof(List));
  return;
}
