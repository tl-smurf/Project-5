//
// Created by tl_smurf on 6/7/2021.
//

#ifndef PROJECT_5_NODE_H
#define PROJECT_5_NODE_H
#include "vector"
#include <string>

class Node {
private:

public:
    Node(){hasBeenVisited = false; postOrderOrder = -1;}
    ~Node(){}

    //Variables
    int name;
    std::vector<int> nodesNextDoor;
    bool hasBeenVisited;
    int postOrderOrder;

    //Functions?
    std::string toString();
    bool isCyclic();
    bool operator<(const Node& x) const
    {
        if(name < x.name)
            return true;
        else
            return false;
    }
    bool operator==(const Node& x)
    {
        if(name == x.name)
            return true;
        else
            return false;
    }

};


#endif //PROJECT_5_NODE_H
