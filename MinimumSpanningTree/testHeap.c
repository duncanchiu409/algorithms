#include "Kruskal_Alg.c"

int main(void){
    Heap* testing=malloc(sizeof(Heap));
    initialize_heap(testing);
    insert_heap(testing,0,0,5);
    insert_heap(testing,0,0,4);
    insert_heap(testing,0,0,3);
    insert_heap(testing,0,0,2);
    insert_heap(testing,0,0,1);
    print_heap(testing);
    return 0;
}
