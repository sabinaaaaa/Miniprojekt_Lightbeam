//
// Created by bgbg5 on 6/2/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_VERTEX_H
#define MINIPROJEKT_LIGHTBEAM_VERTEX_H

#include <string>
#include <iostream>
#include <climits>
#define UNENDING UINT16_MAX
#define NIL -1
class vertex{
public:
    vertex();
    enum color{WHITE, GRAY, BLACK};
    bool is_thirdParty();
    bool is_firstParty();
    void setId(unsigned id);
    unsigned getId();
    void setName(std::string name);
    std::string getName();
    void print();
    vertex &operator=(const vertex &vertex);
    void setColor(color color);
    color getColor();
    void setDistance(unsigned distance);
    unsigned getDistance();
    void setParentId(unsigned parentId);
    unsigned getParentId();
private:
    color color;
    unsigned distance;
    unsigned parentId;
    unsigned vertId;
    std::string name;
    bool firstParty;
};
#endif //MINIPROJEKT_LIGHTBEAM_VERTEX_H
