//
// Created by tl_smurf on 5/15/2021.
//

#include "Database.h"

void Database::addRelation(std::string stringIn, Relation relationIn) {
    relations.insert({stringIn, relationIn});
}

bool Database::tupleChecker(Relation relIn, Database dbIn) {
    if (dbIn.relations.find(std::string(relIn.getName())) == dbIn.relations.end()) {
        return false;
    }
    else {
        for (std::set<Tuple>::iterator it = relIn.tuples.begin(); it != relIn.tuples.end(); it++) {
            if (dbIn.relations[relIn.getName()].getSize() != relIn.getSize()) {
                return false;
            }
        }
        return true;
    }
}

void Database::addTuple(std::string nameIn, Tuple tupleIn) {
    relations.at(nameIn).addTuple(tupleIn);
}

void Database::toString() {
    std::string outputString;
    for(auto i: relations) {
        outputString = i.first + ": \n" + i.second.toString();
    }
    std::cout << outputString;
}

int Database::getSize() {
    int size = 0;
    for(std::map<std::string, Relation>::iterator it = relations.begin(); it != relations.end(); ++it) {
        size += it->second.getSize();
    }
    return size;
}
