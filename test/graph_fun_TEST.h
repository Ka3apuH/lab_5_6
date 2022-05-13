//
// Created by kirill_kazarin on 23.02.2022.
//

#ifndef LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
#define LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H

#include <gtest/gtest.h>
#include <random>
#include "../function_graph/graph.h"


class Testing_main_func_priority_queue : public ::testing::Test {
protected:
    void SetUp() override {

    }
    void TearDown() override{
    }

// объекты тестового окружения, доступные в каждом тесте
    h_work::graph<10> graph;
    std::random_device randomDevice;
};

#endif //LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
