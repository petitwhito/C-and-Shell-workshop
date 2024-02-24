#!/bin/sh

while read -r line; do
    if [ -z "$line" ]; then
        echo "it is empty"
        continue
    fi

    res=$(echo "$line" | grep -o '^[a-zA-Z]*$')
    if [ -n "$res" ]; then
        echo "it is a word"
        continue
    fi

    res=$(echo "$line" | grep -o '^[0-9]$')
    if [ -n "$res" ]; then
        echo "it is a digit"
        continue
    fi

    res=$(echo "$line" | grep -o '^[0-9]*+*$')
    if [ -n "$res" ]; then
        echo "it is a number"
        continue
    fi

    res=$(echo "$line" | grep -o '^[a-zA-Z0-9]*+*$')
    if [ -n "$res" ]; then
        echo "it is an alphanum"
        continue
    fi

    echo "it is too complicated"
    exit 0
done

exit 0
