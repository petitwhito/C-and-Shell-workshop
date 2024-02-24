#!bin/sh

path="/etc/passwd"
var=$(cut -d ':' -f 3 $path | sort -r -u -n)
for line in $var; do
    echo $line
done
