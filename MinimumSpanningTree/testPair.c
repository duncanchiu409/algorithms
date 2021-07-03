#include "Kruskal_Alg.c"

int main(void){
    pair_arr* testing=(pair_arr*)malloc(sizeof(pair_arr));
    if(insert_pair(testing,1,2)){printf("success\n");}
    if(insert_pair(testing,1,2)){printf("success\n");}
    if(insert_pair(testing,2,1)){printf("success\n");}
    return 0;
}