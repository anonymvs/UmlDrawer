//
// Created by hegedus on 2017.12.14..
//

#include "Field.h"

Field::Field(Visibility visibility, std::string name, std::string type, bool isStatic) :
        visibility{visibility}, name{name}, type{type}, isStatic{isStatic} {}

std::string Field::write() const {
    std::string ret;
    switch (visibility) {
        case PUBLIC :
            ret = "+ ";
            break;
        case PRIVATE :
            ret = "- ";
            break;
        case PROTECTED :
            ret = "# ";
            break;
        default:
            ret = "+ ";
            break;
    }

    ret += name + " : " + type;
    if(isStatic) {
        ret = "<U>" + ret + "</U>";
    }
    ret += "<BR ALIGN=\"LEFT\"/>";
    return ret;
}