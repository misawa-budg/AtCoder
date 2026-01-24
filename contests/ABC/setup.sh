#!/bin/bash

set -e

if [ -z "$1" ]; then
    echo "Usage: $0 <contest_number> [last_problem]"
    echo "  last_problem: A-F (default: D)"
    exit 1
fi

CONTEST_NUM_RAW=$1
LAST_PROBLEM=${2:-D}
LAST_PROBLEM=$(echo "$LAST_PROBLEM" | tr '[:lower:]' '[:upper:]')

if ! [[ "$CONTEST_NUM_RAW" =~ ^[0-9]+$ ]]; then
    echo "Invalid contest_number: $CONTEST_NUM_RAW (expected digits)"
    exit 1
fi

if ! [[ "$LAST_PROBLEM" =~ ^[A-F]$ ]]; then
    echo "Invalid last_problem: $LAST_PROBLEM (expected A-F)"
    exit 1
fi

CONTEST_NUM_PADDED=$(printf "%03d" "$CONTEST_NUM_RAW")
DIR_NAME="ABC${CONTEST_NUM_PADDED}"

if [ -d "$DIR_NAME" ]; then
    echo "Directory $DIR_NAME already exists"
    exit 1
fi

echo "Creating directory $DIR_NAME"
mkdir "$DIR_NAME"

cd "$DIR_NAME"

echo "Creating empty files (A.cpp - ${LAST_PROBLEM}.cpp)"
last_ascii=$(printf "%d" "'$LAST_PROBLEM")
for ascii in $(seq 65 "$last_ascii"); do
    problem=$(printf "\\x%02X" "$ascii")
    touch "${problem}.cpp"
done

echo "Done!"
ls
