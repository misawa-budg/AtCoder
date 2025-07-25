#!/bin/bash

set -e

if [ -z "$1" ]; then
    echo "Usage: $0 <content_number>"
    exit 1
fi

CONTEST_NUM=$1
DIR_NAME="Beginner${CONTEST_NUM}"

if [ -d "$DIR_NAME" ]; then
    echo "Directory $DIR_NAME already exists"
    exit 1
fi

echo "Creating directory $DIR_NAME"
mkdir "$DIR_NAME"

cd "$DIR_NAME"

echo "Creating empty files (A.cpp - D.cpp)"
for problem in {A..D}; do
    touch "${problem}.cpp"
done

echo "Done!"
ls
