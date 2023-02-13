#include "Percolation.hpp"
#include "PercolationStats.hpp"
#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <memory>

int main() {
    Percolation a(6);
    // std::cout << a._algorithm->getNodes().size() << std::endl;

    // for (unsigned i = 0; i < a._algorithm->getNodes().size(); i++) {
    //     std::cout << i << " " << a._algorithm->getNodes()[i]._id_of_node;
    //     std::cout << " " << a._algorithm->findRoot(a._algorithm->getNodes()[i]);
    //     std::cout << " " << a._algorithm->getNodes()[i]._size_of_tree;
    //     std::cout << " " << a._grid[i] << "\n";
    // }
    // std::cout << "----------" << "\n";

    for (unsigned i = 0; i < a._algorithm->getNodes().size(); i++) {
        std::cout << i << " " << a._algorithm->getNodes()[i]._id_of_node;
        std::cout << " " << a._algorithm->findRoot(a._algorithm->getNodes()[i]);
        std::cout << " " << a._algorithm->getNodes()[i]._size_of_tree;
        std::cout << " " << a._grid[i] << "\n";
    }
    std::cout << "----------" << "\n";

    //Como esperado ele apenas percola quando chega na linha 5 coluna 0
    //Dessa forma tem um caminho direto da parte de cima para a parte de baixo
    for (unsigned i = 0; i < a._grid_size; i++) {
        for (unsigned j = 0; j < a._grid_size; j++) {
            a.open(i, j);
            std::cout << i << " " << j << "\n";
        }
        if (a.percolates()) break;
    }
}