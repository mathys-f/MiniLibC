/*
** EPITECH PROJECT, 2025
** tests_memcpy.c
** File description:
** tests_memcpy.c
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

static void test_memcpy(void *dest, void *src, size_t n)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    void *(*my_memcpy)(void *dest, void *src, size_t n) = dlsym(handle, "memcpy");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_memcpy, NULL);
    my_memcpy(dest, src, n);
    dlclose(handle);
}

Test(memcpy, basic_test, .init = redirect_all_stdout)
{
    char buffer[10] = {0};
    char buffer2[10] = {0};

    memset(buffer, 'A', 10);
    test_memcpy(buffer2, buffer, 10);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(buffer2[i], 'A');
}

Test(memcpy, partial_fill, .init = redirect_all_stdout)
{
    char buffer[10] = {0};
    char buffer2[10] = {0};

    memset(buffer, 'B', 5);
    test_memcpy(buffer2, buffer, 5);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(buffer2[i], 'B');
    for (int i = 5; i < 10; i++)
        cr_assert_eq(buffer2[i], 0);
}

Test(memcpy, zero_length, .init = redirect_all_stdout)
{
    char buffer[10] = {0};
    char buffer2[10] = {0};

    memset(buffer, 'C', 0);
    test_memcpy(buffer2, buffer, 0);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(buffer2[i], 0);
}

Test(memcpy, large_fill, .init = redirect_all_stdout)
{
    char buffer[1000];
    char buffer2[1000];

    memset(buffer, 'D', 1000);
    test_memcpy(buffer2, buffer, 1000);
    for (int i = 0; i < 1000; i++)
        cr_assert_eq(buffer2[i], 'D');
}
