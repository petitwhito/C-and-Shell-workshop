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

line=$(tail -n "+$line_number" "$csv_file" | head -n 1)

if [ -z "$line" ]; then
    exit 1
fi

column2=$(echo "$line" | cut -d ';' -f 2)
column3=$(echo "$line" | cut -d ';' -f 3)

echo "$column2 is $column3"
