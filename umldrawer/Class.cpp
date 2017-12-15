//
// Created by hegedus on 2017.12.14..
//

#include "Class.h"

Class::Class() {
    name = "";
    fields = std::list<Field>{};
    methods = std::list<Function>{};
}

Class::Class(std::string name, std::list<Field> attribs, std::list<Function> methods, std::string type) :
    name{name}, fields{attribs}, methods{methods}, type{type} {
    isAbstrack = true;
    if(methods.empty()) {
        isAbstrack = false;
    } else {
        for(auto f : methods) {
            if(!f.isVirtual) {
                isAbstrack = false;
                break;
            }
        }
    }
}

Class::Class(std::string name, std::list<Field> attribs, std::list<Function> methods) :
        name{name}, fields{attribs}, methods{methods} {
    isAbstrack = true;
    if(methods.empty()) {
        isAbstrack = false;
    } else {
        for(auto f : methods) {
            if(!f.isVirtual) {
                isAbstrack = false;
                break;
            }
        }
    }
}

void Class::write(std::string &str) {
    std::string opener = "\t" + name + " [\n";
    std::string label_open = "\t\tlabel = <{";
    std::string type_final;
    if(!type.empty()) {
        type_final = "&lt;&lt;" + type + "&gt;&gt;<BR ALIGN=\"LEFT\"/>";
    }
    std::string label;
    if(isAbstrack) {
        label = type_final + "<I>" + name + "</I>" + "|";
    } else {
        label = type_final + name + "|";
    }
    for(auto iterator = fields.begin(); iterator != fields.end(); ++iterator) {
        label += iterator.operator*().write();
    }
    label += "|";
    for(auto iterator = methods.begin(); iterator != methods.end(); ++iterator) {
        label += iterator.operator*().write();
    }

    std::string label_close = "}>\n\t";
    std::string closer = "]\n\n";
    str += (opener + label_open + label + label_close + closer);
}

std::string Class::getName() {
    return name;
}

void Class::addField(Field field) {
    fields.push_back(field);
}

void Class::addFunction(Function function) {
    methods.push_back(function);
}
