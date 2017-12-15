//
// Created by hegedus on 2017.12.14..
//

#include "ClassDiagram.h"
#include "Generalization.h"


ClassDiagram::ClassDiagram() {
    initDotFile();
}

std::string ClassDiagram::getContent() {
    for(auto c : diagram) {
        c.second.write(classes_content);
    }
    for(auto const &r : relations) {
        relations_content += r->write();
    }
    /*for(size_t i = 0; i < relations.size(); ++i) {
        relations_content += relations[i].write();
    }*/
    return content + classes_content + relations_content + "\n}";
}

void ClassDiagram::addClass(Class c) {
    diagram[c.getName()] = c;
}

void ClassDiagram::addRelation(IRelation *relation) {
    relations.push_back(relation);
}

void ClassDiagram::initDotFile() {
    std::string type = "digraph G {\n";
    std::string fontname = "\tfontname = \"Bitstream Vera Sans\"\n";
    std::string fontsize = "\tfontsize = 8\n";

    std::string node = "\n\n \tnode [\n\t" + fontname + "\t" + fontsize;
    std::string shape = "\t\tshape = \"record\"\n\t]\n\n";

    std::string edge = "\tedge [\n\t" + fontname + "\t" + fontsize + "\t]\n\n";

    content =  type + fontname + fontsize + node + shape + edge;
}

const Class& ClassDiagram::getClass(std::string const &name) {
    return diagram[name];
}

ClassDiagram::~ClassDiagram() {
    for(auto v : relations) {
        delete v;
    }
}

