//
// Created by tl_smurf on 5/15/2021.
//

#include "Interpreter.h"
#include "Graph.h"
#include <algorithm>

Interpreter::Interpreter() {
}

std::vector<std::string> Interpreter::makeAttList(Predicate predicateIn) {
    std::vector<std::string> outputVect;
    for (unsigned int i = 0; i < predicateIn.getParameters().size(); i++) {
        if (predicateIn.getParameters().at(i).getType() == "ID") {
            outputVect.push_back(predicateIn.getParameters().at(i).toString());
        }
    }
    return outputVect;
}

std::vector<std::string> Interpreter::makeFactVector(Predicate predicateIn) {
    std::vector<std::string> outputVect;
    for (unsigned int i = 0; i < predicateIn.getParameters().size(); i++) {
        if (predicateIn.getParameters().at(i).getType() == "STRING") {
            outputVect.push_back(predicateIn.getParameters().at(i).toString());
        }
    }
    return outputVect;
}

void Interpreter::Start(Parser parserIn) {

    schemesList = parserIn.schemesList;
    factsList = parserIn.factsList;
    rulesList = parserIn.rulesList;
    queryList = parserIn.queryList;
    schemify();
    factify();
    processDemRules();
    queryify();
}

void Interpreter::schemify() {
    for (unsigned int i = 0; i < schemesList.size(); i++) {
        Relation newRelation;
        newRelation.setName(schemesList.at(i).getName());
        Header newHeader;
        std::vector<std::string> tempVect = makeAttList(schemesList.at(i));
        newHeader.setAttributes(tempVect);
        newRelation.setHeader(newHeader);
        db.addRelation(newRelation.getName(), newRelation);
    }
}

void Interpreter::factify() {
    for (unsigned int i = 0; i < factsList.size(); i++) {
        Tuple tempTuple;
        std::string tempName = factsList.at(i).getName();
        for (unsigned int j = 0; j < makeFactVector(factsList.at(i)).size(); j++) {
            tempTuple.values.push_back(makeFactVector(factsList.at(i)).at(j));
        }
        db.addTuple(tempName, tempTuple);
    }
}

void Interpreter::queryify() {
    std::cout << "Query Evaluation\n";
    for (unsigned int i = 0; i < queryList.size(); i++) {
        Relation tempRelation;
        tempRelation = evaluatePredicate(queryList.at(i));
        std::cout << queryList.at(i).toString() << "?"; //I took the two spaces out of predicate, that might have been a bad idea. IDK
        if (tempRelation.tuples.size() == 0) {
            std::cout << " No\n";
        }
        else {
            std::cout << " Yes(" << tempRelation.tuples.size() <<")\n";
            std::vector<Parameter> temParam = queryList.at(i).getParameters();
            bool hasVariable = false;
            for (unsigned int i = 0; i < temParam.size(); i++) {
                if (temParam.at(i).getType() == "ID") {
                    hasVariable = true;
                }
            }
            //if there >= 1 variable in query, print out results
            if (hasVariable) {
                std::cout << tempRelation.toString();
            }
            else {
                //if there aren't any variable in query, don't print anything
            }

        }


    }

}

Relation Interpreter::evaluatePredicate(Predicate P) {
    std::string name = P.getName();
    std::vector<std::string> stringsToSave;
    std::vector<int> intsToSave;
    Relation myRelation = db.relations.at(name);
        for (unsigned int i = 0; i < P.getParameters().size(); i++) {
            if (P.getParameters().at(i).isConstant()) {
                std::string tempString = P.getParameters().at(i).toString();
                myRelation = myRelation.Select(i,tempString); //Select type 1
            }
            else {
                bool isItDuplicate = false;
                for (unsigned int j = 0; j < stringsToSave.size(); j++) {
                    if (stringsToSave.at(j) == P.getParameters().at(i).toString()) {
                        isItDuplicate = true;
                        myRelation = myRelation.Select(i,intsToSave.at(j)); //Select type 2
                        break;
                    }
                }
                if (!isItDuplicate) {
                    stringsToSave.push_back(P.getParameters().at(i).toString());
                    intsToSave.push_back(i);
                }
            }

        }
    Relation newRelationPLEASE = myRelation;
    if (!intsToSave.empty()) {
        newRelationPLEASE = myRelation.Project(intsToSave);
    }
    if (!stringsToSave.empty()) {
        newRelationPLEASE = newRelationPLEASE.Rename(stringsToSave);
    }
    return newRelationPLEASE;
}

void Interpreter::toString() {
    db.toString();
}

