#!/bin/sh

for i; do
    if [ -d "$i" ]; then
        echo "$i: directory"
    elif [ -f "$i" ]; then
        echo "$i: file"
    else
        echo "$i: unknown"
    fi
done
