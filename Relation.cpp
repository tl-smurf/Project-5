//
// Created by tl_smurf on 5/15/2021.
//

#include "Relation.h"
#include <iostream>

Relation::Relation() {
    name = "null";
}

std::string Relation::getName() {
    return name;
}

Header Relation::getHeader() {
    return header;
}

std::set<Tuple> Relation::getTuples() {
    return tuples;
}

void Relation::addTuple(Tuple tupleIn) {
    tuples.insert(tupleIn);
}

std::string Relation::toString() {
    std::string outputString;
    std::vector<std::string> tempVect = getHeader().attributes;
    for (auto it : tuples) {
        if (tempVect.size() != 0) {
            outputString += "  ";
        }
        for (unsigned int i = 0; i < tempVect.size(); i++) {
            outputString += tempVect.at(i) + "=" + it.values.at(i);
            if (tempVect.size() > 1 && i != tempVect.size() -1) {
                outputString += ", ";
            }
        }
        outputString += "\n";
    }
    //outputString.pop_back();  //UGLY/easy way to get rid of last endline
    return outputString;
}

void Relation::setHeader(Header headerIn) {
    header = headerIn;
}

void Relation::setName(std::string nameIn) {
    name = nameIn;
}

Relation Relation::Select(int index, std::string value) {
    //Select 1
    //std::cout << "I did a Select 1\n";
    Relation relationSelect;
    relationSelect.setName(name);
    relationSelect.setHeader(header);
    for(std::set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); ++it) {
        if((*it).values[index] == value) {
            relationSelect.addTuple(*it);
        }
    }
    return relationSelect;
}

Relation Relation::Select(int index1, int index2) {
    Relation NewRelation, NewRelation1;
    NewRelation.setName(name);
    NewRelation.header = header;
    for (auto i: tuples) {
        if (i.values.at(index1)== i.values.at(index2)) {
            NewRelation.addTuple(i);
        }
    }
    return NewRelation;
}

void Relation::Unionize(Relation r) {
    for (auto t:r.tuples) {
        if (tuples.insert(t).second) {
            std::cout << "  ";
            for (unsigned int i = 0; i < unsigned(t.size()); i++) {
                std::cout << r.getHeader().attributes.at(i);
                if (i != unsigned(t.size() - 1)) {
                    std::cout << "=" << t.getValue(i) << ", ";
                }
                else {
                    std::cout << "=" << t.getValue(i);
                }
            }
            std::cout << "\n";
        }
    }
}

Relation Relation::Project(std::vector<int> indices) {
    Relation relationProject;
    relationProject.setName(name);
    Header tempHead;
    for (unsigned int i = 0; i < indices.size(); i++) {
        tempHead.attributes.push_back(header.attributes.at(indices.at(i)));
    }
    for(std::set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); ++it) {
        Tuple tempTuple;
        for (unsigned int j = 0; j < indices.size(); j++) {
            tempTuple.values.push_back(it->values.at(indices.at(j)));
        }
        relationProject.addTuple(tempTuple);
    }
    relationProject.setHeader(tempHead);
    return relationProject;
}

Relation Relation::Rename(std::vector<std::string> stringsIn) {
    Relation relationRename;
    relationRename.setName(name);
    Header tempHead;
    tempHead.attributes = stringsIn;
    relationRename.setHeader(tempHead);
    for (auto it: tuples) {
        relationRename.addTuple(it);
    }
    return relationRename;
}

int Relation::getSize() {
    return tuples.size();
}

void Relation::addTuples(Relation tuplesIn) {
    for (std::set<Tuple>::iterator it = tuplesIn.tuples.begin(); it != tuplesIn.tuples.end(); it++) {
        addTuple(*it);
    }
}


