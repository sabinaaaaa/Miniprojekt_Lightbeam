#include <iostream>
#include "json.hpp"
#include <fstream>
using json=nlohmann::json;
using namespace std;
int main() {
    json ivo;
    ivo["age"]=20;
    ivo["height"]= nullptr;
    std::cout<<ivo["age"]<<std::endl<<ivo["height"]<<std::endl<<ivo["weight"];
    ofstream fivo;
    fivo.open("D:\\FH-SWF\\2. Semester\\Grundlagen der Informatik 2\\json project\\fivo.json", ofstream::out);
    fivo<<ivo;
    return 0;
}
