# UmlDrawer
My c++11 second homework

Usage: (on linux)

run from console with one parameter as the filename for the source file
```
  $./main class_diagram.class
```
then using graphviz convert the .dot file into .png with:
```
  $ dot -Tpng class_diagram_from_file.dot -o dst.png
```
if dot is not installed, you can install from package manager
