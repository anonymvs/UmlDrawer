//
// Created by hegedus on 2017.12.15..
//

#ifndef UMLDRAWER_ASSOCIATION_H
#define UMLDRAWER_ASSOCIATION_H


#include "IRelation.h"

class Association : public IRelation {
private:
    void initAssociation();
public:
    Association();
    Association(Class const &, Class const &);
    std::string write() override;
};


#endif //UMLDRAWER_ASSOCIATION_H
