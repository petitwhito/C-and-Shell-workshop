#!/bin/sh

if [ 2 -ne $# ]; then
    echo "Usage: ./hcf.sh num1 num2"
    exit 1

elif [ $2 -eq 0 ]; then
    echo "Exception: division by 0"
    exit 2

elif [ $1 -eq $2 ]; then
    echo $1

elif [ $1 -eq 0 ]; then
    echo $2

else
    dev=1
    res=1
    while [ $dev -ne $1 ] && [ $dev -ne $2 ]; do
       if [ $(($1%dev)) -eq 0 ] && [ $(($2%dev)) -eq 0 ]; then
           res=$dev
       fi
       dev=$((dev+1))
    done
    echo $res
fi
