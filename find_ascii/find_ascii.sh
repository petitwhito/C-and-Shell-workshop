#!/bin/bash

ls "$1" | while read name
    do
        var="$(file "$1/$name")"
        res=$(echo "$var" | grep -o 'ASCII')
        if [ -n "$res" ]; then
            echo "$var"
        fi
   done

