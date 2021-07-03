#ifndef LIBRARY
#define LIBRARY

// Implementation by DUCAN :)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 100

// No heap library :'(
typedef struct{
    int start_vertex;
    int end_vertex;
    int weight;
}HeapNode;

typedef struct{
    HeapNode* q[max_size+1];
    int n;
}Heap;

void heapifyup(Heap* pq,int i){ // sift up
    int size=pq->n;
    int current=i;
    int parent=i/2;

    if(parent!=0&&pq->q[current]->weight<pq->q[parent]->weight){
        parent=current;
    }
    if(parent!=0&&parent!=i/2){
        // swap q->[current] & q->[parent]
        HeapNode* temp=pq->q[i/2];
        pq->q[i/2]=pq->q[parent];
        pq->q[parent]=temp;

        // recurrsive call
        heapifyup(pq,i/2);
    }
}

void heapifydown(Heap* pq,int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<pq->n&&pq->q[smallest]>pq->q[left]){
        smallest=left;
    }
    if(right<pq->n&&pq->q[smallest]>pq->q[right]){
        smallest=right;
    }
    if(smallest!=i){
        HeapNode* temp=pq->q[i];
        pq->q[i]=pq->q[smallest];
        pq->q[smallest]=temp;

        heapifydown(pq,smallest);
    }
}

void insert_heap(Heap* pq,int x,int y,int z){
    // initialize heap node
    HeapNode* hn=(HeapNode*)malloc(sizeof(HeapNode)); // temp node pointer
    hn->start_vertex=x;
    hn->end_vertex=y;
    hn->weight=z;

    // Heap Node insertion
    pq->n++;
    int i=pq->n;
    pq->q[i]=hn;
    heapifyup(pq,i);
}

void initialize_heap(Heap* pq){
    int i=0; // counter
    for(;i<=max_size;i++){
        pq->q[i]=NULL;
    }
    pq->n=0;
}

void print_heap(Heap* pq){
    int i=1; // counter;
    int size=pq->n; // size of Heap

    for(;i<=size;i++){
        printf("x:%d y:%d weight:%d \n",pq->q[i]->start_vertex,pq->q[i]->end_vertex,pq->q[i]->weight);
    }
}

// I am responsibile student :)
void free_heap(Heap* pq){
    int i=0; // counter
    for(;i<=max_size;i++){
        free(pq->q[i]);
    }
    free(pq);
}


HeapNode* delete_root(Heap* pq){
    int size=pq->n;
    HeapNode* min=pq->q[1];
    pq->q[1]=pq->q[pq->n];
    free(pq->q[pq->n]);
    pq->n--;
    heapifydown(pq,1);
    return min;
}

typedef struct{
    int one; // x
    int two; // y
}Pair;

typedef struct{
    Pair* arr[max_size];
    int n;
}PairArr;

void initialize_arr(PairArr* copy){
    copy->n=0;
    int i=0;
    for(;i<max_size;i++){
        copy->arr[i]=NULL;
    }
}

bool check_existed(PairArr* copy,int x,int y){
    int i=0; 
    for(;i<copy->n;i++){
        Pair* temp=copy->arr[i];
        if(temp->one==y&&temp->two==x){
            return true;
        }
        if(temp->one==x&&temp->two==y){
            return true;
        }
    }
    return false;
}

bool insert_pair(PairArr* copy,int x,int y){
    if(check_existed(copy,x,y)){
        return false;
    }
    Pair* temp=(Pair*)malloc(sizeof(Pair));
    temp->one=x;
    temp->two=y;
    copy->arr[copy->n]=temp;
    copy->n++;
    return true;
}

#endif
// Credited to DUCAN :)