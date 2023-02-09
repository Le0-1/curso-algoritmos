#ifndef WEIGHTED_QUICK_UNION_H
#define WEIGHTED_QUICK_UNION_H

#include <vector>



class WeightedQuickUnion {
    public:    
        struct Node {
            unsigned _id_of_node;
            unsigned _size_of_tree;
        };

        std::vector<Node> _node;

        unsigned _number_of_components;

    public:
        WeightedQuickUnion(unsigned numberOfNodes);

        void connectNodes(Node& firstNode, Node& secondNode);

        bool isConnected(Node& firstNode, Node& secondNode);

        unsigned findRoot(Node& Node);

        unsigned getComponents();
};




#endif