#ifndef PERCOLATION_H
#define PERCOLATION_H

#define SITE_IS_CLOSED 0  //Constante para falar se o site está fechado
#define SITE_IS_OPEN 1   //Constante para falar se o site está aberto

#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <vector>
#include <memory>

//Struct para armazenar os dados necessários de um "Site" (local) no Grid

class Percolation { 
    public:
        //O grid é um vector de "Sites" (locais);
        std::vector<bool> _grid;

        //Váriavel para guardar o tamanho do grid, se o grid é n-por-n, a váriavel tera valor n
        unsigned _grid_size;

        //Algoritmo responsável por fazer as uniões
        WeightedQuickUnion* _algoritmo;

    public:

        // Cria um grid n-por-n, com todos os locais (quadrados) bloqueados
        Percolation(unsigned n);

        //Abri o local, se ele já não estiver aberto
        void open(unsigned row, unsigned col);

        // O local (row, col) está aberto?
        bool isOpen(unsigned row, unsigned col);

        //O local (row, col) está cheio?
        bool isFull(unsigned row, unsigned col);

        // Retorna o número de locais abertos
        unsigned numberOfOpenSites();

        unsigned returnIndex(unsigned row, unsigned col);

        //O sistema pode ser "percolado"?
        bool percolates();
};

#endif
