#include "Library.c"
#include "WeightedUndirectedGraph.c"
#include "Kruskal_Algorithm.c"

int main(void){
    graph* testing=(graph*)malloc(sizeof(graph));
    initialize_graph(testing,false);
    read_graph(testing,false);
    print_graph(testing);

    Kruskal_Algorithms(testing);
    return 0;
}