#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

#define N 100

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");
    List_check(list);

    return NULL;
}

char *test_destroy()
{
    List_check(list);
    List_clear_destroy(list);

    return NULL;

}

char *test_push_pop()
{
    List_check(list);
    List_push(list, test1);
    List_check(list);
    mu_assert(List_last(list) == test1, "Wrong last value.");

    List_push(list, test2);
    List_check(list);
    mu_assert(List_last(list) == test2, "Wrong last value");

    List_push(list, test3);
    List_check(list);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on push.");

    char *val = List_pop(list);
    List_check(list);
    mu_assert(val == test3, "Wrong value on pop.");

    val = List_pop(list);
    List_check(list);
    mu_assert(val == test2, "Wrong value on pop.");

    val = List_pop(list);
    List_check(list);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(List_count(list) == 0, "Wrong count after pop.");

    return NULL;
}

char *test_unshift()
{
    List_check(list);
    List_unshift(list, test1);
    List_check(list);
    mu_assert(List_first(list) == test1, "Wrong first value.");

    List_unshift(list, test2);
    List_check(list);
    mu_assert(List_first(list) == test2, "Wrong first value");

    List_unshift(list, test3);
    List_check(list);
    mu_assert(List_first(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on unshift.");

    return NULL;
}

char *test_remove()
{
    // we only need to test the middle remove case since push/shift
    // already tests the other cases
    List_check(list);
    char *val = List_remove(list, list->first->next);
    List_check(list);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(List_count(list) == 2, "Wrong count after remove.");
    mu_assert(List_first(list) == test3, "Wrong first after remove.");
    mu_assert(List_last(list) == test1, "Wrong last after remove.");

    return NULL;
}


char *test_shift()
{
    List_check(list);
    mu_assert(List_count(list) != 0, "Wrong count before shift.");

    char *val = List_shift(list);
    List_check(list);
    mu_assert(val == test3, "Wrong value on shift.");

    val = List_shift(list);
    List_check(list);
    mu_assert(val == test1, "Wrong value on shift.");
    mu_assert(List_count(list) == 0, "Wrong count after shift.");

    return NULL;
}

char *test_copy()
{
    List *src = List_create();
    mu_assert(src != NULL, "Failed to create list.");

    List_push(src, test1);
    List_push(src, test2);
    List_push(src, test3);

    List *copy = List_copy(src);

    mu_assert(copy != NULL, "Failed to copy list.");
    List_check(copy);
    mu_assert(copy->count == 3, "Wrong count after copy.");
    mu_assert(copy != src, "Copy is src actually");
    mu_assert(copy->first != src->first, "Copy shares nodes with src.");
    mu_assert(copy->first->value == src->first->value, "Not shallow copy");
    mu_assert(  List_first(copy) == test1 &&
                List_last(copy) == test3 &&
                copy->first->next->value == test2,
                "Wrong copy value.");

    List_destroy(copy);
    List_destroy(src);

    return NULL;
}

char *test_concat()
{
    List *dest = List_create();
    List *src = List_create();

    mu_assert(dest != NULL && src != NULL, "Failed to create list.");

    List_push(dest, test1);
    List_push(dest, test2);
    List_push(src, test3);

    ListNode *old_last = dest->last;
    ListNode *old_first = src->first;

    List_concat(src, dest);

    mu_assert(old_last->next == old_first, "Wrong next pointer.");
    mu_assert(old_first->prev == old_last, "Wrong prev pointer.");
    mu_assert(dest->count == 3, "Wrong count after concat.");
    mu_assert(src->count == 0, "Src not cleared.");
    mu_assert(  List_first(dest) == test1 &&
                List_last(dest) == test3 &&
                dest->first->next->value == test2,
                "Wrong concat value.");
    mu_assert(src->first == NULL && src->last == NULL, "Src not cleared.");

    List_check(dest);
    List_check(src);

    List_destroy(dest);
    List_destroy(src);

    return NULL;
}

char *test_split()
{
    List *list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    List_push(list, test1);
    List_push(list, test2);
    List_push(list, test3);

    List *right = List_split(list, 2);
    mu_assert(right != NULL, "Failed to split list.");

    mu_assert(list->count == 2, "Wrong count of left.");
    mu_assert(right->count == 1, "Wrong count of right.");
    mu_assert(  List_first(list) == test1 &&
                List_last(list) == test2,
                "Wrong left value.");
    mu_assert(  List_first(right) == test3 &&
                List_last(right) == test3,
                "Wrong right value.");
    mu_assert(list->last->next == NULL, "Wrong left tail.");
    mu_assert(right->first->prev == NULL, "Wrong right head.");

    List_check(list);
    List_check(right);

    List_destroy(list);
    List_destroy(right);

    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_unshift);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_destroy);
    mu_run_test(test_copy);
    mu_run_test(test_concat);
    mu_run_test(test_split);

    return NULL;
}

RUN_TESTS(all_tests);