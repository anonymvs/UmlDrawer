//
// Created by hegedus on 2017.12.14..
//

#include "Function.h"

Function::Function(Visibility visibility, std::string name, std::map<std::string, std::string> params,
                   std::string type, bool isStatic, bool isVirtual) :
    visibility{visibility}, name{name}, parameters{params}, return_type{type}, isStatic{isStatic}, isVirtual{isVirtual} {}

std::string Function::write() const {
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

    ret += name + "(";
    std::string params = "";
    if(!parameters.empty()) {
        for (auto it = parameters.begin(); it != parameters.end(); ++it) {
            params += it.operator*().first + " : " + it.operator*().second + ", ";
        }
        params.pop_back();
        params.pop_back();
    }
    ret += ") : " + return_type;
    if(isStatic) {
        ret = "<U>" + ret + "</U>";
    }
    if(isVirtual) {
        ret = "<I>" + ret + "</I>";
    }
    ret += "<BR ALIGN=\"LEFT\"/>";
    return ret;
}