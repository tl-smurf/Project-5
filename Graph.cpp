//
// Created by tl_smurf on 6/7/2021.
//

#include "Graph.h"

std::string Graph::toString() {
    std::string output;
    for (auto it : nodes) {
        output += it.second.toString() + "\n";
    }
    return output;
}

std::vector<Node> Graph::getMaloneOrder() {


    return std::vector<Node>();
}

std::vector<Node> Graph::cantSeeForest4TheTrees(Node &nodeIn) {


    return std::vector<Node>();
}
