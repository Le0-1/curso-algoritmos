#include "Percolation.hpp"
#include "WeightedQuickUnion.hpp"

Percolation::Percolation(unsigned n)  {
    this->_algorithm = std::make_shared<WeightedQuickUnion>(n*n);

    //Esse é o número de elementos que cada linha e coluna do grid tem, para facilitar alguns cálculos.
    this->_grid_size = n;

    //Inicializa todo o grid com os sites fechados
    for (unsigned i = 0; i < n * n; i++) {
        this->_grid.push_back(SITE_IS_CLOSED);
    }

    //Inicialização das variáveis que irão servir para conectar o top-row e o bottom-row
    this->initializeVirtalNodes(n);
    this->connectVirtualNodesToFirstAndLastRow();

    //Se todos os sites começam fechados, logo o número de sites abertos = 0;
    this->_number_of_open_sites = 0;
}

//Função para dar um id e size da árvore para os nós virtuais, é bom notar que o número de elementos no grid
//nao aumenta com a adição desses dois nós, já que eles são apenas auxiliares. Eles servem
//para informar quando algum nó conectado com a parte de baixo encontra um nó com a parte de cima,
//ou seja, quando a raizes dós nós virtuais são iguais.
void Percolation::initializeVirtalNodes(unsigned n) {
    
    //Id do nó é n * n pois assim eu nunca vou ter um mesmo id que algum outro nó que
    //já foi criado no construtor do WeightedQuickUnion.
    this->virtual_bottom_node._id_of_node = n * n;
    this->virtual_bottom_node._size_of_tree = 1;

    
    this->virtual_top_node._id_of_node = n * n + 1;
    this->virtual_top_node._size_of_tree = 1;

    this->_algorithm->getNodes().push_back(virtual_bottom_node);
    this->_algorithm->getNodes().push_back(virtual_top_node);
}

//conecta os nós virtuais ao top row e bottom row
void Percolation::connectVirtualNodesToFirstAndLastRow() {
    unsigned gridSize = this->_grid_size;

    for (unsigned i = 0; i < gridSize; i++) {
        //Conecta o virtal_top_node aos nós que representam o primeiro row do grid
        this->_algorithm->connectNodes(this->virtual_top_node, this->_algorithm->getNodes()[i]);

        //A expressão (gridSize * gridSize -1 -i) é para pegar apenas os nodes da ultima linha do grid
        this->_algorithm->connectNodes(this->virtual_bottom_node, this->_algorithm->getNodes()[gridSize * gridSize -1 -i]);
    }
}

//Abre uma posição no grid e verifica se há outras posição abertas para conectar os nós
void Percolation::open(unsigned row, unsigned col) {
    unsigned correctIndex = this->returnCorrectedIndex(row, col);

    //Posição não está aberta
    if (this->_grid[correctIndex] == SITE_IS_CLOSED) {
        this->_grid[correctIndex] = SITE_IS_OPEN;
        this->_number_of_open_sites+= 1;
    }
    else {
        return; 
    }

    //Preciso conectar os nó que representa o "site" aberto com os outros 
    //nós que representam os "sites" adjacentes, se estiverem abertos.
    this->connectWithAdjacentSites(row, col);
}

//Como escrito na linha 67, preciso conectar os nós que estão abertos se eles forem adjacentes
//para manter o "track" do grid e verificar se o grid foi "percolado"
void Percolation::connectWithAdjacentSites(unsigned row, unsigned col) {
    unsigned correctIndex = this->returnCorrectedIndex(row, col);

    //Conectar com o de cima se aberto, a fórmula para pegar o de cima é grid_size * (row - 1) + col. Se row == 0, o grid não tem nada em cima.
    unsigned adjacentUpGrid = (this->_grid_size * (row - 1)) + col;

    if ((row != 0) && (this->_grid[adjacentUpGrid] == SITE_IS_OPEN)) {
        this->_algorithm->connectNodes(this->_algorithm->getNodes()[correctIndex], this->_algorithm->getNodes()[adjacentUpGrid]);
    }

    //Conectar com o de baixo se aberto, a fórmula para pegar o de cima é grid_size * (row + 1) + col. Se row == lastRow, o grid não tem nada em baixo.
    unsigned adjacentDownGrid = (this->_grid_size * (row + 1)) + col;
    unsigned lastRow = this->_grid_size - 1;

    if ((row != lastRow)  && (this->_grid[adjacentDownGrid] == SITE_IS_OPEN)) {
        this->_algorithm->connectNodes(this->_algorithm->getNodes()[correctIndex], this->_algorithm->getNodes()[adjacentDownGrid]);
    }

    //Conectar com o que está do lado esquerdo, se a col == 0, não tem nada do lado esquerdo. A fórmula é só pegar o correctIndex e diminuir em 1
    unsigned adjacentLeftGrid = correctIndex - 1;

    if ((col != 0) && (this->_grid[adjacentLeftGrid] == SITE_IS_OPEN)) {
        this->_algorithm->connectNodes(this->_algorithm->getNodes()[correctIndex], this->_algorithm->getNodes()[adjacentLeftGrid]);
    }

    //Conectar com o que está do lado direito, se a col == grid_size - 1, então não tem nada do lado direito pois é a última coluna.
    //A fórmula é só adicionar mais um ao correct Index
    unsigned adjacentRightGrid = correctIndex + 1;
    unsigned lastCollum = this->_grid_size - 1;

    if ((col != lastCollum) && (this->_grid[adjacentRightGrid] == SITE_IS_OPEN)) {
        this->_algorithm->connectNodes(this->_algorithm->getNodes()[correctIndex], this->_algorithm->getNodes()[adjacentRightGrid]);
    }
}

//Método que retorna se um "Site está aberto"
bool Percolation::isOpen(unsigned row, unsigned col) {
    unsigned index = this->returnCorrectedIndex(row, col);

    if (this->_grid[index] == SITE_IS_OPEN) {
        return true;
    }
    else 
        return false;
}

//Como eu não fiz uma matrix, esse método ajuda a pegar o index correto do elemento desejado
//Fórmula é: grid_size * row + col
unsigned Percolation::returnCorrectedIndex(unsigned row, unsigned col) {
    unsigned index = (this->_grid_size * row) + col;
    return index;
}

//Retorna o número de sites abertos
unsigned Percolation::numberOfOpenSites() {
    return this->_number_of_open_sites;
}

//Retrona se o grid foi "percolado", isto é, se existe um caminho aberto entre o top e o bottom row
//Pra isso, é necessário que a raiz dos virtual nodes sejam iguais.
bool Percolation::percolates() {
    unsigned topRoot = this->_algorithm->findRoot(this->virtual_top_node);
    unsigned bottomRoot = this->_algorithm->findRoot(this->virtual_bottom_node);

    if (topRoot == bottomRoot) {
        return true;
    }
    else {
        return false;
    }
}