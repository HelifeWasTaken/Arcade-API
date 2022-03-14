# Arcade-API
Arcade API Implementation and documentation

## How to make the documentation:

```bash
doxygen Doxyfile
```

## How to update your local API inside your repository:

```bash
#!/bin/bash

FOLDER="/tmp/arcade"

rm -rf $FOLDER
git clone git@github.com:HelifeWasTaken/Arcade-API.git $FOLDER
mv $FOLDER/LICENSE .
mv $FOLDER/README.md .
mv $FOLDER/Doxyfile .
mv $FOLDER/.gitignore .

rm -rf ./html
mv $FOLDER/html .

rm -rf ./arcade/API ./arcade/API.hpp
mkdir -p ./arcade/API

mv $FOLDER/arcade/API.hpp $FOLDER/arcade/API ./arcade
```
