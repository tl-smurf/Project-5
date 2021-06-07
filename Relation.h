//
// Created by tl_smurf on 5/15/2021.
//

#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H
#include <string>
#include <set>
#include <list>
#include "Tuple.h"
#include "Header.h"
#include "list"


class Relation {
private:

public:
    //Variables
    std::string name;
    Header header;
    std::set<Tuple> tuples;

    Relation();
    void setName(std::string nameIn);
    std::string getName();
    Header getHeader();
    std::set<Tuple> getTuples();
    void addTuple(Tuple tupleIn);
    void addTuples(Relation tuplesIn);
    std::string toString();
    void setHeader(Header headerIn);
    int getSize();
    Relation Select(int index, std::string value);
    Relation Select(int index1, int index2);
    Relation Project(std::vector<int> indices);
    Relation Rename(std::vector<std::string>);  //This might need to take in a Header class object not a list. We'll see


    void Unionize(Relation r);
};


#endif //PROJECT_3_RELATION_H
