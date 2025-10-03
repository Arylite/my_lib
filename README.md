# Libmy - Epitech Tek 1 Project

## The Idea

When I joined Epitech, I was told not to use any basic functions from the standard C library (libc, glibc, or similar). As a result, I decided to create my own library, called **Libmy**, which reimplements essential functions such as string manipulation, memory management, and input/output operations.

## Purpose

The main goal of this project is to gain a deeper understanding of how fundamental C functions work under the hood. By writing these functions myself, I improve my programming skills and learn best practices for writing efficient and reliable code.

## Features

- Custom implementations of standard functions like `my_strlen`, `my_strcpy`, `my_putchar`, and more.
- Modular code structure for easy maintenance and extension.
- Comprehensive documentation and comments for each function.

## Usage

To use Libmy in your own projects, simply include the header file and link the compiled library. Example:

```c
#include "my.h"

int main(void) {
    my_putstr("Hello, Libmy!\n");
    return 0;
}
```

## License

This project is released under the MIT License. Feel free to use, modify, and share it as you wish.

---

> **DANGER! DO NOT USE THIS LIBRARY FOR ANY EPITECH PROJECT!**
>
> Using Libmy in Epitech assignments is strictly forbidden and may result in severe academic penalties, including automatic failure or disciplinary action. This library is for personal learning and experimentation only. **You have been warned!**

---