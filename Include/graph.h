//
// Created by bgbg5 on 6/3/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_GRAPH_H
#define MINIPROJEKT_LIGHTBEAM_GRAPH_H
#include "vertex.h"
#include "cust_json.h"
#include <string>
#include <limits>
class Graph{
public:
    Graph(json obj);
    void ins_json_edges();
    void extractVertNames();
    void fill_adjMatrix();
    void printVertices();
    ~Graph();

protected:
    vertex* vertices;
    unsigned vertCount;
    short* adjMatrix; // since the values will only be 0 and 1
    json object;
//    std::string* keys;
};
#endif //MINIPROJEKT_LIGHTBEAM_GRAPH_H
