#!/bin/sh

set -eu

output=a.out

while [ "$#" -gt 0 ]; do
    case "$1" in
        -o)
            if [ "$#" -lt 2 ]; then
                echo "Usage: $0 [-o output]" >&2
                exit 1
            fi
            output=$2
            shift 2
            ;;
        -h|--help)
            echo "Usage: $0 [-o output]";
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >&2
            echo "Usage: $0 [-o output]" >&2
            exit 1
            ;;
    esac
done

set --
for file in ./*.cpp; do
    [ -e "$file" ] || continue
    set -- "$@" "$file"
done

if [ "$#" -eq 0 ]; then
    echo "No cpp files found in current directory." >&2
    exit 1
fi

g++ -std=c++17 -O2 -Wall -Wextra "$@" -o "$output"

echo "Build succeeded: ./$output"