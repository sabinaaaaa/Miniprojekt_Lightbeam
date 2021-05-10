//
// Created by I. Marinov on 6/3/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_GRAPH_H
#define MINIPROJEKT_LIGHTBEAM_GRAPH_H

#include "vertex.h"
#include "Queue.h"
#include "cust_json.h"
#include <string>
#include <limits>

class Graph {
public:
    Graph();

    Graph(json obj); //
    void init(json obj); // init from an json object
    void ins_json_edges();

    void extractVertNames();

    void fill_adjMatrix();

    unsigned findVertexId(std::string name);

    void printVertices();

    void printAdjMatrix();

    void objDebug();

    void BFS(unsigned start);

    void printPath(unsigned start, unsigned end);

    void printPath(std::string start, std::string end);

    bool isEmpty();

    ~Graph();

protected:
    vertex *vertices;
    unsigned vertCount;
    short *adjMatrix; // since the values will only be 0 and 1
    json object;
    std::string *keys;
};

#endif //MINIPROJEKT_LIGHTBEAM_GRAPH_H
