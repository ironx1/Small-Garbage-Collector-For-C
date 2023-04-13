//
// Created by akaan on 12.04.2023.
//
#include "garbage_collector.h"
#include <stdio.h>
Node *new_Node(int **data){
    Node *node = mem_alloc(Node, 1);
    node->ptrAddress = data;
    node->prev = node->next = NULL;
    return node;
}

LinkedList *new_LinkedList(){
    LinkedList *ll = mem_alloc(LinkedList, 1);
    ll->head = ll->tail = NULL;
    return ll;
}

GarbageCollector *new_GarbageCollector(){
    GarbageCollector *gc = mem_alloc(GarbageCollector, 1);
    gc->list = new_LinkedList();
    gc->dataAddress = NULL;
    return gc;
}

LinkedList *insertAtFront(LinkedList *ll, int **data){
    if(ll->head==NULL){
        ll->head = ll->tail = new_Node(data);
        return ll;
    }
    else{
        ll->head->prev = new_Node(data);
        ll->head->prev->next = ll->head;
        ll->head = ll->head->prev;
        return ll;
    }
}

int *allocate_memory(int **addressOfPtr, int size, GarbageCollector *gc){
    gc->list = insertAtFront(gc->list, addressOfPtr);
    gc->dataAddress = mem_alloc(int, size);
    return gc->dataAddress;
}

int *assign(int **destAddress, int *data, GarbageCollector *gc){
    gc->list = insertAtFront(gc->list, destAddress);
    return data;
}

void check(GarbageCollector *gc){
    Node *iter = gc->list->head;
    int flag = 0;
    int size = 0;
    while(iter!=NULL){
        if(*(iter->ptrAddress) == NULL || *(iter->ptrAddress)!=gc->dataAddress){
            flag++;
        }
        size ++;
        iter = iter->next;
    }
    if(flag==size&&flag!=0){
        free(gc->dataAddress);
        free(gc->list);
        gc->dataAddress = NULL;
        printf("deleted\n");
        return;
    }
    printf("not deleted\n");
}
