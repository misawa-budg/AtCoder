#!/bin/bash

set -e

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)

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
TARGET_DIR="${SCRIPT_DIR}/${DIR_NAME}"

if [ -d "$TARGET_DIR" ]; then
    echo "Directory $TARGET_DIR already exists"
    exit 1
fi

echo "Creating directory $TARGET_DIR"
mkdir "$TARGET_DIR"

cd "$TARGET_DIR"

echo "Creating empty files (A.cpp - ${LAST_PROBLEM}.cpp)"
last_ascii=$(printf "%d" "'$LAST_PROBLEM")
for ascii in $(seq 65 "$last_ascii"); do
    problem=$(printf "%c" "$ascii")
    touch "${problem}.cpp"
done

echo "Done!"
ls
