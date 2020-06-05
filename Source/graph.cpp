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
    this->object = obj; // copy the given object
    vertCount = Count_Objects(this->object); // get vertices count
    vertices = new vertex[vertCount]; // allocate memory for the vertices read
    for (int i = 0; i < this->vertCount; ++i) {
        vertices[i].setId(i); // give incrementing ids to all vertices
    }

    adjMatrix = new short[vertCount * vertCount]; // allocate memory for the
    for (int i = 0; i < this->vertCount * this->vertCount; ++i) {
        //adjMatrix[i] = INT16_MAX; // fill the matrix with 'infinity' numbers
        adjMatrix[i] = 0; // fill the matrix with zeros
    }
    cout<<"debug1";
    this->extractVertNames();
    cout<<"debug2";
    this->objDebug();
//    for(int i=0;i<this->vertCount;++i)
//        cout<<this->keys[i];
    this->fill_adjMatrix();
    cout<<"debug3";
}
void Graph::objDebug() {
    enumerate(this->object);
}
void Graph::fill_adjMatrix() {
    int counter;
    unsigned currId = INT16_MAX;
    int i=0;
    cout<<this->findVertexId("fonts.googleapis.com");
    for(auto it=this->object.begin(); it!=this->object.end();it++,++i){
        counter=0;
        if (it->is_object()) {
            while (this->object[it.key()]["thirdParties"][counter].is_string()) {
                string str = this->object[it.key()]["thirdParties"][counter++];
                currId = this->findVertexId(str);
                this->adjMatrix[i * vertCount + currId] = 1;
            }
        }
    }
}

unsigned Graph::findVertexId(std::string name) {
    for (int i = 0; i < this->vertCount; ++i) {
        if (this->vertices[i].getName() == name)
            return this->vertices[i].getId();
    }
    throw runtime_error("Id wasn't found(findVertexId)");
}

void Graph::extractVertNames() {
    this->keys = extractObjectKeys(this->object);
    for (int i = 0; i < this->vertCount; ++i) { // iterate through the vertices and get their names from the object
        vertices[i].setName(this->object[this->keys[i]]["hostname"]);
    }
}

void Graph::printVertices() {
    for (int i = 0; i < this->vertCount; ++i) {
        vertices[i].print();
    }
}

void Graph::debug() {
    cout << endl << "Adjazentmatrix:" << endl << endl;

    cout << "  ";
    //Spaltennamen
    for (int x = 0; x < this->vertCount; x++) {
        if (this->vertices[x].getName() == "") {
            cout << "   " << x;
        } else
            cout << "   " << this->vertices[x].getName();
    }
    cout << endl;

    for (int i = 0; i < this->vertCount; i++)  //Für jeden Knoten
    {
        cout << "   ";
        for (int m = 0; m < this->vertCount; m++)  //Zeilentrenner
        {
            cout << "----";
        }
        cout << endl;
        //Zeilennamen
        if (this->vertices[i].getName()=="") {
            cout << i << " ";
        } else
            cout << this->vertices[i].getName() << " ";

        for (int j = 0; j < this->vertCount; j++) //Spaltentrenner und adjazents zwischen zwei Knoten(1 oder 0)
        {
            cout << " | " << this->adjMatrix[i*vertCount+j];
        }
        cout << endl;
    }
}

Graph::~Graph() {
    delete[] this->adjMatrix;
    delete[] this->vertices;
    delete[] this->keys;
}
