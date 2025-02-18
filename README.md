# MiniLibC

## Project Description

MiniLibC is a project that reimplements several standard C library functions in assembly language.

## Functions Implemented

The following functions are implemented in assembly:

- `strlen`
- `strchr`
- `strrchr`
- `memset`
- `memcpy`
- `strcmp`
- `memmove`
- `strncmp`
- `strcasecmp`
- `strstr`
- `strpbrk`
- `strcspn`
- `ffs`
- `index`
- `rindex`
- `strfry`
- `memfrob`
- `syscall`

## Compilation

```sh
make
```

This will generate the `libasm.so` shared library.

## Usage

You can link the generated `libasm.so` library with C programs to use the implemented functions.

Here is an example of how to link and use the library :
```c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    const char *str = "Hello, World!";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    size_t (*my_strlen)(const char *) = dlsym(handle, "strlen");
    if (!my_strlen) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    printf("Length of string: %zu\n", my_strlen(str));
    dlclose(handle);
    return 0;
}
```

Compile the above program with :
```sh
gcc -o test_program test_program.c -L. -lasm
```
