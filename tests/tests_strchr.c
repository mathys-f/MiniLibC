/*
** EPITECH PROJECT, 2025
** tests_strchr.c
** File description:
** tests_strchr.c
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
    test_strchr("Hello", 'l');
}

Test(strchr, not_found, .init = redirect_all_stdout)
{
    test_strchr("Hello", 'z');
}

Test(strchr, empty, .init = redirect_all_stdout)
{
    test_strchr("", 'z');
}

Test(strchr, null_term, .init = redirect_all_stdout)
{
    test_strchr("Hello\0", '\0');
}
