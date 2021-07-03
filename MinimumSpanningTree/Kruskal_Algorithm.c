/* Kruskal's Algorithm
Each vertex starts as a separate tree and these trees merges together by repeatedly adding the lowest cost edge that spans two distinct subtrees.

Pesudo Code:
Kruskal(G)
    for each vertex
        make edge set
    sort the edges in order of increasing weight
    count = 0
    while(count<n-1)do
        get next edge(v,w)
        if(component(v)!=component(w))
            add to T
            component(v)=component(w)
        fi
    end

The "which component?" tests can be efficiently implemented using the union-find data structure to yield an O(mlgm) algorithm. */
// Credited to The Algorithms Design Manual

#ifndef KRUSKAL
#define KRUSKAL

#include "Library.c"
#include "WeightedUndirectedGraph.c"

int Kruskal_Algorithms(graph* g){
    PairArr* arr1=(PairArr*)malloc(sizeof(PairArr));
    initialize_arr(arr1);
    Heap* arr2=(Heap*)malloc(sizeof(Heap));
    initialize_heap(arr2);
    graph* Q=(graph*)malloc(sizeof(graph));
    initialize_graph(g,false);
    
    int x,y;
    int i=1;
    edgenode* temp1; 
    for(;i<=g->nvertices;i++){
        x=i;
        temp1=g->edges[x];
        while(temp1!=NULL){
            y=g->edges[x]->y;
            if(insert_pair(arr1,x,y))insert_heap(arr2,x,y,g->edges[x]->weight);
            temp1=temp1->next;
        }
        printf("HAy");
    }
    
    HeapNode* temp2;
    int j=1;
    for(;j<=arr2->n;j++){
        temp2=delete_root(arr2);
        printf("x: %d, y: %d, cost: %d",temp2->start_vertex,temp2->end_vertex,temp2->weight);
    }
    return 0;
}

#endif