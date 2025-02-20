/*
** EPITECH PROJECT, 2025
** tests_strrchr.c
** File description:
** tests_strrchr.c
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

static void test_strrchr(char *str, int c)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    char *(*my_strrchr)(const char *str, int c) = dlsym(handle, "strrchr");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strrchr, NULL);
    cr_assert_eq(strrchr(str, c), my_strrchr(str, c));
    dlclose(handle);
}

Test(strrchr, basic, .init = redirect_all_stdout)
{
    test_strrchr("Hello", 'l');
}

Test(strrchr, not_found, .init = redirect_all_stdout)
{
    test_strrchr("Hello", 'z');
}

Test(strrchr, empty, .init = redirect_all_stdout)
{
    test_strrchr("", 'z');
}
