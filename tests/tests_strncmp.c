/*
** EPITECH PROJECT, 2025
** tests_strncmp.c
** File description:
** tests_strncmp.c
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

static void test_strncmp(const char *str1, const char *str2, size_t n)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    size_t (*my_strncmp)(const char *str1, const char *str2, size_t n) = dlsym(handle, "strncmp");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strncmp, NULL);
    cr_assert_eq(strncmp(str1, str2, n), my_strncmp(str1, str2, n));
    dlclose(handle);
}

Test(strncmp, eq_return, .init = redirect_all_stdout)
{
    test_strncmp("", "", 0);
    test_strncmp("Hello", "Hello", 5);
    test_strncmp("World\n", "World\n", 6);
    test_strncmp("Hello World\0", "Hello World\0", 12);
}

Test(strncmp, neg_return, .init = redirect_all_stdout)
{
    test_strncmp("Hello", "World", 5);
    test_strncmp("World", "Hello", 5);
    test_strncmp("Hello", "World\n", 6);
    test_strncmp("World\n", "Hello", 6);
    test_strncmp("Hello", "World\0", 12);
    test_strncmp("World\0", "Hello", 12);
}

Test(strncmp, pos_return, .init = redirect_all_stdout)
{
    test_strncmp("Hello", "", 0);
    test_strncmp("", "Hello", 0);
    test_strncmp("Hello", "World ", 6);
    test_strncmp("World ", "Hello", 6);
    test_strncmp("Hello", "World\0", 6);
    test_strncmp("World\0", "Hello", 6);
}
