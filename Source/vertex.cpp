//
// Created by bgbg5 on 6/3/2020.
//
#include "vertex.h"

bool vertex::is_firstParty() {
    return this->firstParty;
}
/**
 * @brief setId sets the id of the vertex
 * @param id -
 */
void vertex::setId(unsigned int id) {
    this->vertId=id;
}
/**
 * @brief
 * @return
 */
unsigned vertex::getId() {
    return vertId;
}
/**
 * @brief setName gives a vertex its name
 * @param name is the name that the vertex will be given
 */
void vertex::setName(std::string name) {
    this->name=name;
}
/**
 * @brief getName returns the name of the vertex
 * @return name of the vertex
 */
std::string vertex::getName() {
    return this->name;
}
void vertex::print() {
    std::cout<<"Vertex name: "<<this->name<<std::endl
    <<"Vertex id: "<<this->vertId<<std::endl
    <<"First party: "<<this->firstParty<<std::endl;
}