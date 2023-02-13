#include "WeightedQuickUnion.hpp"

#include <iostream>

//Construtor para inicializar os nós que irão representar o grid
WeightedQuickUnion::WeightedQuickUnion(unsigned numberOfNodes) {
    this->_nodes.reserve(numberOfNodes);

    for (unsigned i = 0; i < numberOfNodes; i++) {
        Node new_node;
        new_node._id_of_node = i;
        new_node._size_of_tree = 1;
        this->_nodes.push_back(new_node);
    }

    this->_number_of_components = numberOfNodes; 
}

//Retorna o número de componentes do grid
unsigned WeightedQuickUnion::getComponents() {
    return this->_number_of_components;
}

//Enquanto o id for diferente do id que se encontra dentro do nó
//Ele vai procurando para encontrar a raiz
unsigned WeightedQuickUnion::findRoot(Node& Node) {
    unsigned id = Node._id_of_node;

    while (id != this->_nodes[id]._id_of_node) {
        id = this->_nodes[this->_nodes[id]._id_of_node]._id_of_node; //path compression
    }
    return id;
}

//Apenas checa se a raiz é a mesma
bool WeightedQuickUnion::isConnected(Node& firstNode, Node& secondNode) {
    if (this->findRoot(firstNode) == this->findRoot(secondNode)) {
        return 1;
    }

    else return 0;
}

//Conecta dois nós que não estão conectados
void WeightedQuickUnion::connectNodes(Node& firstNode, Node& secondNode) {
    unsigned rootFirstNode = this->findRoot(firstNode);
    unsigned rootSecondNode = this->findRoot(secondNode);

    unsigned sizeTreeFirstNode = this->_nodes[rootFirstNode]._size_of_tree;
    unsigned sizeTreeSecondNode = this->_nodes[rootSecondNode]._size_of_tree;

    if (rootFirstNode == rootSecondNode) return;

    //Conecta o nó com a menor árvore na maior para evitar árvores longas
    else if (sizeTreeFirstNode < sizeTreeSecondNode) {
        this->_nodes[rootFirstNode]._id_of_node = rootSecondNode;
        this->_nodes[rootSecondNode]._size_of_tree+= sizeTreeFirstNode;
    }

    else {
        this->_nodes[rootSecondNode]._id_of_node = rootFirstNode;
        this->_nodes[rootFirstNode]._size_of_tree+= sizeTreeSecondNode;
    }

    //Cada conexão bem sucedida diminui o número de componentes em um
    this->_number_of_components-= 1;
}


//Retorna o vector de nós para poder dar push_back.
std::vector<Node>& WeightedQuickUnion::getNodes() {
    return this->_nodes;
}