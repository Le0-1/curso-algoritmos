#include "Percolation.hpp"
#include "WeightedQuickUnion.hpp"

Percolation::Percolation(unsigned n)  {
    this->_algoritmo = new WeightedQuickUnion(n * n);
    //this->_grid_size = n;
    this->_grid_size = n; 

    for (unsigned i = 0; i < n * n; i++) {
        this->_grid.push_back(SITE_IS_CLOSED);
    }

    //Inicialização das variáveis que irão servir para conectar o top-row e o bottom-row
    Node virtual_bottom_node;
    virtual_bottom_node._id_of_node = 5959;
    virtual_bottom_node._size_of_tree = 1;

    Node virtual_top_node;
    virtual_top_node._id_of_node = 9595;
    virtual_top_node._size_of_tree = 1;

    this->_algoritmo->getNodes().push_back(virtual_bottom_node);
    this->_algoritmo->getNodes().push_back(virtual_top_node);
}

// void Percolation::open(unsigned row, unsigned col) {
//     // unsigned index = this->returnIndex(row, col);
// }

// //Método que retorna se um "Site está aberto"
// bool Percolation::isOpen(unsigned row, unsigned col) {
//     unsigned index = this->returnIndex(row, col);

//     if (this->_grid[index] == SITE_IS_OPEN) {
//         return true;
//     }
//     else 
//         return false;
// }

// //Como eu não fiz uma matrix, esse método ajuda a pegar o index correto do elemento desejado
// unsigned Percolation::returnIndex(unsigned row, unsigned col) {
//     unsigned index = (this->_grid_size * row) + col;
//     return index;
// }