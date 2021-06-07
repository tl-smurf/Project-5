//
// Created by tl_smurf on 5/15/2021.
//
#include "Relation.h"

#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H
#include <map>
#include <iostream>
#include <string>

class Database {
private:

public:
    Database(){}
    void toString();
    int getSize();
    void addTuple(std::string nameIn, Tuple tupleIn);
    void addRelation(std::string stringIn, Relation relationIn);
    std::map<std::string, Relation> relations;

    bool tupleChecker(Relation relIn, Database dbIn);
};


#endif //PROJECT_3_DATABASE_H
