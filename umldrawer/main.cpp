#include <iostream>
#include <fstream>
#include <list>
#include <map>

#include "DiagramReader.h"

// Usage: (on linux)
// run from console with one parameter as the filename for the source file
//   $./main class_diagram.class
// then using graphviz convert the .dot file into .png with:
//   $ dot -Tpng class_diagram_from_file.dot -o dst.png
// if dot is not installed, you can install from package manager

int main(int argc, char **argv) {

    if(argc != 2) {
        std::cerr << "Not enough arguments";
    }

    //test();
    DiagramReader dr;
    dr.readFromPath(argv[1]); //class_diagram.class

    std::ofstream file;
    file.open("class_diagram_from_file.dot");
    file << dr.getContent();
    file.close();

    return 0;
}


