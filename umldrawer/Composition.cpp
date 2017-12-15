//
// Created by hegedus on 2017.12.15..
//

#include "Composition.h"

void Composition::initComposition() {
    content = "\tedge [\n";
    content += "\t\t arrowhead = \"diamond\"\n";
    content += "\t\t style = \"solid\"\n";
    content += "\t]\n";
}

Composition::Composition() : IRelation{""} {
    initComposition();
}

Composition::Composition(Class const &from, Class const &to) : IRelation{""}{
    initComposition();
    members.first = from;
    members.second = to;
}

std::string Composition::write() {
    content += "\t" + members.first.getName() + " -> " + members.second.getName() + "\n\n";
    return content;
}
