#include "minunit.h"
#include <template.h>

char *test_add()
{
    mu_assert(template_add(2, 3) == 5, "template_add failed.");

    return NULL;
}


char *all_tests() {
    mu_suite_start();

    mu_run_test(test_add);

    return NULL;
}

RUN_TESTS(all_tests);