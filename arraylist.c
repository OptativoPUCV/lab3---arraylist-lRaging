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
  for (l->size; l->size >= i; l->size--) 
  {
    l->data[l->size] = l->data[l->size-1];
  }
  l->data[i]= data;
  l->size++;
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
