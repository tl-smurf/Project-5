//
// Created by tl_smurf on 6/7/2021.
//

#ifndef PROJECT_5_NODE_H
#define PROJECT_5_NODE_H
#include "vector"

class Node {
private:

public:
    Node(){hasBeenVisited = false; postOrderOrder = -1}
    ~Node(){}
    //Variables
    int name;
    std::vector<int> nodesNextDoor;
    bool hasBeenVisited;
    int postOrderOrder;
    std::string toString();
    //Functions?

};


#endif //PROJECT_5_NODE_H
