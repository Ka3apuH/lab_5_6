//
// Created by kirill_kazarin on 12.05.22.
//

#ifndef LAB_5_6_GRAPH_H
#define LAB_5_6_GRAPH_H

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <list>
#include <bitset>
#include <stack>

namespace  h_work {

template<int number_of_vertices>
class graph {
public:

    typedef std::array<std::array<int, number_of_vertices>, number_of_vertices> _matrix;

    ~graph() = default;

    graph() = default;

    graph(std::initializer_list<std::initializer_list<int>> initializerList) {

        for (int i = 0; i < number_of_vertices; ++i) {
            for (int j = 0; j < number_of_vertices; ++j) {
                tridentity_matrix[i][j] = *((initializerList.begin() + i)->begin() + j);
                if (tridentity_matrix[i][j] != 0)mass_E.emplace_back(i, j);
                /*std::cout<<tridentity_matrix[i][j]<<" ";*/
            }
        }
    }

    graph(_matrix& matrix):tridentity_matrix(std::move(matrix)){};


private:
    void recursion_dfs(std::bitset<number_of_vertices> &visited, int x, std::stack<int> &res) {
        res.push(x);
        visited.set(x);
        for (int y: tridentity_matrix[x]) {
            if (y != 0 && !visited.test(y))recursion_dfs(visited, y, res);
        }
    }

    void recursion_dfs_inv(std::bitset<number_of_vertices> &visited, int x, std::stack<int> &res) {

        visited.set(x);

        std::for_each(tridentity_matrix[x].begin(), tridentity_matrix[x].end(),[&visited, this,&res](int y){
            if(!visited.test(y))this->tridentity_matrix(visited, y, res);
            res.push(y);
        });
/*        for (int y: tridentity_matrix[x]) {
            if (y != 0 && !visited.test(y))recursion_dfs(visited, y, res);
        }*/
    }

    std::array<int, number_of_vertices> &operator[](int i) {
        return tridentity_matrix.at(i);
    }

    int find_num_min_el(std::array<int, number_of_vertices> &arr, std::bitset<number_of_vertices> &vis) {
        int num_min = -1;
        for (int i = 0; i < number_of_vertices; ++i) {
            if (vis.test(i))continue;
            if (num_min == -1) {
                num_min = i;
                continue;
            }

            if (arr[num_min] > arr[i])num_min = i;
        }
        return num_min;
    }

    explicit graph(std::array<int, number_of_vertices> &arr, _matrix matrix) {
        for (int i = 0; i < number_of_vertices; ++i) {
            if (arr[i] == INT32_MAX)continue;

            this->tridentity_matrix[i][arr[i]] = matrix[i][arr[i]];
        }

    }

public:
    std::stack<int> dfs(int num_first_peak) {
        auto visited = std::bitset<number_of_vertices>(0);
        auto result = std::stack<int>();

        recursion_dfs(visited, num_first_peak, result);

        return result;
    }

    std::list<int> bfs(int num_first_peak) {
        auto visited = std::bitset<number_of_vertices>(0);
        auto result = std::list<int>();
        auto queue = std::list<int>();

        queue.push_back(num_first_peak);

        while (queue.empty()) {
            int x = queue.back();
            queue.pop_back();
            result.push_back(x);
            for (int y: tridentity_matrix[x]) {
                if (y != 0 && !visited.test(y)) {
                    queue.push_back(y);
                    visited.set(y);
                }
            }
        }

        return result;
    }

    std::array<int, number_of_vertices> dijkstra(int num_peak) {

        auto path_arr = std::array<int, number_of_vertices>();
        std::for_each(path_arr.begin(), path_arr.end(), [](int &i) { i = INT32_MAX; });

        auto visited = std::bitset<number_of_vertices>(0);

        path_arr[num_peak] = 0;

        while (!visited.all()) {
            int find_v = find_num_min_el(path_arr, visited);
            visited.set(find_v);
            for (int u = 0; u < number_of_vertices; ++u) {
                if (tridentity_matrix[find_v][u] != 0 &&
                    path_arr[u] > (path_arr[find_v] + tridentity_matrix[find_v][u])) {
                    path_arr[u] = (path_arr[find_v] + tridentity_matrix[find_v][u]);
                }
            }
        }
        return path_arr;
    }


