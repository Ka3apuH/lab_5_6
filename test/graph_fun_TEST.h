//
// Created by kirill_kazarin on 23.02.2022.
//

#ifndef LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
#define LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H

#include <gtest/gtest.h>
#include "priority_queue.h"
#include <queue>


class Testing_main_func_priority_queue : public ::testing::Test {
protected:
    void SetUp() override {

    }
    void TearDown() override {
        test_heap.clear();
    }

// объекты тестового окружения, доступные в каждом тесте
    std::priority_queue<unsigned int> real_heap;
    h_work::priority_queue<unsigned int> test_heap;
    std::random_device randomDevice;
};

#endif //LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
