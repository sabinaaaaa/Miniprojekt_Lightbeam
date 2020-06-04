#include <iostream>
#include "json.hpp"
#include <fstream>
#include "cust_json.h"
#include "graph.h"
using json=nlohmann::json;
using namespace std;
#define PERSON 1
/* 1- Ivaylo
 * 2- Sabina
 * 3- Matviy
 */
int main() {
    json lightbeam;
    ifstream lightb;
    if(PERSON==2)
    lightb.open(R"(C:\Users\Sabina\CLionProjects\Miniprojekt_Lightbeam\Json files\lightbeamData.json)", ifstream::in);
    else if(PERSON==1)
        lightb.open(R"(D:\FH-SWF\2. Semester\Grundlagen der Informatik 2\LIGHTBEAM REPO\Miniprojekt_Lightbeam\Json files\lightbeamData.json)", ifstream::in);
    else if(PERSON==3)
        lightb.open(R"()", ifstream::in);
    lightb>>lightbeam;
    enumerate(lightbeam);
    cout<<"Expected value: 9"<<endl;
    cout<<"Object count: "<<Count_Objects(lightbeam)<<endl;

    string* keys = new string[Count_Objects(lightbeam)];

    for(int i = 0; i<Count_Objects(lightbeam); i++){
        keys[i] = extractObjectKeys(lightbeam)[i];
        cout<<keys[i]<<endl;
    }

    cout<<lightbeam[keys[8]]["thirdParties"][4]<<endl<<endl;
    Graph lightbeamgraph(lightbeam);
    lightbeamgraph.printVertices();
/*    string test="test";
    string apple="apple";
    string tapple="test apple";
    cout<<test.compare(apple)<<"   "<<test.compare(tapple)<<"   "<<apple.compare(tapple)<<"   "
    <<test.compare(test)<<"   "<<test.compare("glkm")<<endl;*/

    return 0;
}
