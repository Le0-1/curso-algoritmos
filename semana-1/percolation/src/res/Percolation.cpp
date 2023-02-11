#include "Percolation.hpp"
#include "WeightedQuickUnion.hpp"

Percolation::Percolation(unsigned n)  {
    this->_algoritmo = new WeightedQuickUnion(n*n + 2);
    this->_grid_size = n;

    for (unsigned i = 0; i < n * n; i++) {
        Site new_site;
        new_site.is_open = SITE_IS_CLOSED;
        new_site._node._id_of_node = i;
        new_site._node._size_of_tree = 1;
        this->_grid.push_back(new_site);
    }

    //Inicialização das variáveis que irão servir para conectar o top-row e o bottom-row
    this->_virtual_bottom_node._id_of_node = n * n + 1;
    this->_virtual_bottom_node._size_of_tree = 1;
    this->_virtual_top_node._id_of_node = n * n + 2;
    this->_virtual_top_node._size_of_tree = 1;
}

void Percolation::open(unsigned row, unsigned col) {
    // unsigned index = this->returnIndex(row, col);
}

//Método que retorna se um "Site está aberto"
bool Percolation::isOpen(unsigned row, unsigned col) {
    unsigned index = this->returnIndex(row, col);

    if (this->_grid[index].is_open == SITE_IS_OPEN) {
        return true;
    }
    else 
        return false;
}

//Como eu não fiz uma matrix, esse método ajuda a pegar o index correto do elemento desejado
unsigned Percolation::returnIndex(unsigned row, unsigned col) {
    unsigned index = (this->_grid_size * row) + col;
    return index;
}