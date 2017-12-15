#include <iostream>
#include <fstream>
#include <list>
#include <map>

#include "DiagramReader.h"

void test();

int main(int argc, char **argv) {

    if(argc != 2) {
        std::cerr << "Not enough arguments";
    }

    //test();
    DiagramReader dr;
    dr.readFromPath(argv[1]);

    std::ofstream file;
    file.open("class_diagram_from_file.dot");
    file << dr.getContent();
    file.close();

    return 0;
}


