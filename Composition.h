//
// Created by hegedus on 2017.12.15..
//

#ifndef UMLDRAWER_COMPOSITION_H
#define UMLDRAWER_COMPOSITION_H


#include "IRelation.h"

class Composition : public IRelation {
private:
    void initComposition();
public:
    Composition();
    Composition(Class const &, Class const &);
    std::string write() override;
};


#endif //UMLDRAWER_COMPOSITION_H
