
//
// Created by I. Marinov on 10/05/2021.
//

#ifndef MINIPROJEKT_LIGHTBEAM_MENU_H
#define MINIPROJEKT_LIGHTBEAM_MENU_H

#include <string>
#include <iostream>
#include <fstream>
#include "cust_json.h"
#include "graph.h"

void clearConsole();

void clearBuffer();

void Pause();

class Menu {
public:
    Menu();

    virtual ~Menu();

private:
    std::string dirPath;
    std::string fileName;
    std::ifstream objFile;
    json obj;
    Graph graph;
    std::string dirPathMenu();
    void fileNameMenu();
    void BFS_path_menu_ids();
    void BFS_path_menu_names();
    void printMatrix();
    void menu();
    isValidDirPath();
};


#endif //MINIPROJEKT_LIGHTBEAM_MENU_H
