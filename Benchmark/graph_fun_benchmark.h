//
// Created by kirill_kazarin on 24.02.2022.
//


#ifndef LAB1_BENCHMARK_PRIORITY_QUEUE_H
#define LAB1_BENCHMARK_PRIORITY_QUEUE_H

#include <random>
#include "benchmark/benchmark.h"
#include "priority_queue.h"

class benchmark_priority_queue_fix: public benchmark::Fixture{

public:

    void SetUp(const ::benchmark::State &state) override {

        for (int64_t i = 0; i < state.range(0); ++i) {
            pr_heap.add_element(randomDevice());
        }
    }

    void TearDown(const ::benchmark::State &state) override{
        this->pr_heap.clear();
    }


protected:
    h_work::priority_queue<unsigned int> pr_heap;
    std::random_device randomDevice;
};

#endif //LAB1_BENCHMARK_PRIORITY_QUEUE_H
