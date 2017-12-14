//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_CLASS_H
#define UMLDRAWER_CLASS_H

#include <list>
#include "Function.h"
#include "Field.h"

class Class {
private:
    std::string name;
    std::list<Function> methods;
    std::list<Field> fields;
    std::string type = "";
    bool isAbstrack = false;
public:
    Class();
    Class(std::string, std::list<Field>, std::list<Function>, std::string = "");
    Class(std::string, std::list<Field>, std::list<Function>);
    void write(std::string &);

    std::string getName();
};


#endif //UMLDRAWER_CLASS_H
