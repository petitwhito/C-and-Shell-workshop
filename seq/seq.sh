#!/bin/sh

if [ "$#" -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
    exit 1
fi

first="$1"
increment="$2"
last="$3"

if [ "$increment" -eq 0 ]; then
    exit 1
fi

if [ "$first" -eq "$last" ]; then
    echo "$first"
fi

if [ "$first" -lt "$last" ]; then
    if [ "$increment" -le 0 ]; then
        exit 1
    fi
    i=0
    n=$((first+i*increment))
    while [ "$first" -le "$n" ] && [ "$last" -ge "$n" ]; do
        echo "$n"
        i=$((i+1))
        n=$((first+i*increment))
    done
fi

if [ "$first" -gt "$last" ]; then
    if [ "$increment" -ge 0 ]; then
        exit 1
    fi
    i=0
    n=$((first+i*increment))
    while [ "$last" -le "$n" ]&&[ "$first" -ge "$n" ]; do
        echo "$n"
        i=$((i+1))
        n=$((first+i*increment))
    done
fi


