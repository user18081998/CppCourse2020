#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListElmt ListElmt;
struct ListElmt{
  int value;
  ListElmt *next;
};

typedef struct List List;
struct List{
  int size;
  ListElmt *head;
  ListElmt *tail;
};

void list_init(List *list);
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element,int data);
int list_rem_next(List *list, ListElmt *element,int *data);
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#endif
