#include <iostream>

#include "priority_queue.h"
#include "gtest/gtest.h"

#include <random>

#include "graph_fun_TEST.h"

using namespace h_work;
using namespace std;

TEST_F(Testing_main_func_priority_queue,add_element){

    unsigned int sizeOfHeap=randomDevice()%103;
    //чтобы не было часто равно 0.... взял простое число

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {
        auto element=randomDevice();
        test_heap.add_element(element);
        real_heap.push(element);
    }

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {

        ASSERT_EQ(test_heap.max_elem(),real_heap.top());
        test_heap.pop();
        real_heap.pop();
    }
}

TEST_F(Testing_main_func_priority_queue,add_2_element){


    unsigned int sizeOfHeap=randomDevice()%103;
    //чтобы не было часто равно 0.... взял простое число

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {
        auto element=randomDevice();
        test_heap.add_element(element);
        real_heap.push(element);
    }

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {

        ASSERT_EQ(test_heap.max_elem(),real_heap.top());
        test_heap.pop();
        real_heap.pop();
    }
}


