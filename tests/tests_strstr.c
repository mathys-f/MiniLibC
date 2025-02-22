/*
** EPITECH PROJECT, 2025
** tests_strstr.c
** File description:
** tests_strstr.c
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

static void test_strstr(const char *str, const char *to_find)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    char *(*my_strstr)(const char *str, const char *to_find) = dlsym(handle, "strstr");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strstr, NULL);
    cr_assert_eq(strstr(str, to_find), my_strstr(str, to_find));
    dlclose(handle);
}

Test(strstr, basic, .init = redirect_all_stdout)
{
    test_strstr("Hello", "ell");
}

Test(strstr, not_found, .init = redirect_all_stdout)
{
    test_strstr("Hello", "z");
}

Test(strstr, empty, .init = redirect_all_stdout)
{
    test_strstr("", "z");
}

Test(strstr, empty_to_find, .init = redirect_all_stdout)
{
    test_strstr("Hello", "");
}
