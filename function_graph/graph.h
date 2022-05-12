//
// Created by kirill_kazarin on 12.05.22.
//

#ifndef LAB_5_6_GRAPH_H
#define LAB_5_6_GRAPH_H

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

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
    _matrix tridentity_matrix;
};

#endif //LAB_5_6_GRAPH_H
