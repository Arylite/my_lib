#!/bin/sh
set -e
echo "Building libmy..."
cd "$(dirname "$0")"
SRCS=$(find . -name "*.c" ! -name "build.sh")
rm -f *.o libmy.a
epiclang -c $SRCS
ar rcs libmy.a *.o
rm -f *.o
echo "Done."
cd - > /dev/null