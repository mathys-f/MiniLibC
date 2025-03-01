/*
** EPITECH PROJECT, 2025
** tests_strcspn.c
** File description:
** tests_strcspn.c
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

static void test_strcspn(const char *str1, const char *str2)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    size_t(*my_strcspn)(const char *str1, const char *str2) = dlsym(handle, "strcspn");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strcspn, NULL);

    size_t ret = my_strcspn(str1, str2);
    size_t expected = strcspn(str1, str2);
    cr_assert_eq(ret, expected);

    dlclose(handle);
}

Test(strcspn, basic, .init = redirect_all_stdout)
{
    test_strcspn("Hello", "leo");
}

Test(strcspn, not_found, .init = redirect_all_stdout)
{
    test_strcspn("Hello", "z");
}

Test(strcspn, empty, .init = redirect_all_stdout)
{
    test_strcspn("", "");
}

Test(strcspn, empty_to_find, .init = redirect_all_stdout)
{
    test_strcspn("Hello", "");
}
