#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

#include "Class.h"
#include "Field.h"
#include "Function.h"
#include "ClassDiagram.h"
#include "Visibility.h"
#include "Generalization.h"
#include "DiagramReader.h"

void test();

int main(int argc, char **argv) {

    if(argc != 2) {
        std::cerr << "Not enough arguments";
    }

    //test();
    DiagramReader dr;
    dr.readFromPath(argv[1]);

    std::ofstream file;
    file.open("class_diagram_from_file.dot");
    file << dr.getContent();
    file.close();

    return 0;
}

void test() {
    std::ofstream file;
    file.open("class_diagram.dot");

    ClassDiagram dw{};

    std::list<Field> fields;
    std::list<Function> methods;

    fields.push_back(Field{PRIVATE, "id", "int"});
    fields.push_back(Field{PUBLIC, "name", "string"});
    fields.push_back(Field{PUBLIC, "population", "long", true});

    std::map<std::string, std::string> params;
    params["id"] = "int";
    params["name"] = "string";
    methods.push_back(Function{PRIVATE, "Person", params, "" });
    methods.push_back(Function{PRIVATE, "work", std::map<std::string, std::string>{}, "void" });
    methods.push_back(Function{PRIVATE, "numbers", std::map<std::string, std::string>{}, "int", true});
    methods.push_back(Function{PRIVATE, "random", std::map<std::string, std::string>{}, "string", true, true});

    Class person{"Person", fields, methods, ""};

    std::list<Field> fields_worker;
    std::list<Function> methods_worker;
    fields_worker.push_back(Field{PRIVATE, "workplace", "string"});
    Class worker{"Worker", fields_worker, methods_worker, ""};

    Class civilian("Civilian", std::list<Field>{}, std::list<Function>{}, "");

    dw.addClass(person);
    dw.addClass(worker);
    dw.addClass(civilian);
    Generalization *wp = new Generalization{worker, person};
    dw.addRelation( wp );
    Generalization *cp = new Generalization{civilian, worker};
    dw.addRelation( cp);

    file << dw.getContent();
    file.close();
    delete wp;
    delete cp;

}

