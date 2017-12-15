//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_RELATION_H
#define UMLDRAWER_RELATION_H


#include <utility>
#include "Class.h"

class IRelation {
protected:
    std::string name;
    std::string content;
    std::pair<Class, Class> members;
public:
    explicit IRelation(std::string const &name) : name{name} {}
    virtual std::string write() = 0;
    virtual ~IRelation() {};
};


#endif //UMLDRAWER_RELATION_H
