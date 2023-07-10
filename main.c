#include <stdio.h>
#include <malloc.h>
#include "swap.h"
#include "make_ptrs_array.h"
#include "pointers_merge_sort.h"

#define ARR_SIZE 20

int main() {
    /* Реализуйте функцию Swap, которая принимает два указателя и обменивает местами значения, на которые указывают
     * эти указатели (нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).
     * */
    printf("-------task 1 swap function test begin-------\n");
    int x=5, y =6;
    int *a = &x;
    int *b = &y;
    printf("a = %d, a_ptr = %p\na = %d, b_ptr = %p\n", *a, a, *b, b);
    printf("swap them\n");
    swap(&a, &b, sizeof(int*));
    printf("b = %d, a_ptr = %p\na = %d, b_ptr = %p\n", *a, a, *b, b);
    printf("-------task 1 swap function test end-------\n\n");

    printf("-------task 2 sort pointers test begin-------\n");

    srand(2342);

    int* arr = malloc(sizeof(int)*ARR_SIZE);
    printf("initial array: \n");
    for (unsigned int i=0; i<ARR_SIZE; i++){
        arr[i] = rand()%100;
        printf("%d,", arr[i]);
    }

    printf("\n");
    int ** arr_of_ptrs = make_ptrs_array(arr, ARR_SIZE);
    printf("test output of arr_of_ptrs:\n");

    for (unsigned int i=0; i<ARR_SIZE; i++){
        printf("%d,", (*arr_of_ptrs[i]));
    }
    printf("\n");

    arr_of_ptrs = pointers_merge_sort(arr_of_ptrs, ARR_SIZE);
    printf("pointers array, sorted by value:\n");
    for (unsigned int i=0; i<ARR_SIZE; i++){
        printf("%d,", (*arr_of_ptrs[i]));
    }
    printf("\n");
    printf("initial array:\n");
    for (unsigned int i=0; i<ARR_SIZE; i++){
        printf("%d,", (arr[i]));
    }
    printf("\n");
    printf("-------task 2 sort pointers test end-------\n\n");
    free(arr_of_ptrs);
    free(arr);
    return 0;
}
