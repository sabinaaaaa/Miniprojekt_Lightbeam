//
// Created by bgbg5 on 6/2/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
#define MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
#include "json.hpp"
#include "vertex.h"
#include <iostream>
#include <string>
using json=nlohmann::json;
/**
 * @brief Count_Objects Count the nested objects in a json
 * @param j-  json object
 * @return returns the count of nested objects
 */
int Count_Objects(json &j);
/**
 * @brief enumerate
 * @param j
 */
void enumerate (json j);
/**
 * @brief
 * @param src
 * @param key
 */
void findNPrintKey (json src, const std::string& key);

/**
 * @brief Extracts all nested object keys off a json
 * @param j The main json object
 * @return returns a string pointer containing all object keys
 */
std::string* extractObjectKeys(json j);

#endif //MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
