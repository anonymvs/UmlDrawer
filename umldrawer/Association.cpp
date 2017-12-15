//
// Created by hegedus on 2017.12.15..
//

#include "Association.h"

void Association::initAssociation() {
    content = "\tedge [\n";
    content += "\t\t arrowhead = \"normal\"\n";
    content += "\t\t style = \"solid\"\n";
    content += "\t]\n";
}

Association::Association() : IRelation{""} {
    initAssociation();
}

Association::Association(Class const &from, Class const &to) : IRelation{""}{
    initAssociation();
    members.first = from;
    members.second = to;
}

std::string Association::write() {
    content += "\t" + members.first.getName() + " -> " + members.second.getName() + "\n\n";
    return content;
}
