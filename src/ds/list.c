#include "list.h"

#include <stdlib.h>


/* Create a list
 * @data data to store
 *
 *
 * @return newlist
 */
struct list * 
bs_list_create(void *data)
{
  struct list *node;
  node = (struct list *)malloc(sizeof(struct list ));

  node->data = data;
  node->next = NULL;

  return node;
}

struct list * bs_list_insert(struct list *temp_list, void *data, int pos)
{
  if(pos == 0)
  {

  }

  return NULL;
}

/**
 * Locate the data in the list. If succeeds returns the position, 0
 * being the first element. Else returns -1.
 *
 *
 */
int           
bs_list_locate(struct list * temp_list, void * data, void_data_compare fn)
{
  int pos = -1;
  int counter = 0;
  int result;
  struct list *iter_list = temp_list;

  while(iter_list != NULL)
  {
    result = fn(data, iter_list->data, NULL);
    if(result == 0)
    {
      pos = counter;
      break;
    }
    iter_list = iter_list->next;
    counter++;
  }
  return pos;
}

struct list * bs_list_retrieve(struct list *temp_list, int pos)
{
  int counter = 0;
  struct list *node = NULL;

  if (pos < 0)
    return NULL;

  while(temp_list != NULL)
  {
    if (counter == pos)
    {
      node = temp_list;
      break;
    }
    counter ++;
    temp_list = temp_list->next;
  }
  return node;
}

struct list * bs_list_delete(struct list *l, delete_node fn, int pos)
{


  return NULL;
}


struct list * bs_list_next(struct list *temp_list)
{
  if(temp_list !=NULL)
    return temp_list->next;
  else
    return NULL;
}


struct list * bs_list_make_null(struct list *temp_list, delete_node fn)
{
  while(temp_list != NULL)
  {
    void *data = temp_list->data;
    temp_list = temp_list->next;
    if(fn == NULL)
    {
      free(temp_list);
    }
    else
    {
      fn(data);
      free(temp_list);
    }
  }
  return NULL;
}

struct list * bs_list_end(struct list *temp_list)
{
  struct list * end_element = NULL;
  while(temp_list!=NULL)
  {
    if(temp_list->next == NULL)
    {
      end_element = temp_list;
      break;
    }
    temp_list = temp_list->next;
  }
  return end_element;
}


void
bs_list_print(struct list *temp_list, print_data fn)
{
  if(fn == NULL)
    return;
  while(temp_list != NULL)
  {
    fn(temp_list, NULL);
    temp_list = temp_list->next;
  }
}



