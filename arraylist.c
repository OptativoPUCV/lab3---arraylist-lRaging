#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) 
{
    ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
    if (list == NULL) return NULL; 
    
    list->data = (void**) malloc(sizeof(void*) * 2);
    if (list->data == NULL)  return NULL;
  
  
    list->capacity = 2;
    list->size = 0;
    return list;
}

void append(ArrayList * l, void * data)
{
  if (data == NULL) return;
  if (l->size >= l->capacity) 
  {
    int new_capacity = l->capacity * 2;
    l->data = realloc(l->data, new_capacity * sizeof(void*));
    if (l->data == NULL) return;
    l->capacity = new_capacity;
  }
  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList * l, void * data, int i)
{
  if (i < 0 || i > l->size) return;
  if (l->size == l->capacity) 
  {
    l->capacity *= 2;
    l->data = realloc(l->data, l->capacity * sizeof(void*));
  }
  for (int j = l->size; j >= i; j--)
  {
    l->data[j] = l->data[j-1];
  }
  l->data[i]= data;
  l->size++;
}

void* pop(ArrayList * l, int i)
{
  if(l->data == NULL) return NULL;
  if(i>=0) 
  {
    for(int j=0; j>l->size; j++)
    {
      l->data[i+1] = l->data[i];
    }
  }
  if(i<0)
  {
    for(int j=0 ; j>l->size ; j++)
    {
        l->data[i+1] = l->data[i];
    }
  }
  
  l->size--;
  return NULL;
}

void* get(ArrayList * l, int i)
{
  if(i>=l->size) return NULL;
  if(i<0) return l->data[(l->size)+i];
  if(i>=0) return l->data[i];
  return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

void clean(ArrayList * l)
{
}
