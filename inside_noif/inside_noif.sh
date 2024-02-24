#!/bin/sh

[ 1 -ne $# ] && echo "Sorry, expected 1 argument but $# were passed" && exit 1 ||
    {
        test ! -f $1 && echo "$1:" && echo "\tis not a valid file" && exit 2 ||
            {
                cat $1
            }
    }

