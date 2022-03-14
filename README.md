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

rm -rf ./html ./arcade/API ./arcade/API.hpp
mv $FOLDER/LICENSE $FOLDER/README.md $FOLDER/Doxyfile $FOLDER/.gitignore $FOLDER/html .

mkdir -p ./arcade/API
mv $FOLDER/arcade/API.hpp $FOLDER/arcade/API ./arcade
```
