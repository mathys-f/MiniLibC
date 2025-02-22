/*
** EPITECH PROJECT, 2025
** tests_strcmp.c
** File description:
** tests_strcmp.c
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

static void test_strcmp(const char *str1, const char *str2)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    size_t (*my_strcmp)(const char *str1, const char *str2) = dlsym(handle, "strcmp");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strcmp, NULL);
    cr_assert_eq(strcmp(str1, str2), my_strcmp(str1, str2));
    dlclose(handle);
}

Test(strcmp, eq_return, .init = redirect_all_stdout)
{
    test_strcmp("", "");
    test_strcmp("Hello", "Hello");
    test_strcmp("World\n", "World\n");
    test_strcmp("Hello World\0", "Hello World\0");
}

Test(strcmp, neg_return, .init = redirect_all_stdout)
{
    test_strcmp("Hello", "World");
    test_strcmp("World", "Hello");
    test_strcmp("Hello", "World\n");
    test_strcmp("World\n", "Hello");
    test_strcmp("Hello", "World\0");
    test_strcmp("World\0", "Hello");
}

Test(strcmp, pos_return, .init = redirect_all_stdout)
{
    test_strcmp("Hello", "");
    test_strcmp("", "Hello");
    test_strcmp("Hello", "World ");
    test_strcmp("World ", "Hello");
    test_strcmp("Hello", "World\0");
    test_strcmp("World\0", "Hello");
}
