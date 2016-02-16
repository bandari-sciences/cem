#ifndef BS_DS_LIST_H 
#define BS_DS_LIST_H 


#include "common_utils.h"

struct list
{
  struct list *next;
  union
  {
    void * data;
    char * key;
  };
};


struct list * bs_list_create(void *data);

struct list * bs_list_insert(struct list *l, void *data, int pos);

int           bs_list_locate(struct list * l, void * data,
		void_data_compare fn);

struct list * bs_list_retrieve(struct list *, int pos);

struct list * bs_list_delete(struct list *l, delete_node fn, int pos);

struct list * bs_list_next(struct list *l);

struct list * bs_list_make_null(struct list *l, delete_node fn);

struct list * bs_list_end(struct list *l);

void          bs_list_print(struct list *l, print_data fn);

#endif

