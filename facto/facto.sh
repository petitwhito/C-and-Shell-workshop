#!/bin/sh

if [ "$#" -ne 1 ]; then
        exit 1
fi

facto() {
    var=1
    keep=$1
    while [ $keep -gt 0 ]; do
        var=$((var*keep))
        keep=$((keep-1))
    done
    echo $var
}

echo $(facto $1)
