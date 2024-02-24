#!/bin/sh

if [ "$#" -ne 1 ]; then
    exit 1
fi

if [ ! -r "$1" ]; then
    exit 1
fi

while IFS= read -r line; do
    char=$(echo -n "$line" | wc -c)
    if [ "$char" -ge 80 ]; then
        printf "%s\n" "$line"
    fi
done < "$1"
