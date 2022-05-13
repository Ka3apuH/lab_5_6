#include <iostream>

#include "../function_graph/graph.h"
#include "gtest/gtest.h"
#include <array>

#include <random>

#include "graph_fun_TEST.h"


using namespace h_work;
using namespace std;

TEST(lab_5a,dfs){
    auto test_graph=graph<7>{{0,1,1,0,0,0,0},
                             {1,0,0,1,1,0,0},
                             {1,0,0,1,0,1,1},
                             {0,1,1,0,1,0,0},
                             {0,1,0,1,0,0,0},
                             {0,0,1,0,0,0,0}};
    auto res=test_graph.dfs(1);
}

TEST(lab_5a,dijkstra) {
    auto test_graph = graph<7>{{0, 2, 1, 4, 0, 6, 0},
                               {2, 0, 0, 1, 3, 0, 0},
                               {1, 0, 0, 2, 0, 4, 0},
                               {4, 1, 2, 0, 0, 0, 1},
                               {0, 3, 0, 0, 0, 0, 4},
                               {6, 0, 4, 0, 0, 0, 7},
                               {0, 0, 0, 1, 4, 7, 0}};

    ASSERT_EQ(test_graph.dijkstra(3), (std::array<int, 7>{3, 1, 2, 0, 4, 6, 1}));
}

TEST(lab_5a,kruskal) {
    auto test_graph = graph<8>{{0, 4, 5, 0, 0, 0, 1, 0},
                               {4, 0, 0, 8, 0, 0, 0, 3},
                               {5, 0, 0, 0, 6, 0, 0, 0},
                               {0, 8, 0, 0, 0, 9, 0, 0},
                               {0, 0, 6, 0, 0, 7, 0, 0},
                               {0, 0, 0, 9, 7, 0, 0, 10},
                               {1, 0, 0, 0, 0, 0, 0, 2},
                               {0, 3, 0, 0, 0, 10, 2, 0},
                               };

    auto res=test_graph.kruskal();

    //ASSERT_EQ(test_graph.kruskal());
}