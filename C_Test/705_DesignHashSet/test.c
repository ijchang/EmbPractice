#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

#define BUCKET_SIZE 769

typedef struct listData{
    struct listData * next;
    int key;
}listData_t;

typedef struct{
    listData_t *head;
    int size;
}sList_t;

typedef struct{
    sList_t setData[BUCKET_SIZE];
}HashSet_t;

int hash(int key){
    return (key % BUCKET_SIZE);
}

HashSet_t* hashSetCreate(){
    HashSet_t* ret;
    ret = malloc(sizeof(HashSet_t));
    for(int i = 0; i < BUCKET_SIZE; i++){
        sList_t *p_list = &ret[i];
        p_list->size = 0;
        p_list->head = NULL;
    }
    
    return ret;
}

bool hashSetContain(HashSet* p_set, int key){
    int h = hash(key);
    sList_t* p_list = &p_set[h];
    if(p_list->size == 0){
        return false;
    }else{
        listData_t *p_data = p_list->head;
        while(p_data != NULL){
            if(p_data->key == key){
                return true;
            }
            p_data = p_data->next;
        }
        return false;
    }
}

void hashSetAdd(HashSet* p_set, int key){
    int h = hash(key);
    sList_t* p_list = &p_set[h];
    listData_t* p_data = malloc(sizeof(listData_t));
    p_data->key = key;

    if(p_list->size == 0){
        p_list->head = p_data;
        p_list->size++;
    }else{
        p_data->next = p_list->head;
        p_list->head = p_data;
    }
}

void hashSetRemove(HashSet* p_set, int key){
    int h = hash(key);
    if(false == hashContain(p_set, key)){
        return;
    }

    sList_t* p_list = &p_set[h];
    listData_t* p_data = p_list->head;
    listData_t* p_pre = p_list->head;
    do{
        if(p_data->key == key){
            p_pre->next = p_data->next;
            free(p_data);
        }
        p_pre = p_data;
        p_data = p_data->next;
    }while(p_data != NULL);
}

void hashSetFree(HashSet* p_set){
    sList_t* p_list;
    listData_t* p_data;

    for(int i = 0; i < BUCKET_SIZE; i++){
        p_list = &p_set[i];
        p_data = p_list->head;
        while(p_data != NULL){
            p_list->head = p_data->next;
            free(p_data);
            p_data = p_list->head;
        }
    }
    free(p_set);
}
