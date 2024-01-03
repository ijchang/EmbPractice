#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"



typedef struct sListData{
    struct sListData* next;
    int key;
}sListData_t;

typedef struct{
    sListData_t* head;
    int size;
}sList_t;

typedef struct {
    sList_t* data;
}MyHashSet;

#define NUM_OF_BUCKET 769

int hash(int key){
    return (key % NUM_OF_BUCKET);
}

MyHashSet* myHashSetCreate() {
    MyHashSet* ret = malloc(sizeof(MyHashSet));
    ret->data = malloc(NUM_OF_BUCKET * sizeof(sList_t));
    for(int i = 0; i < NUM_OF_BUCKET; i++){
        sList_t* list = &ret->data[i];
        list->size = 0;
        list->head = NULL;
    }
    
    return ret;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int h = hash(key);
    sList_t* list = &obj->data[h];
    sListData_t* node = list->head;
    while(node != NULL){
        if(node->key == key){
            return true;
        }
        node = node->next;
    }
    
    return false;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int h = hash(key);
    sList_t* list = &obj->data[h];
    
    if(true == myHashSetContains(obj, key)){
        return;
    }
    
    sListData_t* node = malloc(sizeof(sListData_t));
    node->key = key;
    if(list->head == NULL){
        node->next = NULL;
        list->head = node;
    }else{
        node->next = list->head;
        list->head = node;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int h = hash(key);
    sList_t* list = &obj->data[h];
    sListData_t* node = list->head;
    sListData_t* prev = NULL;
    while(node != NULL){
        if(node->key == key){
            break;
        }
        prev = node;
        node = node->next;
    }
    if(node != NULL){
        if(prev == NULL){
            list->head = node->next;
            free(node);
        }else{
            prev->next = node->next;
            free(node);
        }
    }
}

void myHashSetFree(MyHashSet* obj) {
    for(int i = 0; i < NUM_OF_BUCKET; i++){
        sList_t* list = &obj->data[i];
        sListData_t* node = list->head;
        while(node != NULL){
            sListData_t* tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(obj->data);
} 


int main(void)
{
	MyHashSet *p_set;
	p_set = myHashSetCreate();
	
	myHashSetAdd(p_set, 1);
	myHashSetAdd(p_set, 2);
	printf("Set contains 1? ans = %d\n", myHashSetContains(p_set, 1));
	printf("Set contains 3? ans = %d\n", myHashSetContains(p_set, 3));
    myHashSetAdd(p_set, 2);
	printf("Set contains 2? ans = %d\n", myHashSetContains(p_set, 2));
	myHashSetRemove(p_set, 2);
	printf("Set contains 2? ans = %d\n", myHashSetContains(p_set, 2));
	myHashSetFree(p_set);

    return 0;
}



