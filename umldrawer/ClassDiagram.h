//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_DOTWRITER_H
#define UMLDRAWER_DOTWRITER_H

#include <string>
#include <vector>
#include <memory>

#include "Class.h"
#include "IRelation.h"

class ClassDiagram {
private:
    std::string content;
    std::string classes_content;
    std::string relations_content;

    std::map<std::string, Class> diagram;
    std::vector<IRelation*> relations;

    void initDotFile();
public:
    ClassDiagram();

    std::string getContent();

    void addClass(Class);
    void addRelation(IRelation *);
    const Class& getClass(std::string const &);
    ~ClassDiagram();
};


#endif //UMLDRAWER_DOTWRITER_H
