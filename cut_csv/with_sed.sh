#!/bin/sh

if [ "$#" -ne 2 ]; then
    exit 1
fi

csv_file="$1"
line_number="$2"

if [ ! -f "$csv_file" ]; then
    exit 1
fi

case "$line_number" in
    ''|*[!0-9]*) exit 1;;
    *) ;;
esac

if [ "$line_number" -lt 0 ]; then
    exit 1
fi

line_count=$(wc -l < "$csv_file")

if [ $line_number -gt $line_count ] || [ "$line_number" -lt 1 ]; then
    exit 1
fi

sed -n "${line_number}p" "$csv_file" | {
    read -r line
    if [ -z "$line" ]; then
        exit 1
    fi

    column2=$(echo "$line" | sed 's/[^;]*;\([^;]*\);.*/\1/')
    column3=$(echo "$line" | sed 's/[^;]*;[^;]*;\(.*\);[^;]*;/\1/')

    echo "$column2 is $column3"
}

exit 0
