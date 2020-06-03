#include <iostream>
#include "json.hpp"
#include <fstream>
#include "cust_json.h"
using json=nlohmann::json;
using namespace std;

int main() {
    json lightbeam;
    ifstream lightb;
    lightb.open(R"(C:\Users\Sabina\CLionProjects\Miniprojekt_Lightbeam\Json files\lightbeamData.json)", ifstream::in);
    lightb>>lightbeam;
    enumerate(lightbeam);
    cout<<"Expected value: 9"<<endl;
    cout<<"Object count: "<<Count_Objects(lightbeam)<<endl;

    string* keys = new string[Count_Objects(lightbeam)];

    for(int i = 0; i<Count_Objects(lightbeam); i++){
        keys[i] = extractObjectKeys(lightbeam)[i];
        cout<<keys[i]<<endl;
    }

    cout<<lightbeam[keys[8]]["thirdParties"][4]<<endl;

    return 0;
}
