#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data);


int main(void)
{
    int rc = 0;
    char *lib_file = "./build/libex29.so";

    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL, "Failed to open library: %s", dlerror());

    // Test print_a_message
    lib_function func = dlsym(lib, "print_a_message");
    check(func != NULL, "Failed to find print_a_message: %s", dlerror());

    rc = func("Hello World");
    check(rc == 0, "Function %s return %d for data: %s", "print_a_message", rc, "Hello World");

    // Test uppercase
    func = dlsym(lib, "uppercase");
    check(func != NULL, "Failed to find uppercase: %s", dlerror());

    rc = func("hello");
    check(rc == 0, "Function %s return %d for data: %s", "uppercase", rc, "hello");

    // Test lowercase
    func = dlsym(lib, "lowercase");
    check(func != NULL, "Failed to find lowercase: %s", dlerror());

    rc = func("WORLD");
    check(rc == 0, "Function %s return %d for data: %s", "lowercase", rc, "WORLD");

    // close lib
    rc = dlclose(lib);
    lib = NULL;
    check(rc == 0, "Failed to close %s", lib_file);

    return 0;

error:
    if(lib != NULL) {
        dlclose(lib);
    }
    return 1;
}