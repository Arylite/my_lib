#!/bin/sh
echo "Building libmy..."
cd "$(dirname "$0")" || exit 1 # need to go to the script's directory bc i dunno if marvin is smart enought to do it himself
rm -f *.o libmy.a
clang -c -Wno-implicit-function-declaration *.c -Wint-to-void-pointer-cast
ar rc libmy.a *.o
rm -f *.o
echo "Done."
