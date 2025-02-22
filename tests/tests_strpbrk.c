/*
** EPITECH PROJECT, 2025
** tests_strpbrk.c
** File description:
** tests_strpbrk.c
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

static void test_strpbrk(const char *str1, const char *str2)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    char *(*my_strpbrk)(const char *str1, const char *str2) = dlsym(handle, "strpbrk");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strpbrk, NULL);
    cr_assert_eq(strpbrk(str1, str2), my_strpbrk(str1, str2));
    dlclose(handle);
}

Test(strpbrk, basic, .init = redirect_all_stdout)
{
    test_strpbrk("Hello", "leo");
}

Test(strpbrk, not_found, .init = redirect_all_stdout)
{
    test_strpbrk("Hello", "z");
}

Test(strpbrk, empty, .init = redirect_all_stdout)
{
    test_strpbrk("", "");
}

Test(strpbrk, empty_to_find, .init = redirect_all_stdout)
{
    test_strpbrk("Hello", "");
}
