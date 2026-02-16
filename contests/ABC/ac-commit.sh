#!/usr/bin/env bash

set -euo pipefail

usage() {
    cat <<'EOF'
Usage:
  ./contests/ABC/ac-commit.sh [--push] [contest [problems...]]

Behavior:
  - Default is auto mode (no contest/problems): detect changed ABC files.
  - Before running git add/commit, show target files and wait for Enter.
  - If --push is set, run git push after successful commit.

Examples:
  ./contests/ABC/ac-commit.sh
  ./contests/ABC/ac-commit.sh --push
  ./contests/ABC/ac-commit.sh 443 A B C
  ./contests/ABC/ac-commit.sh ABC443 D
EOF
}

to_upper() {
    printf '%s' "$1" | tr '[:lower:]' '[:upper:]'
}

normalize_contest() {
    local raw upper n
    raw="$1"
    upper=$(to_upper "$raw")

    if [[ "$upper" =~ ^[0-9]+$ ]]; then
        printf 'ABC%03d\n' "$((10#$upper))"
        return
    fi

    if [[ "$upper" =~ ^ABC([0-9]+)$ ]]; then
        n="${BASH_REMATCH[1]}"
        printf 'ABC%03d\n' "$((10#$n))"
        return
    fi

    echo "Invalid contest: $raw (expected 443 or ABC443)" >&2
    exit 1
}

normalize_problem() {
    local p
    p=$(to_upper "$1")
    if [[ ! "$p" =~ ^[A-F]$ ]]; then
        echo "Invalid problem: $1 (expected A-F)" >&2
        exit 1
    fi
    printf '%s\n' "$p"
}

collect_changed_abc_files() {
    {
        git diff --name-only -- 'contests/ABC/ABC[0-9][0-9][0-9]/[A-F].cpp'
        git diff --name-only --cached -- 'contests/ABC/ABC[0-9][0-9][0-9]/[A-F].cpp'
        git ls-files --others --exclude-standard -- 'contests/ABC/ABC[0-9][0-9][0-9]/[A-F].cpp'
    } | sort -u
}

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(git -C "$SCRIPT_DIR" rev-parse --show-toplevel)
cd "$REPO_ROOT"

PUSH=false
declare -a POSITIONAL=()

while [[ $# -gt 0 ]]; do
    case "$1" in
    --push)
        PUSH=true
        ;;
    --auto)
        ;;
    -h|--help)
        usage
        exit 0
        ;;
    --)
        shift
        POSITIONAL+=("$@")
        break
        ;;
    -*)
        echo "Unknown option: $1" >&2
        usage
        exit 1
        ;;
    *)
        POSITIONAL+=("$1")
        ;;
    esac
    shift
done

declare contest=""
declare -a target_files=()
declare -a problems=()

if [[ ${#POSITIONAL[@]} -eq 0 ]]; then
    mapfile -t target_files < <(collect_changed_abc_files)
    if [[ ${#target_files[@]} -eq 0 ]]; then
        echo "No changed ABC files found under contests/ABC/ABCNNN/[A-F].cpp" >&2
        exit 1
    fi

    declare -A contest_seen=()
    declare -a contests=()
    for file in "${target_files[@]}"; do
        c=$(basename "$(dirname "$file")")
        if [[ -z "${contest_seen[$c]:-}" ]]; then
            contest_seen[$c]=1
            contests+=("$c")
        fi
    done

    if [[ ${#contests[@]} -ne 1 ]]; then
        echo "Auto mode found multiple contests. Specify contest manually." >&2
        printf 'Detected: %s\n' "${contests[@]}" >&2
        exit 1
    fi

    contest="${contests[0]}"
else
    contest=$(normalize_contest "${POSITIONAL[0]}")

    if [[ ${#POSITIONAL[@]} -eq 1 ]]; then
        while IFS= read -r file; do
            if [[ "$file" =~ ^contests/ABC/${contest}/[A-F]\.cpp$ ]]; then
                target_files+=("$file")
            fi
        done < <(collect_changed_abc_files)
        if [[ ${#target_files[@]} -eq 0 ]]; then
            echo "No changed files found for ${contest}. Add problems explicitly (e.g. ${contest} A B C)." >&2
            exit 1
        fi
    else
        for raw_problem in "${POSITIONAL[@]:1}"; do
            p=$(normalize_problem "$raw_problem")
            file="contests/ABC/${contest}/${p}.cpp"
            if [[ ! -f "$file" ]]; then
                echo "File not found: $file" >&2
                exit 1
            fi
            target_files+=("$file")
        done
    fi
fi

declare -A problem_seen=()
for file in "${target_files[@]}"; do
    p=$(basename "$file")
    p="${p%.cpp}"
    if [[ -z "${problem_seen[$p]:-}" ]]; then
        problem_seen[$p]=1
        problems+=("$p")
    fi
done

if [[ ${#problems[@]} -eq 0 ]]; then
    echo "No problems detected from target files." >&2
    exit 1
fi

IFS=$'\n' read -r -d '' -a target_files < <(printf '%s\n' "${target_files[@]}" | sort -u && printf '\0')
IFS=$'\n' read -r -d '' -a problems < <(printf '%s\n' "${problems[@]}" | sort -u && printf '\0')
unset IFS

problem_joined=$(printf '%s' "${problems[@]}")
commit_msg="solve: ${contest} ${problem_joined}"

echo "Repository: ${REPO_ROOT}"
echo "Commit message: ${commit_msg}"
echo "Target files:"
printf '  - %s\n' "${target_files[@]}"
if $PUSH; then
    echo "Post action: git push"
else
    echo "Post action: no push"
fi
echo

read -r -p "Press Enter to run, or type anything to cancel: " confirm
if [[ -n "$confirm" ]]; then
    echo "Canceled."
    exit 0
fi

git add -- "${target_files[@]}"
if git diff --cached --quiet -- "${target_files[@]}"; then
    echo "No staged changes for target files. Nothing to commit." >&2
    exit 1
fi

git commit -m "$commit_msg" -- "${target_files[@]}"

if $PUSH; then
    git push
fi
