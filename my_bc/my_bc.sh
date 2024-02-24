#!/bin/sh

if [ "$#" -eq 1 ]; then
    echo "$(($1))"
    exit 0
fi

tmp="$1"
while read line; do
    echo "$(($line))"
done
