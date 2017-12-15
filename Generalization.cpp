//
// Created by hegedus on 2017.12.14..
//

#include "Generalization.h"

Generalization::Generalization() : IRelation{""}{
    initGeneralization();
}

Generalization::Generalization(Class const &from, Class const &to) : IRelation{""} {
    initGeneralization();
    members.first = from;
    members.second = to;
}

std::string Generalization::write() {
    content += "\t" + members.first.getName() + " -> " + members.second.getName() + "\n\n";
    return content;
}

void Generalization::initGeneralization() {
    content = "\tedge [\n";
    content += "\t\t arrowhead = \"empty\"\n\t]\n";
}


