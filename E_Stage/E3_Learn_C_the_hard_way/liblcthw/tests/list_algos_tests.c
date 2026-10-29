#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define NUM_VALUES 5
#define MAX_N 10000

int compare_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int numbers[MAX_N];

void init_test_data(void)
{
    srand(261029);
    for(int i = 0; i < MAX_N; i++) {
        numbers[i] = rand() % 1000;
    }
}

List *create_test_list(int n)
{
    if(n < 0 || n > MAX_N) {
        return NULL;
    }

    List *list = List_create();
    if(list == NULL) return NULL;

    for(int i = 0; i < n; i++) {
        List_push(list, &numbers[i]);
    }

    return list;
}

List *create_words()
{
    int i = 0;
    List *words = List_create();

    for(i = 0; i < NUM_VALUES; i++) {
        List_push(words, values[i]);
    }

    return words;
}

int is_sorted(List *words)
{
    LIST_FOREACH(words, first, next, cur) {
        if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
            debug("%s %s", (char *)cur->value, (char *)cur->next->value);
            return 0;
        }
    }

    return 1;
}

char *test_bubble_sort()
{
    List *words = create_words();

    // should work on a list that needs sorting
    int rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort failed.");
    mu_assert(is_sorted(words), "Words are not sorted after bubble sort.");

    // should work on an already sorted list
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort of already sorted failed.");
    mu_assert(is_sorted(words), "Words should be sort if already bubble sorted.");

    List_destroy(words);

    // should work on an empty list
    words = List_create();
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort failed on empty list.");
    mu_assert(is_sorted(words), "Words should be sorted if empty.");

    List_destroy(words);

    return NULL;
}

char *test_merge_sort()
{
    List *words = create_words();

    // should work on a list that needs sorting
    List *res = List_merge_sort(words, (List_compare)strcmp);
    mu_assert(is_sorted(res), "Words are not sorted after merge sort.");

    List *res2 = List_merge_sort(res, (List_compare)strcmp);
    mu_assert(is_sorted(res2), "Should still be sorted after merge sort.");
    
    if(res2 != res) List_destroy(res2);
    if(res != words) List_destroy(res);

    List_destroy(words);
    return NULL;
}

char *test_bottom_up_sort()
{
    int data[] = {4, 2, 7, 1, 3};

    List *list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    for(int i = 0; i < 5; i++) {
        List_push(list, &data[i]);
    }

    int rc = List_merge_sort_bottom_up(list, compare_int);

    mu_assert(rc == 0, "Bottom-up merge sort failed.");
    mu_assert(list->count == 5, "Wrong count.");
    mu_assert(List_check(list), "Invalid list structure.");
    mu_assert(List_is_sorted(list, compare_int) == 1, "List is not sorted.");

    List_destroy(list);
    return NULL;
}

