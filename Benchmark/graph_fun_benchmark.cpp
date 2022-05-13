//
// Created by kirill_kazarin on 23.02.2022.
//

#include <random>

#include "benchmark/benchmark.h"
#include "../function_graph/function.h"
#include "graph_fun_benchmark.h"


BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_add_elements) (benchmark::State& state) {
    for (auto _ : state) {
        pr_heap.add_element(randomDevice());
        benchmark::DoNotOptimize(pr_heap.add_element(randomDevice()));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_del_elements) (benchmark::State& state) {
    for (auto _ : state) {
        pr_heap.pop();
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_sort_elements) (benchmark::State& state) {
    for (auto _ : state) {
        for (int64_t i = 0; i <state.range(0) ; ++i) {
            pr_heap.pop();
        }
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_add_elements)
->RangeMultiplier(2)
->Range(8, 8<<8)
        ->Iterations(1)
->Complexity(benchmark::oAuto);

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_del_elements)
->RangeMultiplier(2)
->Range(8, 8<<8)
        ->Iterations(1)
->Complexity(benchmark::oAuto);

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_sort_elements)
        ->RangeMultiplier(2)
        ->Range(8, 8<<8)
        ->Iterations(1)
        ->Complexity(benchmark::oAuto);

// Run the benchmark
BENCHMARK_MAIN();



