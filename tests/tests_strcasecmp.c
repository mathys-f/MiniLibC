/*
** EPITECH PROJECT, 2025
** tests_strcasecmp.c
** File description:
** tests_strcasecmp.c
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

static void test_strcasecmp(const char *str1, const char *str2)
{
    void *handle = dlopen("libasm.so", RTLD_LAZY);
    size_t (*my_strcasecmp)(const char *str1, const char *str2) = dlsym(handle, "strcasecmp");

    cr_assert_neq(handle, NULL);
    cr_assert_neq(my_strcasecmp, NULL);
    cr_assert_eq(strcasecmp(str1, str2), my_strcasecmp(str1, str2));
    dlclose(handle);
}

Test(strcasecmp, eq_return, .init = redirect_all_stdout)
{
    test_strcasecmp("", "");
    test_strcasecmp("HeLlo", "HellO");
    test_strcasecmp("world\n", "WorLd\n");
    test_strcasecmp("HEllo WoRld\0", "hello WorLd\0");
}

Test(strcasecmp, neg_return, .init = redirect_all_stdout)
{
    test_strcasecmp("Hello", "World");
    test_strcasecmp("World", "Hello");
    test_strcasecmp("Hello", "World\n");
    test_strcasecmp("World\n", "Hello");
    test_strcasecmp("Hello", "World\0");
    test_strcasecmp("World\0", "Hello");
}

Test(strcasecmp, pos_return, .init = redirect_all_stdout)
{
    test_strcasecmp("Hello", "Hello");
    test_strcasecmp("World", "World");
    test_strcasecmp("Hello\n", "Hello\n");
    test_strcasecmp("World\n", "World\n");
    test_strcasecmp("Hello\0", "Hello\0");
    test_strcasecmp("World\0", "World\0");
}
