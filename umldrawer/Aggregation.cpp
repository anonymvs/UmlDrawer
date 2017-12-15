//
// Created by hegedus on 2017.12.15..
//

#include "Aggregation.h"

void Aggregation::initAggregation() {
    content = "\tedge [\n";
    content += "\t\t arrowhead = \"odiamond\"\n";
    content += "\t\t style = \"solid\"\n";
    content += "\t]\n";
}

Aggregation::Aggregation() : IRelation{""}{
    initAggregation();
}

Aggregation::Aggregation(Class const &from, Class const &to) : IRelation{""} {
    initAggregation();
    members.first = from;
    members.second = to;
}

std::string Aggregation::write() {
    content += "\t" + members.first.getName() + " -> " + members.second.getName() + "\n\n";
    return content;
}


