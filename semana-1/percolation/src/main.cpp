#include "Percolation.hpp"
#include "PercolationStats.hpp"
#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <memory>

int main() {
   Percolation a(3);

   std::cout << a._algoritmo->getNodes().size() << std::endl;

    for (unsigned i = 0; i < a._algoritmo->getNodes().size(); i++) {
        std::cout << a._algoritmo->getNodes()[i]._id_of_node << "\n";
    }
    

}