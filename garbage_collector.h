//
// Created by akaan on 12.04.2023.
//

#ifndef GARBAGE_COLLECTOR_GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_GARBAGE_COLLECTOR_H
#include <stdlib.h>
#define mem_alloc(type, size) (type*)malloc(size*sizeof(type))

typedef struct node Node;
typedef struct ll LinkedList;
typedef struct gc GarbageCollector;

struct node{
    int **ptrAddress;
    Node *next, *prev;
};

struct ll{
    Node *head, *tail;
};

struct gc{
    LinkedList *list;
    int *dataAddress;
};

Node *new_Node(int **data);
LinkedList *new_LinkedList();
GarbageCollector *new_GarbageCollector();
LinkedList *insertAtFront(LinkedList *ll, int **data);
int *allocate_memory(int **addressOfPtr, int size, GarbageCollector *gc);
int *assign(int **destAddress, int *ptr, GarbageCollector *gc);
void check(GarbageCollector *gc);
#endif //GARBAGE_COLLECTOR_GARBAGE_COLLECTOR_H