Graph Interpreter::makeGraph() {
    Graph graphyGraph;

    for (unsigned int i = 0; i < rulesList.size(); i++) {
        Rule tempRule = rulesList.at(i);

        Node tempNode;
        tempNode.name = i;
        for (unsigned int j = 0; j < tempRule.getPredicateList().size(); j++) {
            Predicate currPred = tempRule.getPredicateList().at(j);

            for (unsigned int k = 0; k < rulesList.size(); k++) {
                if (currPred.getName() == rulesList[k].getHeadlol().getName()) {
                    tempNode.nodesNextDoor.push_back(k);
                }
            }
        }
        sort(tempNode.nodesNextDoor.begin(), tempNode.nodesNextDoor.end());
        tempNode.nodesNextDoor.erase(unique(tempNode.nodesNextDoor.begin(), tempNode.nodesNextDoor.end()), tempNode.nodesNextDoor.end());
        graphyGraph.nodes.insert(std::pair<int, Node>(i, tempNode));
    }
    return graphyGraph;
}

Graph Interpreter::revGraph() {
    Graph graphyGraph;

    for (unsigned int i = 0; i < rulesList.size(); i++) {
        Rule tempRule = rulesList.at(i);
        Node tempNode;
        tempNode.name = i;
        for (unsigned int j = 0; j < rulesList.size(); j++) {
            for (unsigned int k = 0; k < rulesList.at(j).getPredicateList().size(); k++) {
                if (rulesList[j].getPredicateList().at(k).getName() == tempRule.getHeadlol().getName()) {
                    tempNode.nodesNextDoor.push_back(j);
                }
            }
        }
        sort(tempNode.nodesNextDoor.begin(), tempNode.nodesNextDoor.end());
        tempNode.nodesNextDoor.erase(unique(tempNode.nodesNextDoor.begin(), tempNode.nodesNextDoor.end()), tempNode.nodesNextDoor.end());
        graphyGraph.nodes.insert(std::pair<int, Node>(i, tempNode));
    }
    return graphyGraph;
}

