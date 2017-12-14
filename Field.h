//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_FIELD_H
#define UMLDRAWER_FIELD_H

#include <string>
#include "Visibility.h"

class Field {
private:
    Visibility visibility;
    std::string name;
    std::string type;
public:
    bool isStatic;
    Field(Visibility, std::string, std::string, bool = false);
    std::string write() const;
};


#endif //UMLDRAWER_FIELD_H
