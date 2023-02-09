#include "WeightedQuickUnion.hpp"

#include <iostream>

WeightedQuickUnion::WeightedQuickUnion(unsigned numberOfNodes) {
    this->_node.reserve(numberOfNodes);

    for (unsigned i = 0; i < numberOfNodes; i++) {
        this->_node[i]._id_of_node = i;
        this->_node[i]._size_of_tree = 1;
    }
    this->_number_of_components = numberOfNodes;
}

unsigned WeightedQuickUnion::getComponents() {
    return this->_number_of_components;
}

unsigned WeightedQuickUnion::findRoot(Node& Node) {
    unsigned id = Node._id_of_node;

    while (id != Node._id_of_node) {
        id = Node._id_of_node;
    }

    return id;
}

bool WeightedQuickUnion::isConnected(Node& firstNode, Node& secondNode) {
    if (this->findRoot(firstNode) == this->findRoot(secondNode)) {
        return 1;
    }

    else return 0;
}

void WeightedQuickUnion::connectNodes(Node& firstNode, Node& secondNode) {
    unsigned rootFirstNode = this->findRoot(firstNode);
    unsigned rootSecondNode = this->findRoot(secondNode);

    unsigned sizeTreeFirstNode = this->_node[rootFirstNode]._size_of_tree;
    unsigned sizeTreeSecondNode = this->_node[rootSecondNode]._size_of_tree;

    if (rootFirstNode == rootSecondNode) return;

    else if (sizeTreeFirstNode < sizeTreeSecondNode) {
        this->_node[rootFirstNode]._id_of_node = rootSecondNode;
        this->_node[rootSecondNode]._size_of_tree+= sizeTreeFirstNode;
        this->_number_of_components-= sizeTreeFirstNode;
    }

    else {
        this->_node[rootSecondNode]._id_of_node = rootFirstNode;
        this->_node[rootFirstNode]._size_of_tree+= sizeTreeSecondNode;
        this->_number_of_components-= sizeTreeSecondNode;
    }
}