void Interpreter::processDemRules() {
    regGraph = makeGraph();
    reverseGraph = revGraph();
    std::vector<Node> posty = reverseGraph.getMaloneOrder();

    std::cout << "Dependency Graph\n" + regGraph.toString();

    while(!posty.empty()) {
        int size = posty.size() - 1;
        if (!regGraph.nodes[posty[size].name].hasBeenVisited) {
            std::vector<Node> tempNode = regGraph.depthDoesntMatter(regGraph.nodes[posty[size].name]);
            sort(tempNode.begin(), tempNode.end());
            tempNode.erase(unique(tempNode.begin(), tempNode.end()), tempNode.end());
            sccs.push_back(tempNode);
        }
        posty.pop_back();
    }

    std::cout << "\nRule Evaluation\n";
    //doesn't work when it depends on another rule????
    for (unsigned int i = 0; i < sccs.size(); i++) {
        int numPasses = 1;
        std::vector<int> YaOutputeado;
        std::cout << "SCC: ";
        std::string fixerupper;
        fixerupper = "R" + std::to_string(sccs[i][0].name);
        YaOutputeado.push_back(sccs[i][0].name);
        for (unsigned int q = 0; q < sccs[i].size(); q++) {
            //Something that checks if the rule has already been run, and if so, only prints new rules.
            if (i >= unsigned(sccs[i][q].name)) {
                //The rule has been seen.
            }
            else {
                bool alreadyDone = false;
                for (unsigned int r = 0; r < YaOutputeado.size(); r++) {
                    if (YaOutputeado.at(r) == sccs[i][q].name) {
                        alreadyDone = true;
                        break;
                    }
                }
                if (!alreadyDone) {
                    fixerupper +=  ",R";
                    fixerupper += std::to_string(sccs[i][q].name);
                    YaOutputeado.push_back(sccs[i][q].name);
                }
            }
        }
        std::cout << fixerupper << "\n";
        int sizeBefore = 0;
        int sizeAfter = 0;
        if(sccs[i].size() == 1 && !sccs[i][0].isCyclic()) {
            Predicate headPred = rulesList[sccs.at(i)[0].name].getHeadlol();
            std::vector<Predicate> predList = rulesList[sccs.at(i)[0].name].getPredicateList();
            Relation afterPreds;
            afterPreds = evaluatePredicate(predList[0]);
            for(unsigned int j = 1; j < predList.size(); j++) {
                afterPreds = Join(afterPreds, evaluatePredicate(predList[j]));
            }
            std::vector<int> intdexes;
            for (unsigned int i = 0; i < headPred.getParameters().size(); i++) {
                for (unsigned int j = 0; j < afterPreds.getHeader().attributes.size(); j++) {
                    if (headPred.getParameters().at(i).toString() == afterPreds.getHeader().attributes.at(j)) {
                        intdexes.push_back(j);
                    }
                }
            }
            afterPreds = afterPreds.Project(intdexes);
            afterPreds = afterPreds.Rename(db.relations[headPred.getName()].getHeader().attributes);
            std::cout << rulesList[sccs.at(i)[0].name].toString();
            db.relations[headPred.getName()].Unionize(afterPreds);
            std::cout << "1 passes: " << fixerupper << "\n";
        }
        else {
            do
            {
                sizeBefore = db.getSize();
                for(unsigned int j = 0; j < sccs.at(i).size(); j++) {
                    std::vector<int> toBeOutputted;
                    toBeOutputted.push_back(sccs.at(i)[j].name);
                    Predicate headPred = rulesList[sccs.at(i)[j].name].getHeadlol();
                    std::vector<Predicate> predList = rulesList[sccs.at(i)[j].name].getPredicateList();
                    Relation afterPreds;
                    afterPreds = evaluatePredicate(predList[0]);
                    for(unsigned int k = 1; k < predList.size(); k++) {
                        afterPreds = Join(afterPreds, evaluatePredicate(predList[k]));
                    }
                    std::vector<int> intdexes;
                    for (unsigned int i = 0; i < headPred.getParameters().size(); i++) {
                        for (unsigned int j = 0; j < afterPreds.getHeader().attributes.size(); j++) {
                            if (headPred.getParameters().at(i).toString() == afterPreds.getHeader().attributes.at(j)) {
                                intdexes.push_back(j);
                            }
                        }
                    }
                    afterPreds = afterPreds.Project(intdexes);
                    afterPreds = afterPreds.Rename(db.relations[headPred.getName()].getHeader().attributes);
                    /*
                    std::string fixeruupertwo;
                    fixeruupertwo = "R" + std::to_string(sccs[i][0].name);
                    std::sort(toBeOutputted.begin(), toBeOutputted.end());
                    for (unsigned int z = 0; z < toBeOutputted.size(); z++) {
                        fixeruupertwo += ",R" + std::to_string(toBeOutputted.at(z));
                    }
                    std::cout << fixeruupertwo << "\n";
                    */
                    std::cout << rulesList[sccs.at(i)[j].name].toString();
                    db.relations[headPred.getName()].Unionize(afterPreds); //tuples are printed here
                }
                sizeAfter = db.getSize();
                numPasses++;
            } while(sizeBefore != sizeAfter);
            numPasses--;
            std::cout << std::to_string(numPasses) << " passes: " << fixerupper;
            /*for (unsigned int j = 0; j < sccs[i].size(); j++) {
                std::cout << ",R" << sccs[i][j].name;
            }*/
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

Header Interpreter::combineHeaders(Header one, Header two) {
    matchList.clear();
    for (unsigned int i = 0; i < two.attributes.size(); i++) {
        bool yaExiste = false;
        for (unsigned int j = 0; j < one.attributes.size(); j++) {
            if (two.attributes[i] == one.attributes[j]) {
                yaExiste = true;
                matchList.push_back(std::make_pair<int,int> (j,i));
            }
        }
        if (!yaExiste) {
            one.attributes.push_back(two.attributes[i]);
        }
    }
    return one;
}

Tuple Interpreter::combineTuples(Tuple tOne, Tuple tTwo, int lengthIn) {
    for (unsigned int i = 0; i < unsigned(tTwo.size()); i++) {
        bool yaExiste = false;
        for (unsigned int j = 0; j < matchList.size(); j++) {
            if (unsigned(matchList.at(j).second) == i) {
                yaExiste = true;
            }
        }
        if (!yaExiste) {
            tOne.values.push_back(tTwo.values[i]);
        }
    }
    return tOne;
}

Relation Interpreter::Join(Relation one, Relation two) {
    Relation resultingRelation;
    //Predicate joinProject;
    Header resultingHeader = combineHeaders(one.getHeader(), two.getHeader());
    resultingRelation.setHeader(resultingHeader);
    int length = int(resultingHeader.attributes.size());

    for (std::set<Tuple>::iterator it = one.tuples.begin(); it != one.tuples.end(); ++it) {
        for (std::set<Tuple>::iterator jt = two.tuples.begin(); jt != two.tuples.end(); ++jt) {
            if (isJoinable(*it, *jt, one.getHeader().attributes,two.getHeader().attributes)) {
                resultingRelation.addTuple(combineTuples((*it), (*jt), length));
            }
        }
    }
    return resultingRelation;
}

bool Interpreter::isJoinable(Tuple one, Tuple two, std::vector<std::string> paramOne, std::vector<std::string> paramTwo) {
    for (unsigned int i = 0; i < matchList.size(); i++) {
        if (one.getValue(matchList.at(i).first) != two.getValue(matchList.at(i).second)) {
            return false;
        }
    }
    return true;
}
