
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

void clearBuffer();

void clearConsole();

void Pause();

class Menu {
public:
    Menu(const std::string &dirPath);

    virtual ~Menu();

private:
    std::string dirPath;
    std::string dirPathMenu();
};



void menu() {
    /*
 * Program Menu
 * 1- Choose a LightBeam ".json" file.(specify the whole path like C:/example/.../example.json
 * 2- Print Adjacency Matrix of the graph
 * 3- Find path and distance between two vertices(using id's)
 * 4- Find path and distance between two vertices(using vertex names)
 * e- Exit the program
 * */
    std::cout << "If you are using this program for the first time we recommend looking at the README first.\n"
                 "Else press Enter to continue";
    Pause();
    clearBuffer();
    clearConsole();

    json obj;
    std::ifstream objFile;
    std::string dirPath = "";
    std::string fileName = "";
    std::string s_start, s_end;
    int start, end;
    char opt; // used as the menu option holder
    Graph Graph;
    while (opt != 'e') { // menu loop

        //print menu options
        std::cout << "Program Menu\n"
                     "1- Choose a directory path\n"
                     "2- Read a graph-file from the directory path. Only specify the file name i.e testgraph \n"
                     "3- Print Adjacency Matrix of the graph\n"
                     "4- Find path and distance(using BFS) between two vertices(using id's)\n"
                     "5- Find path and distance(using BFS) between two vertices(using vertex names)\n"
                     "e- Exit the program\n";
        std::cin >> opt; // ask user for input (choose an option from the menu)
        clearBuffer();

        switch (opt) {
            case '1': //directory path
                dirPathMenu(dirPath);
                break;


            case '2': // lighbeam .json file name
                if (dirPath == "") { // if the directory path is not specified
                    std::cout << "Please choose a directory path first(option 1 in the menu).";
                    break;
                }

                if (!Graph.isEmpty()); //if graph is not empty,
                Graph.~Graph();// delete it(free all of its allocated memory)

                if (objFile.is_open()) { // if a file is already open ask the user if they want to replace it
                    std::cout << "A file is already open. Are you sure you wish to open a new one?(y/n)\n";
                    std::cin >> opt;// ask user for input
                    clearBuffer(); // clear buffer
                    if (opt == 'y' || opt == 'Y') { // if user choses y (yes)
                        objFile.close(); // first close the previous file
                        std::cout << "Enter the new file name.\n";
                        std::cin >> fileName; // ask user for new file name
                        clearBuffer(); // clear input buffer
                        std::cout << "Opening the following file. \"" +
                                     dirPath + fileName + "\"";
                    } else {
                        //(condition) ? (if_true) : (if_false)
                        std::cout << "File path was not changed. Current path is: \"" +
                                     dirPath + fileName + "\"";
                    }
                } else {
                    std::cout << "Enter file name";
                    std::cin >> fileName; // ask user for new file name
                    clearBuffer(); // clear input buffer
                    std::cout << "Opening the following file. \"" +
                                 dirPath + fileName + "\"";
                }
                objFile.open(dirPath + fileName, std::ifstream::in);
                objFile >> obj;
                Graph.init(obj);
                break;
            case '3': // print the adjacency matrix of the graph
                Graph.printAdjMatrix();
                break;
            case '4': // find path and distance between two vertices with THEIR IDs
                std::cout << "Please enter a starting vertex(using id).\n";
                std::cin >> start;
                clearBuffer();
                std::cout << "Please enter the end vertex(using id).\n";
                std::cin >> end;
                clearBuffer();
                Graph.printPath(end, start);
                break;
            case '5': // find path and distance between two vertices with THEIR NAMES
                std::cout << "Please enter a starting vertex(using its name).\n";
                std::cin >> s_start;
                clearBuffer();
                std::cout << "Please enter the end vertex(using its name).\n";
                std::cin >> s_end;
                Graph.printPath(s_end, s_start);
                clearBuffer();
                break;
            case 'e':
                break;
            default: // when option isn't found
                std::cout << "Please enter a valid option from the menu.\n";
                Pause();
                clearBuffer();
                clearConsole();
                break;
        }

    }
}

/**
 * @brief Clear buffer of any unwanted input.
 */
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/**
 * @brief clear the console window
 */
void clearConsole() {
#ifdef __WIN32
    system("cls");
#else
    system("clear"); // most other systems use this
#endif
}

/**
 * @brief Pause the program and wait for Enter input to continue
 */
void Pause() {
    std::cout << "\nPress Enter to continue";
    std::cin.get();
}

#endif //MINIPROJEKT_LIGHTBEAM_MENU_H
