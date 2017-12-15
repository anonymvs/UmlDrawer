//
// Created by hegedus on 2017.12.15..
//

#ifndef UMLDRAWER_DEPENDENCY_H
#define UMLDRAWER_DEPENDENCY_H


#include "IRelation.h"

class Dependency : public IRelation {
private:
    void initDependency();

public:
    Dependency();
    Dependency(Class const &, Class const &);
    std::string write() override;
};


#endif //UMLDRAWER_DEPENDENCY_H
