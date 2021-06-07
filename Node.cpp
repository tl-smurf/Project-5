//
// Created by tl_smurf on 6/7/2021.
//

#include "Node.h"



std::string Node::toString() {
    std::string output;
    output += "R" + std::to_string(name) + ":";
    for (unsigned int i = 0; i < nodesNextDoor.size(); i++) {
        if (i > 0) {
            output += ",";
        }
        output += "R" + std::to_string(nodesNextDoor.at(i));
    }
    return output;
}

bool Node::isCyclic() {
    for (unsigned int i = 0; i < nodesNextDoor.size(); i++) {
        if (nodesNextDoor.at(i) == name) {
            return true;
        }
    }
    return false;

}
