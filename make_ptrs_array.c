//
// Created by raulett on 04.07.2023.
//

#include "make_ptrs_array.h"

int ** make_ptrs_array(int arr[], size_t arr_size){
    int** arr_of_ptrs = malloc(sizeof(int**)*arr_size);

    for (size_t i=0; i<arr_size; i++){
        arr_of_ptrs[i] = &arr[i];
    }

    return arr_of_ptrs;
}