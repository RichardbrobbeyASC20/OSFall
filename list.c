// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *listt = malloc(sizeof(list_t));
  if(listt != NULL){
    listt -> head = NULL;
  }
  return listt;
 }
void list_free(list_t *l) {
  if(l != NULL) {
    node_t *curr = l -> head;
    while(curr != NULL) {
      node_t *temp = curr;
      curr = curr -> next;
      free(temp);
    } 
    free(l); 
  }
}

void list_print(list_t *l) {
  if(l == NULL)
  {
    printf("List is NULL\n");
    return;
  }
  node_t *curr = l -> head;
  while(curr != NULL){
    printf("%d  ", curr -> value);
    curr = curr -> next;
  }
}
int list_length(list_t *l) { 
  int count = 0;
  if(l == NULL){
    return count;
  }
  node_t *curr = l ->head;
  while (curr != NULL){
    count++;
    curr = curr -> next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *newn = malloc(sizeof(node_t));
  newn -> value = value;
  newn -> next = NULL;
  if(l ->head == NULL){
    l -> head = newn;
  } else {
    node_t *curr = l -> head;
    while(curr -> next != NULL){
      curr = curr -> next;
    }
    curr -> next = newn;
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t *newn = malloc(sizeof(node_t));
  newn -> value = value;
  newn -> next = l -> head;
  l -> head = newn;
}
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *newn = malloc(sizeof(node_t));
  newn -> value = value;
  if(index == 0){
    newn -> next = l -> head;
    l -> head = newn;
  } else {
    node_t *curr = l -> head;
    int i = 0;
    while( curr != NULL && i < index -1){
      curr = curr -> next;
      i++;
    }
    if( curr != NULL){
      newn -> next = curr -> next;
      curr -> next = newn;
    } else {
      free(newn); //out of bounds
    }
  }
}

elem list_remove_from_back(list_t *l) { 
  if (l == NULL || l -> head == NULL) {
        return -1;
    }
    
    if (l -> head -> next == NULL) {
        elem removed_value = l->head->value;
        free(l->head);
        l->head = NULL; 
        return removed_value;
    }
    node_t *curr = l->head;
    while (curr -> next -> next != NULL) {
        curr = curr -> next;
    }
    elem removed_value = curr -> next -> value;
    free(curr -> next);
    curr -> next = NULL;
    return removed_value;
}
elem list_remove_from_front(list_t *l) { 
  if (l == NULL || l -> head == NULL) {
        return -1;
    }
    node_t *removed_node = l->head;
    elem removed_value = removed_node -> value;
    l -> head = l -> head -> next; 
    free(removed_node); 
    return removed_value;
 }
elem list_remove_at_index(list_t *l, int index) { 
  if (l == NULL || index < 0 || l -> head == NULL) {
        return -1;
    }   
    if (index == 0) {
        return list_remove_from_front(l);
    }
    
    node_t *curr = l -> head;
    int i = 0;
    while (curr -> next != NULL && i < index - 1) {
        curr = curr -> next;
        i++;
    }
    if (curr -> next != NULL) {
        node_t *removed_node = curr -> next;
        elem removed_value = removed_node -> value;
        curr -> next = removed_node -> next;
        free(removed_node);
        return removed_value;
    } else {
        return -1;
    }
}

bool list_is_in(list_t *l, elem value) { 
  if (l == NULL || l->head == NULL) {
        return false;
    }

    node_t *curr = l -> head;
    while (curr != NULL) {
        if (curr->value == value) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
elem list_get_elem_at(list_t *l, int index) { 
  if (l == NULL || index < 0 || l -> head == NULL) {
        return -1;
    }

    node_t *curr = l -> head;
    int i = 0;
    while (curr != NULL && i < index) {
        curr = curr->next;
        i++;
    }

    if (curr != NULL) {
        return curr->value;
    } else {
        return -1;
    }
 }
int list_get_index_of(list_t *l, elem value) { 
  if (l == NULL || l -> head == NULL) {
        return -1;
    }

    node_t *curr = l->head;
    int index = 0;
    while (curr != NULL) {
        if (curr->value == value) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
 }

