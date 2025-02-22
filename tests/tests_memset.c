/*
** EPITECH PROJECT, 2025
** tests_memset.c
** File description:
** tests_memset.c
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

static void test_memset(void *s, int c, size_t n)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    void *(*my_memset)(void *s, int c, size_t n) = dlsym(handle, "memset");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_memset, NULL);
    my_memset(s, c, n);
    dlclose(handle);
}


Test(memset, basic_test, .init = redirect_all_stdout)
{
    char buffer[10];

    test_memset(buffer, 'A', 10);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(buffer[i], 'A');
}

Test(memset, partial_fill, .init = redirect_all_stdout)
{
    char buffer[10] = {0};

    test_memset(buffer, 'B', 5);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(buffer[i], 'B');
    for (int i = 5; i < 10; i++)
        cr_assert_eq(buffer[i], 0);
}

Test(memset, zero_length, .init = redirect_all_stdout)
{
    char buffer[10] = {0};

    test_memset(buffer, 'C', 0);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(buffer[i], 0);
}

Test(memset, large_fill, .init = redirect_all_stdout)
{
    char buffer[1000];

    test_memset(buffer, 'D', 1000);
    for (int i = 0; i < 1000; i++)
        cr_assert_eq(buffer[i], 'D');
}
