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

ArrayList *createList(void) {
    return NULL;
}

void append(ArrayList * l, void * data)
{
  if(l->capacity == l->size)
  {
    l->data = realloc(l->data, 2 * l->capacity);
    l->capacity = 2 * l->size;
  }
  l->size ++;
}

void push(ArrayList * l, void * data, int i){

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
