#!/bin/bash

PROJECT_DIR="$(dirname $0)"
OUT_PATH="$PROJECT_DIR/out/merging_heaps"

if [ ! -d "$(dirname $OUT_PATH)" ]; then
    mkdir -p "$(dirname $OUT_PATH)"
fi

gcc -o $OUT_PATH $PROJECT_DIR/main.c $PROJECT_DIR/data_structures/*.c $PROJECT_DIR/io/*.c $PROJECT_DIR/operations/*.c $PROJECT_DIR/runtime/*.c

echo "Compiled to $OUT_PATH"