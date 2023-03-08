#include "doublylinkedlist.h"

// Add new node at the head, replacing it.
void inserthead(struct DoubleLinkedList *list, void* data){
    struct node* ins = malloc(sizeof(struct node));
    ins->data = data;
    ins->previous = NULL;
    if (list->size == 0){
        ins->next = NULL;

        list->tail = ins;
    }else{
        ins->next = list->head;
        list->head->previous = ins;
    }
    list->head = ins;
    list->size++;
}

// Add new node at the tail, replacing it.
void inserttail(struct DoubleLinkedList *list, void* data){
    struct node* ins = malloc(sizeof(struct node));
    ins->data = data;
    ins->next = NULL;
    if (list->size == 0){
        ins->previous = NULL;
        list->head = ins;

    }else{
        ins->previous = list->tail;
        list->tail->next = ins;
    }
    list->tail = ins;
    list->size++;


}

// Remove the list's tail replacing it by the node before it
void poptail(struct DoubleLinkedList *list){
    struct node *newtail = list->tail->previous;

    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->tail);
    if (list->size > 1){
        newtail->next = NULL;
        list->tail = newtail;
    }
    list->size--;

}
// Remove the list's head replacing it with the next node
void pophead(struct DoubleLinkedList *list){
    struct node *newhead = list->head->next;

    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->head);

    if (list->size > 1){
        newhead->previous = NULL;
        list->head = newhead;
    }
    list->size--;

}

// Get data by index starting at the heazd
void* getindexfromhead(struct DoubleLinkedList *list, int index){

    int i;
    struct node* cur = list->head;

    for (i = 0; i<index; i++){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
    }

    return cur->data;
}

// Get data by index starting at the tail
void* getindexfromtail(struct DoubleLinkedList *list, int index){
    int i;
    struct node* cur = list->tail;

    for (i = 0; i<index; i++){
        cur = cur->previous;
        if (cur == NULL){
            return NULL;
        }
    }

    return cur->data;
}

// Create and init double linked list
struct DoubleLinkedList make_dll(){
    struct DoubleLinkedList ret;
    ret.size = 0;
    ret.head = NULL;
    ret.tail = NULL;
    return ret;
}

// Completely wipe a doubly linked list
void nuke(struct DoubleLinkedList *list){
    struct node *cur;
    if (list->size == 0){
        return NULL;
    }
    if (list->head == list->tail){
        free(list->head);
    }else{
        cur = list->head;
        while(1){
            struct node *nxt = cur->next;
            if (cur == list->tail){
                free(cur);
                break;
            } else{
                free(cur);
                cur = nxt;
            }

        }
    }  
    list->size = 0;

}

// Sets the data of a DoublyLinkedList's certain index, starting from the head.
void setdata(struct DoubleLinkedList *list, void* data, int index){
    int i;
    struct node* cur = list->head;
    for (i = 0; i<index; i++){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
    }
        cur->data = data;

}
