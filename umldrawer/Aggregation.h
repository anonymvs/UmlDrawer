//
// Created by hegedus on 2017.12.15..
//

#ifndef UMLDRAWER_AGGREGATION_H
#define UMLDRAWER_AGGREGATION_H


#include "Class.h"
#include "IRelation.h"

class Aggregation : public IRelation {
private:
    void initAggregation();
public:
    Aggregation();
    Aggregation(Class const &, Class const &);
    std::string write() override;
};



#endif //UMLDRAWER_AGGREGATION_H
