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

echo "Creating files from template (A.cpp - ${LAST_PROBLEM}.cpp)"
for problem in A B C D E F; do
    cat > "${problem}.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}
EOF

    if [ "$problem" = "$LAST_PROBLEM" ]; then
        break
    fi
done

echo "Done!"
ls
