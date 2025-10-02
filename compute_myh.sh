#!/bin/bash
#!/bin/bash

HEADER="my.h"
DEBUG=0
TMPFILE=$(mktemp)

# Check for debug flag
if [[ "$1" == "--debug" ]]; then
    DEBUG=1
fi

# Initialize header file with guards and macros if it doesn't exist or reset it
cat > "$TMPFILE" << EOF
/*
** EPITECH PROJECT, $(date +%Y)
** My Library
** File description:
** Header file for my library
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/* Useful macros */
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define UNUSED __attribute__((unused))

/* Function prototypes */
EOF

# Extract function prototypes from all .c files
find . -name "*.c" | while read -r file; do
    if [[ $DEBUG -eq 1 ]]; then
        echo "Processing $file"
    fi
    
    grep -o -E '(int|void|char|float|double|long|short|unsigned|size_t)([[:space:]]+\*?)[[:space:]]+my_[a-zA-Z0-9_]+[[:space:]]*\([^{;]*\)[[:space:]]*;' "$file" | \
    sed -E 's/[[:space:]]+/ /g' | sort -u >> "$TMPFILE"
done

# Add closing header guard
echo -e "\n#endif /* MY_H_ */" >> "$TMPFILE"

# Check if any functions were found
if [[ $DEBUG -eq 1 ]]; then
    echo "Function count: $(grep -c 'my_' "$TMPFILE")"
    echo "Generated header:"
    cat "$TMPFILE"
fi

# Replace the header with our new version
mv "$TMPFILE" "$HEADER"
chmod 644 "$HEADER"

echo "Updated $HEADER successfully"
