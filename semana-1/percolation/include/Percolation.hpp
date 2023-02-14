#ifndef PERCOLATION_H
#define PERCOLATION_H

#define SITE_IS_CLOSED 0  //Constante para falar se o site está fechado
#define SITE_IS_OPEN 1   //Constante para falar se o site está aberto

#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <vector>
#include <memory>

class Percolation { 
    private:
        //O grid é um vector de "Sites" (locais) abertos ou fechados
        std::vector<bool> _grid;

        //Váriavel para guardar o tamanho do grid, se o grid é n-por-n, a váriavel tera valor n
        unsigned _grid_size;

        //Algoritmo responsável por fazer as uniões
        std::shared_ptr<WeightedQuickUnion> _algorithm;

        Node virtual_bottom_node;
        Node virtual_top_node;

        unsigned _number_of_open_sites;

    public:

        // Cria um grid n-por-n, com todos os locais (quadrados) bloqueados
        Percolation(unsigned n);

        //Inicializa os nodes virtuais do top e bottom com id n*n e n*n+1, respectivamente
        void initializeVirtalNodes(unsigned n);

        //Conecta os virtal nodes a parte de cima e de baixo do grid
        void connectVirtualNodesToFirstAndLastRow();

        //Abri o local, se ele já não estiver aberto
        void open(unsigned row, unsigned col);

        //Conecta com os "sites" adjacentes
        void connectWithAdjacentSites(unsigned row, unsigned col);

        // O local (row, col) está aberto?
        bool isOpen(unsigned row, unsigned col);

        //O local (row, col) está cheio?
        //Acabei não usando esse método
        bool isFull(unsigned row, unsigned col);

        // Retorna o número de locais abertos
        unsigned numberOfOpenSites();

        unsigned returnCorrectedIndex(unsigned row, unsigned col);

        //O sistema pode ser "percolado"?
        bool percolates();
};

#endif
