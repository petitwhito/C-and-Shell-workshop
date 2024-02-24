#!/bin/sh

FILENAME=default
NUMBER=1
EXTENSION=txt

f=0
n=0
e=0


for i in "$@"; do
        if [ $f -eq 1 ]; then
            FILENAME="$i"
            f=0

        elif [ $n -eq 1 ]; then
            NUMBER="$i"
            n=0

        elif [ $e -eq 1 ]; then
            EXTENSION="$i"
            e=0
        else
            if [ "$i" = "--filename" ] || [ "$i" = "-f" ]; then
                f=1
            elif [ "$i" = "--number" ] || [ "$i" = "-n" ]; then
                n=1
            elif [ "$i" = "--extension" ] || [ "$i" = "-e" ]; then
                e=1
            else
                exit 1
            fi
        fi
done

for i in $(seq 1 $NUMBER); do
    touch -- "$FILENAME-$i.$EXTENSION"
done


