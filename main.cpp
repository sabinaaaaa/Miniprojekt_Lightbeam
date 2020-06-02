#include <iostream>
#include "json.hpp"
#include <fstream>
#include "cust_json.h"
using json=nlohmann::json;
using namespace std;

int main() {
    json lightbeam;
    ifstream lightb;
    lightb.open(R"(D:\FH-SWF\2. Semester\Grundlagen der Informatik 2\LIGHTBEAM REPO\Miniprojekt_Lightbeam\Json files\lightbeamData.json)", ifstream::in);
    lightb>>lightbeam;
    enumerate(lightbeam);
    cout<<"Expected value: 9"<<endl;
    cout<<"Object count: "<<Count_Objects(lightbeam)<<endl;
    return 0;
}
