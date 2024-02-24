#!/bin/sh

sed -ne '/^[a-zA-Z0-9].*[()]$/p' "$1" | sed 's/$/;/'
