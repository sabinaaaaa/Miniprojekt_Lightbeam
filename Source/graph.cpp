//
// Created by bgbg5 on 6/3/2020.
//
#include "graph.h"
using namespace std;
/**
 * @brief - saves object in the Graph
 * - counts vertices, gets their names, sets their ids
 * - allocates the adjacency matrix
 *
 * @param obj a json object that contains the vertices from a lightbeam .json file
 */
Graph::Graph(json obj) {
    this->object=obj; // copy the given object
    vertCount=Count_Objects(this->object); // get vertices count
    vertices=new vertex[vertCount]; // allocate memory for the vertices read
    for(int i=0; i<this->vertCount; ++i){
        vertices[i].setId(i); // give incrementing ids to all vertices
    }

    adjMatrix=new short[vertCount*vertCount]; // allocate memory for the
    for(int i=0; i<this->vertCount * this->vertCount;++i) {
        adjMatrix[i] = INT16_MAX; // fill the matrix with 'infinity' numbers
    }
    this->extractVertNames();
}
void Graph::extractVertNames() {
    string* keys=extractObjectKeys(this->object);
    for(int i=0;i<this->vertCount;++i){ // iterate through the vertices and get their names from the object
        vertices[i].setName(this->object[keys[i]]["hostname"]);
    }
}
void Graph::printVertices() {
    for(int i=0; i<this->vertCount; ++i){
        vertices[i].print();
    }
}
Graph::~Graph() {
    delete [] this->adjMatrix;
    delete [] this->vertices;
}
