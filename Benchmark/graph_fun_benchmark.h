//
// Created by kirill_kazarin on 24.02.2022.
//


#ifndef LAB1_BENCHMARK_PRIORITY_QUEUE_H
#define LAB1_BENCHMARK_PRIORITY_QUEUE_H

#include <random>
#include "benchmark/benchmark.h"
#include "../function_graph/graph.h"


class benchmark_priority_queue_fix: public benchmark::Fixture{

public:

    void SetUp(const ::benchmark::State &state) override {
    }

    void TearDown(const ::benchmark::State &state) override{
    }


protected:
    std::random_device randomDevice;
};

#endif //LAB1_BENCHMARK_PRIORITY_QUEUE_H
