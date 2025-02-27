#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3-1: Write a binary search algorithm that only does one comparison within the loop
// (may have to do additional comparisons outside loop). Measure difference in run time.

// The single comparison algorithm is a bit faster when working with large arrays, but
// time complexity for both is the same, so will depend on particulars of environment.

int bin_search_double_comparison(int target, int arr[], int arr_length) {
    int l = 0, r = arr_length - 1;

    clock_t start = clock();
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (target < arr[m]) {
            r = m - 1;
        } else if (target > arr[m]) {
            l = m + 1;
        } else {
            return m; // return idx of match
        }
    }
    clock_t end = clock();

    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Double comparison bin search time: %f seconds\n", time_elapsed);
    return -1; // no match
}

int bin_search_single_comparison(int target, int arr[], int arr_length) {
    int l = 0, r = arr_length - 1;
    int m = l + (r - l) / 2;

    clock_t start = clock();
    while (l <= r) {
        if (target < arr[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
        m = l + (r - l) / 2;
    }
    clock_t end = clock();

    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Single comparison bin search time: %f seconds\n", time_elapsed);

    if (arr[m] == target) {
        return m;
    }
    return -1;
}

int main() {
    int arr[999999] = {0};
    int target = 54321;

    for (int i = 0; i < 999999; i++) {
        if (i != target) {
            arr[i] = i;
        }
    }

    int arr_size = sizeof(arr) / sizeof(int);

    bin_search_double_comparison(target, arr, arr_size); // no result. entire array searched
    bin_search_single_comparison(target, arr, arr_size); // no result. entire array searched
}