    _matrix floyd_Warshall() {
        _matrix res = _matrix(tridentity_matrix);

        for (int k = 0; k < number_of_vertices; k++) {
            for (int i = 0; i < number_of_vertices; i++) {
                for (int j = 0; j < number_of_vertices; j++) {
                    res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
                }
            }
        }
        return res;
    }

    graph<number_of_vertices> prima() {
        auto parent = std::array<int, number_of_vertices>();
        std::for_each(parent.begin(), parent.end(), [](int &i) { i = INT32_MAX; });


        auto len_to_oth_peaks = std::array<int, number_of_vertices>();
        std::for_each(len_to_oth_peaks.begin(), len_to_oth_peaks.end(), [](int &i) { i = INT32_MAX; });

        int start_peak = 0;

        auto visit = std::bitset<number_of_vertices>(0);


        len_to_oth_peaks[start_peak] = 0;

        while (!visit.all()) {
            int find_n = find_num_min_el(len_to_oth_peaks, visit);
            visit.set(find_n);

            for (int v = 0; v < number_of_vertices; ++v) {

                if (tridentity_matrix[find_n][v] != 0 &&
                    len_to_oth_peaks[v] > tridentity_matrix[find_n][v] &&
                    !visit.test(v)) {
                    len_to_oth_peaks[v] = tridentity_matrix[find_n][v];
                    parent[v] = find_n;
                }
            }
        }
        return graph<number_of_vertices>(parent, this->tridentity_matrix);
    }

    graph<number_of_vertices> kruskal() {
        auto own_peaks = std::bitset<number_of_vertices>(0);
        auto res_graph = graph<number_of_vertices>();

        std::sort(mass_E.begin(), mass_E.end(),
                  [this](std::pair<int, int> &a, std::pair<int, int> &b) {
                      return tridentity_matrix[a.first][a.second] < tridentity_matrix[b.first][b.second];
                  }
        );

        for (std::pair<int, int> i: mass_E) {
            if (own_peaks[i.first] != own_peaks[i.second]) {
                res_graph[i.first][i.second] = tridentity_matrix[i.first][i.second];
                int temp = own_peaks[i.first];
                for (int j = 0; j < number_of_vertices; ++j) {
                    if (own_peaks[j] == temp)
                        own_peaks[j] = own_peaks[i.second];
                }
            }
        }
        return res_graph;
    }

    std::stack<int> dfs_inv() {
        auto visit = std::bitset<number_of_vertices>(0);

        auto result = std::stack<int>();

        for (int x = 0; x < number_of_vertices; ++x) {
            if (!visit.test(x))recursion_dfs_inv(visit, x, result);
        }
        return result;
    }

    std::stack<std::stack<int>> kosaraiyo(){
        auto visit = std::bitset<number_of_vertices>(0);

        auto result = std::stack<std::stack<int>>();

        //для G^T

        _matrix T_mat;

        for (int i = 0; i <number_of_vertices ; ++i) {
            for (int j = 0; j < number_of_vertices; ++j) {
                T_mat[j][j]=tridentity_matrix[i][j];
            }
        }

        auto T_graph=graph<number_of_vertices>(T_mat);

        for (int v = 0; v < number_of_vertices; ++v) {
            std::stack<int> temp;
            if(!visit.test(v)){
                (T_graph.recursion_dfs_inv(visit,v,temp));
                result.push(temp);
            }
        }

        for (int v = 0; v < number_of_vertices; ++v) {
            if(!visit.test(v)){
                while (!result.empty()){
                    v=result.top().top();
                    result.top().pop();
                    if(!visit.test(v))recursion_dfs();
                }
            }
        }
        return result;
    }


private:
    std::vector<std::pair<int, int>> mass_E;
    _matrix tridentity_matrix;
};

}
#endif //LAB_5_6_GRAPH_H
