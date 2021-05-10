//
// Created by I. Marinov on 6/3/2020.
//
#include "vertex.h"
vertex::vertex() {
    this->color=vertex::WHITE;
    this->distance=UNENDING;
    this->parentId=NIL;
}
bool vertex::is_firstParty() {
    return this->firstParty;
}

/**
 * @brief setId sets the id of the vertex
 * @param id -
 */
void vertex::setId(unsigned int id) {
    this->vertId = id;
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
    this->name = name;
}

/**
 * @brief getName returns the name of the vertex
 * @return name of the vertex
 */
std::string vertex::getName() {
    return this->name;
}

void vertex::print() {
    std::cout << "Vertex name: " << this->name << std::endl
              << "Vertex id: " << this->vertId << std::endl;
              //<< "First party: " << this->firstParty << std::endl;
}

vertex &vertex::operator=(const vertex &vertex) {
    if (this != &vertex) {
        this->name = vertex.name;
        this->vertId = vertex.vertId;
        this->firstParty = vertex.firstParty;
    }
    return *this;
}
void vertex::setColor(enum color color) {
    this->color=color;
}
void vertex::setDistance(unsigned int distance) {
    this->distance=distance;
}
unsigned vertex::getDistance() {
    return this->distance;
}
void vertex::setParentId(unsigned int parentId) {
    this->parentId=parentId;
}
enum vertex::color vertex::getColor() {
    return this->color;
}
unsigned int vertex::getParentId() {
    return this->parentId;
}
