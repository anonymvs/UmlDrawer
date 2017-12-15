//
// Created by hegedus on 2017.12.14..
//

#include "DiagramReader.h"
#include "Generalization.h"
#include "Dependency.h"
#include "Aggregation.h"
#include "Composition.h"
#include "Association.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

/*enum RelationType : std::string {
    GENERALIZATION = '-|>',
    COMPOSITION = '--*',
    AGGREGATION = '--o',
    ASSOCIATION = '-->',
    DEPENDENCY = '..>'
};*/

template <typename T>
void split(const std::string &str, char delim, T result) {
    std::stringstream ss(str);
    std::string item;
    while(std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(std::string const &str, char delim) {
    std::vector<std::string> elements;
    split(str, delim, std::back_inserter(elements));
    return elements;
}

void DiagramReader::readFromPath(std::string path) {
    std::ifstream is;
    is.exceptions(std::ifstream::badbit | std::ifstream::eofbit | std::ifstream::failbit);
    is.open(path);
    int number = 1;

    std::string line;
    while (std::getline(is, line)) {
        if(line == "@enduml") {
            break;
        }
        if(line.empty()) {
            std::cout << "empty line\n";
            number++;
        } else {
            std::vector<std::string> tokens = split(line, ' ');
            if(tokens[0] == "class") {
                number++;
                Class c;
                if(tokens.size() > 3 && !tokens[2].empty()) {
                    if(parseClass(c, is, tokens[1], tokens[2], number)) {
                        cd.addClass(c);
                    }
                }
                if(parseClass(c, is, tokens[1], "", number)) {
                    cd.addClass(c);
                }
            } else {
                parseRelation(line);
            }
        }
    }
}

bool DiagramReader::parseClass(Class &c, std::ifstream &is, std::string const &name, std::string const &type, int &number) {
    std::string line;
    std::list<Function> functions{};
    std::list<Field> fields{};
    while (std::getline(is, line)) {
        if(line == "@enduml") {
            return false;
        }
        if(line == "}") {
            break;
        }
        if(!line.empty()) {
            std::string param_str;
            if(isFunction(line, param_str)) {
                Function function = parseFunction(line, param_str, number);
                functions.push_back(function);
            } else {
                Field field = parseField(line, number);
                fields.push_back(field);
            }
        } else {
            return false;
        }
        number++;
    }
    Class *tmp = new Class{name, fields, functions, type};
    c = *tmp;
    delete tmp;
    return true;
}

Function DiagramReader::parseFunction(std::string const &line, std::string const &param, int number) {
    std::vector<std::string> tokens = split(line, ' ');
    Visibility v;
    try {
        v = parseVisibility(tokens[0].c_str()[1]);
    } catch (...) {
        std::string error = "Syntax Error: in line #";
        error += number + ": visibility error";
        throw std::runtime_error(error);
    }

    tokens[0] = tokens[0].substr(2, tokens[0].size() - 2);
    std::string type = tokens[1];
    std::string name = split(tokens[2], '(')[0];
    std::map<std::string, std::string> parameters = parseParams(param);
    bool isVirtual = false;
    bool isStatic = false;
    if(tokens.back().find(')') == std::string::npos) {
        if(tokens[tokens.size()-1].find(')') == std::string::npos) {
            isVirtual = true;
            isStatic = true;
        }
        if(tokens.back() == "static") {
            isStatic = true;
        }
        if(tokens.back() == "virtual") {
            isVirtual = true;
        }
    }
    return Function{v, name, parameters, type, isStatic, isVirtual};
}

Visibility DiagramReader::parseVisibility(char c) {

    switch (c) {
        case '+' :
            return Visibility{PUBLIC};
        case '-' :
            return Visibility{PRIVATE};
        case '#' :
            return Visibility{PROTECTED};
        default:
            throw;
    }
}

bool DiagramReader::isFunction(std::string const &line, std::string &param) {
    if(line.find('(') != std::string::npos) {
        bool copy_status = false;
        for(auto it = line.begin(); it != line.end(); ++it) {
            if(*it == '(') {
                it++;
                copy_status = true;
            }
            if(*it == ')') {
                break;
            }
            if(copy_status) {
                param += *it;
            }
        }
        return true;
    }
    return false;
}

std::map<std::string, std::string> DiagramReader::parseParams(std::string const &params) {
    std::map<std::string, std::string> ret;
    std::vector<std::string> tmp = split(params, ',');
    for(auto v : tmp) {
        std::vector<std::string> param = split(v, ' ');
        if(param.size() == 3) {
            ret[param[1]] = param[2];
        } else {
            ret[param[0]] = param[1];
        }
    }
    return std::map<std::string, std::string>{ret};
}

Field DiagramReader::parseField(std::string const &line, int &number) {
    std::string tmp = line;
    std::vector<std::string> tokens = split(line, ' ');
    Visibility v;
    try {
        v = parseVisibility(tokens[0].c_str()[1]);
    } catch (...) {
        std::string error = "Syntax Error: in line #";
        error += number + ": visibility error";
        throw std::runtime_error(error);
    }
    tokens[0] = tokens[0].substr(2, tokens[0].size() - 2);
    std::string type = tokens[1];
    std::string name = tokens[2];
    bool isStatic = false;
    if(tokens.size() == 4 && tokens[3] == "static") {
        isStatic = true;
    }
    return Field(v, name, type, isStatic);
}

std::string DiagramReader::getContent() {
    return cd.getContent();
}

void DiagramReader::parseRelation(std::string const &line) {
    std::vector<std::string> tokens = split(line, ' ');
    if(tokens[0] != "relation") {
        return;
    }
    Class from = cd.getClass(tokens[1]);
    Class to = cd.getClass(tokens.back());
    if(tokens[2].find("-|>") != std::string::npos) {
        auto generalization = new Generalization{from, to};
        cd.addRelation(generalization);
    }
    if(tokens[2].find("..>") != std::string::npos) {
        auto dependency = new Dependency{from, to};
        cd.addRelation(dependency);
    }
    if(tokens[2].find("--o") != std::string::npos) {
        auto aggregation = new Aggregation{from, to};
        cd.addRelation(aggregation);
    }
    if(tokens[2].find("--*") != std::string::npos) {
        auto composition = new Composition{from, to};
        cd.addRelation(composition);
    }
    if(tokens[2].find("-->") != std::string::npos) {
        auto association = new Association{from, to};
        cd.addRelation(association);
    }

}


DiagramReader::DiagramReader() = default;
