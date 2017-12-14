//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_DOTWRITER_H
#define UMLDRAWER_DOTWRITER_H

#include <string>

#include "Class.h"

class DotWriter {
private:
    std::string content;
    std::string classes_content;
    std::string generalizations_content;
    std::map<std::string, Class> diagram;
    std::list<std::pair<Class, Class>> generalizations;

    void initDotFile();
    void initGeneralizations();
public:
    DotWriter();

    std::string getContent();

    void addClass(Class);
    void addGeneralization(std::string, std::string);
};


#endif //UMLDRAWER_DOTWRITER_H
