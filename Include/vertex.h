//
// Created by bgbg5 on 6/2/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_VERTEX_H
#define MINIPROJEKT_LIGHTBEAM_VERTEX_H

#include <string>
#include <iostream>
class vertex{
public:
    bool is_thirdParty();
    bool is_firstParty();
    void setId(unsigned id);
    unsigned getId();
    void setName(std::string name);
    std::string getName();
    void print();
private:
    unsigned vertId;
    std::string name;
    bool firstParty;
};
#endif //MINIPROJEKT_LIGHTBEAM_VERTEX_H
