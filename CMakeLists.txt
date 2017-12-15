cmake_minimum_required(VERSION 3.9)
project(umldrawer)

set(CMAKE_CXX_STANDARD 17)

add_executable(umldrawer main.cpp ClassDiagram.cpp ClassDiagram.h Class.cpp Class.h Function.cpp Function.h Field.cpp Field.h Visibility.h DiagramReader.cpp DiagramReader.h IRelation.h Generalization.cpp Generalization.h Dependency.cpp Dependency.h Aggregation.cpp Aggregation.h Composition.cpp Composition.h Association.cpp Association.h)