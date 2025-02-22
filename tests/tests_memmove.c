/*
** EPITECH PROJECT, 2025
** tests_memmove.c
** File description:
** tests_memmove.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <dlfcn.h>
#include <string.h>
#include <stddef.h>

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void test_memmove(void *dest, const void *src, size_t n)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }
    void *(*my_memmove)(void *dest, const void *src, size_t n) = dlsym(handle, "memmove");
    if (!my_memmove) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        return;
    }
    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_memmove, NULL);
    my_memmove(dest, src, n);
    dlclose(handle);
}

Test(memmove, basic_test, .init = redirect_all_stdout)
{
    char dest[10] = "Hello";
    char src[10] = "World";
    size_t n = 5;

    test_memmove(dest, src, n);
    cr_assert_str_eq(dest, "World");
}

Test(memmove, partial_fill, .init = redirect_all_stdout)
{
    char dest[10] = "Hello";
    char src[10] = "World";
    size_t n = 3;

    test_memmove(dest, src, n);
    cr_assert_str_eq(dest, "Worlo");
}

Test(memmove, zero_length, .init = redirect_all_stdout)
{
    char dest[10] = "Hello";
    char src[10] = "World";
    size_t n = 0;

    test_memmove(dest, src, n);
    cr_assert_str_eq(dest, "Hello");
}

Test(memmove, overlap, .init = redirect_all_stdout)
{
    char dest[10] = "Hello";
    char src[10] = "World";
    size_t n = 5;

    test_memmove(dest, src, n);
    cr_assert_str_eq(dest, "World");
}
