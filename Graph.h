//
// Created by tl_smurf on 6/7/2021.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H
#include "Node.h"
#include <map>


class Graph {
private:

public:
    Graph(){}
    ~Graph(){}
    //Variables
    std::map<int,Node> nodes;

    //Functions
    std::string toString();
    std::vector<Node> getMaloneOrder();
    std::vector<Node> cantSeeForest4TheTrees(Node& nodeIn);

};


#endif //PROJECT_5_GRAPH_H
