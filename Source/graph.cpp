//
// Created by I. Marinov on 6/3/2020.
//
#include "graph.h"

using namespace std;
Graph::Graph() {
    this->adjMatrix=nullptr;
    this->vertices= nullptr;
    this->keys= nullptr;
}
/**
 * @brief - saves object in the Graph
 * - counts vertices, gets their names, sets their ids
 * - allocates and fills the adjacency matrix
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
    this->extractVertNames(); // get the vertices' names(website names)
    //this->objDebug();
//    for(int i=0;i<this->vertCount;++i)
//        cout<<this->keys[i];
    this->fill_adjMatrix(); // fill the adjancecy matrix of the  graph
}
/**
 * @brief 'deeply' iterate the json object and print all of its keys and values
 */
void Graph::objDebug() {
    enumerate(this->object);
}
void Graph::init(json obj) {
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
    this->extractVertNames(); // get the vertices' names(website names)
    //this->objDebug();
//    for(int i=0;i<this->vertCount;++i)
//        cout<<this->keys[i];
    this->fill_adjMatrix(); // fill the adjancecy matrix of the  graph
}
/**
 * @brief Fills the adjacency matrix of the current graph(inserts the edges extracted from the .json file
 */
void Graph::fill_adjMatrix() {
    int counter;
    unsigned currId = INT16_MAX;
    int i = 0;
    for (auto it = this->object.begin(); it != this->object.end(); it++, ++i) {
        counter = 0;
        if (it->is_object()) {
            while (this->object[it.key()]["thirdParties"][counter].is_string()) {
                string str = this->object[it.key()]["thirdParties"][counter++];
                currId = this->findVertexId(str);
                this->adjMatrix[i * vertCount + currId] = 1;
            }
        }
    }
}
/**
 * @brief Find the id of a vertex with a given name
 * @param name name of the vertex(website)
 * @return id of the vertex with the given name
 */
unsigned Graph::findVertexId(std::string name) {
    for (int i = 0; i < this->vertCount; ++i) {
        if (this->vertices[i].getName() == name)
            return this->vertices[i].getId();
    }
    throw runtime_error("Id wasn't found(findVertexId)");
    //throw "Id wasn't found(findVertexId)";
}
/**
 * @brief extract the website "hostnames" from the json object
 */
void Graph::extractVertNames() {
    this->keys = extractObjectKeys(this->object);
    for (int i = 0; i < this->vertCount; ++i) { // iterate through the vertices and get their names from the object
        vertices[i].setName(this->object[this->keys[i]]["hostname"]);
    }
}
/**
 * @brief Prints the names and ids of all vertices
 */
void Graph::printVertices() {
    for (int i = 0; i < this->vertCount; ++i) {
        vertices[i].print();
    }
}
/**
 * @brief Prints the adjacency matrix of the graph
 */
void Graph::printAdjMatrix() {
    cout << endl << "Adjazentmatrix:" << endl << endl;

    cout << "  ";
    //*************** Columns ******************************
    //this loop only prints the first row of the matrix where the column names/ids are
    for (int x = 0; x < this->vertCount; x++) {
        if (this->vertices[x].getName() == "" || this->vertices->getName().length() > 2) {
            if (x >= 10 && x < 100)
                cout << "  " << x;
            else if (x >= 100 && x < 1000)
                cout << " " << x;
            else
                cout << "   " << x;
        } else
            cout << "   " << this->vertices[x].getName();
    }
    cout << endl;
    // ************ end of column names *******************

    //***************** ROWS ***********************
    for (int i = 0; i < this->vertCount; i++)  //for each vertex
    {
        /*********** line separator ****************/
        cout << "   ";
        for (int m = 0; m < this->vertCount; m++)
        {
            cout << "----";
        }
        cout << endl;
        /************ end of line separator ************/

        /************ row names/ids **************/
        if (this->vertices[i].getName() == "" || this->vertices->getName().length() > 2) {
            if (i >= 10)
                cout << i << "";
            else
                cout << i << " ";
        } else
            cout << this->vertices[i].getName() << " ";
        /*********** end of row names/ids print ***********/

        /*********** print values ***************/
        for (int j = 0; j < this->vertCount; j++) //Spaltentrenner und adjazents zwischen zwei Knoten(1 oder 0)
        {
            cout << " | " << this->adjMatrix[i * vertCount + j];
        }
        cout << endl;
        /**********end of values printing ********/
        /*************end of ROWS ****************/
    }
}
/**
 * @brief Iterates through the graph with a given start vertex and finds all reachable vertices and the distance
 * between them. Algorithm explained in the book  Algorithmen – Eine Einführung
 * @param start Starting vertex
 */
void Graph::BFS(unsigned int start){
    for(int i=0; i<this->vertCount; ++i){
        this->vertices[i].setColor(vertex::WHITE);
        this->vertices[i].setDistance(UNENDING);
        this->vertices[i].setParentId(NIL);
    }
    this->vertices[start].setColor(vertex::GRAY);
    this->vertices[start].setDistance(0);
    this->vertices[start].setParentId(NIL);
    Queue Q;
    Q.enqueue(start);
    unsigned u;
    while(Q.getCurrAmt()!=0){
        u=Q.dequeue();
        for(int i=0;i<this->vertCount;++i){
            if(this->adjMatrix[u*this->vertCount+i]!=1) continue;
            else if(this->vertices[i].getColor()==vertex::WHITE){
                this->vertices[i].setColor(vertex::GRAY);
                this->vertices[i].setDistance(this->vertices[u].getDistance()+1);
                this->vertices[i].setParentId(u);
                Q.enqueue(i);
            }
        }
        this->vertices[u].setColor(vertex::BLACK);
    }
}
/**
 * @brief Finds the *shortest path between two points. Requires a run BFS-algorithm run
 * @param start Starting vertex of the path
 * @param end Ending vertex of the path
 */
void Graph::printPath(unsigned int start, unsigned int end){
    this->BFS(start);
    std::cout<<"Der kuerzeste Weg von Knote "<<start<<" nach Knote "<<end<<" ist folgender: "<<std::endl;
    unsigned save=end;
    unsigned prev;
    while(end!=NIL){
        prev=end;
        if(end!=start)
            std::cout<<end<<", ";
        else std::cout<<end;
        end=this->vertices[end].getParentId();
    }
    if(prev!=start) std::cout<<"Kein Pfad von Knote "<<save<<" nach Knote: "<<start<<std::endl;
    std::cout<<std::endl;
}
void Graph::printPath(std::string start, std::string end) {
    int id_start=this->findVertexId(start);
    int id_end=this->findVertexId(end);
    this->printPath(id_end, id_start);
}
/**
 * @brief Check if the matrix is empty(if all of its pointers equal nullptr
 * @return Evaluates true if all pointers equal nullptr
 */
bool Graph::isEmpty() {
    return this->keys==nullptr && this->vertices== nullptr && this->adjMatrix== nullptr;
}
/**
 * @brief deletes all of the allocated memory
 */
Graph::~Graph() {
    delete[] this->adjMatrix;
    delete[] this->vertices;
    delete[] this->keys;
}
