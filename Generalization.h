//
// Created by hegedus on 2017.12.14..
//

#ifndef UMLDRAWER_GENERALIZATION_H
#define UMLDRAWER_GENERALIZATION_H


#include "IRelation.h"

class Generalization : public IRelation {
private:
    void initGeneralization();
public:
    Generalization();
    Generalization(Class const &, Class const &);
    std::string write() override;
};


#endif //UMLDRAWER_GENERALIZATION_H
