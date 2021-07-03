#ifndef WUG_C
#define WUG_C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000 // Max is a constant

typedef struct edgenodes{
    int y;
    int weight;
    struct edgenode* next;
}edgenode;

typedef struct graphs{
    edgenode *edges[MAX+1]; // MAX+1 because vertices are named by no starting from 1
    int degree[MAX+1]; // degree is the no of outgoing edges of each vertex
    int nvertices;
    int nedges;
    bool directed; // Is it undirected or directed or mixed ?
}graph;

void initialize_graph(graph *g,bool directed){
    int i=0; // counter

    g->nvertices=0;
    g->nedges=0;
    g->directed=directed;

    for(;i<=MAX;i++){g->degree[i]=0,g->edges[i]=NULL;}
}

void insert_edge(graph* g, int x, int y, int z, bool directed){
    edgenode* p; // temp node pointer

    // initialize node
    p=(edgenode*)malloc(sizeof(edgenode));
    p->y=y;
    p->weight=z;
    // insert edge at head of adjacency list
    p->next=g->edges[x];
    g->edges[x]=p;

    g->degree[x]++;
    if(directed==false){
        // Graph is stored in adjacency list, where a index = vertex id. 
        // A y node in list means a vertex i can go to vertex y #directed.
        insert_edge(g,y,x,z,true); // insert two copies of each edge as x <-> y
    }{
        g->nedges++;
    }
}

void read_graph(graph *g,bool directed){
    int i=0; // counter
    int m; // number of edges
    int x,y,z; // vertices in edge (x->y), weight of edge (z)

    initialize_graph(g,directed);
    
    scanf("%d %d",&(g->nvertices),&m);
    g->nedges=m;
    printf("Compelet set up");
    for(;i<m;i++){
        printf("X  Y  Z:\n");
        scanf("%d %d %d",&x,&y,&z);
        insert_edge(g,x,y,z,directed);
    }
}

void print_graph(graph* g){
    int i=1; // counter
    edgenode* p; // temp node pointer

    for(;i<=g->nvertices;i++){
        printf("%d: ",i);
        p=g->edges[i];
        while(p!=NULL){
            printf("%d ",p->y);
            p=p->next;
        }
        printf("\n");
    }
}

#endif