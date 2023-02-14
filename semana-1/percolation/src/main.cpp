#include "Percolation.hpp"
#include "PercolationStats.hpp"
#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int main() {
    unsigned gridSize, simulations;

    std::cout << "Digite o tamanho do grid: ";
    std::cin >> gridSize;

    std::cout << "Digite a quantidade de trials (simulações): ";
    std::cin >> simulations;

    PercolationStats percStats(gridSize, simulations);
    percStats.printStats();

}