#ifndef DOUBLE_LL_
#define DOUBLE_LL_

#include <stdlib.h>

struct node{
    struct node* previous;
    void* data;
    struct node* next;
};

struct DoubleLinkedList{
    int size;
    struct node* head;
    struct node* tail;


};

void inserthead(struct DoubleLinkedList *list, void* data);
void inserttail(struct DoubleLinkedList *list, void* data);

void* poptail(struct DoubleLinkedList *list);
void* pophead(struct DoubleLinkedList *list);

void* getindexfromhead(struct DoubleLinkedList *list, int index);
void* getindexfromtail(struct DoubleLinkedList *list, int index);

struct DoubleLinkedList *make_dll();
void nuke(struct DoubleLinkedList *list);
void setdata(struct DoubleLinkedList *list, void* data, int index);


#endif