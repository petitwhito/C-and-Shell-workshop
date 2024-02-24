#!/bin/sh

ext=txt
if [ $# -ne 0 ]; then
    ext=$1
fi

for i in *.$ext; do
    rm $i
done
