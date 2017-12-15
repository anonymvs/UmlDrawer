//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_DIAGRAMREADER_H
#define UMLDRAWER_DIAGRAMREADER_H

#include <string>
#include <vector>

#include "Class.h"
#include "IRelation.h"
#include "ClassDiagram.h"

class DiagramReader {
private:
    ClassDiagram cd;
public:
    DiagramReader();
    void readFromPath(std::string);

    bool parseClass(Class &, std::ifstream &, std::string const &, std::string const &, int &);

    Function& parseFunction(std::string const &, std::string const &,  int);

    Field& parseField(std::string const &, int &);

    Visibility& parseVisibility(char);

    bool isFunction(std::string const &, std::string &);

    std::map<std::string, std::string>& parseParams(std::string const  &);

    std::string getContent();

    void parseRelation(std::string const &);
};


#endif //UMLDRAWER_DIAGRAMREADER_H
