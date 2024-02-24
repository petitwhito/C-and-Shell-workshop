#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1

else
    i=$1
    res=1
    while [ $i -ne 0 ]; do
        res=$((res*i))
        i=$((i-1))
    done
    echo $res
fi
