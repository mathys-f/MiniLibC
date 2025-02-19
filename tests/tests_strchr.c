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

static void test_strchr(char *str, int c)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *str, int c) = dlsym(handle, "strchr");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strchr, NULL);
    cr_assert_eq(strchr(str, c), my_strchr(str, c));
    dlclose(handle);
}

Test(strchr, basic, .init = redirect_all_stdout)
{
    test_strchr("Hello", 'e');
    test_strchr("World\n", '\n');
    test_strchr("Hello World\0", '\0');
}

Test(strchr, special_characters, .init = redirect_all_stdout)
{
    test_strchr("\t", '\t');
    test_strchr("\r", '\r');
    test_strchr("\v", '\v');
    test_strchr("\b", '\b');
    test_strchr("\a", '\a');
    test_strchr("\\", '\\');
    test_strchr("\"", '\"');
    test_strchr("\'", '\'');
}

Test(strchr, long_string, .init = redirect_all_stdout)
{
    char long_string[1001];

    memset(long_string, 'a', 1000);
    long_string[1000] = '\0';
    test_strchr(long_string, 'a');
}
