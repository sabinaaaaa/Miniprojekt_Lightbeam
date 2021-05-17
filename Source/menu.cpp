
//
// Created by I. Marinov on 10/05/2021.
//

#include "menu.h"
#include <unistd.h>

std::string Menu::dirPathMenu() {
    char opt;
    clearBuffer();
    std::cout << "Current path is: \"" << ((this->dirPath != "") ? dirPath : "No path") <<
              "\".\nDo you wish to change it?(y/n)\n";
    std::cin >> opt;
    clearBuffer();

    if (opt == 'y' || opt == 'Y') {
        std::cout << "Enter the new directory path.(i.e C:/example/.../example)\n";
        std::getline(std::cin, this->dirPath);
        std::cout << "Path was set to: \"" +
                     ((dirPath != "") ? dirPath : "No path") + "\"";
    } else {
//(condition) ? (if_true) : (if_false)
        std::cout << "Directory path was not changed. Current path is: \"" +
                     ((dirPath != "") ? dirPath : "No path") + "\"";
    }
    char lastChar = *std::prev(dirPath.end()).base();
    if (&lastChar != "/" | &lastChar != "\\")
        dirPath += "/";

    Pause();
    return dirPath;
}


/**
 * @brief
 * SOURCE: https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program
 */
Menu::Menu() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
    this->dirPath = cwd;
    this->menu();
}

Menu::~Menu() {

}

void Menu::menu() {
    /*
 * Program Menu
 * 1- Choose a LightBeam ".json" file.(specify the whole path like C:/example/.../example.json
 * 2- Print Adjacency Matrix of the graph
 * 3- Find path and distance between two vertices(using id's)
 * 4- Find path and distance between two vertices(using vertex names)
 * e- Exit the program
 * */
    std::cout << "If you are using this program for the first time we recommend looking at the README first.\n";
    Pause();
    //clearBuffer();
    //clearConsole();

    char opt; // used as the menu option holder

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

        switch (opt) {
            case '1': //directory path
                dirPathMenu();
                break;
            case '2': // lighbeam .json file name
                fileNameMenu();
                break;
            case '3': // print the adjacency matrix of the graph
                printMatrix();
                break;
            case '4': // find path and distance between two vertices with THEIR IDs
                BFS_path_menu_ids();
                break;
            case '5': // find path and distance between two vertices with THEIR NAMES
                BFS_path_menu_names();
                break;
            case 'e':
                break;
            default: // when option isn't found
                clearConsole();
                std::cout << "Please enter a valid option from the menu.\n";
                Pause();
                clearBuffer();
                break;
        }
    }
}

void Menu::fileNameMenu() {
    if (dirPath == "") { // if the directory path is not specified
        std::cout << "Please choose a directory path first(option 1 in the menu).";
        return;
    }

    if (!graph.isEmpty()) //if graph is not empty,
        graph.~Graph();// delete it(free all of its allocated memory)
    int opt;
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
    graph.init(obj);
}

void Menu::BFS_path_menu_ids() {
    int start, end;
    std::cout << "Please enter a starting vertex(using id).\n";
    std::cin >> start;
    clearBuffer();
    std::cout << "Please enter the end vertex(using id).\n";
    std::cin >> end;
    clearBuffer();
    graph.printPath(end, start);
}

void Menu::BFS_path_menu_names() {
    std::string s_start, s_end;
    std::cout << "Please enter a starting vertex(using its name).\n";
    std::cin >> s_start;
    clearBuffer();
    std::cout << "Please enter the end vertex(using its name).\n";
    std::cin >> s_end;
    graph.printPath(s_end, s_start);
    clearBuffer();
}

void Menu::printMatrix() {
    if (graph.isEmpty()) {
        printf("Read a JSON file first.\n");
        clearBuffer();
        return;
    }
    graph.printAdjMatrix();
}

int Menu::isValidDirPath() {
    struct stat stat;
    if(stat())
    return 0;
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
