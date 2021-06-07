//
// Created by tl_smurf on 5/15/2021.
//

#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H
#include <vector>
#include <string>

class Header {
private:

public:
    Header();
    void setAttributes(std::vector<std::string> vectorIn);
    std::string getString(int index);
    std::vector<std::string> attributes;
};


#endif //PROJECT_3_HEADER_H