char* test_performance()
{
    int sizes[] = {10, 100, 500, 1000, 5000, 10000};
    int num_size = sizeof(sizes) / sizeof(sizes[0]);
    init_test_data();

    for(int i = 0; i < num_size; i++) {
        int n = sizes[i];
        clock_t total1 = 0;
        clock_t total2 = 0;
        clock_t total3 = 0;
        clock_t total4 = 0;
        int runs1 = 0;
        int runs2 = 0;
        int runs3 = 0;
        int runs4 = 0;

        while((double)total1 / CLOCKS_PER_SEC < 5.0) {
            List *list1 = create_test_list(sizes[i]);
            mu_assert(list1 != NULL, "Failed to create list.");

            clock_t start = clock();
            int rc = List_bubble_sort(list1, compare_int);
            clock_t end = clock();
            total1 += end - start;
            runs1++;

            mu_assert(rc == 0, "Bubble sort failed.");
            mu_assert(List_is_sorted(list1, compare_int) == 1, "Bubble sort result is not sorted.");
            
            List_destroy(list1);
        }

        while((double)total2 / CLOCKS_PER_SEC < 5.0) {
            List *list2 = create_test_list(sizes[i]);
            mu_assert(list2 != NULL, "Failed to create list.");

            clock_t start = clock();
            List *result = List_merge_sort(list2, compare_int);
            clock_t end = clock();
            total2 += end - start;
            runs2++;

            mu_assert(result != NULL, "Merge sort failed.");
            mu_assert(List_is_sorted(result, compare_int) == 1, "Merge sort result is not sorted.");

            if(result != list2) {
                List_destroy(list2);
            }
            List_destroy(result);
        }

        while((double)total3 / CLOCKS_PER_SEC < 5.0) {
            List *list3 = List_create();
            mu_assert(list3 != NULL, "Failed to create list.");

            clock_t start = clock();
            int rc = 0;
            for(int j = 0; j < n; j++) {
                rc = List_insert_sorted(list3, &numbers[j], compare_int);
                if(rc != 0) break;
            }

            clock_t end = clock();
            total3 += end - start;
            runs3++;

            mu_assert(rc == 0, "Sorted insert failed.");
            mu_assert(list3->count == n, "Wrong count.");
            mu_assert(List_check(list3), "Invalid list structure.");
            mu_assert(List_is_sorted(list3, compare_int) == 1, "Sorted insert result is not sorted.");

            List_destroy(list3);
        }

        while((double)total4 / CLOCKS_PER_SEC < 5.0) {
            List *list4 = create_test_list(n);
            mu_assert(list4 != NULL, "Failed to create list.");

            clock_t start = clock();
            int rc = List_merge_sort_bottom_up(list4, compare_int);
            clock_t end = clock();

            total4 += end - start;
            runs4++;

            mu_assert(rc == 0, "Bottom-up merge sort failed.");
            mu_assert(list4->count == n, "Wrong count.");
            mu_assert(List_check(list4), "Invalid list structure.");
            mu_assert(List_is_sorted(list4, compare_int) == 1, "Bottom-up merge sort result is not sorted.");

            List_destroy(list4);
        }

        double seconds1 = (double)total1 / CLOCKS_PER_SEC;
        double average1 = seconds1 / runs1;
        double seconds2 = (double)total2 / CLOCKS_PER_SEC;
        double average2 = seconds2 / runs2;
        double seconds3 = (double)total3 / CLOCKS_PER_SEC;
        double average3 = seconds3 / runs3;
        double seconds4 = (double)total4 / CLOCKS_PER_SEC;
        double average4 = seconds4 / runs4;

        printf("Total time of bubble in size of %d: %.6f s\n", sizes[i], seconds1);
        printf("Iterations of bubble in size of %d: %d\n", sizes[i], runs1);
        printf("Average time of bubble in size of %d: %.9f s\n", sizes[i], average1);
        printf("------------------------------------------\n");
        printf("Total time of merge in size of %d: %.6f s\n", sizes[i], seconds2);
        printf("Iterations of merge in size of %d: %d\n", sizes[i], runs2);
        printf("Average time of merge in size of %d: %.9f s\n", sizes[i], average2);
        printf("------------------------------------------\n");
        printf("Total time of sorted insert in size of %d: %.6f s\n", n, seconds3);
        printf("Iterations of sorted insert in size of %d: %d\n", n, runs3);
        printf("Average time of sorted insert in size of %d: %.9f s\n", n, average3);
        printf("------------------------------------------\n");
        printf("Total time of bottom-up merge in size of %d: %.6f s\n", n, seconds4);
        printf("Iterations of bottom-up merge in size of %d: %d\n", n, runs4);
        printf("Average time of bottom-up merge in size of %d: %.9f s\n", n, average4);
        printf("Speedup of bottom-up over top-down: %.2f\n", average2 / average4);
        printf("==========================================\n");
    }

    return NULL;
}

char *test_insert_sorted()
{
    List *list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    int values[] = {3, 1, 5, 2, 4};

    for(int i = 0; i < 5; i++) {
        int rc = List_insert_sorted(list, &values[i], compare_int);

        mu_assert(rc == 0, "Insert sorted failed.");
        mu_assert(list->count == i + 1, "Wrong count.");
        mu_assert(List_check(list), "Invalid list structure.");
        mu_assert(List_is_sorted(list, compare_int) == 1,
                  "List is not sorted.");
    }

    List_destroy(list);
    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);
    mu_run_test(test_performance);
    mu_run_test(test_insert_sorted);
    mu_run_test(test_bottom_up_sort);
    return NULL;
}

RUN_TESTS(all_tests);