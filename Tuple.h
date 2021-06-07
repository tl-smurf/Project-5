//
// Created by tl_smurf on 5/15/2021.
//

#ifndef PROJECT_3_TUPLE_H
#define PROJECT_3_TUPLE_H
#include <vector>
#include <string>

class Tuple {
private:
public:
    std::string getValue(int index);
    std::vector<std::string> values;
    std::string toString();
    void addValue(std::string valueIn);
    int size();
    bool operator< (const Tuple & other) const {
        return values < other.values;
    }

};


#endif //PROJECT_3_TUPLE_H
