//
// Created by bgbg5 on 6/2/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
#define MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
#include "json.hpp"
#include <iostream>
#include <string>
using json=nlohmann::json;
/**
 * @brief Count_Objects Count the nested objects of a
 * @param j
 * @return
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
 * @brief
 * @param j
 * @param keys
 */
std::string* extractObjectKeys(json j);

#endif //MINIPROJEKT_LIGHTBEAM_CUST_JSON_H
