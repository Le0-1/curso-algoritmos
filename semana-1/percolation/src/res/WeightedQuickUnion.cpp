#include "WeightedQuickUnion.hpp"

#include <iostream>

WeightedQuickUnion::WeightedQuickUnion(unsigned numberOfNodes) {
    // this->_nodes.reserve(numberOfNodes);

    for (unsigned i = 0; i < numberOfNodes; i++) {
        Node new_node;
        new_node._id_of_node = i;
        new_node._size_of_tree = 1;
        this->_nodes.push_back(new_node);
    }

    this->_number_of_components = numberOfNodes + 2; // virtal bottom and top nodes
}

unsigned WeightedQuickUnion::getComponents() {
    return this->_number_of_components;
}

unsigned WeightedQuickUnion::findRoot(Node& Node) {
    unsigned id = Node._id_of_node;

    while (id != Node._id_of_node) {
        id = this->_nodes[Node._id_of_node]._id_of_node; //path compression
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

    unsigned sizeTreeFirstNode = this->_nodes[rootFirstNode]._size_of_tree;
    unsigned sizeTreeSecondNode = this->_nodes[rootSecondNode]._size_of_tree;

    if (rootFirstNode == rootSecondNode) return;

    else if (sizeTreeFirstNode < sizeTreeSecondNode) {
        this->_nodes[rootFirstNode]._id_of_node = rootSecondNode;
        this->_nodes[rootSecondNode]._size_of_tree+= sizeTreeFirstNode;
    }

    else {
        this->_nodes[rootSecondNode]._id_of_node = rootFirstNode;
        this->_nodes[rootFirstNode]._size_of_tree+= sizeTreeSecondNode;
    }

    this->_number_of_components-= 1;
}

std::vector<Node>& WeightedQuickUnion::getNodes() {
    return this->_nodes;
}