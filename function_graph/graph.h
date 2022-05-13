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

template<int number_of_vertices>
class graph{
public:

    typedef std::array<std::array<int,number_of_vertices>,number_of_vertices> _matrix;

    ~graph()=default;
    graph()=default;

    graph(std::initializer_list<std::initializer_list<int>> initializerList){

        for (int i = 0; i < number_of_vertices; ++i) {
            for (int j = 0; j < number_of_vertices; ++j) {
                tridentity_matrix[i][j]=*((initializerList.begin()+i)->begin()+j);
                std::cout<<tridentity_matrix[i][j]<<" ";
            }
        }
    }

private:
    void recursion_dfs(std::bitset<number_of_vertices> &visited,int x, std::list<int> &res){
        res.push_back(x);
        visited.set(x);
        for (int y:tridentity_matrix[x]) {
            if(y!=0 && !visited.test(y))recursion_dfs(visited,y,res);
        }
    }

    int find_num_min_el(std::array<int,number_of_vertices> &arr,std::bitset<number_of_vertices> &vis){
        int num_min=-1;
        for (int i = 0; i < number_of_vertices; ++i) {
            if(vis.test(i))continue;
                if(num_min==-1) {
                    num_min = i;
                    continue;
                }

            if(arr[num_min]>arr[i])num_min=i;
        }
        return num_min;
    }

    explicit graph(std::array<int,number_of_vertices> &arr,_matrix matrix){
        for (int i = 0; i < number_of_vertices; ++i) {
            if(arr[i]==INT32_MAX)continue;

            this->tridentity_matrix[i][arr[i]]=matrix[i][arr[i]];
        }

    }

public:
    std::list<int> dfs(int num_first_peak){
        auto visited=std::bitset<number_of_vertices>(0);
        auto result=std::list<int>();

        recursion_dfs(visited,num_first_peak,result);

        return result;
    }

    std::list<int> bfs(int num_first_peak){
        auto visited=std::bitset<number_of_vertices>(0);
        auto result=std::list<int>();
        auto queue =std::list<int>();

        queue.push_back(num_first_peak);

        while (queue.empty()){
            int x=queue.back();
            queue.pop_back();
            result.push_back(x);
            for (int y:tridentity_matrix[x]) {
                if(y!=0 && !visited.test(y)){
                    queue.push_back(y);
                    visited.set(y);
                }
            }
        }

        return result;
    }

    std::array<int,number_of_vertices> dijkstra(int num_peak){

        auto path_arr=std::array<int,number_of_vertices>();
        std::for_each(path_arr.begin(), path_arr.end(),[](int &i){i=INT32_MAX;});

        auto visited=std::bitset<number_of_vertices>(0);

        path_arr[num_peak]=0;

        while (!visited.all()){
            int find_v= find_num_min_el(path_arr,visited);
            visited.set(find_v);
            for (int u = 0; u < number_of_vertices; ++u) {
                if(tridentity_matrix[find_v][u]!=0 &&
                path_arr[u]>(path_arr[find_v]+tridentity_matrix[find_v][u])){
                    path_arr[u]=(path_arr[find_v]+tridentity_matrix[find_v][u]);
                }
            }
        }
        return path_arr;
    }


    _matrix floydWarshall() {
        _matrix res =_matrix(tridentity_matrix);

        for (int k = 0; k < number_of_vertices; k++) {
            for (int i = 0; i < number_of_vertices; i++) {
                for (int j = 0; j < number_of_vertices; j++) {
                        res[i][j] = std::min(res[i][j],res[i][k] + res[k][j]);
                }
            }
        }
        return res;
    }

    graph<number_of_vertices> prima(){
        auto parent = std::array<int,number_of_vertices>();
        std::for_each(parent.begin(), parent.end(),[](int &i){i=INT32_MAX;});


        auto len_to_oth_peaks= std::array<int,number_of_vertices>();
        std::for_each(len_to_oth_peaks.begin(), len_to_oth_peaks.end(),[](int &i){i=INT32_MAX;});

        int start_peak=0;

        auto visit=std::bitset<number_of_vertices>(0);


        len_to_oth_peaks[start_peak] = 0;

        while (!visit.all()) {
            int find_n=find_num_min_el(len_to_oth_peaks, visit);
            visit.set(find_n);

            for (int v = 0; v < number_of_vertices; ++v) {

                if(tridentity_matrix[find_n][v] != 0 &&
                len_to_oth_peaks[v]>tridentity_matrix[find_n][v] &&
                !visit.test(v)){
                    len_to_oth_peaks[v]=tridentity_matrix[find_n][v];
                    parent[v]=find_n;
                }
            }
        }
        return graph<number_of_vertices>(parent, this->tridentity_matrix);
    }



private:
    _matrix tridentity_matrix;
};

#endif //LAB_5_6_GRAPH_H
