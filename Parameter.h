//
// Created by tl_smurf on 5/10/2021.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H
#include <string>
#include <vector>

class Parameter {
private:

    std::string type;
    std::string value;
public:
    bool constant;
    Parameter();
    ~Parameter(){};
    std::string toString();
    Parameter(std::string tokentype, std::string val);
    std::string getType();

    bool isConstant();
};


#endif //PROJECT_2_PARAMETER_H
