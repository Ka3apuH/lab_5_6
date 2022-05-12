//
// Created by kirill_kazarin on 12.05.22.
//
#include "function_graph/graph.h"
int main(){
auto a=graph<6>{
    {1,2,3,4,5,6},
    {1,2,3,3,4,6},
    {1,2,4,5,4,6},
    {1,2,3,4,6,4},
    {1,2,5,4,5,6},
    {2,2,3,2,4,6}};


    return 0;
}