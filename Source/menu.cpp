
//
// Created by I. Marinov on 10/05/2021.
//

#include "menu.h"

Menu::~Menu() {

}


std::string Menu::dirPathMenu() {
    int opt;
    std::cout << "Current path is: \"" + ((dirPath != "") ? dirPath : "No path") +
                 "\". Do you wish to change it?(y/n)\n";
    std::cin >> opt;
    clearBuffer();
    if (opt == 'y' || opt == 'Y') {
        std::cout << "Enter the new directory path.(i.e C:/example/.../example) \n";
        std::getline(std::cin, dirPath);
        clearBuffer();
        std::cout << "Path was set to: \"" +
                     ((dirPath != "") ? dirPath : "No path") + "\"";
    } else {
//(condition) ? (if_true) : (if_false)
        std::cout << "Directory path was not changed. Current path is: \"" +
                     ((dirPath != "") ? dirPath : "No path") + "\"";
    }
    dirPath += "/";
    Pause();
}

Menu::Menu(const std::string &dirPath) : dirPath(dirPath) {}
