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
    std::vector<Node> nodesToReturn;
    for (auto it : nodes) {
        if (!it.second.hasBeenVisited) {
            std::vector<Node> temp = depthDoesntMatter(it.second);
            nodesToReturn.insert(nodesToReturn.end(), temp.begin(), temp.end());
        }
    }
    return nodesToReturn;
}

std::vector<Node> Graph::depthDoesntMatter(Node &nodeIn) {
    std::vector<Node> nodesToReturn;
    nodeIn.hasBeenVisited = true;
    for (unsigned int i = 0; i < nodeIn.nodesNextDoor.size(); i++) {
        if (!nodes[nodeIn.nodesNextDoor[i]].hasBeenVisited) {
            std::vector<Node> temp = depthDoesntMatter(nodes[nodeIn.nodesNextDoor[i]]);
            nodesToReturn.insert(nodesToReturn.end(), temp.begin(), temp.end());
        }
    }
    nodesToReturn.push_back(nodeIn);
    return nodesToReturn;
}
