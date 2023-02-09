#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <iostream>


class Percolation {
    public:

        // Cria um grid n-por-n, com todos os locais (quadrados) bloqueados
        Percolation(int n);

        //Abri o local, se ele já não estiver aberto
        void open(int row, int col);

        // O local (row, col) está aberto?
        bool isOpen(int row, int col);

        //O local (row, col) está cheio?
        bool isFull(int row, int col);

        // Retorna o número de locais abertos
        int numberOfOpenSites();

        //O sistema pode ser "percolado"?
        bool percolates();
};

#endif
