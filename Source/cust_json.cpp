//
// Created by bgbg5 on 6/2/2020.
//
#include "cust_json.h"
int Count_Objects(json &j){
    int counter=0;
    for(auto it=j.begin(); it!=j.end(); ++it){
        if(it->is_object()) {
            ++counter;
            counter+=(Count_Objects(it.value()));
        }
    }
    return counter;
}

void findNPrintKey (json src, const std::string& key) {
    auto result = src.find(key);
    if (result != src.end()) {
        std::cout << "Entry found for : " << result.key() << std::endl;
    } else {
        std::cout << "Entry not found for : " << key << std::endl ;
    }
}

void enumerate (json j) {
    // Enumerate all keys (including sub-keys -- not working)
    int counter=0;
    for (auto it=j.begin() ; it != j.end(); it++ , counter++) {
        if(it->is_object())
        {
            std::cout << "key"<<counter <<": " << it.key() << " is object"<<std::endl;
            enumerate(it.value());
        }
        else
            std::cout << "key"<<counter <<": " << it.key() << " : " << it.value() << std::endl;
    }

    // find a top-level key
    findNPrintKey(j, "hostname");
    // find a nested key
    findNPrintKey(j, "firstParty");
    std::cout<<std::endl<<std::endl<<std::endl;
}

std::string* extractObjectKeys(json j)
{
    int counter = 0;
    std::string* keys = new std::string[Count_Objects(j)];
    for (auto it=j.begin() ; it != j.end(); it++, counter++) {
        if(it->is_object())
        {
            keys[counter] = it.key();
        }
    }
    return keys;
}