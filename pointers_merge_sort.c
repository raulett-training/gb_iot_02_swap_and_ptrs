//
// Created by raulett on 05.07.2023.
//
#include <malloc.h>
#include <stdio.h>
#include "pointers_merge_sort.h"
#define DEBUG 0
size_t merge_call_counter = 1;
size_t pointers_merge_sort_counter = 1;

int** pointers_merge_sort(int** ptrs_arr, size_t ptrs_arr_size){
#if DEBUG
    printf("pointers_merge_sort call, #%zu\n", pointers_merge_sort_counter);
    printf("Input array 1\n");
    for (int a=0; a<ptrs_arr_size; a++){
        printf("%d, ", *ptrs_arr[a]);
    }
    printf("\n");
#endif
    if (ptrs_arr_size < 2){
        return ptrs_arr;
    } else{
        size_t left_size = ptrs_arr_size/2 + ptrs_arr_size%2;
        int** lef_subarray = pointers_merge_sort(ptrs_arr, left_size);
        int** right_subarray = pointers_merge_sort(ptrs_arr+left_size, ptrs_arr_size-left_size);
        return merge_sorted(lef_subarray, left_size, right_subarray, ptrs_arr_size - left_size);;
    }
}

int** merge_sorted(int** first_arr_sorted, size_t first_arr_size,
                   int** second_arr_sorted, size_t second_arr_size){
    size_t i = 0, j = 0;
#if DEBUG
    printf("merge sort call #%zu\n", merge_call_counter);
    printf("merge call for 2 substrings\n");
    printf("first substring: ");
    for (int a=0; a<first_arr_size; a++){
        printf("%d, ", *first_arr_sorted[a]);
    }
    printf("\n");
    printf("second substring: ");
    for (int a=0; a<second_arr_size; a++){
        printf("%d, ", *second_arr_sorted[a]);
    }
    printf("\n");
#endif
    int** temp_result_arr;
    temp_result_arr = malloc(sizeof(int*) * (first_arr_size + second_arr_size));

    while((i<first_arr_size) && (j < second_arr_size)) {
        if (*first_arr_sorted[i] > *second_arr_sorted[j]) {
            temp_result_arr[i + j] = second_arr_sorted[j];
            j++;

        } else {
            temp_result_arr[i + j] = first_arr_sorted[i];
            i++;

        }
    }
    if (i < first_arr_size){
        for(i;i<first_arr_size;i++){
            temp_result_arr[i + j] = first_arr_sorted[i];
        }
    } else{
        for(j;j<second_arr_size;j++){
            temp_result_arr[i + j] = second_arr_sorted[j];
        }
    }
#if DEBUG
    printf("write len i+j = %zu, Total len first_arr_size + second_arr_size = %zu\n", i + j, first_arr_size + second_arr_size);
#endif
    for(size_t k = 0; k < first_arr_size + second_arr_size; k++){
        first_arr_sorted[k] = temp_result_arr[k];
    }
    free(temp_result_arr);
#if DEBUG
    printf("result array: ");
    for (int g=0; g<first_arr_size+second_arr_size; g++){
        printf("%d, ", *first_arr_sorted[g]);
    }
    merge_call_counter++;
    printf("\n");
#endif
    return first_arr_sorted;
}
