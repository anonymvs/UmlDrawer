//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_FUNCTION_H
#define UMLDRAWER_FUNCTION_H

#include <string>
#include <map>
#include "Visibility.h"

class Function {
private:
    std::string name;
    Visibility visibility;
    std::string return_type;
    std::map<std::string, std::string> parameters;
public:
    bool isStatic;
    bool isVirtual;

    Function(Visibility, std::string, std::map<std::string, std::string>,  std::string = "", bool = false, bool = false);
    std::string write() const;
};


#endif //UMLDRAWER_FUNCTION_H
