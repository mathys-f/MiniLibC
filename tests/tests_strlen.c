/*
** EPITECH PROJECT, 2025
** tests_strlen.c
** File description:
** tests_strlen.c
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

static void test_strlen(char *str)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    size_t (*my_strlen)(const char *str) = dlsym(handle, "strlen");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strlen, NULL);
    cr_assert_eq(strlen(str), my_strlen(str));
    dlclose(handle);
}

Test(strlen, basic, .init = redirect_all_stdout)
{
    test_strlen("");
    test_strlen("Hello");
    test_strlen("World\n");
    test_strlen("Hello World\0");
}

Test(strlen, special_characters, .init = redirect_all_stdout)
{
    test_strlen("\t");
    test_strlen("\r");
    test_strlen("\v");
    test_strlen("\b");
    test_strlen("\a");
    test_strlen("\\");
    test_strlen("\"");
    test_strlen("\'");
}

Test(strlen, long_string, .init = redirect_all_stdout)
{
    char long_string[1001];

    memset(long_string, 'a', 1000);
    long_string[1000] = '\0';
    test_strlen(long_string);
}
