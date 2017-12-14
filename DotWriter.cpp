//
// Created by hegedus on 2017.12.14..
//

#include "DotWriter.h"


DotWriter::DotWriter() {
    initDotFile();
    initGeneralizations();
}

std::string DotWriter::getContent() {
    for(auto c : diagram) {
        c.second.write(classes_content);
    }
    for(auto g : generalizations) {
        generalizations_content += "\t" + g.first.getName() + " -> " + g.second.getName() + "\n";
    }
    return content + classes_content + generalizations_content + "\n}";
}

void DotWriter::addClass(Class c) {
    diagram[c.getName()] = c;
    //c.write(classes_content);
}

void DotWriter::addGeneralization(std::string lhs, std::string rhs) {
    Class from = diagram[lhs];
    Class to = diagram[rhs];
    generalizations.push_back(std::pair{from, to});
}

void DotWriter::initDotFile() {
    std::string type = "digraph G {\n";
    std::string fontname = "\tfontname = \"Bitstream Vera Sans\"\n";
    std::string fontsize = "\tfontsize = 8\n";

    std::string node = "\n\n \tnode [\n\t" + fontname + "\t" + fontsize;
    std::string shape = "\t\tshape = \"record\"\n\t]\n\n";

    std::string edge = "\tedge [\n\t" + fontname + "\t" + fontsize + "\t]\n\n";

    content =  type + fontname + fontsize + node + shape + edge;
}

void DotWriter::initGeneralizations() {
    std::string str = "\tedge [\n";
    str += "\t\t arrowhead = \"empty\"\n\t]\n\n";
    generalizations_content = str;
}
