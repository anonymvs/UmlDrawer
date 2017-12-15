//
// Created by hegedus on 2017.12.15..
//

#include "Dependency.h"

void Dependency::initDependency() {
    content = "\tedge [\n";
    content += "\t\t arrowhead = \"normal\"\n";
    content += "\t\t style = \"dashed\"\n";
    content += "\t]\n";
}

Dependency::Dependency() : IRelation{""} {
    initDependency();
}

Dependency::Dependency(Class const &from, Class const &to) : IRelation{""} {
    initDependency();
    members.first = from;
    members.second = to;
}

std::string Dependency::write() {
    content += "\t" + members.first.getName() + " -> " + members.second.getName() + "\n\n";
    return content;
}
