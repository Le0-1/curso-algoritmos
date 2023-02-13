#ifndef WEIGHTED_QUICK_UNION_H
#define WEIGHTED_QUICK_UNION_H

#include <vector>

struct Node {
    unsigned _id_of_node;
    unsigned _size_of_tree;
};

class WeightedQuickUnion {
    private:    
        std::vector<Node> _nodes;
        unsigned _number_of_components;

    public:

        //Cria os nós responsáveis pelo representação do grid da classe Percolation
        WeightedQuickUnion(unsigned numberOfNodes);

        ~WeightedQuickUnion() { };

        //Conecta dois nós
        void connectNodes(Node& firstNode, Node& secondNode);

        //Retorna se dois nós estão conectados
        bool isConnected(Node& firstNode, Node& secondNode);

        //Retorna a raiz de um nó
        unsigned findRoot(Node& Node);

        unsigned getComponents();

        //Retorna por referência para poder dar push back nos nós na classe Percolation
        std::vector<Node>& getNodes();
};

#endif